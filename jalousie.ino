#include <WebSocketsClient.h>

#include "config.h"
#include "debug.h"

#include "WiFiUtilities.h"
#include "JalousieSwitch.h"

WebSocketsClient webSocket;

JalousieSwitch leftJalousie(D7, D8, "Left Jalousie");
JalousieSwitch rightJalousie(D0, D1, "Right Jalousie");

void processCommand(char* command, size_t length) {
    if (strcmp("OPEN_ALL", command) == 0) {
        leftJalousie.open();
        rightJalousie.open();
    } else if (strcmp("CLOSE_ALL", command) == 0) {
        leftJalousie.close();
        rightJalousie.close();
    } else if (strcmp("OPEN_LEFT", command) == 0) {
        leftJalousie.open();
    } else if (strcmp("OPEN_RIGHT", command) == 0) {
        rightJalousie.open();
    } else if (strcmp("CLOSE_LEFT", command) == 0) {
        leftJalousie.close();
    } else if (strcmp("CLOSE_RIGHT", command) == 0) {
        rightJalousie.close();
    } else if (strcmp("LEFT_UP", command) == 0) {
        leftJalousie.up();
    } else if (strcmp("RIGHT_UP", command) == 0) {
        rightJalousie.up();
    } else if (strcmp("LEFT_DOWN", command) == 0) {
        leftJalousie.down();
    } else if (strcmp("RIGHT_DOWN", command) == 0) {
        rightJalousie.down();
    } else if (strcmp("NOOP", command) == 0) {
        leftJalousie.release();
        rightJalousie.release();
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
            debug("Connected to url: %s",    payload);
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
    
    leftJalousie.loop();
    rightJalousie.loop();
}
