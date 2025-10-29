# Advanced Programming Assignment – Smart Home Device Simulator

This repository contains a C++ console application for simulating smart home devices which was apart of my Advanced Programming Module at university. The program allows users to manage and interact with multiple device types, including speakers, lights, thermostats, radiator valves, sockets, and temperature/humidity sensors.

---

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Installation](#installation) 
---

## Overview
The project is designed to demonstrate object-oriented programming concepts such as inheritance, polymorphism, and dynamic memory management. Users can interact with different devices, perform quick actions, set schedules, and save/load device states from a text file.

The program is menu-driven and provides a clear interface to:
- View all devices.
- Sort devices by name or type.
- Interact with each device's full feature set.
- Add new devices.
- Save and load device data.

---

## Features
- **Speaker**: Turn on/off, change volume, quick view, rename, delete.
- **Heating Thermostat**: Turn on/off, set temperature, schedule, heating boost, quick view, rename, delete.
- **Radiator Valve**: Turn on/off, set temperature, schedule, quick view, rename, delete.
- **Light**: Turn on/off, change brightness, sleep timer, quick view, rename, delete.
- **Temperature & Humidity Sensor**: View current and historical data, rename, delete.
- **Sorting**: Devices can be sorted by name or type.
- **Persistence**: Device data is saved to `data.txt` and loaded automatically on program start.

---

## Installation
1. Clone this repository:
   ```bash
   git clone https://github.com/<your-username>/AdvancedProgrammingAssignment.git
