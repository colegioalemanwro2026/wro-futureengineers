#pragma once
#include <Arduino.h>

// Lectura de un HC-SR04 con timeout. Devuelve distancia en metros,
// o -1.0 si no hay eco valido (fuera de rango / sin pared).
class Ultrasonic {
public:
  Ultrasonic(uint8_t trigPin, uint8_t echoPin);
  void begin();
  float readMeters();
private:
  uint8_t _trig;
  uint8_t _echo;
};

// Lecturas del tick actual. -1.0 significa invalido (sin pared).
struct SensorReadings {
  float dLeft  = -1.0f;   // m
  float dFront = -1.0f;   // m
  float dRight = -1.0f;   // m
};
