# ============================================================
# WRO Future Engineers - Nicla Vision (firmware OpenMV)
# Rumbo por giroscopio + deteccion de colores, un solo UART.
#
# Envia por Serial1 ("LP1", pines TX/RX) a 115200 baud:
#   "G,<centesimas de grado>\n"  a ~20 Hz   (rumbo continuo)
#   'Y' 'R' 'B' 'W' '.' + '\n'   por frame  (color mas grande visto)
#
# MONTAJE VALIDADO: placa VERTICAL, camara al frente,
# AXIS = 0 (X), girar a la IZQUIERDA = yaw POSITIVO.
# Al energizar: NO MOVER el auto hasta "lista" (~3 s de calibracion).
# Guardar con OpenMV IDE: Tools > Save open script to Nicla Vision
# (as main.py) para que arranque sola sin PC.
# ============================================================
import sensor, imu, time
from pyb import UART

AXIS     = 0        # X del chip (montaje vertical validado)
YAW_SIGN = 1.0      # izquierda = positivo (validado)
SEND_MS  = 50       # periodo de envio del rumbo (20 Hz)

uart = UART("LP1", 115200, timeout_char=100)

def calibrar(N=300):
    while True:
        print("Calibrando giroscopio... NO MOVER el auto")
        s  = 0.0
        s2 = 0.0
        for i in range(N):
            r = imu.angular_rate_mdps()[AXIS] / 1000.0
            s  += r
            s2 += r * r
            time.sleep_ms(10)
        bias = s / N
        var  = s2 / N - bias * bias       # quieta: desviacion < 0.1 deg/s
        if var < 0.01:
            return bias
        print("¡Movimiento detectado! Repitiendo calibracion...")

bias = calibrar()
print("bias =", round(bias, 4), "deg/s - lista")

sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QQVGA)          # 160x120
sensor.skip_frames(time=1000)
sensor.set_auto_gain(False)                 # obligatorio para color estable
sensor.set_auto_whitebal(False)

# Umbrales LAB (L_min, L_max, A_min, A_max, B_min, B_max)
# Calibrar con Tools > Machine Vision > Threshold Editor en la pista real
# COMPETENCIA (Obstacle Challenge): solo ROJO y VERDE deciden el giro.
COLORS = [
    ("R", (25, 75, 20, 60, 5, 50)),       # rojo
    ("G", (25, 80, -60, -15, -15, 40)),   # verde
    # -- extras para pruebas en banco (comentar para competir) --
    # ("Y", (60, 95, -25, 15, 35, 90)),   # amarillo
    # ("B", (20, 60, -30, 10, -70, -30)), # azul
    # ("W", (85, 100, -10, 10, -15, 15)), # blanco
]

yaw    = 0.0
lastUs = time.ticks_us()
lastTx = time.ticks_ms()

while True:
    # --- Rumbo: integrar siempre (el dt absorbe los tiempos de vision) ---
    rate = YAW_SIGN * (imu.angular_rate_mdps()[AXIS] / 1000.0 - bias)
    now  = time.ticks_us()
    yaw += rate * (time.ticks_diff(now, lastUs) * 1e-6)
    lastUs = now

    if time.ticks_diff(time.ticks_ms(), lastTx) >= SEND_MS:
        lastTx = time.ticks_ms()
        uart.write("G,%d\n" % int(yaw * 100))

    # --- Vision: color del blob mas grande delante ---
    img = sensor.snapshot()
    best_ch = "."
    best_px = 150                              # umbral minimo de blob
    for ch, th in COLORS:
        blobs = img.find_blobs([th], pixels_threshold=150,
                               area_threshold=150, merge=True)
        if blobs:
            b = max(blobs, key=lambda x: x.pixels())
            if b.pixels() > best_px:
                best_px = b.pixels()
                best_ch = ch
    uart.write(best_ch + "\n")