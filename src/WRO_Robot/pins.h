#pragma once
// ============================================================
// WRO Future Engineers 2026 - Arduino UNO R4 WiFi pinout
// Motor Kittenbot 360 2KG (rojo) via L298N | Servo (gris) en D3
// 3x HC-SR04: izquierdo, frontal, derecho
// ============================================================

#define SERVO_PIN   3    // Servo direccion (gris)
#define ENA_PIN     5    // PWM velocidad motor (L298N) - D5 tiene PWM en R4
#define IN1_PIN     2    // direccion motor
#define IN2_PIN     4    // direccion motor

#define TRIG_LEFT   7
#define ECHO_LEFT   8
#define TRIG_FRONT  9
#define ECHO_FRONT  10
#define TRIG_RIGHT  A0
#define ECHO_RIGHT  A1

#define START_PIN   11   // boton de arranque (INPUT_PULLUP, a GND)
#define BUMPER_PIN  6    // boton de parachoques (INPUT_PULLUP, a GND)
                         // retrocede en recta si choca contra una pared
