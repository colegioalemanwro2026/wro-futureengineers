#pragma once
#include <Arduino.h>

// Filtro de Kalman lineal (2 estados) sobre [e_y, e_psi].
// Medicion: e_y = (d_der - d_izq)/2 cuando ambos laterales son validos.
// El rumbo e_psi no se mide: se estima por la dinamica e_y_dot = v*e_psi.
class Kalman {
public:
  void init(float ey0 = 0.0f, float epsi0 = 0.0f);
  void predict(float v, float deltaRad);   // propagacion con la entrada real
  bool update(float eyMeas);               // gating por innovacion
  bool updatePsi(float psiMeas);           // medida de rumbo del IMU (H=[0,1])
  float ey()   const { return _x[0]; }
  float epsi() const { return _x[1]; }
private:
  float _x[2];     // [e_y, e_psi]
  float _cov[3];   // covarianza simetrica 2x2: [P11, P12, P22]
};