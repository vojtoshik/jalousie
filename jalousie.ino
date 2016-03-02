#define DEBUG_ENABLED 1

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include "wifi_credentials.h"

int pingCounter = 0;

void debug(char* debugString, ...);
void setupSerial();

void verifyWifiIsConnected();

void setup() {
  // initialize serial communications at 9600 bps
  setupSerial();
  verifyWifiIsConnected();
}

void loop() {
  verifyWifiIsConnected();
  Serial.printf("PING %d\n", pingCounter++);
  delay(1000);
}
