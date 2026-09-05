#pragma once

#include <Arduino.h>

#include "sensors.h"
#include "kalman.h"
#include "imu_link.h"

// ============================================================
// ESTADOS DE LA MISION
// ============================================================

enum class RobotState : uint8_t {

IDLE = 0,          // esperando boton de START

FOLLOW,            // seguimiento mediante Kalman + LQR

CORNER_TURN,       // giro de 90 grados

RECOVERY,          // retroceso de seguridad

STOP,              // mision finalizada

STRAIGHT_TEST      // prueba de movimiento recto
};

// ============================================================
// MAQUINA DE ESTADOS
// ============================================================

class Mission {

public:

void init();

// ----------------------------------------------------------
// UPDATE PRINCIPAL
// ----------------------------------------------------------

// Recibe lecturas de sensores y entrega:
//
// steerServoDeg = posicion del servo
// motorPwm      = PWM del motor
// motorDir      = 1 adelante, -1 atras, 0 detenido

void update(unsigned long now,
const SensorReadings& s,
float& steerServoDeg,
int& motorPwm,
int& motorDir);

// ----------------------------------------------------------
// TELEMETRIA / ESTADO
// ----------------------------------------------------------

RobotState state() const {

return _state;


}

int cornerCount() const {


return _cornerCount;


}

int recoveryCount() const {


return _recoveryCount;


}

float eyEst() const {


return _kf.ey();


}

float epsiEst() const {


return _kf.epsi();


}

private:

// ==========================================================
// ESTADO PRINCIPAL
// ==========================================================

RobotState _state;

Kalman _kf;

// ==========================================================
// CONTROL DE DIRECCION
// ==========================================================

// +1 = izquierda
// -1 = derecha

int8_t _turnDir;

// Ultima direccion aplicada por el LQR / giro.

float _lastDelta;

// ==========================================================
// VELOCIDAD
// ==========================================================

float _vCurrent;

// ==========================================================
// TIEMPOS
// ==========================================================

unsigned long _stateStartMs;

// ==========================================================
// CONTADORES DE MISION
// ==========================================================

int _cornerCount;

int _recoveryCount;

// ==========================================================
// DETECCION DE ESQUINA
// ==========================================================

int _frontCloseTicks;

int _frontClearTicks;

// Instante en que se confirma una posible esquina.

unsigned long _cornerConfirmMs;

// ==========================================================
// MEMORIA DEL SENSOR FRONTAL
// ==========================================================

// Ultima vez que el frontal vio una pared cercana.

unsigned long _frontLastCloseMs;

// Indica que anteriormente se detecto una pared cercana.

bool _frontWasClose;

// ==========================================================
// DIRECCION DE GIRO
// ==========================================================

// En Open Challenge:
//
// false = todavia no se ha decidido
// true  = direccion fijada durante la carrera

bool _turnDirLocked;

// ==========================================================
// SERIAL
// ==========================================================

bool _serialStart;

// ==========================================================
// IMU
// ==========================================================

// Rumbo absoluto de referencia del corredor actual.

float _yawRef;

// Rumbo al comenzar un giro.

float _yawTurn0;

// Indica si la IMU estaba disponible al comenzar el giro.

bool _imuActive;

// ==========================================================
// BUMPER
// ==========================================================

// Indica que el RECOVERY fue provocado por el bumper.

bool _bumperTriggered;

// Numero de ticks consecutivos del bumper.

int _bumperTicks;

// Evita multiples disparos mientras permanece presionado.

bool _bumperArmed;

// Nivel electrico detectado cuando el bumper esta en reposo.

int _bumperIdleLevel;
};
