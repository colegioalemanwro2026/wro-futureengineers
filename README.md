# Documentación de Ingeniería - Team Eule Tech
![](https://github.com/colegioalemanwro2026/wro-futureengineers/blob/main/Engineering%20(1).png)


## Introducción
En el presente repositorio podrán encontrar toda la construcción y ensamblaje del Robot Autónomo construido por el *Team Eule Tech* para la categoría Future Engineers en la temporada 2026 de la *World Robot Olympiad (WRO)*. Este proyecto se materializó tras meses de arduo trabajo y experiencias inolvidables, representando nuestra pasión por la robótica y por alcanzar nuestros más grandes sueños.
> _"Was immer du tun kannst oder träumst es zu können, fang damit an. Kühnheit hat Genie, Macht und Magie in sich." - Johann Wolfgang von Goethe_


## Contenido
- [Integrantes del Team](https://github.com/colegioalemanwro2026/wro-futureengineers/blob/main/README.md#integrantes-del-equipo)
- [Diseño de Hardware](https://github.com/colegioalemanwro2026/wro-futureengineers#diseño-de-hardware)
 - [Proceso de Diseño](https://github.com/colegioalemanwro2026/wro-futureengineers#proceso-de-diseño)
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


Sin embargo, el robot pasó por múltiples revisiones estructurales y electrónicas antes de alcanzar su forma final lista para competencia.


### Versión 1: 
El plan original era construir el robot completamente con el **Kit de Inventor Nezha**, es decir, Chasis, ruedas, motor de tracción y servomotor de dirección de Nezha, utilizar un **Micro:bit** combinado con un **Expansion Board Nezha** como controlador principal, sensores Nezha para percepción y una cámara **Arduino Nicla Vision** para visión artificial (elegida sobre la cámara de Nezha).


### Versión 2:
Enfrentamos dificultades significativas de cableado al integrar la cadena **Micro:bit → Expansion Board → Nicla Vision**. Para resolverlo, reemplazamos la mayoría de la electrónica Nezha por: un **Microcontrolador ESP32**, un **Controlador TB6612FNG (HW-166)** (Puente H Dual) y un **Sensor ultrasónico HC-SR04**. Esto simplificó la interfaz con la Nicla Vision, pero introdujo inestabilidad en el Bluetooth entre el ESP32 y la Nicla.


### Versión 3:
Para lograr una conexión estable entre el sistema de visión y el cerebro del robot, pivoteamos a una **interfaz cableada directa**, con el **Arduino Uno R4 WiFi** como controlador principal, el cual es compatible con la Nicla Vision,**Controlador L298N (HW-095)** (Puente H Dual Robusto) y demás electrónica de soporte estandarizada para Arduino. Esto eliminó la intermitencia inalámbrica y las caídas de conexión, asegurando captura de frames y tiempos de inferencia correctos. Cada modificación se realizó con un resultado único y compacto en mente, llegando así al diseño final que se presenta en la competencia.

## Proceso de Ensamblaje


![Diagrama de Conexiones](wiring-diagram.svg)


