#include "lqr.h"
#include "parameters.h"

// Ganancias de la DARE discreta, Q = diag(100,10), R = 1
// (generadas con python/solve_dare.py)
static const float SCHED_V[3]  = {0.20f, 0.25f, 0.286f};
static const float SCHED_K1[3] = {7.759f, 7.291f, 6.975f};
static const float SCHED_K2[3] = {2.941f, 2.805f, 2.713f};

static float interp1(float x, const float xs[3], const float ys[3]) {
  if (x <= xs[0]) return ys[0];
  if (x >= xs[2]) return ys[2];
  if (x <= xs[1]) {
    float t = (x - xs[0]) / (xs[1] - xs[0]);
    return ys[0] + t * (ys[1] - ys[0]);
  }
  float t = (x - xs[1]) / (xs[2] - xs[1]);
  return ys[1] + t * (ys[2] - ys[1]);
}

// u = -K x, con saturacion al maximo angulo de direccion.
float lqrComputeDelta(float ey, float epsi, float v) {
  float k1 = interp1(v, SCHED_V, SCHED_K1);
  float k2 = interp1(v, SCHED_V, SCHED_K2);
  float delta = -(k1 * ey + k2 * epsi);
  if (delta >  STEER_MAX_RAD) delta =  STEER_MAX_RAD;
  if (delta < -STEER_MAX_RAD) delta = -STEER_MAX_RAD;
  return delta;
}

// delta (rad) -> comando de servo (grados). Calibracion:
// delta_deg = (servo - 30) * 0.9  =>  servo = 30 + delta_deg / 0.9
// STEER_SIGN corrige aqui, en el UNICO punto de salida al hardware,
// si el servo fisico resulta invertido respecto al modelo.
float servoFromDelta(float deltaRad) {
  deltaRad *= STEER_SIGN;
  float deltaDeg = deltaRad / DEG2RAD;
  float s = SERVO_CENTER + deltaDeg / SERVO_GAIN_DEG_PER_SERVODEG;
  if (s > SERVO_RANGE) s = SERVO_RANGE;
  if (s < 0.0f) s = 0.0f;
  return s;
}