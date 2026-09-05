#include "mission.h"
#include "parameters.h"
#include "lqr.h"
#include "pins.h"

// ============================================================
// UTILIDADES ANGULARES
// ============================================================

// Normaliza un angulo a [-PI, PI].

static inline float wrapAngle(float a) {

while (a > PI) {


a -= 2.0f * PI;


}

while (a < -PI) {


a += 2.0f * PI;


}

return a;
}

// Diferencia angular firmada.
// target - current.

static inline float angleDiff(float target,
float current) {

return wrapAngle(target - current);
}

// Redondea un rumbo al cardinal mas cercano.

static inline float snapToCardinal(float yawRad) {

const float step =
(float)PI / 2.0f;

return roundf(yawRad / step) *
step;
}

// Limita un valor.

static inline float clampFloat(float x,
float minVal,
float maxVal) {

if (x < minVal) {


return minVal;


}

if (x > maxVal) {


return maxVal;


}

return x;
}

// ============================================================
// CONTROL PROGRESIVO DEL GIRO
// ============================================================

static inline float turnSteerMagnitude(
float turnedAbs) {

// ----------------------------------------------------------
// 0 - 55 grados
// Giro fuerte.
// ----------------------------------------------------------

if (turnedAbs < 0.96f) {


return STEER_MAX_RAD;


}

// ----------------------------------------------------------
// 55 - 70 grados
// Reducimos progresivamente.
// ----------------------------------------------------------

if (turnedAbs < 1.22f) {


float k =
    (1.22f - turnedAbs) /
    (1.22f - 0.96f);

k = clampFloat(
    k,
    0.0f,
    1.0f
);

return STEER_MAX_RAD *
       (0.55f + 0.45f * k);


}

// ----------------------------------------------------------
// 70 - 80 grados
// Giro moderado.
// ----------------------------------------------------------

if (turnedAbs < 1.40f) {


float k =
    (1.40f - turnedAbs) /
    (1.40f - 1.22f);

k = clampFloat(
    k,
    0.0f,
    1.0f
);

return STEER_MAX_RAD *
       (0.22f + 0.33f * k);


}

// ----------------------------------------------------------
// 80 grados en adelante.
// Giro muy pequeño.
// ----------------------------------------------------------

return STEER_MAX_RAD *
0.12f;
}

// ============================================================
// ERROR LATERAL
// ============================================================

static inline float bestEy(
float dL,
float dR,
bool haveEy,
bool validL,
bool validR,
bool& haveZ) {

// Ambas paredes disponibles.

if (haveEy) {


haveZ = true;

return
    (dR - dL) /
    2.0f;


}

// Solo pared derecha.

if (validR &&
dR < OPEN_SIDE_M) {


haveZ = true;

return
    dR -
    CORRIDOR_HALF_M;


}

// Solo pared izquierda.

if (validL &&
dL < OPEN_SIDE_M) {


haveZ = true;

return
    CORRIDOR_HALF_M -
    dL;


}

haveZ = false;

return 0.0f;
}

// ============================================================
// INICIALIZACION
// ============================================================

void Mission::init() {

_state =
RobotState::IDLE;

_turnDir =
1;

_lastDelta =
0.0f;

_vCurrent =
V_CRUISE;

_stateStartMs =
0;

_cornerCount =
0;

_recoveryCount =
0;

_frontCloseTicks =
0;

_frontClearTicks =
0;

_serialStart =
false;

_yawRef =
0.0f;

_yawTurn0 =
0.0f;

_imuActive =
false;

_bumperTriggered =
false;

_cornerConfirmMs =
0;

_bumperTicks =
0;

_bumperArmed =
true;

_bumperIdleLevel =
digitalRead(
BUMPER_PIN
);

// Memoria frontal.

_frontLastCloseMs =
0;

_frontWasClose =
false;

// Direccion Open Challenge.

_turnDirLocked =
false;

_kf.init();
}

// ============================================================
// UPDATE PRINCIPAL
// ============================================================

