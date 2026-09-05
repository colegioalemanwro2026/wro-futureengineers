#pragma once
#include <Arduino.h>

// Motor DC (rojo) via L298N. pwm 0..255.
void motorForward(int pwm);
void motorReverse(int pwm);
void motorBrake();