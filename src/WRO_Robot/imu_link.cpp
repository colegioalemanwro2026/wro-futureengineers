#include "imu_link.h"
#include "parameters.h"

ImuLink imuLink;

void ImuLink::update() {
  while (Serial1.available()) {
    char c = (char)Serial1.read();
    if (c == '\n') {
      _buf[_n] = '\0';
      if (_buf[0] == 'G' && _buf[1] == ',') {
        _yawDeg = atof(_buf + 2) * 0.01f;
        _lastMs = millis();
        _seen = true;
      } else if (_n == 1 && strchr("YRBWG.", _buf[0]) != nullptr) {
        _color = _buf[0];
        _colorMs = millis();
        _colorSeen = true;
      }
      _n = 0;
    } else if (c != '\r' && _n < sizeof(_buf) - 1) {
      _buf[_n++] = c;
    } else {
      _n = 0;   // desborde: descartar linea
    }
  }
}