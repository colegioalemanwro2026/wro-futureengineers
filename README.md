# Documentación de Ingeniería - Team Eule Tech
![](assets/engineeringdoc.png)


## Introducción
En el presente repositorio podrán encontrar toda la construcción y ensamblaje del Robot Autónomo construido por el *Team Eule Tech* para la categoría Future Engineers en la temporada 2026 de la *World Robot Olympiad (WRO)*. Este proyecto se materializó tras meses de arduo trabajo y experiencias inolvidables, representando nuestra pasión por la robótica y por alcanzar nuestros más grandes sueños.
> _"Was immer du tun kannst oder träumst es zu können, fang damit an. Kühnheit hat Genie, Macht und Magie in sich." - Johann Wolfgang von Goethe_


## Contenido
- [Integrantes del Team](https://github.com/colegioalemanwro2026/wro-futureengineers/blob/main/README.md#integrantes-del-equipo)
- [Diseño de Hardware](https://github.com/colegioalemanwro2026/wro-futureengineers#diseño-de-hardware)
 - [Proceso de Diseño](https://github.com/colegioalemanwro2026/wro-futureengineers#proceso-de-diseño)
 - [Proceso de Ensamblaje](https://github.com/colegioalemanwro2026/wro-futureengineers/blob/main/README.md#proceso-de-ensamblaje)
 - [Elementos](https://github.com/colegioalemanwro2026/wro-futureengineers/blob/main/README.md#elementos)
   - [Piezas Estructurales (Kits)](https://github.com/colegioalemanwro2026/wro-futureengineers/blob/main/README.md#piezas-estructurales-kits)
   - [Electrónica](https://github.com/colegioalemanwro2026/wro-futureengineers/blob/main/README.md#electr%C3%B3nica)
- [Diseño de Software](https)
 - [Procesamiento de Imagen y Color](https)
    - [Captura de Imagen](https)
	- [Creación de Máscaras Roja y Verde](https)
	- [Imagen Final](https)
	- [Distancia a los Conos](https)
 - [Movimiento del Robot](https)
   - [Configuración Smart Robot Servo](https)
   - [Orientación del Robot](https)
   - [Determinación de Ruta](https)
  - [Envío de Datos](https)
- [Impacto](https)
- [Nuestro Recorrido](https))

---
# *Integrantes del Equipo*
- Isaac Camargo
![](https://github.com/colegioalemanwro2026/wro-futureengineers/blob/main/775a4106-e3e2-4c4f-919d-1946a50a8b13.jpg)
> Mi chiquito pechocho


- Fernanda León
![](https://github.com/colegioalemanwro2026/wro-futureengineers/blob/main/e168a51f-258d-4fb5-9f0c-e48285d9942f.jpg)
> Bebetita de su bebetito y solo de bebetito
---
# *Diseño de Hardware*
## *Proceso de Diseño*

Nuestro robot está construido en el chasis principalmente a partir de una combinación de piezas del **LEGO SPIKE Prime Set** y el **Nezha 48 in 1 Inventor's Kit**, incluyendo el motor de tracción, ruedas, servomotor de dirección y estructura. La alimentación proviene de una **batería VEX IQ Education Kit (2ª generación)** y unas **baterías de Iones de Litio (Li-Ion) 18650** con electrónica personalizada que habilita la funcionalidad autónoma completa.

Nuestro robot pasó por múltiples revisiones estructurales y electrónicas antes de alcanzar su forma final y lista para competencia, las cuales están divididas en 4 versiones:

### Versión 1:
El plan original se basó en construir el robot completamente con el Kit de Inventor Nezha (chasis, ruedas, motor de tracción y servomotor de dirección) gracias a la facilidad de construcción de sus piezas. Usamos una Micro:bit junto con una Placa de Expansión Nezha como controlador principal, sensores Nezha para detectar el entorno y una cámara Arduino Nicla Vision para visión artificial. Elegimos esta cámara sobre la de Nezha debido a su reconocimiento de objetos preciso y eficiente.

![](v-photos/v-designs/moti-v1.jpg)

### Versión 2:
Enfrentamos dificultades significativas de cableado al intentar conectar la Micro:bit → Placa de Expansión Nezha → Nicla Vision debido a la diferencia de puertos RJ45 y Micro USB respectivamente. Para resolverlo, reemplazamos la mayoría de la electrónica Nezha por un Microcontrolador ESP32, un Controlador TB6612FNG (HW-166) (Puente H Dual) y Sensores ultrasónicos HC-SR04. Esto simplificó la conexión con la Nicla Vision, pero nos dimos cuenta de que el controlador principal necesitaba una entrada de 5V constantes y mayor rango de voltaje, con los cuales el ESP32 y el Puente H Dual no contaban.

![](v-photos/v-designs/moti-v2.jpg)

### Versión 3:
Para lograr una conexión cableada estable entre el sistema de visión y el cerebro del robot, migramos en un principio al Arduino Uno. Aunque cumplía con los 5V necesarios, elegimos finalmente el Arduino Uno R4 WiFi como el controlador principal fijo, el cual tiene mayor rango de voltaje, es totalmente compatible con la Nicla Vision y va de la mano en potencia con un Controlador L298N (HW-095) (Puente H Dual Robusto) y demás electrónica de soporte estandarizada para Arduino. Esto eliminó cualquier complicación por falta de voltaje, asegurando la captura correcta de imágenes en la cámara y mayor seguridad en el circuito.

![](v-photos/v-designs/moti-v3.jpg)

### Versión 4:
En último lugar, con la finalidad de perfeccionar la comunicación y evitar problemas como el reinicio de los componentes al no distribuirse correctamente la energía cuando los motores exigían mucha fuerza, se incluyeron en el circuito unas Baterías de Litio 18650 recargables con su respectivo Módulo de Carga de Baterías de Litio (TP4056 / HW-373) y un Módulo Elevador de Voltaje StepUp HW-045 (MT3608). Esto estabilizó la comunicación entre componentes y eliminó cualquier problema de bajas de voltaje a futuro. Cada modificación se realizó con un resultado único y compacto en mente, llegando así al diseño final que se presenta en la competencia.

![](v-photos/v-designs/moti-v3.jpg)

## Proceso de Ensamblaje

El ensamblaje del robot se llevó a cabo de manera modular y progresiva, construyendo desde la base (chasis y tren de tracción) hacia la superficie (electrónica de control y visión) siguiendo una metodología de análisis y gestión "bottom-up", la cual al consistir en empezar partiendo del proceso o sistema más pequeño hasta el más trabajado, permitió validar cada etapa antes de integrar la siguiente.

El primer paso consistió en la construcción del módulo inferior. Partimos de referencias de vehículos autónomos de evasión de obstáculos, tomando como base principal el [**Case 26 — The Obstacle Avoidance Car 2**](https://wiki.elecfreaks.com/en/microbit/building-blocks/nezha-inventors-kit-v2/the-smart-obstacle-avoidance-car-2/) del Kit Nezha, el cual adaptamos y modificamos para cumplir con los requisitos de la competencia. Este módulo integra el chasis principal construido con piezas de LEGO SPIKE Prime y Nezha, el motor de tracción trasera, el servomotor de dirección, las ruedas con su sistema de transmisión, los sensores y la batería VEX IQ Education Kit de segunda generación montada sobre un soporte de LEGO, elegida debido a la capacidad de Voltaje tan fuerte y beneficiaria que posee, que va de 7.4 V a 2000 mA.

Una vez definida la arquitectura electrónica final (tras la migración desde Micro:bit/Nezha hacia Arduino Uno R4 WiFi y Controlador L298N) se diseñó un nivel superior dedicado para alojar toda la electrónica sobre el soporte de batería ya existente. En este módulo intermedio se aplicaron tres criterios fundamentales: una gestión de cableado ordenada, separación física entre fuentes de potencia (motores) y señal (sensores, comunicación) para minimizar interferencias electromagnéticas; accesibilidad total a conectores USB-C de Arduino y MicroUSB Nicla para la configuración de códigos en la práctica.

En tercer lugar, se fabricó un soporte dedicado para la Nicla Vision hecho de piezas LEGO del mismo Kit, que mantiene la cámara en el ángulo óptico preciso de 10° respecto a la horizontal (validado mediante pruebas de campo); garantiza estabilidad dinámica entre el soporte y el chasis; y protege las conexiones hacia el Arduino, evitando tensiones en el puerto durante la manipulación y el encendido del robot.

Y luego, al añadir las baterías de Litio para mayor estabilidad de comunicación, se pegaron a una estructura hecha de LEGO en la cara trasera del robot, en paralelo, con el fin de generar mayor potencia a la Cámara Nicla y al Arduino, y no ocupar espacio que es necesario para las conexiones. Así como el módulo elevador de voltaje,

La unificación de los módulos se logró mediante ejes pasadores (Axle pins) LEGO Technic/Nezha junto con cinta 3M VHB 5952 (1,1 mm) para la fijación de PCBs, reguladores y módulos sin orificios de tornillo, resistente a vibración, ciclos térmicos y manipulación repetida. Este enfoque modular permitió iterar independientemente en cada nivel, lo que permitió realizar los cambios antes mencionados, y el cual puede representarse en el siguiente esquema:

![Esquema de conexiones](schemes/wiringdiagram.png)

# Elementos

## Piezas Estructurales (Kits)

> **Nota:** Todas las piezas estructurales provienen de los kits indicados; no se fabricaron piezas personalizadas mediante impresión 3D.

![](other/lego-spike-kit.png)
### LEGO SPIKE Prime Set (45678)
- **Referencia:** LEGO Education SPIKE™ Prime Set — Set 45678
- **Año de lanzamiento:** 2020 | **Piezas:** 528 (oficial) / 532 (inventario real)
- **Componentes electrónicos incluidos en el kit:**
  -- **Hub programable (Large Hub)** — 6 puertos I/O, matriz LED 5×5, giroscopio de 6 ejes, altavoz, Bluetooth, batería recargable integrada
  - **Motores:** 1 × Large Angular Motor + 2 × Medium Angular Motors (con encoder absoluto, control de posición/velocidad)
  - **Sensores:** Distance Sensor (ultrasónico), Force Sensor, Color Sensor
  - **Conectividad:** Bluetooth LE, USB-C (en Hub), cables inteligentes
- **Elementos estructurales:** +500 piezas LEGO Technic™ (vigas, ángulos, ejes, pasadores, engranajes, ruedas, neumáticos, plates, frames) en paleta de colores fresca
- **Almacenamiento:** Caja resistente con bandejas de clasificación
- **Uso en el robot:** Chasis principal, estructura de soporte de batería, ejes pasadores para unión de módulos

![](other/nezha-kit.webp)
### Nezha 48 in 1 Inventor's Kit (ELECFREAKS micro:bit)
- **Referencia:** ELECFREAKS micro:bit Nezha 48 IN 1 Inventor's Kit (sin micro:bit)
- **Componentes electrónicos incluidos:**
  - **Nezha Expansion Board** — Placa base FR4 epoxy 94VO, batería Li-Ion 900 mAh integrada, puertos RJ11 con código de color (IIC, UART, SPI), entrada 5 V, carga 1 A
  - **Sensores/módulos (Planet X):** LED rojo/verde/amarillo, sensor de impacto, sensor de seguimiento de línea, sensor ultrasónico, potenciómetro, sensor de humedad de suelo, bocina, etc. (hasta 40+ sensores soportados)
  - **Actuadores:** Motor DC Nezha, Servomotor Nezha
  - **Construcción:** +400 piezas de bloques compatibles LEGO/Fischer, ruedas, engranajes, ejes
  - **Programación:** MakeCode, JavaScript, Python, C++
- **Especificaciones de la Expansion Board:** 60×82×28 mm, carcasa ABS ignífuga, protocolos IIC/UART/SPI
- **Uso en el robot (versión inicial):** Chasis base (Case 26 Obstacle Avoidance Car),  Expansion Board para micro:bit, sensores Nezha. **En versión final:** Solo se conservan piezas estructurales (vigas, brackets, ruedas, engranajes) y electrónicas del kit (motor DC y servomotor); toda la electrónica Nezha fue reemplazada.

![](other/battery-vex.webp)
### VEX IQ Education Kit (2ª Generación) — Solo Batería
- **Referencia:** VEX IQ Robot Battery (Li-Ion, 2000 mAh) — Part 228-7045
- **Especificaciones:**
  - **Química:** Li-Ion (iones de litio) — 5× mayor retención de voltaje vs NiMH
  - **Voltaje nominal:** 7.2 V (7.4 V pico)
  - **Capacidad:** 2000 mAh
  - **Corriente máxima continua:** 8 A (limitada por temperatura)
  - **Carga:** Puerto USB-C integrado, tiempo ~2 horas
  - **Indicador:** 4 LEDs verdes (barra de carga) + botón de estado
  - **Dimensiones/peso:** ~0.23 kg
  - **Compatibilidad:** Funciona con IQ Robot Brain 1ª y 2ª gen
- **Uso en el robot:** Fuente de energía principal para motores (vía L298N) e interruptor (5 V para lógica)

![](other/baterias-lit.jpg)
### Baterías de Iones de Litio (Li-Ion) 18650 — Flycat 3.7 V (2 Unidades en el Sistema)
- **Formato / Tamaño**: 18650 (Cilíndrica, $18\text{ mm}$ de diámetro $\times 65\text{ mm}$ de longitud)
- **Química**: Iones de Litio (Li-Ion)
- **Voltaje nominal**: $3.7\text{ V}$ por celda ($7.4\text{ V}$ nominal total en configuración en serie / $3.7\text{ V}$ en paralelo)
- **Voltaje de carga máxima**: $4.2\text{ V}$ por celda
- **Voltaje de corte por descarga**: $2.75\text{ V}$ - $3.0\text{ V}$ por celda (mínimo seguro)
- **Capacidad nominal declarada**: Marca Flycat $7800\text{ mAh}$ (Capacidad comercial/etiqueta)
- **Corriente máxima de descarga**: $1\text{C}$ – $2\text{C}$ en descarga continua habitual para celdas estándar de robótica
- **Vida útil**: ~500 ciclos de carga/descarga completa
- **Polaridad**: Terminal positivo plano/convexo (+) y terminal negativo plano (-)
- **Peso aprox.**: ~$45\text{ g}$ por celda
- **Función en el robot**: Fuente principal de almacenamiento de energía recargable del robot. Proveen la corriente requerida por el driver de motores L298N (potencia) y el módulo elevador MT3608 (lógica) para garantizar total autonomía.

## Electrónica

### Control Principal

![](other/arduino-uno-r4.jpg)
**Arduino Uno R4 WiFi (ABX00087)**
- **MCU principal:** Renesas RA4M1 (R7FA4M1AB3CFM) — Arm Cortex-M4 @ 48 MHz con FPU
- **Coprocesador inalámbrico:** ESP32-S3-MINI-1-N8 — Xtensa dual-core LX7, Wi-Fi 4 (2.4 GHz), Bluetooth 5 LE
- **Memoria (RA4M1):** 256 KB Flash / 32 KB SRAM / 8 KB EEPROM
- **Memoria (ESP32-S3):** 384 KB ROM / 512 KB SRAM
- **Voltaje de operación:** 5 V (RA4M1) / 3.3 V (ESP32-S3) — traductor de nivel TXB0108 interno
- **USB:** USB-C (hasta 21 V PD input, HID support)
- **I/O:** 14 pines digitales, 6 entradas analógicas (14-bit ADC), 6 PWM, 1 DAC (12-bit), CAN Bus, I2C (Qwiic), SPI, UART
- **Extras:** Matriz LED 12×8, RTC, VRTC pin (batería backup), pin OFF
- **Función en el robot:** Controlador principal — fusión de sensores, control PWM de motores (L298N), comunicación serie UART con Nicla Vision @ 115200 baudios, telemetría WiFi/BLE, bucle de control 50 Hz

### Visión Artificial

![](other/nicla-vision.webp)
**Arduino Nicla Vision (ABX00051)**
- **MCU:** STM32H747AII6 — Dual core: Cortex-M7 @ 480 MHz + Cortex-M4 @ 240 MHz
- **Cámara:** GC2145 / OV5640 — 2 MP color, 30 FPS @ resolución completa, soporte TinyML
- **Sensores integrados:** LSM6DSOX (IMU 6-ejes), MP34DT05 (micrófono MEMS), VL53L1CBV0FY (ToF distancia)
- **Conectividad:** Murata 1DX (CYW4343W) — Wi-Fi / BLE 4.2, USB-C (high-speed 500 Mbps)
- **Memoria:** 2 MB Flash / 1 MB RAM + 16 MB QSPI Flash
- **Seguridad:** NXP SE050C2 Crypto chip
- **Alimentación:** 3.7 V Li-Po (cargador MAX17262 integrado) o USB-C 5 V
- **Dimensiones:** 22.86 × 22.86 mm | **Temp. operación:** -20 °C a +70 °C
- **Interfaces:** I2C (conector ESLOV), SPI, UART, GPIO, ADC, JTAG, castellated pins
- **Función en el robot:** Detección de pista en tiempo real (conos rojos/verdes), clasificación, envío de datos de posición/orientación vía UART serie directo a Arduino Uno R4 WiFi. Cableado USB-C protegido, ángulo fijo 22°.

### Control de Motores

![](other/puente-h.webp)

**L298N Dual H-Bridge Motor Driver (HW-095 / MDU-1049)**
- **Chip:** STMicroelectronics L298N (Monolithic IC, Multiwatt15 / PowerSO-20)
- **Topología:** Puente H dual (2 canales independientes)
- **Voltaje motor (VCC):** 5–35 V (máx. 46 V chip)
- **Voltaje lógica:** 5 V (4.5–7 V)
- **Corriente continua:** 2 A por canal
- **Corriente pico:** 3–4 A (no repetitivo, con disipador adecuado)
- **Potencia máxima:** 25 W
- **Protecciones:** Térmica (apagado ~130 °C), sobrecorriente, diodos de flyback internos
- **Regulador 5 V integrado:** 78M05 (activo con jumper si VCC ≤ 12 V; provee 5 V @ 1 A para lógica/MCU)
- **Pines de control:** IN1–IN4 (dirección), ENA/ENB (PWM velocidad)
- **Dimensiones módulo:** 43×43×27 mm | **Peso:** ~25–33 g
- **Función en el robot:** Acciona motor DC de tracción (canal A) y servomotor de dirección (canal B) desde PWM del Arduino. Alimentado desde batería VEX 7.4 V.

### Sensores

![](other/sensor-hc-sr04.webp)

**HC-SR04 Ultrasonic Distance Sensor**
- **Principio:** Sonar ultrasónico 40 kHz (time-of-flight)
- **Rango teórico:** 2 cm – 400 cm (práctico: 2–80 cm óptimo)
- **Precisión:** ±3 mm
- **Ángulo de haz:** <15° (cono efectivo ~30°)
- **Voltaje:** 5 V DC (4.5–5.5 V)
- **Corriente:** <15 mA activa, <2 mA reposo
- **Pines:** VCC, Trig (input, pulso 10 µs), Echo (output, pulso ancho = tiempo vuelo), GND
- **Dimensiones:** 45×20×15 mm | **Peso:** 9 g
- **Función en el robot:** Detección frontal de paredes/obstáculos, montado en parachoques con ángulo fijo.

### Conversión y Distribución de Potencia

![](other/protoboard.jpg)

**Protoboard / Protoboard compacta** (placa de pruebas de 400/830 puntos o PCB perforada)
- **Uso:** Distribución de líneas de potencia (5 V, 7.4 V, GND), conexiones de señales PWM, I2C, UART, capacitores de desacoplo (100 µF electrolítico + 0.1 µF cerámico por rail)

![](other/cap-electrolit.jpg)

**Capacitor Electrolítico de Aluminio | 100 µF / 25 V (105 °C, Low ESR)**
- **Capacitancia nominal**: 100 µF (±20 % estándar)
- **Voltaje nominal**: 25 V (mínimo 16 V; 25 V recomendado para rails de 5 V y 7.4 V con margen 2×)
- **Tipo**: Radial through-hole, diámetro 6.3–8 mm × altura 11–12 mm, paso 2.5–3.5 mm
- **ESR**: 0.3–0.8 Ω a 100 kHz, 25 °C (series Low ESR: FC, FM, YXF, UPW)
- **Corriente de rizado**: 200–400 mA rms a 100 kHz, 105 °C
- **Temperatura de operación**: -40 °C a +105 °C
- **Vida útil**: 1000–2000 horas a 105 °C con voltaje nominal
- **Polaridad**: Polarizado — terminal largo = positivo (+), banda blanca = negativo (-)
- **Montaje**: Through-hole (PTH)
- **Función en el robot**: Reservorio de carga en cada rail de potencia (7.4 V, 5 V, 3.3 V). Se encuentra en la entrada de potencia de cada módulo (bornes VCC del L298N). Provee reserva durante picos de arranque de motor.

![](other/cap-ceramico.jpg)

**Capacitor Cerámico Multicapa (MLCC) — 0.1 µF (100 nF) / 25 V / X7R / 0805**
- **Capacitancia nominal**: 0.1 µF = 100 nF (código 104)
- **Tolerancia**: ±10 % (K) o ±20 % (M)
- **Voltaje nominal**: 25 V (mínimo 16 V; 25 V da margen para rails de 5 V y 7.4 V)
- **Dieléctrico**: X7R (variación ±15 % de -55 °C a +125 °C)
- **Caja / Footprint**: 0805 (2.0 × 1.25 mm) preferido para soldadura manual; 0603 (1.6 × 0.8 mm) si hay restricción de espacio
- **ESR**: < 0.05 Ω a 1 MHz
- **ESL**: ~0.5–1 nH (muy bajo)
- **Frecuencia efectiva**: > 1 MHz hasta 100+ MHz — filtra ruido de conmutación (buck, PWM, MCU)
- **Corriente de rizado**: > 500 mA (limitada por calentamiento dieléctrico)
- **Temperatura de operación**: -55 °C a +125 °C
- **Polaridad**: No polarizado
- **Montaje**: SMD (0805/0603)
- **Función en el robot**: High-frequency decoupling en cada rail (5 V, 3.3 V) junto a cada circuito integrado. Se coloca **uno por pin de alimentación** (VCC-GND) del IC: Arduino Uno R4 WiFi, Nicla Vision, lógica del L298N, HC-SR04.

![](other/elevador.jpg)
**Módulo Elevador de Voltaje Step-Up — MT3608 (HW-045)**
- **Módulo / IC**: MT3608 (HW-045)
- **Voltaje de entrada**: $2.0\text{ V}$ a $24\text{ V}$ (para 2 celdas Li-Ion en serie/paralelo o individuales)
- **Voltaje de salida**: $2.0\text{ V}$ a $28\text{ V}$ (regulable mediante potenciómetro de precisión 3296)
- **Corriente máxima de salida**: $2\text{ A}$ (máxima pico; corriente continua recomendada $\le 1.2\text{ A}$ - $1.5\text{ A}$)
- **Frecuencia de conmutación**: $1.2\text{ MHz}$ (permite alta eficiencia y filtrado compacto)
- **Eficiencia máxima**: Hasta $93\text{ \%}$
- **Protección integrada**: Protección contra sobrecalentamiento térmico y límite de corriente ciclo a ciclo
- **Ajuste**: Potenciómetro de multivueltas (girar en sentido antihorario para elevar voltaje)
- **Dimensiones / Tamaño**: $36\text{ mm} \times 17\text{ mm} \times 14\text{ mm}$
- **Montaje / Conexión**: Pines de soldadura mediante terminales VIN+ / VIN- (Entrada) y VOUT+ / VOUT- (Salida)
- **Función en el robot**: Eleva y regula el voltaje entregado por las baterías de litio a un nivel estable ($5\text{ V}$ - $9\text{ V}$) para alimentar la línea de lógica y evitar reinicios del Arduino Uno R4 WiFi y la Nicla Vision cuando los motores consumen picos de corriente.

### Encendido/Apagado

![](other/pulsador.jpg)

**Pulsador táctil negro (Tactile Pushbutton, 6×6 mm o 12×12 mm, through-hole / SMD)**
- **Tipo:** Momentáneo (SPST-NO), 50 mA @ 12 V DC
- **Fuerza de accionamiento:** ~160–250 gf
- **Vida útil:** 100,000–1,000,000 ciclos
- **Función:** Reset de software / inicio de rutina autónoma

![](other/switch.webp)

**Interruptor deslizante / toggle negro (Slide Switch / Toggle Switch, SPDT o DPDT, panel mount o PCB)**
- **Rating típico:** 3–6 A @ 120 V AC / 28 V DC
- **Función:** Encendido/apagado principal del robot. Corta línea o realiza conexión entre batería VEX y Puente H


### Fijación Mecánica

![](other/piezas-axl.jpg)

- **Ejes pasadores LEGO Technic / Nezha (Axle pins, 3L/5L/7L, gris/negro):** Uniones estructurales rígidas, desmontables, alineadas por diseño entre los 3 módulos

![](other/cinta.jpg)

- **Cinta 3M VHB 5952 (1.1 mm, acrílico de alta cohesión):** Fijación de PCBs (Arduino, L298N, sensores, protoboard), módulos sin orificios roscados. Resistente a vibración, ciclos térmicos (-40 a +90 °C), manipulación repetida. Área de contacto dimensionada >4× peso del módulo.
---
# Diseño de Software
## Procesamiento de Imagen y Color

---
# Impacto

---
# Nuestro Recorrido

