# ESP32 - Drone

### A Drone, Controller, and Flight Software, based on the popular ESP32 Microcontroller architecture.

## Current State
- Drone:  CAD model has been finalized and printed, as shown below. RF24 modules have been tested at distance, and motors and batteries have been mounted.
- Controller: PCB design is underway using multiplexers to extend ESP32 capabilities to more GPIO pins. RF24 module is being integrated, as well as battery circuitry.

## Overview
This is an ESP32-based from-scratch Drone project, meant to help learn the fundamentals of CAD, PCB design, control system software, as well as utilize the C++ programming language for high levels of multithreaded efficiency and performance. The Drone is built on a 4S cell system (14.8V), with 2200Kv motors (I would recommend going with a lower Kv value if you are reproducing this project, as that will be more efficient; I used what was on hand), and 10" propellers. It is designed to carry its own weight as well as a payload of ~1kg (2.2lb). 

## Project Objectives

### Drone
- Use Autodesk Inventor to design and 3D print a custom Drone body, built for carrying heavy weight (25+ kg).
- Utilize RF24 radio modules, as well as MPU6050 sensors, to build a real-time multithreaded flight control system, using PID control system algorithms.
- Create modular systems that allow for plug-and-play extension systems (eg. a payload-dropping and sensing system, as well as a front-mounted camera gimbal.)
- Build error-handling systems that allow for the easy handling of exception scenarios, such as loss of network signal or missed packets.
- Architecture system for Payload Acknowledge based telemetry, for use with flight telemetry / analysis software.

### Controller
- Use a secondary ESP32 system to measure input signals and relay to drone with RF24 modules.
- Utilize 74HC4051 ICs for breaking out signals, allowing for multiple expansion ports in the controller.
- Design and print controller body that allows for easy battery replacement and management, as well as easy access to controller ports for software updates. hook up GPIO_0 for easy boot access, as well as EN pin for reboots.

### Flight Software
- Use ElectronJS, ReactJS, and Victory Charts to create real-time telemetry for use on a desktop system.
- Build a Wifi-based connectivity system to relay information from drone to controller, package information, and then send asynchronously from controller to the host desktop system.
- Allow for multiple running systems and modes (sensing, graphs, console), as well as for reading data instead of only parsing from the drone. Further, use OpenGL and WebGL to render a 3D canvas view of the drone in flight.

