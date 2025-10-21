# ArduinoFollowBot
# Object Following Robot (Arduino + Ultrasonic Sensor)

## Overview
This project uses an Arduino, an HC-SR04 ultrasonic sensor, and an L298N motor driver to create a two-wheel robot that follows an object at a set distance.

## Hardware
- Arduino Uno
- HC-SR04 ultrasonic sensor
- L298N motor driver
- 2x DC motors
- 12V power supply

## Software
- Language: C++ (Arduino)
- Control loop includes hysteresis and PWM speed control.
- Sensor filtering with exponential moving average for stability.

## Files
- `3000L_Version_5` — main Arduino code  
- `wiring_diagram.png` — schematic

## Lessons Learned
Integrated mechanical and electrical systems, applied signal filtering, and learned debugging techniques for motor control.
