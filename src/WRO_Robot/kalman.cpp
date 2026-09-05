#include "kalman.h"
#include "parameters.h"

void Kalman::init(float ey0, float epsi0) {
  _x[0] = ey0;
  _x[1] = epsi0;
  _cov[0] = 1e-3f;   // incertidumbre inicial moderada
  _cov[1] = 0.0f;
  _cov[2] = 1e-3f;
}

// x+ = A x + B u ;  P+ = A P A' + Q
// A = [[1, v*Ts],[0,1]], B = [[0],[(v/L)*tan(delta)*Ts]]
void Kalman::predict(float v, float deltaRad) {
  float a = v * DT;
  float b = (v / WHEELBASE_M) * tanf(deltaRad) * DT;

  float x0 = _x[0] + a * _x[1];
  float x1 = _x[1] + b;
  _x[0] = x0;
  _x[1] = x1;

  float p11 = _cov[0], p12 = _cov[1], p22 = _cov[2];
  _cov[0] = p11 + 2.0f * a * p12 + a * a * p22 + QK_EY;
  _cov[1] = p12 + a * p22;
  _cov[2] = p22 + QK_EPSI;
}

// Actualizacion con H = [1, 0]. Rechaza outliers por Mahalanobis.
bool Kalman::update(float eyMeas) {
  float p11 = _cov[0], p12 = _cov[1], p22 = _cov[2];
  float S = p11 + RK_MEAS;
  float innov = eyMeas - _x[0];
  if (innov * innov > GATE_SQ * S) return false;   // outlier: no actualizar

  float k1 = p11 / S;
  float k2 = p12 / S;
  _x[0] += k1 * innov;
  _x[1] += k2 * innov;
  _cov[0] = (1.0f - k1) * p11;
  _cov[1] = (1.0f - k1) * p12;
  _cov[2] = p22 - k2 * p12;
  return true;
}

// Medida directa del rumbo (Nicla Vision): H = [0, 1].
bool Kalman::updatePsi(float psiMeas) {
  float p12 = _cov[1], p22 = _cov[2];
  float S = p22 + RP_MEAS;
  float innov = psiMeas - _x[1];
  if (innov * innov > GATE_SQ * S) return false;   // outlier: no actualizar

  float k1 = p12 / S;
  float k2 = p22 / S;
  _x[0] += k1 * innov;
  _x[1] += k2 * innov;
  _cov[0] -= k1 * p12;
  _cov[1] -= k1 * p22;
  _cov[2] = (1.0f - k2) * p22;
  return true;
}