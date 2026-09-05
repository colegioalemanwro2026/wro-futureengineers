#include "actuators.h"
#include "pins.h"

void motorForward(int pwm) {
  // Polaridad invertida en este auto: adelante = IN1 LOW, IN2 HIGH.
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, HIGH);
  analogWrite(ENA_PIN, constrain(pwm, 0, 255));
}

void motorReverse(int pwm) {
  digitalWrite(IN1_PIN, HIGH);
  digitalWrite(IN2_PIN, LOW);
  analogWrite(ENA_PIN, constrain(pwm, 0, 255));
}

void motorBrake() {
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, LOW);
  analogWrite(ENA_PIN, 0);
}