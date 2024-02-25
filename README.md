# Flood Detection and Bridge Control System

## Overview

This Arduino project utilizes two servos, a moisture sensor, and a buzzer to detect floods. When the moisture level surpasses a predefined threshold, the system raises a bridge and activates a buzzer for alerts. The bridge lowers when the flood subsides.

![maxresdefault](https://github.com/shreyaskbkukke/smart_bridge/assets/96857515/13beb000-271d-4bc2-8336-8d59bf3c193c)

## Components

- 2 Servo Motors
- Moisture Sensor
- Buzzer
- Arduino Board

## Pin Configuration

- Left Servo: Pin 5
- Right Servo: Pin 6
- Moisture Sensor: Analog Pin A0
- Buzzer: Pin 8

## Usage

1. The bridge is initially lowered.
2. Flood detection raises the bridge and activates the buzzer.
3. The bridge lowers when the flood subsides.

## Configuration

- Adjust the moisture threshold and servo angles as needed.

Feel free to modify the code for specific requirements.
