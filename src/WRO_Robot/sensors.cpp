#include "sensors.h"

Ultrasonic::Ultrasonic(uint8_t trigPin, uint8_t echoPin)
  : _trig(trigPin), _echo(echoPin) {}

void Ultrasonic::begin() {
  pinMode(_trig, OUTPUT);
  pinMode(_echo, INPUT);
  digitalWrite(_trig, LOW);
}

float Ultrasonic::readMeters() {
  digitalWrite(_trig, LOW);
  delayMicroseconds(3);
  digitalWrite(_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trig, LOW);

  unsigned long t0 = micros();
  while (digitalRead(_echo) == LOW) {
    if (micros() - t0 > 5000UL) return -1.0f;   // sin inicio de eco
  }
  unsigned long t1 = micros();
  while (digitalRead(_echo) == HIGH) {
    if (micros() - t1 > 30000UL) return -1.0f;  // >30 ms => fuera de rango
  }
  unsigned long t2 = micros();
  float seconds = (float)(t2 - t1) * 1e-6f;
  float meters  = seconds * 343.0f * 0.5f;       // ida y vuelta
  if (meters > 3.5f) return -1.0f;
  return meters;
}
