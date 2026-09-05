#pragma once
#include <Arduino.h>

// Control LQR con gain scheduling por velocidad.
// Ganancias K obtenidas de la DARE discreta (ver python/solve_dare.py).
float lqrComputeDelta(float ey, float epsi, float v); // rad, saturado
float servoFromDelta(float deltaRad);                 // rad -> grados de servo