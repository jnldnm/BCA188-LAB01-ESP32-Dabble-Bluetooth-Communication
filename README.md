# Using ESP32 Bluetooth with Dabble App for IoT Communication

## Introduction

This laboratory activity demonstrates wireless communication between an ESP32 development board and a smartphone through the Dabble application. Using the Dabble Terminal module and the STEMpedia `DabbleESP32` library, the ESP32 receives text messages from the smartphone, displays them in the Arduino Serial Monitor, and sends responses back to the application.

## Project Overview

The implementation uses the ESP32's built-in Bluetooth Low Energy (BLE) capability. The program initializes Dabble under the device name `ESP32_Dabble`, processes incoming data, and supports two-way text communication through the Terminal module.

The implementation uses `DabbleESP32.h` and `Dabble.begin("ESP32_Dabble")`, following the ESP32-specific Dabble interface.

## Main Components

| Component | Purpose |
|---|---|
| ESP32 development board | Microcontroller and Bluetooth communication device |
| Smartphone with Dabble | Sends and receives Terminal messages |
| Arduino IDE | Development environment for the ESP32 program |
| DabbleESP32 library | Provides the Dabble BLE and Terminal functionality |

## Program Summary

The program initializes serial communication at 115200 baud and establishes the Dabble connection. During operation, `Dabble.processInput()` handles incoming application data. When a Terminal message is available, the ESP32 reads it, displays it in the Serial Monitor, and returns a response through `Terminal.println()`.

## Conclusion

The activity demonstrates the use of Bluetooth Low Energy for communication between an ESP32 and a mobile application. Through the Dabble Terminal module, the project illustrates how a microcontroller can receive, process, and respond to text messages wirelessly.

## References

1. STEMpedia, [Dabble Terminal Module](https://ai.thestempedia.com/docs/dabble-app/terminal-module/).
2. STEMpedia, [DabbleESP32 GitHub Repository](https://github.com/STEMpedia/DabbleESP32).
3. Espressif, [Arduino-ESP32 Documentation](https://docs.espressif.com/projects/arduino-esp32/en/latest/).
4. Arduino, [Arduino IDE](https://www.arduino.cc/en/software/).

See [ACTIVITY-ANSWERS.md](ACTIVITY-ANSWERS.md) for the laboratory questions and answers.