void Mission::update(
unsigned long now,
const SensorReadings& s,
float& steerServoDeg,
int& motorPwm,
int& motorDir) {

// ----------------------------------------------------------
// SALIDAS POR DEFECTO
// ----------------------------------------------------------

steerServoDeg =
SERVO_CENTER;

motorPwm =
0;

motorDir =
0;

// ----------------------------------------------------------
// SENSORES
// ----------------------------------------------------------

float dL =
s.dLeft;

float dF =
s.dFront;

float dR =
s.dRight;

bool validL =
dL >= 0.0f &&
dL < 2.5f;

bool validF =
dF >= 0.0f &&
dF < 2.5f;

bool validR =
dR >= 0.0f &&
dR < 2.5f;

// ----------------------------------------------------------
// IMU
// ----------------------------------------------------------

bool imuOk =
imuLink.fresh(now);

float psiMeas =
0.0f;

if (imuOk) {


psiMeas =
    angleDiff(
        imuLink.yawRad(),
        _yawRef
    );


}

// ----------------------------------------------------------
// ERROR LATERAL
// ----------------------------------------------------------

bool haveEy =
validL &&
validR;

bool haveZ =
false;

float z =
bestEy(
dL,
dR,
haveEy,
validL,
validR,
haveZ
);

// ----------------------------------------------------------
// APERTURA LATERAL
// ----------------------------------------------------------

bool leftOpen =
!validL ||
dL > OPEN_SIDE_M;

bool rightOpen =
!validR ||
dR > OPEN_SIDE_M;

// ----------------------------------------------------------
// MEMORIA DEL SENSOR FRONTAL
// ----------------------------------------------------------

bool rawFrontClose =
validF &&
dF < CORNER_FRONT_TRIG;

if (rawFrontClose) {


_frontWasClose =
    true;

_frontLastCloseMs =
    now;


}

bool stickyClose =
_frontWasClose &&
_frontLastCloseMs != 0 &&
(now - _frontLastCloseMs <=
FRONT_STALE_MS);

bool frontClose =
rawFrontClose ||
stickyClose;

// IMPORTANTE:
// Sin eco NO significa frente libre.

bool frontClear =
validF &&
dF > CORNER_FRONT_CLEAR;

// ==========================================================
// COMANDOS SERIAL
// ==========================================================

// ======================================================
// COMANDOS SERIAL
// ======================================================

while (Serial.available()) {

  char c = (char)Serial.read();

  // ----------------------------------------------------
  // C = FORZAR FIN DEL GIRO
  // ----------------------------------------------------

  if (c == 'c' || c == 'C') {

    if (_state == RobotState::CORNER_TURN) {

      Serial.println(">>> C: FORZANDO FIN DEL GIRO");

      _cornerCount++;

      if (_imuActive && imuLink.fresh(now)) {

        _yawRef +=
            (float)_turnDir *
            ((float)PI / 2.0f);

        _yawRef =
            snapToCardinal(_yawRef);

        float eyNew =
            haveZ ? z : _kf.ey();

        float epsiNew =
            angleDiff(
                imuLink.yawRad(),
                _yawRef
            );

        epsiNew =
            clampFloat(
                epsiNew,
                -20.0f * DEG2RAD,
                 20.0f * DEG2RAD
            );

        _kf.init(
            eyNew,
            epsiNew
        );
      }

      _lastDelta = 0.0f;

      _frontCloseTicks = 0;
      _frontClearTicks = 0;
      _cornerConfirmMs = 0;

      _frontWasClose = false;
      _frontLastCloseMs = 0;

      _state =
          RobotState::FOLLOW;

      _vCurrent =
          V_CRUISE;

      _stateStartMs =
          now;

      Serial.println(">>> C: FOLLOW - AVANZANDO");
    }
  }

  // ----------------------------------------------------
  // S = START
  // ----------------------------------------------------

  else if (c == 's' || c == 'S') {

    _state =
        RobotState::IDLE;

    _serialStart =
        true;
  }

  // ----------------------------------------------------
  // T = STOP
  // ----------------------------------------------------

  else if (c == 't' || c == 'T') {

    _state =
        RobotState::STOP;
  }

  // ----------------------------------------------------
  // M = STRAIGHT TEST
  // ----------------------------------------------------

  else if (c == 'm' || c == 'M') {

    _state =
        RobotState::STRAIGHT_TEST;
  }
}

// ==========================================================
// BUMPER
// ==========================================================

bool bumperIsPressed =
digitalRead(
BUMPER_PIN
) !=
_bumperIdleLevel;

if (bumperIsPressed) {


_bumperTicks++;


}

else {


_bumperTicks =
    0;

_bumperArmed =
    true;


}

bool canUseBumper =
(_state ==
RobotState::FOLLOW ||
_state ==
RobotState::CORNER_TURN) &&
(now - _stateStartMs >
1000);

if (_bumperArmed &&
canUseBumper &&
_bumperTicks >= 2) {


_bumperTriggered =
    true;

_bumperArmed =
    false;

_bumperTicks =
    0;


_state =
    RobotState::RECOVERY;

_stateStartMs =
    now;

_vCurrent =
    V_RECOVERY;

_recoveryCount++;

_frontCloseTicks =
    0;

_frontClearTicks =
    0;

_cornerConfirmMs =
    0;


}

// ==========================================================
// MAQUINA DE ESTADOS
// ==========================================================

switch (_state) {


// ========================================================
// IDLE
// ========================================================

case RobotState::IDLE: {


  if (digitalRead(
          START_PIN
      ) == LOW) {

    _frontCloseTicks++;
  }

  else {

    _frontCloseTicks =
        0;
  }


  if (_serialStart) {

    _frontCloseTicks =
        CLOSE_TICKS;

    _serialStart =
        false;
  }


  if (_frontCloseTicks >=
      2) {


    _cornerCount =
        0;

    _recoveryCount =
        0;

    _frontCloseTicks =
        0;

    _frontClearTicks =
        0;

    _lastDelta =
        0.0f;

    _vCurrent =
        V_CRUISE;

    _turnDirLocked =
        false;


    // Referencia inicial.

    if (imuOk) {

      _yawRef =
          snapToCardinal(
              imuLink.yawRad()
          );
    }

    else {

      _yawRef =
          0.0f;
    }


    _kf.init();


    _frontWasClose =
        false;

    _frontLastCloseMs =
        0;


    _stateStartMs =
        now;

    _state =
        RobotState::FOLLOW;
  }


  break;
}


// ========================================================
// FOLLOW
// ========================================================

case RobotState::FOLLOW: {


  // ------------------------------------------------------
  // KALMAN
  // ------------------------------------------------------

  _kf.predict(
      _vCurrent,
      _lastDelta
  );


  if (haveZ) {

    _kf.update(
        z
    );
  }


  if (imuOk) {

    _kf.updatePsi(
        psiMeas
    );
  }


  // ------------------------------------------------------
  // COLISION FRONTAL
  // ------------------------------------------------------

  if (validF &&
      dF <
      COLLISION_DIST_M) {


    _state =
        RobotState::RECOVERY;

    _stateStartMs =
        now;

    _vCurrent =
        V_RECOVERY;

    _recoveryCount++;

    _bumperTriggered =
        false;

    _frontCloseTicks =
        0;

    _frontClearTicks =
        0;

    _cornerConfirmMs =
        0;


    break;
  }


  // ------------------------------------------------------
  // RESPALDO IMU
  // ------------------------------------------------------

  bool wallCloseAnySide =
      (validF &&
       dF <
       CORNER_FRONT_TRIG) ||

      (validL &&
       dL <
       WALL_NEAR_M) ||

      (validR &&
       dR <
       WALL_NEAR_M) ||

      stickyClose;


  if (imuOk &&
      fabsf(
          psiMeas
      ) >
      HEADING_DANGER_RAD &&
      wallCloseAnySide) {


    _state =
        RobotState::RECOVERY;

    _stateStartMs =
        now;

    _vCurrent =
        V_RECOVERY;

    _recoveryCount++;

    _bumperTriggered =
        false;

    _frontCloseTicks =
        0;

    _frontClearTicks =
        0;

    _cornerConfirmMs =
        0;


    break;
  }


  // ------------------------------------------------------
  // DETECCION DE ESQUINA
  // ------------------------------------------------------

  if (rawFrontClose) {

    if (_frontCloseTicks <
        CLOSE_TICKS) {

      _frontCloseTicks++;
    }
  }


  else if (stickyClose) {

    // Conservamos el contador.
    // No incrementamos artificialmente.

  }


  else {

    _frontCloseTicks =
        0;
  }


  if (_frontCloseTicks >=
      CLOSE_TICKS) {

    if (_cornerConfirmMs ==
        0) {

      _cornerConfirmMs =
          now;
    }
  }


  // ------------------------------------------------------
  // CONFIRMACION DE ESQUINA
  // ------------------------------------------------------

  if (_cornerConfirmMs !=
      0) {

    char col =
        imuLink.colorFresh(
            now
        );


    bool colorReady =
        col != '.';


    bool observeDone =
        (now -
         _cornerConfirmMs) >=
        CORNER_COLOR_OBSERVE_MS;


    if (colorReady ||
        observeDone) {


      // --------------------------------------------------
      // DIRECCION DEL GIRO
      // --------------------------------------------------

      if (col ==
          COLOR_LEFT_CHAR) {

        _turnDir =
            +1;
      }


      else if (col !=
               '.') {

        _turnDir =
            -1;
      }


      else if (!_turnDirLocked) {


        if (leftOpen &&
            !rightOpen) {

          _turnDir =
              +1;
        }


        else if (rightOpen &&
                 !leftOpen) {

          _turnDir =
              -1;
        }


        else {

          _turnDir =
              (dL > dR)
              ? +1
              : -1;
        }


        _turnDirLocked =
            true;
      }


      // --------------------------------------------------
      // ENTRAR EN GIRO
      // --------------------------------------------------

      _imuActive =
          imuOk;


      if (_imuActive) {

        _yawTurn0 =
            imuLink.yawRad();
      }

      else {

        _yawTurn0 =
            0.0f;
      }


      _cornerConfirmMs =
          0;


      _state =
          RobotState::CORNER_TURN;

      _stateStartMs =
          now;

      _frontClearTicks =
          0;

      _frontCloseTicks =
          0;

      _vCurrent =
          V_CORNER;


      _lastDelta =
          (float)_turnDir *
          STEER_MAX_RAD;
    }


    else if (!frontClose) {

      _cornerConfirmMs =
          0;
    }
  }


  // ------------------------------------------------------
  // CONTROL LQR
  // ------------------------------------------------------

  else {


    float delta =
        haveZ
        ? lqrComputeDelta(
              _kf.ey(),
              _kf.epsi(),
              _vCurrent
          )
        : 0.0f;


    _lastDelta =
        delta;


    steerServoDeg =
        servoFromDelta(
            delta
        );


    motorPwm =
        PWM_CRUISE;

    motorDir =
        1;
  }


  // ------------------------------------------------------
  // ATASCO
  // ------------------------------------------------------

  if (frontClose &&
      ((validL &&
        dL <
        WALL_NEAR_M) ||

       (validR &&
        dR <
        WALL_NEAR_M))) {


    _state =
        RobotState::RECOVERY;

    _stateStartMs =
        now;

    _vCurrent =
        V_RECOVERY;

    _recoveryCount++;

    _bumperTriggered =
        false;

    _frontCloseTicks =
        0;

    _cornerConfirmMs =
        0;
  }


  break;
}


// ========================================================
// CORNER TURN
// ========================================================

case RobotState::CORNER_TURN: {


  _kf.predict(
      _vCurrent,
      _lastDelta
  );


  // ------------------------------------------------------
  // ANGULO GIRADO
  // ------------------------------------------------------

  float turnedSigned =
      0.0f;

  float turnedAbs =
      0.0f;


  if (_imuActive &&
      imuLink.fresh(
          now
      )) {


    float yawNow =
        imuLink.yawRad();


    turnedSigned =
        angleDiff(
            yawNow,
            _yawTurn0
        );


    turnedAbs =
        (float)_turnDir *
        turnedSigned;


    if (turnedAbs <
        0.0f) {

      turnedAbs =
          0.0f;
    }
  }


  // ------------------------------------------------------
  // GIRO PROGRESIVO
  // ------------------------------------------------------

  float steerMagnitude =
      turnSteerMagnitude(
          turnedAbs
      );


  float delta =
      (float)_turnDir *
      steerMagnitude;


  // ------------------------------------------------------
  // FRENADO / CONTRA-GIRO
  // ------------------------------------------------------

  if (_imuActive &&
      imuLink.fresh(
          now
      )) {


    // Desde aproximadamente 80 grados.

    if (turnedAbs >=
            1.40f &&
        turnedAbs <
            1.50f) {

      delta =
          -(float)_turnDir *
          (STEER_MAX_RAD *
           0.08f);
    }


    // Muy cerca de 90 grados.

    else if (turnedAbs >=
             1.50f) {

      delta =
          -(float)_turnDir *
          (STEER_MAX_RAD *
           0.18f);
    }
  }


  _lastDelta =
      delta;


  steerServoDeg =
      servoFromDelta(
          delta
      );


  // ------------------------------------------------------
  // VELOCIDAD PROGRESIVA
  // ------------------------------------------------------

  if (!_imuActive) {

    motorPwm =
        PWM_CORNER;
  }


  else {


    if (turnedAbs <
        0.96f) {

      motorPwm =
          PWM_CORNER;
    }


    else if (turnedAbs <
             1.22f) {

      motorPwm =
          125;
    }


    else if (turnedAbs <
             1.40f) {

      motorPwm =
          105;
    }


    else {

      motorPwm =
          80;
    }
  }


  motorDir =
      1;


  // ------------------------------------------------------
  // SALIDA FRONTAL
  // ------------------------------------------------------

  bool frontExit =
      frontClear &&
      (now -
       _stateStartMs >
       TURN_MIN_MS);


  // ------------------------------------------------------
  // SALIDA IMU
  // ------------------------------------------------------

  bool gyroExit =
      false;


  if (_imuActive &&
      imuLink.fresh(
          now
      )) {


    const float TURN_EXIT_RAD =
        78.0f * //Aqui
        DEG2RAD;


    gyroExit =
        turnedAbs >=
        TURN_EXIT_RAD;


    if (now -
        _stateStartMs <
        TURN_MIN_MS) {

      gyroExit =
          false;
    }
  }


  // ------------------------------------------------------
  // DECISION DE FIN DEL GIRO
  // ------------------------------------------------------

  bool turnComplete =
      false;


  if (_imuActive &&
      imuLink.fresh(
          now
      )) {


    turnComplete =
        gyroExit;
  }


  else {


    turnComplete =
        frontExit;
  }


  // ------------------------------------------------------
  // CONFIRMACION DEL FIN
  // ------------------------------------------------------

  if (_imuActive &&
      imuLink.fresh(
          now
      )) {


    // Con IMU no esperamos varios ciclos.

    if (turnComplete) {

      _frontClearTicks =
          CLEAR_TICKS;
    }

    else {

      _frontClearTicks =
          0;
    }
  }


  else {


    if (turnComplete) {

      _frontClearTicks++;
    }

    else {

      _frontClearTicks =
          0;
    }
  }


  // ------------------------------------------------------
  // GIRO TERMINADO
  // ------------------------------------------------------

  if (_frontClearTicks >=
      CLEAR_TICKS) {


    _cornerCount++;

    _frontCloseTicks =
        0;


    // ----------------------------------------------------
    // TOTAL DE ESQUINAS
    // ----------------------------------------------------

    if (_cornerCount >=
        TOTAL_CORNERS) {


      _state =
          RobotState::STOP;
    }


    else {


      float eyNew =
          haveZ
          ? z
          : _kf.ey();


      float epsiNew =
          0.0f;


      // --------------------------------------------------
      // NUEVA REFERENCIA DE RUMBO
      // --------------------------------------------------

      if (_imuActive &&
          imuLink.fresh(
              now
          )) {


        _yawRef +=
            (float)_turnDir *
            ((float)PI /
             2.0f);


        _yawRef =
            snapToCardinal(
                _yawRef
            );


        epsiNew =
            angleDiff(
                imuLink.yawRad(),
                _yawRef
            );


        // Proteccion contra una correccion
        // excesiva inmediatamente despues
        // de terminar el giro.

        epsiNew =
            clampFloat(
                epsiNew,
                -20.0f *
                DEG2RAD,
                20.0f *
                DEG2RAD
            );
      }


      else {


        epsiNew =
            _kf.epsi() -
            (float)_turnDir *
            ((float)PI /
             2.0f);
      }


      _kf.init(
          eyNew,
          epsiNew
      );


      _lastDelta =
          0.0f;


      _state =
          RobotState::FOLLOW;


      _vCurrent =
          V_CRUISE;


      _stateStartMs =
          now;


      _frontWasClose =
          false;

      _frontLastCloseMs =
          0;


      _frontClearTicks =
          0;

      _frontCloseTicks =
          0;
    }
  }


  // ------------------------------------------------------
  // TIMEOUT
  // ------------------------------------------------------

  else if (
      now -
      _stateStartMs >
      MAX_TURN_MS) {


    _state =
        RobotState::RECOVERY;

    _stateStartMs =
        now;

    _vCurrent =
        V_RECOVERY;

    _recoveryCount++;
  }


  break;
}


// ========================================================
// RECOVERY
// ========================================================

case RobotState::RECOVERY: {


  _kf.predict(
      -_vCurrent,
      _lastDelta
  );


  // ------------------------------------------------------
  // DIRECCION
  // ------------------------------------------------------

  float delta =
      0.0f;


  if (_bumperTriggered) {


    delta =
        0.0f;
  }


  else if (validR &&
           dR <
           0.25f) {


    delta =
        STEER_MAX_RAD;
  }


  else if (validL &&
           dL <
           0.25f) {


    delta =
        -STEER_MAX_RAD;
  }


  _lastDelta =
      delta;


  steerServoDeg =
      servoFromDelta(
          delta
      );


  motorPwm =
      PWM_RECOVERY;

  motorDir =
      -1;


  // ------------------------------------------------------
  // TIEMPOS
  // ------------------------------------------------------

  bool minTimeDone =
      now -
      _stateStartMs >
      RECOVERY_TIME_MS;


  bool maxTimeDone =
      now -
      _stateStartMs >
      RECOVERY_MAX_MS;


  // ------------------------------------------------------
  // FRENTE
  // ------------------------------------------------------

  bool frontStillBlocked =
      validF &&
      dF <
      CORNER_FRONT_TRIG;


  bool frontUnknown =
      !validF;


  bool lateralSpaceAvailable =
      (validL &&
       dL >
       WALL_NEAR_M) ||

      (validR &&
       dR >
       WALL_NEAR_M);


  // ------------------------------------------------------
  // DECISION DE SALIDA
  // ------------------------------------------------------

  bool canLeaveRecovery =
      false;


  if (maxTimeDone) {


    canLeaveRecovery =
        true;
  }


  else if (minTimeDone &&
           !frontStillBlocked) {


    if (!frontUnknown) {

      canLeaveRecovery =
          true;
    }


    else if (
        lateralSpaceAvailable) {

      canLeaveRecovery =
          true;
    }
  }


  if (canLeaveRecovery) {


    float eyNew =
        haveZ
        ? z
        : _kf.ey();


    float epsiNew =
        imuOk
        ? psiMeas
        : _kf.epsi();


    _kf.init(
        eyNew,
        epsiNew
    );


    _lastDelta =
        0.0f;

    _bumperTriggered =
        false;

    _frontCloseTicks =
        0;

    _frontClearTicks =
        0;

    _cornerConfirmMs =
        0;


    if (imuOk) {


      epsiNew =
          angleDiff(
              imuLink.yawRad(),
              _yawRef
          );


      _kf.init(
          eyNew,
          epsiNew
      );
    }


    _state =
        RobotState::FOLLOW;


    _vCurrent =
        V_CRUISE;


    _stateStartMs =
        now;
  }


  break;
}


// ========================================================
// STRAIGHT TEST
// ========================================================

case RobotState::STRAIGHT_TEST: {


  _lastDelta =
      0.0f;


  steerServoDeg =
      SERVO_CENTER;


  motorPwm =
      PWM_CRUISE;


  motorDir =
      1;


  break;
}


// ========================================================
// STOP
// ========================================================

case RobotState::STOP: {


  _lastDelta =
      0.0f;


  steerServoDeg =
      SERVO_CENTER;


  motorPwm =
      0;

  motorDir =
      0;


  break;
}


}
}
