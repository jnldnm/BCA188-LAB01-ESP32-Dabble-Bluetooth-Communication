# Laboratory Activity Answers

**Laboratory Activity:** Using ESP32 Bluetooth with Dabble App for IoT Communication

## Introduction

This document contains the answers and technical explanations for the laboratory activity on ESP32 Bluetooth communication using the Dabble application. The responses correspond to the ESP32 implementation using the STEMpedia `DabbleESP32` library and its Terminal module.

## 1. Activity Questions

### 1. What is the purpose of installing the Dabble library in Arduino IDE?

The Dabble library provides the functions needed for a microcontroller to communicate with the Dabble smartphone application. For the ESP32, the `DabbleESP32` library provides the Bluetooth Low Energy (BLE) communication interface and Terminal module functions.

### 2. What is the purpose of `BluetoothSerial.h`?

`BluetoothSerial.h` provides Bluetooth Classic Serial functionality on supported ESP32 chips. It is not required by the ESP32-specific Dabble BLE implementation used in this activity.

### 3. What is the purpose of `DabbleESP32.h`?

`DabbleESP32.h` includes the STEMpedia library interface for communication between an ESP32 and the Dabble application using BLE. It provides functions such as `Dabble.begin()`, `Dabble.processInput()`, and the selected module interface.

### 4. What is the purpose of `Dabble.begin("ESP32_Dabble")`?

It initializes Dabble communication on the ESP32 and sets the Bluetooth device name to `ESP32_Dabble`, allowing the board to be identified when connecting through the Dabble application.

### 5. Why is `Dabble.processInput()` called inside `loop()`?

It processes data received from the smartphone. Repeatedly calling it allows the program to handle incoming Dabble data while the main loop is running.

### 6. What is the purpose of `Terminal.available()`?

It checks whether new data is waiting in the Dabble Terminal receive queue before the program attempts to read a message.

### 7. What is the purpose of `Terminal.readString()`?

It reads the available Terminal data as a string. In this activity, the received message is stored and displayed in the Arduino Serial Monitor.

### 8. How does the ESP32 send a response to the smartphone?

The program uses `Terminal.println()` to send text to the Dabble Terminal. The function appends a newline to the transmitted message.

### 9. What is the purpose of the Arduino Serial Monitor?

The Arduino Serial Monitor displays diagnostic information and message output from the ESP32 through its USB serial connection. In this activity, it displays messages received from the smartphone and indicates when a response is sent.

### 10. What is the role of the Dabble Terminal module?

The Terminal module provides a text interface for sending data to the ESP32 and receiving data from it. It supports bidirectional text communication between the smartphone and the microcontroller.

## 2. Function Reference

| Function or directive | Purpose |
|---|---|
| `#define CUSTOM_SETTINGS` | Enables custom selection of Dabble modules. |
| `#define INCLUDE_TERMINAL_MODULE` | Includes the Terminal module. |
| `#include <DabbleESP32.h>` | Includes the ESP32-specific Dabble library. |
| `Serial.begin(115200)` | Starts serial communication at 115200 baud. |
| `Dabble.begin("ESP32_Dabble")` | Initializes Dabble BLE communication and sets the device name. |
| `Dabble.processInput()` | Processes incoming Dabble data. |
| `Terminal.available()` | Checks whether Terminal data is available. |
| `Terminal.readString()` | Reads available Terminal data as a string. |
| `Serial.println()` | Displays text in the Serial Monitor. |
| `Terminal.println()` | Sends text to the Dabble Terminal with a newline. |

## 3. Exercises and Additional Activities

### Exercise 1: ESP32-compatible Dabble library

The activity uses the `DabbleESP32` library by STEMpedia. This library provides the ESP32-specific interface for communicating with the Dabble application through BLE and accessing the Terminal module.

### Exercise 2: Bluetooth communication

The ESP32 initializes its Dabble connection using:

```cpp
Dabble.begin("ESP32_Dabble");
```

The configured device name is `ESP32_Dabble`. The Dabble application provides the smartphone interface for the BLE connection and Terminal communication.

### Exercise 3: Receiving and responding to a message

The following code checks for incoming Terminal data, reads the message, displays it in the Serial Monitor, and returns a response to the smartphone.

```cpp
if (Terminal.available()) {
  String receivedMessage = Terminal.readString();

  Serial.print("Received from phone: ");
  Serial.println(receivedMessage);

  Terminal.println("ESP32: Message received - " + receivedMessage);
}
```

## 4. Observations and Analysis

The program is designed to support the following communication sequence:

1. The ESP32 initializes its Dabble BLE connection using the configured device name.
2. The Dabble application connects to the ESP32.
3. A text message is sent through the Dabble Terminal.
4. The ESP32 receives the message and displays it in the Arduino Serial Monitor.
5. The ESP32 sends a response that appears in the Dabble Terminal.

For example, when the message `Hello ESP32` is received, the program is designed to display the following in the Serial Monitor:

```text
Received from phone: Hello ESP32
Response sent to Dabble.
```

The corresponding Dabble Terminal response is:

```text
ESP32: Message received - Hello ESP32
```

These outputs represent the program's expected behavior and are not presented as independently verified hardware test results.

## 5. Technical Note

The supplied sample combines `BluetoothSerial.h`, a `BluetoothSerial` object, and `Dabble.begin(ESP_BT)`. STEMpedia's ESP32 Terminal implementation instead uses the ESP32-specific header `DabbleESP32.h` and initializes communication with `Dabble.begin("Bluetooth_Name")`. It also defines `CUSTOM_SETTINGS` and `INCLUDE_TERMINAL_MODULE` to include the Terminal module.

The implementation represented in this submission follows the ESP32-specific Dabble interface rather than combining Bluetooth Classic Serial with the Dabble BLE interface.

## 6. References

1. STEMpedia, [Dabble Terminal Module](https://ai.thestempedia.com/docs/dabble-app/terminal-module/).
2. STEMpedia, [DabbleESP32 GitHub Repository](https://github.com/STEMpedia/DabbleESP32).
3. Espressif, [Arduino-ESP32 Documentation](https://docs.espressif.com/projects/arduino-esp32/en/latest/).
4. Arduino, [Arduino IDE](https://www.arduino.cc/en/software/).
