# Documentación de Ingeniería - Team Eule Tech
![](https://github.com/colegioalemanwro2026/wro-futureengineers/blob/main/Engineering%20(1).png)


## Introducción
En el presente repositorio podrán encontrar toda la construcción y ensamblaje del Robot Autónomo construido por el *Team Eule Tech* para la categoría Future Engineers en la temporada 2026 de la *World Robot Olympiad (WRO)*. Este proyecto se materializó tras meses de arduo trabajo y experiencias inolvidables, representando nuestra pasión por la robótica y por alcanzar nuestros más grandes sueños.
> _"Was immer du tun kannst oder träumst es zu können, fang damit an. Kühnheit hat Genie, Macht und Magie in sich." - Johann Wolfgang von Goethe_


## Contenido
- [Integrantes del Team](https://github.com/colegioalemanwro2026/wro-futureengineers/blob/main/README.md#integrantes-del-equipo)
- [Diseño de Hardware](https://github.com/colegioalemanwro2026/wro-futureengineers#diseño-de-hardware)
 - [Proceso de Diseño](https://github.com/colegioalemanwro2026/wro-futureengineers#proceso-de-diseño)
 - [Proceso de Ensamblaje](https://github.com/colegioalemanwro2026/wro-futureengineers/blob/main/README.md#proceso-de-ensamblaje)
 - [Elementos](https)
   - [Piezas Estructurales](https)
   - [Electrónica](https)
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
- [Diseño de Hardware](https)
  - [Proceso de Diseño](https)
  - [Proceso de Ensamblaje](https)
  - [Elementos](https)
    - [Kit SPIKE](https)
    - [Electrónica](https)
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
- [Nuestro Recorrido](https)
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

Nuestro robot está construido principalmente a partir de una combinación de componentes del **LEGO SPIKE Prime Set** y el **Nezha 48 in 1 Inventor's Kit**, incluyendo el motor de tracción, ruedas, servomotor de dirección y estructura del chasis. La alimentación proviene de una **batería VEX IQ Education Kit (2ª generación)**, con electrónica personalizada que habilita la funcionalidad autónoma completa.


Sin embargo, el robot pasó por múltiples revisiones estructurales y electrónicas antes de alcanzar su forma final y lista para competencia.


### Versión 1: 
El plan original era construir el robot completamente con el **Kit de Inventor Nezha**, es decir, chasis, ruedas, motor de tracción y servomotor de dirección de Nezha, utilizar un **Micro:bit** combinado con un **Expansion Board Nezha** como controlador principal, sensores Nezha para percepción y una cámara **Arduino Nicla Vision** para visión artificial (elegida sobre la cámara de Nezha).


### Versión 2:
Enfrentamos dificultades significativas de cableado al integrar la cadena **Micro:bit → Expansion Board → Nicla Vision**. Para resolverlo, reemplazamos la mayoría de la electrónica Nezha por: un **Microcontrolador ESP32**, un **Controlador TB6612FNG (HW-166)** (Puente H Dual) y un **Sensor ultrasónico HC-SR04**. Esto simplificó la interfaz con la Nicla Vision, pero introdujo inestabilidad en el Bluetooth entre el ESP32 y la Nicla.


### Versión 3:
Para lograr una conexión estable entre el sistema de visión y el cerebro del robot, migramos a una interfaz cableada directa, con el **Arduino Uno R4 WiFi** como controlador principal, el cual es compatible con la Nicla Vision,**Controlador L298N (HW-095)** (Puente H Dual Robusto) y demás electrónica de soporte estandarizada para Arduino. Esto eliminó la intermitencia inalámbrica y las caídas de conexión, asegurando captura de frames y tiempos de inferencia correctos. Cada modificación se realizó con un resultado único y compacto en mente, llegando así al diseño final que se presenta en la competencia.

## Proceso de Ensamblaje

El ensamblaje del robot se llevó a cabo de manera modular y progresiva, construyendo desde la base (chasis y tren de tracción) hacia la superficie (electrónica de control y visión), siguiendo una estrategia "bottom-up" que permitió validar cada etapa antes de integrar la siguiente.

El primer paso consistió en la construcción del módulo inferior. Partimos de referencias de vehículos autónomos de evasión de obstáculos, tomando como base principal el **Case 26 — The Obstacle Avoidance Car 2** del Kit Nezha, el cual adaptamos y modificamos para cumplir con los requisitos de la competencia. Este módulo integra el chasis principal construido con piezas de LEGO SPIKE Prime y Nezha, el motor de tracción trasera, el servomotor de dirección, las ruedas con su sistema de transmisión, y la batería VEX IQ Education Kit de segunda generación montada sobre un soporte de LEGO.

Una vez definida la arquitectura electrónica final (tras la migración desde Micro:bit/Nezha hacia Arduino Uno R4 WiFi y Controlador L298N) se diseñó un nivel superior dedicado para alojar toda la electrónica sobre el soporte de batería ya existente. En este módulo intermedio se aplicaron tres criterios fundamentales: una gestión de cableado ordenada, separación física entre fuentes de potencia (motores) y señal (sensores, comunicación) para minimizar interferencias electromagnéticas; accesibilidad total a conectores USB-C de Arduino y Nicla para la configuración de códigos en la práctica.

En tercer lugar, se fabricó un soporte dedicado para la Nicla Vision hecho de piezas LEGO del mismo Kit, que mantiene la cámara en el ángulo óptico preciso de 22° respecto a la horizontal (validado mediante pruebas de campo); garantiza estabilidad dinámica entre el soporte y el chasis; y protege el conector USB-C, evitando tensiones en el puerto durante la manipulación y el encendido del robot.

La unificación de los tres módulos se logró mediante ejes pasadores (Axle pins) LEGO Technic/Nezha junto con cinta 3M VHB 5952 (1,1 mm) para la fijación de PCBs, reguladores y módulos sin orificios de tornillo, resistente a vibración, ciclos térmicos y manipulación repetida. Este enfoque modular permitió iterar independientemente en cada nivel, lo que permitió realizar los cambios antes mencionados, y el cual puede representarse en el siguiente esquema:

![Esquema de conexiones](schemes/wiringdiagram.png)

---
# Elementos

## Piezas Estructurales (Kits)

> **Nota:** Todas las piezas estructurales provienen de los kits indicados; no se fabricaron piezas personalizadas mediante impresión 3D.

### LEGO SPIKE Prime Set

- **Vigas y ángulos (beams & angular beams)** — Estructura principal del chasis y soportes de montaje
- **Ejes y pasadores (axles & pins)** — Uniones rígidas entre submódulos (axle pins Technic)
- **Ruedas y neumáticos** — Par trasero motriz y par direccional delantero
- **Engranajes y bujes** — Transmisión del motor de tracción a ruedas traseras
- **Placas y frames** — Base de soporte para batería VEX IQ y nivel intermedio de electrónica

### Nezha 48 in 1 Inventor's Kit
- **Chasis modular y brackets** — Estructura base del Case 26 adaptada; soportes de motor y servomotor
- **Ruedas y sistema de dirección** — Componentes del mecanismo Ackermann/cremallera original
- **Motor DC Nezha** — *Versión inicial* (reemplazado en iteración final por motor compatible L298N)
- **Servomotor Nezha** — *Versión inicial* (reemplazado en iteración final por servomotor compatible L298N)
- **Expansion Board para Micro:bit** — *Versión inicial* (eliminada en migración a Arduino)

### VEX IQ Education Kit (2ª Generación)
- **Batería Li-Ion 7.4 V 2000 mAh** — Fuente de energía principal para motores y reguladores
- **Sistema de gestión de carga** — Conector y circuito de carga integrado

## Electrónica

### Control Principal
- **Arduino Uno R4 WiFi** — Microcontrolador principal (Renesas RA4M1 + ESP32-S3)
  - Lógica 5 V nativa, USB-C, WiFi/BLE integrado
  - Función: fusión de sensores, control de motores, telemetría, comunicación serie con Nicla Vision

### Visión Artificial
- **Arduino Nicla Vision** — Cámara inteligente (STM32H747 + sensor de imagen 2 MP)
  - Interfaz: USB-C / UART serie directa con Arduino Uno R4 WiFi
  - Función: detección de pista (conos rojos/verdes), clasificación en tiempo real, envío de datos de posición

### Control de Motores
- **Controlador L298N (HW-095)** — Puente H dual de alta corriente
  - Canales: 2 (motor DC tracción + servomotor dirección)
  - Voltaje de operación: 5–35 V | Corriente: 2 A continuos (pico 3 A)
  - Función: accionamiento de motor de tracción y servomotor de dirección desde señales PWM del Arduino

### Sensores
- **HC-SR04 Ultrasonic Sensor** — Medición de distancia a obstáculos/paredes
  - Rango: 2–400 cm | Resolución: 3 mm | Alimentación: 5 V
  - Montaje: frontal en parachoques, ángulo fijo para detección temprana

### Conversión y Distribución de Potencia
- **Regulador buck (step-down) 7.4 V → 5 V / 3 A** — Alimentación de Arduino, Nicla, sensores y lógica L298N
- **Regulador LDO 5 V → 3.3 V** — *Si aplica* para periféricos 3.3 V
- **Bornes de distribución / protoboard compacta** — Conexión ordenada de líneas de potencia y tierra

### Conectividad y Cableado
- **Cable USB-C (Arduino ↔ Nicla Vision)** — Enlace de datos y alimentación; longitud ajustada con *strain relief*
- **Cables jumper / silicona AWG22** — Señales PWM, I/O digital, comunicación serie
- **Abrazaderas y canaletas impresas 3D (opcional)** — Gestión de cableado en módulo intermedio

### Fijación Mecánica
- **Ejes pasadores LEGO Technic / Nezha (axle pins)** — Uniones estructurales desmontables entre módulos
- **Cinta 3M VHB 5952 (1.1 mm, acrílico)** — Fijación de PCBs, reguladores y módulos sin orificios roscados
- **Arandelas de goma EPDM (2 mm)** — Amortiguación pasiva en soporte de cámara

---

## Resumen de Especificaciones Clave

| Parámetro | Valor |
|-----------|-------|
| **Dimensiones (L×An×Al)** | ~250 × 180 × 160 mm (configuración competencia) |
| **Peso total** | ~1.1 kg (con batería) |
| **Voltaje nominal** | 7.4 V (batería) / 5 V (lógica) |
| **Consumo pico** | ~2.5 A (arranque motor + visión activa) |
| **Autonomía estimada** | 45–60 min (pruebas continuas) |
| **Comunicación visión–control** | Serie UART @ 115200 baudios (cableado) |
| **Frecuencia bucle control** | 50 Hz (PWM motores) / 30 Hz (inferencia visión) |
