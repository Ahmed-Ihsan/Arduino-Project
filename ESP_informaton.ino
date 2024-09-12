#include <WiFi.h>

void setup() {
  Serial.begin(115200);

  // Get MAC Address
  String macAddress = WiFi.macAddress();
  Serial.print("MAC Address: ");
  Serial.println(macAddress);

  // Get Chip ID
  uint64_t chipid = ESP.getEfuseMac(); // The chip ID is essentially the MAC address
  Serial.print("Chip ID: ");
  Serial.println((uint16_t)(chipid >> 32), HEX);
  Serial.println((uint32_t)chipid, HEX);

  // Get Flash Chip Size
  Serial.print("Flash Chip Size: ");
  Serial.print(ESP.getFlashChipSize() / (1024 * 1024));
  Serial.println(" MB");

  // Get Flash Chip Speed
  Serial.print("Flash Chip Speed: ");
  Serial.print(ESP.getFlashChipSpeed() / 1000000);
  Serial.println(" MHz");

  // Get CPU Frequency
  Serial.print("CPU Frequency: ");
  Serial.print(ESP.getCpuFreqMHz());
  Serial.println(" MHz");

  // Get SDK Version
  Serial.print("SDK Version: ");
  Serial.println(ESP.getSdkVersion());

  // Get Free Heap Size
  Serial.print("Free Heap Size: ");
  Serial.print(ESP.getFreeHeap() / 1024);
  Serial.println(" KB");

  // Get Sketch Size
  Serial.print("Sketch Size: ");
  Serial.print(ESP.getSketchSize() / 1024);
  Serial.println(" KB");

  // Get Free Sketch Space
  Serial.print("Free Sketch Space: ");
  Serial.print(ESP.getFreeSketchSpace() / 1024);
  Serial.println(" KB");

  // Get Chip Revision
  Serial.print("Chip Revision: ");
  Serial.println(ESP.getChipRevision());

  // Get Hall Sensor Value
  int hallValue = hallRead();
  Serial.print("Hall Sensor Value: ");
  Serial.println(hallValue);

  // Get Temperature Sensor Value (if available)
  // Note: ESP32 does not have a built-in temperature sensor accessible via Arduino framework
  // You would need an external sensor for accurate temperature readings
}

void loop() {
  // put your main code here, to run repeatedly:
}
