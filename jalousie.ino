#define DEBUG_ENABLED 1

#include <ESP8266WiFi.h>
#include <WebSocketsClient.h>

#include "config.h"

void debug(char* debugString, ...);
void setupSerial();

void verifyWifiIsConnected();

WiFiClient wifiClient;
WebSocketsClient webSocket;

void processCommand(char* command, size_t length) {
  if (strcmp("OPEN_ALL", command) == 0) {
    debug("Openning both jalousies");
  } else {
    debug("Unknown command %s", command);
  }
}

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
  switch(type) {
    case WStype_DISCONNECTED:      
      debug("Disconnected from controlling server");
      delay(1000);
      break;
    case WStype_CONNECTED:
      debug("Connected to url: %s",  payload);
      break;
    case WStype_TEXT:
      debug("Got command from server: %s", payload);
      processCommand(reinterpret_cast<char*>(payload), length);
      break;
    case WStype_BIN:
      debug("Got binary data from server. Length: %u", length);
      hexdump(payload, length);
      break;
    default:
      debug("Got unexpected event type: %u", type);
      break; 
    }
}

void setup() {
  // initialize serial communications at 9600 bps
  setupSerial();
  verifyWifiIsConnected();

  webSocket.begin(COMMAND_PROVIDER_HOST, COMMAND_PROVIDER_PORT, COMMAND_PROVIDER_PATH, "");
  webSocket.onEvent(webSocketEvent);
}

void loop() {
  verifyWifiIsConnected();
  webSocket.loop();
}
