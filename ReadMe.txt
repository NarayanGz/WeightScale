# Fake Weight Scale Simulator ⚖️

**⚠️ WARNING: This project is strictly for educational purposes only.**

**Credit / GitHub:** [NarayanGz](https://github.com/NarayanGz)

## 📖 Description
The Fake Weight Scale Simulator is an Arduino Nano-based hardware project designed to mimic an industrial digital weighing machine. It sends predefined, realistic weight data (e.g., `+020.000 Kg`) continuously over Serial to a connected Android app via a USB OTG cable. The system uses three physical push buttons to secretly cycle through low, medium, and high weight ranges instantly.

## 🛠️ Hardware Requirements
*   **Microcontroller:** Arduino Nano (ATmega328P / CH340 version)
*   **Inputs:** 3x Tactile Push Buttons
*   **Interface:** USB OTG Adapter (to connect the Arduino directly to an Android smartphone)
*   **Receiver:** Android Smartphone running a Serial listener app (or any USB Serial Terminal)
*   **Wiring:** Jumper wires and a breadboard (or perfboard for a permanent build)

## 🔌 Pinout & Wiring Guide
This project leverages the Arduino's internal pull-up resistors (`INPUT_PULLUP`). This means you do not need any external resistors or 5V power wires. Each button simply acts as a switch between the digital pin and Ground.

| Component | Arduino Pin | Connect To |
| :--- | :--- | :--- |
| **Button 1 (Low Weights)** | D2 | GND |
| **Button 2 (Mid Weights)** | D3 | GND |
| **Button 3 (High Weights)** | D4 | GND |

## 🚀 Features
*   **Continuous Broadcasting:** Shoots the current weight string over Serial every 160ms, perfectly matching the data refresh rate of a real digital scale.
*   **Lightning-Fast Polling:** Uses a 50ms `millis()` cooldown timer for rapid-fire button clicking with zero hardware debounce glitches.
*   **True Plug-and-Play:** Powered entirely by the Android phone's battery via the OTG connection. No external power supply or background PC software required.

## 📜 Usage Instructions
1. Upload the `FakeScaleArduino.cpp` sketch to your Arduino Nano.
2. Wire the three push buttons according to the pinout guide.
3. Plug the Arduino into your Android phone using a USB OTG adapter.
4. Open your Serial listener app set to a `9600` baud rate.
5. Use the buttons to cycle through the fake weight arrays dynamically.
