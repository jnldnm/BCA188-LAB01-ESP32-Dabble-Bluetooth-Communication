
/*
  Project: ESP32 Bluetooth Communication with Dabble
  Module: Terminal
  Library: DabbleESP32 by STEMpedia

  Functionality:
  1. Connects ESP32 to the Dabble mobile application.
  2. Receives messages from the Dabble Terminal.
  3. Displays received messages in Serial Monitor.
  4. Sends a response back to the Dabble Terminal.
*/

#define CUSTOM_SETTINGS
#define INCLUDE_TERMINAL_MODULE

#include <DabbleESP32.h>

// Stores the message received from the smartphone
String receivedMessage = "";

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);

  // Initialize Dabble Bluetooth communication
  Dabble.begin("ESP32_Dabble");

  Serial.println();
  Serial.println("================================");
  Serial.println("ESP32 Dabble Bluetooth System");
  Serial.println("================================");
  Serial.println("Bluetooth is ready.");
  Serial.println("Open Dabble and connect to ESP32_Dabble.");
}

void loop() {

  // Process incoming data from the Dabble application
  Dabble.processInput();

  // Check if a message is available in the Terminal
  if (Terminal.available()) {

    // Read the complete message
    receivedMessage = Terminal.readString();

    // Display the received message
    Serial.print("Received from phone: ");
    Serial.println(receivedMessage);

    // Send a response to the smartphone
    Terminal.println("ESP32: Message received - " + receivedMessage);

    Serial.println("Response sent to Dabble.");
  }

  // Short delay before the next loop iteration
  delay(100);
}
