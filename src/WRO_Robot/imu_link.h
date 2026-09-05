#pragma once
#include <Arduino.h>
#include "parameters.h"

// Enlace UART con el Nicla Vision (firmware OpenMV).
// Mensajes por Serial1 (D0 = RX):
//   "G,<centesimas de grado>\n" -> rumbo continuo a 20 Hz
//   'Y' 'R' 'B' 'W' '.' + '\n'  -> color mas grande visto ('.' = nada)
// Si no hay rumbo fresco, fresh() devuelve false y la mision cae
// al modo sin IMU (integracion de direccion), sin regresiones.
class ImuLink {
public:
  void begin()            { Serial1.begin(115200); }
  void update();          // llamar cada tick: parsea lo disponible
  float yawRad()    const { return _yawDeg * 0.0174532925199433f; }
  char  color()     const { return _color; }        // 'Y','R','B','W','.'
  // Ultimo color SOLO si llego hace poco; si no, '.'.
  char  colorFresh(unsigned long now) const
        { return (_colorSeen && (now - _colorMs) <= COLOR_FRESH_MS)
                   ? _color : '.'; }
  bool  fresh(unsigned long now) const
        { return _seen && (now - _lastMs) <= IMU_TIMEOUT_MS; }
private:
  float _yawDeg = 0.0f;
  unsigned long _lastMs = 0;
  bool  _seen = false;
  char  _color = '.';
  unsigned long _colorMs = 0;
  bool  _colorSeen = false;
  char  _buf[24];
  uint8_t _n = 0;
};

extern ImuLink imuLink;