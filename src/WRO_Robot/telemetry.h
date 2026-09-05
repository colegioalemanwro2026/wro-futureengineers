#pragma once
#include <Arduino.h>
#include "sensors.h"

class Mission;

// Telemetria por Serial a 500 ms (solo para pruebas; apagada en ronda
// por regla 11.10). Envía sensores, estado y estimaciones del EKF.
void telemetrySend(unsigned long now, const SensorReadings& s, const Mission& m);