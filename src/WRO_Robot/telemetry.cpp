#include "telemetry.h"
#include "parameters.h"
#include "mission.h"
#include "pins.h"

void telemetrySend(unsigned long now, const SensorReadings& s, const Mission& m) {
  static unsigned long last = 0;
  if (now - last < 500) return;   // 2 Hz
  last = now;

  Serial.print(F("t="));   Serial.print(now);
  Serial.print(F(" st=")); Serial.print((int)m.state());
  Serial.print(F(" btn=")); Serial.print(digitalRead(START_PIN));
  Serial.print(F(" L="));  Serial.print(s.dLeft  * 100.0f, 1);
  Serial.print(F(" F="));  Serial.print(s.dFront * 100.0f, 1);
  Serial.print(F(" R="));  Serial.print(s.dRight * 100.0f, 1);
  Serial.print(F(" ey=")); Serial.print(m.eyEst()   * 100.0f, 1);
  Serial.print(F(" ps=")); Serial.print(m.epsiEst() * 57.29578f, 1);
  Serial.print(F(" yaw="));
  if (imuLink.fresh(now)) Serial.print(imuLink.yawRad() * 57.29578f, 1);
  else                    Serial.print(F("---"));
  Serial.print(F(" col=")); Serial.print(imuLink.color());
  Serial.print(F(" cor=")); Serial.print(m.cornerCount());
  Serial.print(F(" rec=")); Serial.print(m.recoveryCount());
  Serial.println();
}