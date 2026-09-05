// ============================================================
// Nicla Vision - coprocesador de rumbo (giroscopio LSM6DSOX)
// Envia por Serial1 a 115200 baud: "Y,<centesimas de grado>\n"
// a 50 Hz. Yaw CONTINUO (sin envolver), CCW positivo.
// Montar el Nicla plano, eje Z del chip hacia arriba.
// ============================================================
#include <Arduino_LSM6DSOX.h>

#define YAW_SIGN   +1.0f   // invertir a -1 si el robot gira al reves
#define TX_HZ      50

float yawDeg  = 0.0f;
float biasZ   = 0.0f;
unsigned long lastUs = 0;

void setup() {
  Serial.begin(115200);        // debug por USB
  Serial1.begin(115200);       // enlace al UNO R4
  if (!IMU.begin()) {
    while (1) { }              // sin IMU: quedarse aqui
  }

  // Calibracion de bias: robot COMPLETAMENTE quieto ~2 s al encender.
  const int N = 400;
  float sum = 0.0f;
  for (int i = 0; i < N; i++) {
    float x, y, z;
    while (!IMU.gyroscopeAvailable()) { }
    IMU.readGyroscope(x, y, z);
    sum += z;
  }
  biasZ  = sum / N;
  lastUs = micros();

  Serial.println(F("Nicla IMU listo"));
}

void loop() {
  float x, y, z;
  if (!IMU.gyroscopeAvailable()) return;
  IMU.readGyroscope(x, y, z);

  unsigned long us = micros();
  float dt = (us - lastUs) * 1e-6f;
  lastUs = us;
  yawDeg += YAW_SIGN * (z - biasZ) * dt;

  static unsigned long lastTx = 0;
  if (millis() - lastTx >= (unsigned long)(1000 / TX_HZ)) {
    lastTx = millis();
    Serial1.print(F("Y,"));
    Serial1.print((long)(yawDeg * 100.0f));
    Serial1.print('\n');
  }
}