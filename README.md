# Engineering Documentation - Team Eule Tech
![](https://github.com/colegioalemanwro2026/wro-futureengineers/blob/main/Engineering%20(1).png)

## Introduction
In the present repository you will be able to find all the building and assembly of the Autonomous Robot constructed by the *Team Eule Tech* for the Future Engineers category in the *World Robot Olympiad (WRO)* 2026 Season. This project was brought to fruition through months of hard work and unforgettable experiences, representing our passion for robotics and for achieving our greatest dreams. 
> _"Was immer du tun kannst oder träumst es zu können, fang damit an. Kühnheit hat Genie, Macht und Magie in sich." - Johann Wolfgang von Goethe_

## Contents
- [Team Members](https://github.com/colegioalemanwro2026/wro-futureengineers/blob/main/README.md#team-members)
- [Hardware Design](https://github.com/colegioalemanwro2026/wro-futureengineers#hardware-design)
 - [Design Process](https://github.com/colegioalemanwro2026/wro-futureengineers#design-process)
 - [Assembly Process](https)
 - [Elements](https)
   - [Spike Kit](https)
   - [Electronics](https)
- [Software Design](https)
 - [Image and Color Processing](https)
    - [Image Capturing](https)
	- [Creating Red and Green masks](https)
	- [Final Image](https)
	- [Distance from the cones](https)
 - [Robot Movement](https)
   - [Smart Robot Servo Configuration](https)
   - [Robot Orientation](https)
   - [Route Determination](https)
  - [Data Sending](https)
- [Impact](https)
- [Our Journey](https))
- [Hardware Design](https)
  - [Design Process](https)
  - [Assembly Process](https)
  - [Elements](https)
    - [Spike Kit](https)
    - [Electronics](https)
- [Software Design](https)
  - [Image and Color Processing](https)
    - [Image Capturing](https)
	- [Creating Red and Green masks](https)
	- [Final Image](https)
	- [Distance from the cones](https)
  - [Robot Movement](https)
    - [Smart Robot Servo Configuration](https)
    - [Robot Orientation](https)
    - [Route Determination](https)
  - [Data Sending](https)
- [Impact](https)
- [Our Journey](https)

# *Team Members*
- Isaac Camargo
![](https://github.com/colegioalemanwro2026/wro-futureengineers/blob/main/775a4106-e3e2-4c4f-919d-1946a50a8b13.jpg)
> Mi chiquito pechocho

- Fernanda Leon
![](https://github.com/colegioalemanwro2026/wro-futureengineers/blob/main/e168a51f-258d-4fb5-9f0c-e48285d9942f.jpg)
> Bebetita de su bebetito y solo de bebetito

# *Hardware Design*
## *Design Process*
# Design Process

Our robot is built primarily from a combination of **LEGO SPIKE Prime Set** and **Nezha 48 in 1 Inventor's Kit** components, including the drive motor, wheels, steering servo, and chassis structure. Power is supplied by a **VEX IQ Education Kit (2nd Gen) battery**, with custom electronics enabling full autonomous functionality.

However, the robot underwent multiple structural and electronic revisions before reaching its final competition-ready form.

---

## Evolution History

### Version 1: All-Nezha Platform (Initial Concept)

The original plan was to construct the robot entirely from the **Nezha Inventor's Kit**:
- Chassis, wheels, drive motor, and steering servo from Nezha
- **Micro:bit** + **Nezha Expansion Board** as the main controller
- Nezha sensors for perception
- **Arduino Nicla Vision** camera for computer vision (chosen over Nezha's camera)

### Version 2: ESP32 Migration (Wiring Constraints)

We encountered significant wiring difficulties integrating the **Micro:bit → Expansion Board → Nicla Vision** chain. To resolve this, we replaced most Nezha electronics with:
- **ESP32 microcontroller** — for flexible I/O and wireless capability
- **TB6612FNG (HW-166) motor driver** — compact dual H-bridge
- **HC-SR04 ultrasonic sensor** — for distance measurement

This simplified the Nicla Vision interface but introduced Bluetooth instability between the ESP32 and Nicla.

### Version 3: Arduino Uno R4 WiFi + Direct Wiring (Final Architecture)

To achieve a **stable, deterministic connection** between the vision system and the robot brain, we pivoted to a **direct wired interface**:
- **Arduino Uno R4 WiFi** as the main controller — native USB-C, WiFi/BLE, 5V logic compatible with Nicla Vision
- **L298N (HW-095) motor driver** — robust, high-current dual H-bridge
- Supporting electronics standardized for Arduino ecosystem (level shifters, voltage regulators, connectors)

This eliminated wireless latency and connection drops, ensuring reliable frame capture and inference timing.

### Version 4: Camera Mount Optimization

A dedicated **camera mount structure** was designed to:
- Hold the Nicla Vision at the **precise angle** required for track detection
- Maintain mechanical stability during acceleration and cornering
- Protect the camera and connector during handling and power-on

---

## Design Philosophy

Every iteration was driven by **reliability under competition conditions**:
- **Wired over wireless** for vision link — zero packet loss, deterministic latency
- **Standardized voltage levels** (5V logic) — eliminated level-shifting failures
- **Modular electronics** — swappable drivers, sensors, and controllers
- **Compact, serviceable layout** — all connectors accessible, no hidden wiring

The result is a **unique, integrated design** optimized for the WRO 2026 Future Engineers challenge — robust, maintainable, and competition-proven.
