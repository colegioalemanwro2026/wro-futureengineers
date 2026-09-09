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
- [Mecánica y Sistema de Transmisión](https://github.com/colegioalemanwro2026/wro-futureengineers/blob/main/README.md#mec%C3%A1nica-y-sistema-de-transmisi%C3%B3n)
- [Diseño del Software](https://github.com/colegioalemanwro2026/wro-futureengineers#dise%C3%B1o-del-software)
 - [Arquitectura del Sistema](https://github.com/colegioalemanwro2026/wro-futureengineers#arquitectura-del-sistema)
 - [Adquisición de Datos de los Sensores](https://github.com/colegioalemanwro2026/wro-futureengineers#adquisici%C3%B3n-de-datos-de-los-sensores)
   - [Medición de Distancia con Sensores Ultrasónicos](https://github.com/colegioalemanwro2026/wro-futureengineers#medici%C3%B3n-de-distancia-con-sensores-ultras%C3%B3nicos)
 - [Comunicación con la IMU y Módulos Externos](https://github.com/colegioalemanwro2026/wro-futureengineers#comunicaci%C3%B3n-con-la-imu-y-m%C3%B3dulos-externos)
 - [Estimación de Estado mediante un Filtro de Kalman](https://github.com/colegioalemanwro2026/wro-futureengineers#estimaci%C3%B3n-de-estado-mediante-un-filtro-de-kalman)
 - [Control del Robot](https://github.com/colegioalemanwro2026/wro-futureengineers#control-del-robot)
   - [Controlador LQR para la Dirección](https://github.com/colegioalemanwro2026/wro-futureengineers#controlador-lqr-para-la-direcci%C3%B3n)
 - [Control de la Misión](https://github.com/colegioalemanwro2026/wro-futureengineers#control-de-la-misi%C3%B3n)
   - [Máquina de Estados Finitos](https://github.com/colegioalemanwro2026/wro-futureengineers#m%C3%A1quina-de-estados-finitos)
 - [Control del Motor y la Dirección](https://github.com/colegioalemanwro2026/wro-futureengineers#control-del-motor-y-la-direcci%C3%B3n)
   - [Control del Motor](https://github.com/colegioalemanwro2026/wro-futureengineers#control-del-motor)
   - [Control del Servo de Dirección](https://github.com/colegioalemanwro2026/wro-futureengineers#control-del-servo-de-direcci%C3%B3n)
 - [Telemetría y Depuración](https://github.com/colegioalemanwro2026/wro-futureengineers#telemetr%C3%ADa-y-depuraci%C3%B3n)
 - [Impacto](https://github.com/colegioalemanwro2026/wro-futureengineers#impacto)
 - [Nuestro Recorrido](https://github.com/colegioalemanwro2026/wro-futureengineers#nuestro-recorrido)

---
# *Integrantes del Equipo*

- Isaac Camargo (Programador)
![](t-photos/isaac-pic.jpg)
> Guten Tag! Soy Isaac Camargo, tengo 16 años y junto a mi compañera Fer estoy muy feliz de poder participar en esta competencia. Todo nuestro trayevto ha sido pura diversión y aprendizaje y estoy seguro de que gracias a esto, daremos lo mejor de nosotros en cada encuentro de la WRO. Bis bald!


- Fernanda León (Mecánica)
![](t-photos/fer-pic.jpg)
> Hallo! Soy Fernanda León, tengo 17 años y me emociona tener la oportunidad de participar junto a Isaac en esta competencia. Nuestro esfuerzo durante tanto tiempo finalmente valdrá la pena y daremos lo mejor de nosotros en todo momento. Tschüssi!

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

![](v-photos/v-designs/moti-v4.jpg)

## Proceso de Ensamblaje

El ensamblaje del robot se llevó a cabo de manera modular y progresiva, construyendo desde la base (chasis y tren de tracción) hacia la superficie (electrónica de control y visión) siguiendo una metodología de análisis y gestión "bottom-up", la cual al consistir en empezar partiendo del proceso o sistema más pequeño hasta el más trabajado, permitió validar cada etapa antes de integrar la siguiente.

El primer paso consistió en la construcción del módulo inferior. Partimos de referencias de vehículos autónomos de evasión de obstáculos, tomando como base principal el [**Case 26 — The Obstacle Avoidance Car 2**](https://wiki.elecfreaks.com/en/microbit/building-blocks/nezha-inventors-kit-v2/the-smart-obstacle-avoidance-car-2/) del Kit Nezha, el cual adaptamos y modificamos para cumplir con los requisitos de la competencia. Este módulo integra el chasis principal construido con piezas de LEGO SPIKE Prime y Nezha, el motor de tracción trasera, el servomotor de dirección, las ruedas con su sistema de transmisión, los sensores y la batería VEX IQ Education Kit de segunda generación montada sobre un soporte de LEGO, elegida debido a la capacidad de Voltaje tan fuerte y beneficiaria que posee, que va de 7.4 V a 2000 mA.

Una vez definida la arquitectura electrónica final (tras la migración desde Micro:bit/Nezha hacia Arduino Uno R4 WiFi y Controlador L298N) se diseñó un nivel superior dedicado para alojar toda la electrónica sobre el soporte de batería ya existente. En este módulo intermedio se aplicaron tres criterios fundamentales: una gestión de cableado ordenada, separación física entre fuentes de potencia (motores) y señal (sensores, comunicación) para minimizar interferencias electromagnéticas; accesibilidad total a conectores USB-C de Arduino y MicroUSB Nicla para la configuración de códigos en la práctica.

En tercer lugar, se fabricó un soporte dedicado para la Nicla Vision hecho de piezas LEGO del mismo Kit, que mantiene la cámara en el ángulo óptico preciso de 10° respecto a la horizontal (validado mediante pruebas de campo); garantiza estabilidad dinámica entre el soporte y el chasis; y protege las conexiones hacia el Arduino, evitando tensiones en el puerto durante la manipulación y el encendido del robot.

Y luego, al añadir las baterías de Litio para mayor estabilidad de comunicación, se pegaron a una estructura hecha de LEGO en la cara trasera del robot, en paralelo, con el fin de generar mayor potencia a la Cámara Nicla y al Arduino, y no ocupar espacio que es necesario para las conexiones. Así como el módulo elevador de voltaje,

La unificación de los módulos se logró mediante ejes pasadores (Axle pins) LEGO Technic/Nezha junto con cinta 3M VHB 5952 (1,1 mm) para la fijación de PCBs, reguladores y módulos sin orificios de tornillo, resistente a vibración, ciclos térmicos y manipulación repetida. Este enfoque modular permitió modificar independientemente en cada nivel, lo que permitió realizar los cambios antes mencionados, y el cual puede representarse en el siguiente esquema:

![Esquema de conexiones](schemes/wiring-diagramm.jpg)
---
# Elementos del robot

## 1. Piezas estructurales y mecánicas

> **Nota:** Las piezas estructurales utilizadas en el robot provienen de kits comerciales. No fabricamos piezas estructurales personalizadas mediante impresión 3D.

---

### LEGO SPIKE Prime Set — 45678

![](other/lego-spike-kit.png)

El **LEGO SPIKE Prime Set 45678** proporciona la mayor parte de los elementos estructurales utilizados para construir el chasis y los diferentes soportes mecánicos del robot.

#### Elementos utilizados

- Vigas LEGO Technic.
- Frames y elementos estructurales.
- Ejes y pasadores.
- Engranajes.
- Ruedas y neumáticos.
- Elementos de unión.

#### Uso en nuestro robot

Utilizamos estas piezas principalmente para:

- Construcción del **chasis principal**.
- Soporte de los componentes electrónicos.
- Soporte de la batería.
- Construcción de los ejes.
- Unión entre módulos.
- Construcción del sistema de dirección.
- Construcción de la transmisión mediante engranajes.

#### ¿Por qué lo usamos?

Elegimos utilizar la estructura LEGO Technic porque durante el desarrollo necesitábamos modificar constantemente la posición de diferentes componentes.

Su sistema modular nos permitió cambiar rápidamente:

- La posición del motor.
- La ubicación de los sensores.
- La posición de la batería.
- El sistema de dirección.
- La distribución de la electrónica.

Esto redujo el tiempo necesario para construir y probar diferentes versiones del robot.

---

### ELECFREAKS Nezha 48 in 1 Inventor's Kit

![](other/nezha-kit.webp)

El **Nezha 48 in 1 Inventor's Kit** fue utilizado principalmente durante las primeras etapas del desarrollo.

#### Elementos utilizados en la versión final

Del kit Nezha conservamos principalmente elementos mecánicos:

- Vigas.
- Brackets.
- Ejes.
- Pasadores.
- Engranajes.
- Ruedas.
- Elementos de unión.
- Motor DC.
- Servomotor.

#### Uso en nuestro robot

Las piezas estructurales de Nezha se integraron con las piezas LEGO SPIKE Prime/Technic para construir el chasis y los mecanismos de movilidad.

El **motor DC** y el **servomotor** también forman parte del sistema de movilidad y dirección.

> **Importante:** La electrónica Nezha no forma parte de la arquitectura electrónica final del robot. La Expansion Board y los sensores Nezha fueron utilizados durante versiones anteriores y posteriormente fueron reemplazados.

#### ¿Por qué lo usamos?

El principal beneficio fue poder reutilizar piezas mecánicas compatibles con nuestra estructura LEGO.

Esto permitió desarrollar diferentes prototipos sin tener que fabricar piezas nuevas.

---

### Ejes y pasadores LEGO Technic / Nezha

![](other/piezas-axl.jpg)

Los ejes y pasadores se utilizan para unir y posicionar los diferentes elementos mecánicos del robot.

#### Uso en nuestro robot

- Fijación de vigas.
- Montaje de los ejes de las ruedas.
- Unión de módulos estructurales.
- Construcción de la dirección.
- Montaje de engranajes.

#### ¿Por qué los usamos?

Necesitábamos conexiones suficientemente rígidas para evitar movimientos no deseados, pero que al mismo tiempo pudieran desmontarse durante las iteraciones del diseño.

El sistema de ejes y pasadores permite modificar la estructura sin destruir las piezas.

---

## 2. Sistema de movilidad

### Motor DC de tracción

![](other/motor-dc.jpg)

El motor DC proporciona la fuerza necesaria para desplazar el robot.

#### Características relevantes

- Motor de corriente continua.
- Control mediante PWM.
- Transmisión hacia el eje trasero.
- Tracción mediante las ruedas traseras.

#### Uso en nuestro robot

El motor está conectado al sistema de transmisión mediante un engranaje de **12 dientes**, que transmite el movimiento a un engranaje de **20 dientes** conectado al eje trasero.

#### ¿Por qué lo usamos?

Seleccionamos este motor porque proporciona una solución compacta y compatible con nuestra estructura mecánica.

Además, necesitábamos un motor capaz de proporcionar suficiente velocidad y torque para que el robot pudiera desplazarse y realizar correcciones de trayectoria.

Nuestro objetivo no era maximizar únicamente la velocidad del motor, sino conseguir un equilibrio entre:

**velocidad + torque + tracción + estabilidad.**

> **Datos que queremos validar experimentalmente:** RPM reales, velocidad máxima, torque bajo carga y comportamiento con diferentes valores de PWM.

---

### Sistema de ruedas

![](other/ruedas.jpg)

El robot utiliza cuatro ruedas con un diámetro de **35 mm**.

#### Características

- Diámetro: **35 mm**
- Radio: **17,5 mm**
- Número de ruedas: **4**
- Tracción: **trasera**
- Dirección: **delantera**

La circunferencia teórica de cada rueda es:

$$
C = \pi d
$$

$$
C = \pi(0.035) \approx 0.110\ m
$$

Por lo tanto, una revolución de la rueda representa aproximadamente **110 mm de desplazamiento**, suponiendo que no existe deslizamiento.

#### ¿Por qué usamos estas ruedas?

El diámetro de 35 mm nos permite mantener el robot compacto y proporciona una ventaja mecánica adecuada para el sistema de transmisión.

Una rueda más grande permitiría recorrer una mayor distancia por revolución, pero requeriría más torque para producir la misma fuerza en el suelo.

Por eso seleccionamos un diámetro relativamente pequeño para priorizar **control, tracción y estabilidad**.

---

## 3. Transmisión

### Engranajes 12:20

![](other/engranajes.jpg)

El movimiento del motor se transmite al eje trasero mediante dos engranajes:

- Engranaje conductor: **12 dientes**
- Engranaje conducido: **20 dientes**

La relación de transmisión es:

$$
i = \frac{20}{12} = 1.67:1
$$

Esto representa una **reducción de velocidad de 1,67:1**.

La velocidad del eje de las ruedas es aproximadamente:

$$
RPM_{rueda} = RPM_{motor} \times \frac{12}{20}
$$

$$
RPM_{rueda} = 0.6 \times RPM_{motor}
$$

Por otro lado, el torque teórico aumenta:

$$
T_{salida} \approx T_{motor} \times 1.67
$$

En un sistema real el aumento de torque es menor debido a las pérdidas mecánicas.

#### ¿Por qué usamos esta relación?

Elegimos esta relación porque no queríamos obtener únicamente la mayor velocidad posible.

Una reducción menor aumentaría la velocidad de las ruedas, pero disminuiría el torque disponible.

Una reducción mayor proporcionaría más torque, pero reduciría demasiado la velocidad.

La relación **12:20** representa un compromiso entre:

- Velocidad.
- Torque.
- Tracción.
- Aceleración.
- Estabilidad en curvas.

Esta decisión es especialmente importante porque el robot debe mantener un movimiento controlado mientras realiza correcciones de dirección.

---

## 4. Sistema de dirección

### Servomotor de dirección

![](other/servo.jpg)

El servomotor controla la dirección de las ruedas delanteras.

#### Características relevantes

- Servomotor controlado mediante señal PWM.
- Movimiento bidireccional.
- Posición central definida.
- Conectado mecánicamente al sistema de dirección delantero.

#### Uso en nuestro robot

El servo mueve el mecanismo de dirección mediante una transmisión mecánica tipo **cremallera y piñón**.

Esto convierte el movimiento rotacional del servo en un desplazamiento lateral que modifica el ángulo de las ruedas delanteras.

#### ¿Por qué lo usamos?

Necesitábamos controlar con precisión el ángulo de las ruedas delanteras.

El servomotor permite establecer una posición central y realizar correcciones pequeñas hacia ambos lados.

Esto es fundamental porque el sistema de control calcula continuamente el ángulo de dirección necesario para corregir la trayectoria.

---

### Mecanismo de dirección

![](other/direccion.jpg)

El sistema de dirección está situado en el eje delantero y utiliza una configuración mecánica tipo **cremallera y piñón**.

#### Objetivos del diseño

- Mantener una posición central estable.
- Reducir la holgura.
- Conseguir movimientos repetibles.
- Permitir giros cerrados.
- Mantener el sistema compacto.

#### ¿Por qué es importante?

Una holgura excesiva en la dirección provocaría que el mismo comando del servo produjera diferentes ángulos reales de las ruedas.

Esto afectaría directamente a la estabilidad del robot y al funcionamiento del controlador.

Por esta razón, la rigidez y alineación del mecanismo de dirección fueron aspectos importantes durante el montaje.

---

## 5. Alimentación

### Batería VEX IQ 2ª generación

![](other/battery-vex.webp)

La batería VEX IQ de segunda generación fue utilizada como fuente de alimentación durante una de las configuraciones del sistema.

#### Características relevantes

- Tecnología: Li-Ion.
- Voltaje nominal: **7,2 V**.
- Capacidad: **2000 mAh**.
- Corriente continua disponible: adecuada para la alimentación del sistema de movilidad.
- Puerto USB-C integrado para carga.

#### Uso en nuestro robot

La batería proporciona alimentación al sistema de potencia, principalmente al **driver L298N y al motor de tracción**.

#### ¿Por qué la usamos?

La batería VEX IQ proporciona una fuente de alimentación compacta y recargable, adecuada para un robot móvil.

Su tensión es compatible con la etapa de potencia utilizada para controlar el motor.

---

### Baterías Li-Ion 18650

![](other/baterias-lit.jpg)

Utilizamos dos celdas de Li-Ion formato **18650** como parte del sistema de almacenamiento de energía.

#### Características

- Formato: **18650**.
- Química: **Li-Ion**.
- Voltaje nominal: **3,7 V por celda**.
- Voltaje nominal en serie: **7,4 V**.
- Voltaje máximo de carga: **4,2 V por celda**.

#### Uso en nuestro robot

Las baterías proporcionan energía al sistema de alimentación y permiten alimentar tanto la etapa de potencia como el sistema de regulación utilizado para la electrónica.

#### ¿Por qué las usamos?

Durante las pruebas observamos que los motores podían producir caídas de tensión cuando demandaban corriente durante la aceleración.

La utilización de un sistema de baterías separado y regulado permitió mejorar la estabilidad de la alimentación de la electrónica.

> **Nota:** La capacidad nominal indicada en algunas etiquetas de celdas 18650 puede no representar su capacidad real. Para la documentación final debemos utilizar únicamente la capacidad medida o una especificación fiable del fabricante.

---

### MT3608 — Convertidor Step-Up

![](other/elevador.jpg)

El **MT3608** es un convertidor DC-DC elevador utilizado para obtener una tensión estable para la electrónica.

#### Características relevantes

- Tipo: convertidor Step-Up.
- Entrada: aproximadamente **2–24 V**.
- Salida regulable.
- Frecuencia de conmutación: aproximadamente **1,2 MHz**.
- Eficiencia máxima teórica: aproximadamente **93 %**.

#### Uso en nuestro robot

El MT3608 eleva y regula la tensión procedente de las baterías para proporcionar una alimentación adecuada a la electrónica.

#### ¿Por qué lo usamos?

Durante las pruebas observamos que los cambios de consumo del motor podían provocar variaciones de tensión.

Estas variaciones podían producir reinicios o comportamiento inestable en los sistemas electrónicos.

Por ello, utilizamos regulación de tensión para separar, en la medida de lo posible, las variaciones de la etapa de potencia de la alimentación de la lógica.

---

## 6. Control de motores

### L298N Dual H-Bridge

![](other/puente-h.webp)

El **L298N** es el driver utilizado para controlar el motor de tracción.

#### Características relevantes

- Tipo: doble puente H.
- Tensión de alimentación del motor: hasta aproximadamente **35 V** en el módulo utilizado.
- Corriente nominal aproximada: **2 A por canal**.
- Entradas de control digital.
- Control de velocidad mediante PWM.
- Control de dirección mediante las entradas del puente H.

#### Uso en nuestro robot

El Arduino UNO R4 WiFi envía las señales de control al L298N.

El driver se encarga de entregar la corriente necesaria al motor y permite controlar:

- Dirección de giro.
- Velocidad.
- Frenado.

#### ¿Por qué lo usamos?

Necesitábamos separar la corriente de control del Arduino de la corriente necesaria para el motor.

El Arduino genera las señales de control, mientras que el L298N actúa como etapa de potencia.

Además, su funcionamiento con motores DC y su compatibilidad con nuestra alimentación lo hicieron adecuado para nuestro prototipo.

---

## 7. Sensores

### HC-SR04 — Sensores ultrasónicos

![](other/sensor-hc-sr04.webp)

Utilizamos **tres sensores ultrasónicos HC-SR04** para medir las distancias respecto a las paredes y obstáculos.

#### Características relevantes

- Tecnología: ultrasonido.
- Frecuencia: **40 kHz**.
- Alimentación: **5 V**.
- Rango teórico: aproximadamente **2–400 cm**.
- Comunicación mediante señales `TRIG` y `ECHO`.

#### Distribución en el robot

| Sensor | Función |
|---|---|
| Izquierdo | Medición de la pared izquierda |
| Frontal | Detección de obstáculos y aproximación a esquinas |
| Derecho | Medición de la pared derecha |

#### ¿Por qué usamos tres sensores?

Un único sensor no proporciona suficiente información para conocer la posición lateral del robot dentro del recorrido.

Con dos sensores laterales podemos comparar las distancias:

$$
e_y \approx \frac{d_R-d_L}{2}
$$

Esto permite estimar si el robot está desplazado hacia un lado.

El sensor frontal proporciona información adicional para detectar obstáculos y aproximaciones a las esquinas.

De esta manera, los sensores no funcionan de forma aislada, sino que sus mediciones se utilizan conjuntamente para tomar decisiones de navegación.

---

## 8. Visión artificial

### Arduino Nicla Vision

![](other/nicla-vision.webp)

La **Arduino Nicla Vision** se utiliza para procesar la información visual y proporcionar información de orientación al controlador principal.

#### Características relevantes

- Microcontrolador STM32H747.
- Procesador de doble núcleo.
- Cámara de 2 MP.
- IMU LSM6DSOX.
- Comunicación UART.
- Capacidad para procesamiento de imágenes.
- Formato compacto.

#### Uso en nuestro robot

La Nicla Vision realiza principalmente dos tareas:

1. **Procesamiento de imagen.**
2. **Estimación de orientación mediante la IMU.**

La cámara identifica los colores relevantes de la pista y transmite la información al Arduino UNO R4 WiFi.

La IMU proporciona información de orientación que también se envía al controlador principal.

#### ¿Por qué la usamos?

Necesitábamos realizar procesamiento de visión directamente sobre el robot, sin depender de un computador externo.

El tamaño compacto de la Nicla Vision permitió colocarla en la parte superior del robot sin ocupar demasiado espacio.

También nos permitió dividir las responsabilidades del sistema:

**Nicla Vision → percepción**

**Arduino UNO R4 WiFi → control y navegación**

Esta separación simplifica la arquitectura general del robot.

---

## 9. Distribución eléctrica

### Protoboard / placa de conexiones

![](other/protoboard.jpg)

La protoboard se utiliza para organizar las conexiones eléctricas del sistema.

#### Uso en nuestro robot

Permite distribuir:

- Alimentación.
- GND.
- Señales de control.
- Conexiones de sensores.
- Conexiones entre módulos.
- Capacitores de desacoplo.

#### ¿Por qué la usamos?

Durante el desarrollo necesitábamos cambiar conexiones con frecuencia.

La protoboard permitió realizar modificaciones rápidamente sin tener que fabricar una PCB específica.

Esto fue especialmente útil durante las primeras iteraciones del robot.

---

### Capacitor electrolítico — 100 µF

![](other/cap-electrolit.jpg)

Utilizamos capacitores electrolíticos de **100 µF** como reserva de energía para reducir variaciones rápidas de tensión.

#### Uso en nuestro robot

Se colocan en las líneas de alimentación para ayudar a estabilizar la tensión cuando se producen cambios rápidos en el consumo.

Esto es especialmente relevante durante:

- Arranque del motor.
- Aceleraciones.
- Cambios bruscos de carga.

#### ¿Por qué lo usamos?

Los motores pueden producir cambios rápidos en la demanda de corriente.

El capacitor actúa como un pequeño reservorio de energía y ayuda a reducir las variaciones de tensión en la alimentación.

---

### Capacitor cerámico — 100 nF

![](other/cap-ceramico.jpg)

Los capacitores cerámicos de **100 nF** se utilizan para desacoplar las líneas de alimentación de los circuitos electrónicos.

#### Uso en nuestro robot

Se colocan cerca de los circuitos electrónicos para filtrar ruido eléctrico de alta frecuencia.

#### ¿Por qué lo usamos?

Los motores, PWM y convertidores DC-DC pueden generar ruido eléctrico.

El capacitor cerámico ayuda a reducir este ruido y mejora la estabilidad de la alimentación de los circuitos electrónicos.

---

## 10. Control de encendido y funcionamiento

### Pulsador

![](other/pulsador.jpg)

El pulsador se utiliza como entrada de usuario para iniciar o controlar determinadas funciones del robot.

#### Uso en nuestro robot

Principalmente:

- Inicio de la rutina autónoma.
- Control de estados de funcionamiento.
- Interacción con el sistema antes de comenzar una prueba.

#### ¿Por qué lo usamos?

Necesitábamos una forma sencilla y accesible de iniciar la ejecución del robot sin tener que utilizar un computador durante la prueba.

---

### Interruptor principal

![](other/switch.webp)

El interruptor controla el encendido y apagado general del sistema.

#### Uso en nuestro robot

Permite conectar o desconectar la alimentación principal.

#### ¿Por qué lo usamos?

Un interruptor físico permite apagar rápidamente el robot durante una prueba y proporciona un método sencillo para controlar la alimentación antes de cada ejecución.

---

## 11. Fijación de componentes

### Cinta 3M VHB 5952

![](other/cinta.jpg)

La cinta 3M VHB se utiliza para fijar diferentes componentes electrónicos y módulos al chasis.

#### Uso en nuestro robot

Se utiliza principalmente para fijar:

- Arduino.
- L298N.
- Sensores.
- Protoboard.
- Módulos electrónicos.

#### ¿Por qué la usamos?

Algunos componentes no disponen de orificios de montaje compatibles con nuestra estructura.

La cinta VHB permite fijarlos sin modificar las piezas estructurales y absorbe parte de las vibraciones producidas por el robot.

La fijación también permite desmontar y reposicionar componentes durante las diferentes iteraciones del diseño.

---

# 12. Resumen de componentes

| Componente | Función principal | Razón de uso |
|---|---|---|
| LEGO SPIKE Prime | Estructura | Modularidad y facilidad de prototipado |
| Piezas Nezha | Estructura y movilidad | Compatibilidad mecánica y reutilización |
| Motor DC | Tracción | Generación del movimiento |
| Engranaje 12T | Transmisión | Conduce el movimiento del motor |
| Engranaje 20T | Transmisión | Aumenta torque y reduce velocidad |
| Ruedas 35 mm | Movimiento | Compacidad y ventaja mecánica |
| Servomotor | Dirección | Control preciso del ángulo |
| L298N | Potencia del motor | Permite controlar el motor desde el Arduino |
| Arduino UNO R4 WiFi | Control principal | Control, comunicación y estabilidad a 5 V |
| Nicla Vision | Visión e IMU | Procesamiento de imagen y orientación |
| HC-SR04 ×3 | Distancia | Medición de paredes y obstáculos |
| Batería VEX IQ | Alimentación | Fuente recargable para el sistema de potencia |
| Li-Ion 18650 ×2 | Almacenamiento de energía | Fuente de energía recargable |
| MT3608 | Regulación | Estabilización/elevación de tensión |
| Protoboard | Distribución | Facilita modificaciones durante pruebas |
| Capacitor 100 µF | Filtrado | Reduce variaciones de tensión |
| Capacitor 100 nF | Desacoplo | Reduce ruido de alta frecuencia |
| Pulsador | Entrada | Inicio/control de la rutina |
| Interruptor | Alimentación | Encendido y apagado |
| Ejes/pasadores | Construcción | Uniones estructurales |
| Cinta VHB | Fijación | Montaje de electrónica y módulos |

---

# 13. Filosofía de selección de componentes

La selección de componentes no se realizó únicamente en función de sus especificaciones individuales.

Cada componente fue evaluado considerando cómo afectaba al **sistema completo del robot**.

Por ejemplo:

- El diámetro de las ruedas afecta a la velocidad y al torque.
- La relación de engranajes afecta a la velocidad y a la tracción.
- La rigidez del chasis afecta a la precisión de la dirección.
- La posición de los sensores afecta a la calidad de las mediciones.
- La alimentación afecta a la estabilidad de la electrónica.
- El sistema de dirección afecta directamente al comportamiento del controlador.

Por esta razón, nuestras decisiones de hardware se basaron en el siguiente principio:

> **No buscamos el componente con las mejores especificaciones individuales, sino la combinación de componentes que produzca el comportamiento más estable y predecible del robot.**
---
## Mecánica y Sistema de Transmisión

Nuestro robot es un vehículo compacto de cuatro ruedas diseñado buscando un equilibrio entre **estabilidad, tracción, maniobrabilidad y velocidad**.

Las dimensiones finales del robot son:

| Parámetro | Valor |
|---|---:|
| Longitud | **195 mm** |
| Anchura | **100 mm** |
| Altura | **170 mm** |
| Diámetro de las ruedas | **35 mm** |
| Radio de las ruedas | **17,5 mm** |
| Número de ruedas | **4** |
| Tracción | **Trasera** |
| Dirección | **Delantera** |

El chasis está construido principalmente con elementos estructurales de **LEGO SPIKE Prime/Technic** y piezas mecánicas de Nezha. Elegimos esta construcción porque permite modificar rápidamente la posición del motor, los sensores, la dirección y los componentes electrónicos durante las diferentes etapas de desarrollo.

Nuestro objetivo principal no fue únicamente conseguir que el robot se desplazara, sino conseguir un movimiento **estable, repetible y controlable**.

---

### 2. Diseño del chasis

El chasis tiene unas dimensiones finales de **195 × 100 × 170 mm**.

Su reducido ancho permite que el robot sea compacto y maniobrable, mientras que la estructura proporciona espacio suficiente para integrar:

- Motor de tracción.
- Sistema de transmisión.
- Dirección delantera.
- Sensores ultrasónicos.
- Arduino UNO R4 WiFi.
- Nicla Vision.
- Driver L298N.
- Baterías y sistema de alimentación.

Utilizamos piezas LEGO/Technic porque durante el desarrollo necesitábamos modificar frecuentemente la estructura.

Sus principales ventajas fueron:

- Facilidad de montaje.
- Posibilidad de modificar rápidamente el diseño.
- Reutilización de piezas entre versiones.
- Posicionamiento preciso de ejes y componentes.
- Facilidad para realizar prototipos.

Una de nuestras prioridades fue aumentar la rigidez de las zonas donde se encuentran el **motor, el eje trasero y el sistema de dirección**.

Esto es importante porque una estructura demasiado flexible puede provocar que el movimiento real de las ruedas no coincida con el movimiento esperado por el sistema de control.

---

### 3. Sistema de transmisión

El robot utiliza **tracción trasera**.

El motor transmite el movimiento al eje trasero mediante dos engranajes:

- Engranaje pequeño: **12 dientes**
- Engranaje grande: **20 dientes**

El engranaje de 12 dientes es el **conductor**, conectado al motor, mientras que el engranaje de 20 dientes es el **conducido**, conectado al eje de las ruedas.

La relación de transmisión es:

$$
i = \frac{20}{12} = 1.67:1
$$

Por lo tanto, tenemos una **reducción de velocidad de 1,67:1**.

Esto significa que el eje de las ruedas gira aproximadamente al:

$$
\frac{12}{20} = 0.60
$$

es decir, al **60 % de la velocidad del motor**.

A cambio, idealmente el torque disponible en el eje aumenta aproximadamente:

$$
\frac{20}{12} = 1.67
$$

veces.

En la práctica, el aumento real de torque es menor debido a las pérdidas por fricción y a la eficiencia de los engranajes.

---

### 4. ¿Por qué elegimos una relación 12:20?

Esta fue una decisión importante del diseño mecánico.

No buscábamos simplemente conseguir la mayor velocidad posible. Necesitábamos encontrar un equilibrio entre:

**velocidad → torque → tracción → estabilidad → control**

Una transmisión con una reducción menor permitiría que las ruedas giraran más rápido, pero reduciría el torque disponible en ellas.

Por el contrario, una reducción mayor aumentaría el torque, pero reduciría demasiado la velocidad máxima.

Por eso seleccionamos la relación **12:20 = 1,67:1**.

Esta configuración nos permite disponer de mayor torque en las ruedas, lo que ayuda especialmente durante:

- Aceleraciones.
- Cambios de dirección.
- Curvas.
- Situaciones en las que aumenta la resistencia al movimiento.
- Recuperaciones después de una trayectoria incorrecta.

La decisión busca que el robot sea **rápido, pero también controlable**.

---

### 5. Diseño de las ruedas

El robot utiliza cuatro ruedas de **35 mm de diámetro**.

El radio de cada rueda es:

$$
r = \frac{35}{2} = 17.5\text{ mm}
$$

La distancia teórica recorrida en una revolución es:

$$
C = \pi d
$$

$$
C = \pi(0.035)
$$

$$
C \approx 0.110\text{ m}
$$

Por lo tanto, cada revolución de la rueda representa aproximadamente **110 mm de desplazamiento**, suponiendo que no existe deslizamiento.

El diámetro relativamente pequeño de las ruedas ayuda a mantener el robot compacto y proporciona una ventaja mecánica mayor que una rueda de mayor diámetro.

La elección del diámetro también afecta directamente a la relación entre las RPM del motor y la velocidad lineal del robot.

---

### 6. Relación entre motor, transmisión y velocidad

La transmisión permite calcular la velocidad teórica de las ruedas a partir de las RPM del motor.

Como utilizamos una relación 12:20:

$$
RPM_{rueda} = RPM_{motor} \times \frac{12}{20}
$$

Por lo tanto:

$$
RPM_{rueda} = 0.6 \times RPM_{motor}
$$

La velocidad lineal puede calcularse mediante:

$$
v = \frac{RPM_{rueda} \times 0.110}{60}
$$

Combinando ambas ecuaciones:

$$
v = \frac{RPM_{motor} \times 0.6 \times 0.110}{60}
$$

Esto nos permite relacionar directamente la velocidad del motor con la velocidad teórica del robot.

Por ejemplo, si el motor girara a aproximadamente **260 RPM**:

$$
RPM_{rueda} = 260 \times 0.6 = 156\ RPM
$$

y la velocidad teórica sería aproximadamente:

$$
v \approx 0.286\ m/s
$$

Este valor es cercano a la velocidad de crucero objetivo utilizada por nuestro sistema de control.

> **Nota:** este cálculo representa una velocidad teórica. La velocidad real puede ser menor debido a pérdidas mecánicas, fricción, variaciones de batería y deslizamiento de las ruedas.

---

### 7. Torque y tracción

El torque fue uno de los factores considerados al seleccionar la transmisión.

El motor necesita proporcionar suficiente torque para:

- Acelerar el robot.
- Mantener el movimiento.
- Superar la resistencia de las ruedas.
- Realizar cambios de dirección.
- Mantener la tracción durante las curvas.

La transmisión 12:20 proporciona una multiplicación teórica del torque de:

$$
T_{salida} = T_{motor} \times 1.67
$$

aunque el torque real será menor debido a las pérdidas del sistema.

Esta reducción supone un intercambio:

> **Perdemos velocidad de giro para obtener mayor torque en las ruedas.**

Para nuestro robot consideramos que este intercambio era beneficioso porque la estabilidad y la capacidad de controlar el robot son más importantes que alcanzar únicamente la máxima velocidad posible.

---

### 8. Sistema de dirección

El robot utiliza **dirección en las ruedas delanteras**.

El servomotor controla las ruedas delanteras mediante un mecanismo mecánico tipo **cremallera y piñón**.

El servo transforma su movimiento rotacional en un desplazamiento lateral de la dirección.

Este sistema nos permite conseguir:

- Movimiento de dirección hacia ambos lados.
- Posición central definida.
- Movimiento relativamente preciso.
- Buena capacidad de giro.
- Integración compacta dentro del chasis.

La posición central del servo es especialmente importante porque representa la posición en la que el robot debe desplazarse aproximadamente en línea recta.

---

### 9. Dirección y estabilidad

El sistema de dirección fue diseñado conjuntamente con el sistema de transmisión.

El robot debe ser capaz de realizar giros relativamente cerrados sin perder estabilidad ni tracción.

Durante el funcionamiento normal, el controlador modifica continuamente el ángulo de dirección para corregir la posición del robot.

Por esta razón, el sistema mecánico debe tener **el menor juego posible**.

Prestamos especial atención a:

- Holgura de la dirección.
- Rigidez de los soportes.
- Alineación de las ruedas delanteras.
- Movimiento del eje delantero.
- Fricción del mecanismo.

Una dirección con demasiado juego provocaría que una misma orden del servo produjera diferentes comportamientos en el robot.

Por eso, la precisión mecánica es fundamental para que el controlador pueda funcionar correctamente.

---

### 10. Distribución de los componentes

La posición de los componentes también fue considerada durante el diseño.

El robot incorpora elementos relativamente pesados, como:

- Baterías.
- Motor.
- L298N.
- Arduino.
- Nicla Vision.

Intentamos mantener estos componentes dentro de la estructura del chasis y evitar grandes voladizos.

La distribución de los componentes busca mantener:

- Una estructura compacta.
- Un comportamiento estable.
- Menores vibraciones.
- Buena tracción.
- Espacio suficiente para la dirección y los sensores.

También tuvimos que encontrar un equilibrio entre colocar los componentes en posiciones accesibles para realizar modificaciones y mantener una distribución mecánica adecuada.

---

### 11. Montaje de los sensores

Los tres sensores ultrasónicos están montados en la parte delantera y lateral del robot:

- **Sensor izquierdo:** mide la distancia respecto a la pared izquierda.
- **Sensor frontal:** detecta obstáculos y ayuda a detectar las aproximaciones a las esquinas.
- **Sensor derecho:** mide la distancia respecto a la pared derecha.

La posición de los sensores se mantiene fija durante el funcionamiento.

Esto es importante porque el software interpreta cada medición suponiendo que el sensor está orientado en una dirección determinada.

Si un sensor se moviera durante la ejecución, las mediciones podrían cambiar aunque el entorno permaneciera igual.

Por ello, consideramos el montaje de los sensores como parte del **diseño mecánico y no solamente como una cuestión electrónica**.

---

### 12. Integración de la electrónica

La electrónica está integrada directamente en la estructura del robot.

Los principales componentes electrónicos son:

- Arduino UNO R4 WiFi.
- Nicla Vision.
- L298N.
- Tres HC-SR04.
- Sistema de baterías.
- Regulación de tensión.

La estructura proporciona soporte físico para estos componentes y permite acceder a ellos durante las pruebas.

También prestamos atención al recorrido de los cables, especialmente cerca de:

- La dirección.
- Los engranajes.
- Los ejes.
- Las ruedas.

Esto evita que los cables interfieran con los elementos móviles.

---

### 13. Evolución del diseño mecánico

El robot pasó por diferentes versiones durante el proceso de desarrollo.

#### Primera versión

La primera versión se utilizó principalmente para conseguir una plataforma funcional.

El objetivo inicial era comprobar que el robot pudiera desplazarse y que los diferentes componentes pudieran integrarse en el chasis.

#### Segunda etapa

A medida que cambiaron los componentes electrónicos y el sistema de control, también tuvimos que modificar el diseño mecánico.

Esto nos llevó a utilizar una estructura modular que permitiera cambiar la posición de:

- Motor.
- Baterías.
- Sensores.
- Electrónica.
- Sistema de dirección.

#### Diseño de la transmisión

Posteriormente establecimos la transmisión definitiva mediante los engranajes de **12 y 20 dientes**.

La decisión se tomó buscando un equilibrio entre velocidad y torque.

#### Configuración final

La configuración final tiene:

**195 mm de longitud × 100 mm de anchura × 170 mm de altura**

y utiliza ruedas de **35 mm**.

En esta etapa, nuestra prioridad dejó de ser simplemente conseguir que el robot funcionara y pasó a ser conseguir un movimiento **estable, repetible y predecible**.

---

### 14. Compromisos del diseño mecánico

| Decisión | Ventaja | Desventaja |
|---|---|---|
| Ruedas de 35 mm | Robot compacto y buena ventaja mecánica | Menor velocidad máxima |
| Engranajes 12:20 | Mayor torque y tracción | Menor velocidad de las ruedas |
| Tracción trasera | Sistema sencillo y compacto | Hay que cuidar la distribución del peso |
| Dirección delantera | Buena maniobrabilidad | Requiere una alineación precisa |
| Estructura LEGO/Technic | Fácil de modificar | Hay que controlar la holgura |
| Chasis compacto | Buena maniobrabilidad | Menor espacio para componentes |
| Sensores fijados | Mediciones más consistentes | Menos flexibilidad para cambiar su posición |

---

### 15. Diseño mecánico final

El diseño final es el resultado de buscar un equilibrio entre **velocidad, torque, tracción, estabilidad y precisión de dirección**.

Una de las decisiones mecánicas más importantes fue utilizar un engranaje de **12 dientes como conductor** y uno de **20 dientes como conducido**, obteniendo una relación de reducción de **1,67:1**.

Junto con las ruedas de **35 mm**, esta transmisión proporciona una combinación adecuada entre velocidad y torque para nuestro robot.

La mecánica y el software fueron considerados como un único sistema:

**Transmisión → movimiento → sensores → estimación de posición → dirección → corrección de trayectoria.**

Por ello, no diseñamos cada componente de forma independiente. Las decisiones sobre el chasis, la transmisión, las ruedas, la dirección y la colocación de los sensores se tomaron teniendo en cuenta cómo afectarían al comportamiento completo del robot.

---

### 16. Validación experimental pendiente

Para validar experimentalmente las decisiones mecánicas, queremos comparar diferentes valores de PWM con la velocidad real del robot.

La prueba propuesta consiste en medir el tiempo necesario para recorrer **1 metro**:

| PWM | Tiempo en 1 m | Velocidad real |
|---:|---:|---:|
| 120 | — | — |
| 150 | — | — |
| 180 | — | — |
| 200 | — | — |

La velocidad real se calculará mediante:

$$
v = \frac{distancia}{tiempo}
$$

Estos datos permitirán comparar la velocidad teórica con la velocidad real y determinar qué configuración proporciona el mejor equilibrio entre **velocidad, tracción y estabilidad**.

Esta validación nos permitirá justificar nuestras decisiones mecánicas mediante datos obtenidos directamente del robot.
---
# Diseño del Software

## Arquitectura del Sistema

El software del robot fue desarrollado utilizando una arquitectura modular basada en componentes independientes para la adquisición de datos, estimación, control y actuación. El controlador principal es un **Arduino UNO R4 WiFi**, encargado de ejecutar el algoritmo de navegación, procesar la información de los sensores y generar los comandos para el motor y el servo de dirección.

El software está dividido en varios módulos:

* **Módulo de sensores:** Gestiona los sensores ultrasónicos HC-SR04.
* **Módulo de comunicación con la IMU:** Recibe información sobre la orientación y los colores desde la Nicla Vision mediante comunicación UART.
* **Módulo de estimación de estado:** Utiliza un Filtro de Kalman para reducir el ruido de los sensores y estimar el error de posición del robot.
* **Módulo de control:** Utiliza un controlador LQR para calcular la corrección necesaria en la dirección.
* **Módulo de misión:** Implementa el comportamiento general del robot mediante una máquina de estados finitos.
* **Módulo de actuación:** Controla el motor de corriente continua mediante un controlador L298N y el servo encargado de la dirección.

Esta estructura modular facilita la depuración, calibración y mejora de cada sistema de forma independiente sin afectar el funcionamiento general del robot.

---

# Adquisición de Datos de los Sensores

## Medición de Distancia con Sensores Ultrasónicos

El robot utiliza tres sensores ultrasónicos HC-SR04 ubicados en la parte izquierda, frontal y derecha del chasis.

Estos sensores miden la distancia hasta las paredes enviando un pulso ultrasónico y calculando el tiempo que tarda el eco en regresar. El tiempo medido se convierte en distancia utilizando la velocidad del sonido:

$$
Distancia = \frac{Tiempo \times 343}{2}
$$

Los sensores laterales se utilizan principalmente para mantener el robot alineado dentro de la pista, mientras que el sensor frontal permite detectar obstáculos o esquinas e iniciar las maniobras correspondientes.

![](v-photos/v-components/componentes1.jpg)

Las mediciones inválidas, causadas por ecos ausentes o distancias fuera del rango útil del sensor, son descartadas para evitar que datos incorrectos afecten la navegación.

---

# Comunicación con la IMU y Módulos Externos

El robot se comunica con un módulo **Nicla Vision** mediante comunicación serial UART.

![](v-photos/v-components/componentes2.jpg)

La IMU proporciona información sobre la orientación del robot, permitiendo al controlador conocer su dirección durante el recorrido. La información se transmite utilizando un formato como:

```text
G,<ángulo>
```

donde el ángulo representa la orientación o *yaw* actual del robot.

El módulo también puede enviar información relacionada con los colores detectados:

```text
Y, R, B, W
```

Estos datos son utilizados por la lógica de navegación cuando es necesario identificar elementos de diferentes colores.

En caso de que la señal de la IMU no esté disponible temporalmente, el robot puede utilizar un modo alternativo basado en su estimación interna, evitando una pérdida total del control.

---

# Estimación de Estado mediante un Filtro de Kalman

Para obtener una estimación más estable y precisa de la posición del robot, se implementó un **Filtro de Kalman**.

El filtro estima principalmente dos variables:

* **Error lateral (\(e_y\)):** Representa la desviación del robot con respecto a la trayectoria deseada.
* **Error de orientación (\(e_\psi\)):** Representa la diferencia entre la orientación actual del robot y la dirección deseada.

El error lateral puede calcularse utilizando la información de los sensores laterales:

$$
e_y = \frac{d_{derecha} - d_{izquierda}}{2}
$$

El Filtro de Kalman combina las mediciones obtenidas por los sensores con un modelo del movimiento del robot para reducir el ruido y obtener valores más estables para el sistema de control.

Además, el sistema puede rechazar mediciones anormales mediante un límite de innovación, evitando que lecturas incorrectas de los sensores provoquen correcciones inesperadas en la trayectoria.

---

# Control del Robot

## Controlador LQR para la Dirección

El robot utiliza un controlador **LQR (Linear Quadratic Regulator)** para calcular la corrección necesaria en la dirección.

La ley de control utilizada puede representarse como:

$$
u = -Kx
$$

donde:

* \(u\) representa la corrección aplicada a la dirección.
* \(K\) representa las ganancias calculadas para el controlador.
* \(x\) contiene los errores estimados de posición y orientación.

El controlador utiliza principalmente:

* El error lateral estimado.
* El error de orientación.
* La velocidad actual del robot.

Los valores de control pueden ajustarse según la velocidad mediante una estrategia conocida como **gain scheduling**, permitiendo mantener un comportamiento estable bajo diferentes condiciones de movimiento.

Finalmente, la corrección calculada se transforma en un ángulo para el servo y se limita dentro del rango mecánico permitido por el sistema de dirección.

---

# Control de la Misión

![](v-photos/v-components/componentes3.jpg)

## Máquina de Estados Finitos

El comportamiento general del robot está organizado mediante una **máquina de estados finitos**, la cual divide la misión en diferentes modos de funcionamiento.

### IDLE

En este estado, el robot permanece detenido y espera la señal de inicio antes de comenzar la misión autónoma.

### FOLLOW

Es el modo principal de navegación. El robot sigue la trayectoria en línea recta utilizando:

* Mediciones de los sensores ultrasónicos.
* La estimación obtenida mediante el Filtro de Kalman.
* El controlador LQR para realizar correcciones en la dirección.

### CORNER_TURN

Cuando el sistema detecta una esquina, el robot realiza una maniobra de giro controlada, utilizando la información de orientación proporcionada por la IMU y una lógica específica para completar el giro.

### RECOVERY

Es un modo de seguridad que se activa cuando el robot detecta una situación anormal o una posible colisión. El robot puede retroceder y realizar una maniobra para recuperar su trayectoria.

### STOP

Este estado detiene completamente el robot una vez que la misión ha sido completada.

## Control del Motor y la Dirección

### Control del Motor

El motor de corriente continua es controlado mediante un controlador **L298N**.

El software controla:

* La dirección de giro mediante pines digitales.
* La velocidad utilizando modulación por ancho de pulso o **PWM**.

Las acciones principales disponibles son:

* Movimiento hacia adelante.
* Movimiento hacia atrás.
* Frenado o detención.

El valor de PWM determina la velocidad del motor de acuerdo con el estado actual de la misión.

### Control del Servo de Dirección

El servo de dirección recibe el ángulo calculado por el controlador LQR.

La salida del controlador se convierte desde la corrección matemática obtenida a una posición física para el servo mediante una función de calibración:

$$
Servo = Centro + Corrección
$$

El ángulo final se mantiene dentro de límites establecidos para proteger los componentes mecánicos y asegurar un funcionamiento estable.

---

# Telemetría y Depuración

Durante el desarrollo se implementó un sistema de telemetría mediante comunicación serial.

El sistema permite visualizar información como:

* Distancias medidas por los sensores.
* Estado actual del robot.
* Error lateral estimado.
* Error de orientación estimado.
* Orientación obtenida desde la IMU.
* Colores detectados.
* Contadores relacionados con giros y recuperación.

Esta información fue utilizada durante las pruebas para facilitar la depuración del programa, calibrar los sensores y ajustar los parámetros del sistema de control.

---
# Impacto
El objetivo central de nuestro proyecto fue desarrollar e implementar un sistema autónomo capaz de realizar un reconocimiento y evasión de objetos exitosa en un entorno dinámico, utilizando componentes electrónicos basados en Arduino y visión artificial. Aunque a primera vista la tarea de reconocimiento y evasión puede parecer fundamental, demostramos que un robot puede ejecutarla de manera robusta y consistente. Más allá de cumplir con los requisitos técnicos de la competencia, esta solución tecnológica es escalable y podría aplicarse en robots de servicio para el beneficio humano, por ejemplo, en entornos domésticos, de asistencia o industriales donde la navegación segura es primordial.

A lo largo de este desafío, hemos experimentado un crecimiento significativo en múltiples áreas clave para nuestra formación como futuros ingenieros. Por un lado, nos enfrentamos a constantes desafíos, especialmente durante las pruebas y alteraciones en el diseño mecánico. Esto nos obligó a desarrollar una mentalidad fuerte y analítica; en lugar de frustrarnos, aprendimos a abordar los infortunios de manera calmada y decidida, diagnosticando la causa raíz e implementando soluciones prácticas y continuas basadas en la experiencia.

Asimismo, para lograr la estabilidad del sistema, tuvimos que profundizar en conceptos avanzados. Esto incluyó la integración de algoritmos de visión por computador para el procesamiento de imágenes en tiempo real y la comunicación paralela eficiente entre la unidad de procesamiento principal y el microcontrolador Arduino, lo que amplió drásticamente nuestro conocimiento en programación, control y electrónica. De igual forma, cada componente del robot fue estructurado y adaptado por nosotros utilizando piezas y sistemas de bloques de construcción tipo "legos", lo que nos impulsó a potenciar nuestra creatividad e imaginación. No solo resolvimos problemas de manera funcional, sino que mediante este ensamblaje modular conceptualizamos soluciones físicas que optimizaron el rendimiento, la robustez y el mantenimiento de nuestro robot.

En conclusión, el desarrollo de este proyecto para la categoría Future Engineers ha sido un viaje transformador que nos ha permitido aplicar la teoría a la práctica, aprender de cada fracaso y consolidarnos como un equipo capaz de afrontar problemas complejos. Independientemente del resultado final en la competencia, el aprendizaje y el crecimiento experimentado han sentado las bases para nuestro futuro profesional en la ingeniería.

---

# Nuestro Recorrido
El inicio de esta aventura estuvo marcado por la participación en la competencia “Copa Ka’i 2024”, un evento que representó el primer acercamiento de nuestro Colegio Alemán de Maracaibo al mundo de la robótica. En este proceso inicial fuimos seleccionados un grupo específico de estudiantes, entre quienes nos encontramos nosotros, Isaac y Fernanda. Nos esforzamos día y noche por comprender los conceptos técnicos que aún nos generaban dudas, perfeccionar nuestro robot y dar lo mejor en este nuevo camino. Aunque no alcanzamos una premiación en dicha competencia, las experiencias vividas fueron determinantes y nos motivaron a afrontar un nuevo desafío: la WRO 2025.

En dicha edición, participamos en distintas modalidades dentro de las Regionales del Estado Zulia, donde uno de nuestros integrantes compitió en Misiones Robóticas y el otro en Futuros Innovadores. Tras un gran trabajo, dedicación y un crecimiento constante de nuestra pasión por la robótica, y a pesar de no haber clasificado a la instancia nacional, decidimos no rendirnos. Por el contrario, unimos fuerzas para consolidar un equipo de dos personas donde la comunicación y la pasión se complementan a la perfección. Esto nos ha permitido llegar hasta el día de hoy participando en las competencias regionales de Nueva Esparta y del Zulia, siempre listos para nuevos retos y aprendizajes que forjarán nuestro futuro.

A lo largo de los años, en conjunto con otros jóvenes con alta destreza en la robótica, hemos desarrollado una profunda pasión y un sólido conjunto de conocimientos en el área, los cuales impulsan nuestros planes a futuro y nos permiten ser parte activa del progreso tecnológico. Durante nuestra preparación para la Copa Ka’i 2024, mantuvimos una participación dinámica que incluyó diversas labores sociales, tales como charlas y demostraciones de nuestro proyecto en escuelas interesadas en integrar la robótica en sus programas académicos, fomentando así el aprendizaje y la innovación en la comunidad.
Del mismo modo, realizamos entrevistas en programas de radio, televisión y medios digitales para compartir nuestra visión sobre las soluciones robóticas ante los retos cotidianos. Esta trayectoria también nos ha brindado la oportunidad de crear lazos imborrables con compañeros de otros equipos tanto en la Copa Ka’i como en la WRO 2025. A pesar de haber pertenecido a distintas categorías, lo que nos fortalece e inspira a soñar en grande es el mismo amor y entusiasmo por la robótica que compartimos como equipo.

---
# ¡Muchísimas Gracias! - Team Eule Tech WRO FE 2026
