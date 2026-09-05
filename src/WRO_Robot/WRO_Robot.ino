// ============================================================
// WRO Future Engineers 2025-2026 - Open Challenge
// Control LQR + Filtro de Kalman sobre Arduino UNO R4 WiFi
// Motor Kittenbot 360 2KG (rojo) + L298N | Servo (gris) direccion
// 3x HC-SR04 (izq, frente, der) | Bateria Li-Ion 7.2V
// HOLAAAAAAAAAAAAAAAAAAAAAAAAAAA
// ============================================================
#include <Servo.h>

#include "pins.h"
#include "parameters.h"
#include "sensors.h"
#include "mission.h"
#include "actuators.h"
#include "telemetry.h"

Servo steeringServo;
Ultrasonic sonarLeft (TRIG_LEFT,  ECHO_LEFT);
Ultrasonic sonarFront(TRIG_FRONT, ECHO_FRONT);
Ultrasonic sonarRight(TRIG_RIGHT, ECHO_RIGHT);
Mission mission;

unsigned long lastTick = 0;

void setup() {
  Serial.begin(115200);

  pinMode(ENA_PIN, OUTPUT);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  pinMode(START_PIN, INPUT_PULLUP);
  pinMode(BUMPER_PIN, INPUT_PULLUP);  // parachoques Pin 6 (HIGH suelto, LOW presionado)

  steeringServo.attach(SERVO_PIN);
  steeringServo.write((int)SERVO_CENTER);

  sonarLeft.begin();
  sonarFront.begin();
  sonarRight.begin();

  imuLink.begin();          // Nicla Vision por Serial1 (D0 = RX)

  mission.init();
  motorBrake();

  delay(200);
  Serial.println(F("WRO FE 2026 - arranca solo. Comandos: s=iniciar, t=detener, m=recta prueba."));
}

void loop() {
  unsigned long now = millis();
  if (now - lastTick >= (unsigned long)(DT * 1000.0f)) {
    lastTick = now;

    // Rumbo del Nicla Vision (si esta conectado).
    imuLink.update();

    // Lectura secuencial de los 3 HC-SR04 (evita cross-talk).
    SensorReadings s;
    s.dLeft  = sonarLeft.readMeters();
    s.dFront = sonarFront.readMeters();
    s.dRight = sonarRight.readMeters();

    // EKF -> LQR -> ordenes de actuadores.
    float steerDeg = SERVO_CENTER;
    int pwm = 0, dir = 0;
    mission.update(now, s, steerDeg, pwm, dir);

    steeringServo.write((int)constrain(steerDeg, 0.0f, 60.0f));
    if      (dir ==  1) motorForward(pwm);
    else if (dir == -1) motorReverse(pwm);
    else                motorBrake();

    telemetrySend(now, s, mission);
  }
}