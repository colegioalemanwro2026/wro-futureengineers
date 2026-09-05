#pragma once

// ============================================================
// PARAMETROS DEL MODELO, CONTROLADOR Y MISION
// ============================================================

// ============================================================
// GEOMETRIA / MODELO BICICLETA
// ============================================================

constexpr float WHEELBASE_M   = 0.14f;   // m, medido
constexpr float ROBOT_WIDTH_M = 0.15f;   // m, ancho total

// Periodo nominal del controlador.

constexpr float DT = 0.1f;               // 10 Hz

// ============================================================
// VELOCIDADES
// ============================================================

// Medidas aproximadas:
// PWM 200 -> 1 m en 3.5 s

constexpr float V_CRUISE   = 0.286f;     // m/s
constexpr float V_CORNER   = 0.20f;      // m/s
constexpr float V_RECOVERY = 0.15f;      // m/s

// ============================================================
// CALIBRACION DE DIRECCION
// ============================================================

constexpr float DEG2RAD = 0.0174532925199433f;

constexpr float STEER_MAX_DEG = 27.0f;

constexpr float STEER_MAX_RAD =
STEER_MAX_DEG * DEG2RAD;

constexpr float SERVO_CENTER = 30.0f;

constexpr float SERVO_RANGE = 60.0f;

constexpr float SERVO_GAIN_DEG_PER_SERVODEG =
STEER_MAX_DEG / 30.0f;

// ============================================================
// MOTOR
// ============================================================

constexpr int PWM_CRUISE   = 200;

constexpr int PWM_CORNER   = 150;

constexpr int PWM_RECOVERY = 170;

// ============================================================
// FILTRO DE KALMAN
// ============================================================

// Validado inicialmente en simulador.
// Estado:
// [ e_y , e_psi ]

constexpr float QK_EY   = 1e-6f;

constexpr float QK_EPSI = 5e-6f;

// Ruido estimado HC-SR04.

constexpr float RK_MEAS = 4.9e-5f;

// Gating de innovacion.

constexpr float GATE_SQ = 64.0f;

// Ruido estimado del yaw.

constexpr float RP_MEAS = 1.2e-3f;

// ============================================================
// IMU NICLA VISION
// ============================================================

constexpr unsigned long IMU_TIMEOUT_MS =
300;

// 90 grados.

constexpr float TURN_YAW_TARGET_RAD =
1.5708f;

// ============================================================
// COLOR / OBSTACLE CHALLENGE
// ============================================================

constexpr char COLOR_LEFT_CHAR =
'G';

// Tiempo maximo que consideramos fresco el color.

constexpr unsigned long COLOR_FRESH_MS =
600;

// ============================================================
// GEOMETRIA DEL CORREDOR
// ============================================================

// IMPORTANTE:
//
// Este valor representa la distancia ideal desde
// el centro del robot hasta una pared cuando
// solamente existe una pared lateral disponible.
//
// AJUSTAR SEGUN LA PISTA REAL.

constexpr float CORRIDOR_HALF_M =
0.40f;

// ============================================================
// DETECCION DE ESQUINAS
// ============================================================

// Pared frontal considerada suficientemente cerca
// para comenzar deteccion de esquina.

constexpr float CORNER_FRONT_TRIG =
0.70f;

// Distancia considerada libre cuando usamos
// el sensor frontal como respaldo.

constexpr float CORNER_FRONT_CLEAR =
1.30f;

// Lectura lateral considerada abierta.

constexpr float OPEN_SIDE_M =
1.20f;

// Pared lateral demasiado cercana.

constexpr float WALL_NEAR_M =
0.15f;

// ============================================================
// MEMORIA DEL SENSOR FRONTAL
// ============================================================

// El HC-SR04 puede perder temporalmente el eco
// al mirar directamente hacia una esquina.
//
// Conservamos la ultima deteccion valida durante
// este tiempo.

constexpr unsigned long FRONT_STALE_MS =
400;

// ============================================================
// SEGURIDAD DE RUMBO
// ============================================================

// Si el robot se desvia demasiado del rumbo esperado
// y existe una pared cerca, activamos RECOVERY.

constexpr float HEADING_DANGER_RAD =
35.0f * DEG2RAD;

// ============================================================
// RECOVERY
// ============================================================

// Tiempo minimo retrocediendo.

constexpr unsigned long RECOVERY_TIME_MS =
1200;

// Tiempo maximo retrocediendo.

constexpr unsigned long RECOVERY_MAX_MS =
2600;

// ============================================================
// GIRO
// ============================================================

// Tiempo minimo antes de permitir terminar el giro.

constexpr unsigned long TURN_MIN_MS =
500;

// Timeout de seguridad.

constexpr unsigned long MAX_TURN_MS =
3000;

// Confirmacion de esquina.

constexpr int CLOSE_TICKS =
2;

// Con IMU normalmente solo necesitamos una confirmacion.

constexpr int CLEAR_TICKS =
1;

// ============================================================
// MISION
// ============================================================

// 4 esquinas por vuelta x 3 vueltas.

constexpr int TOTAL_CORNERS =
12;

// ============================================================
// CAMARA / COLOR
// ============================================================

// Tiempo maximo esperando informacion del color
// despues de detectar una posible esquina.

constexpr unsigned long CORNER_COLOR_OBSERVE_MS =
400;

// ============================================================
// SEGURIDAD FRONTAL
// ============================================================

// Si el robot ve una pared demasiado cerca
// mientras esta avanzando, entra en RECOVERY.

constexpr float COLLISION_DIST_M =
0.25f;

constexpr float STEER_SIGN = 1.0f;