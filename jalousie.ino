#include <WebSocketsClient.h>

#include "config.h"
#include "debug.h"

#include "WiFiUtilities.h"
#include "JalousieSwitch.h"

WebSocketsClient webSocket;

JalousieSwitch leftJalousie("Left Jalousie");
JalousieSwitch rightJalousie("Right Jalousie");

void processCommand(char* command, size_t length) {
    if (strcmp("OPEN_ALL", command) == 0) {
        debug("Openning both jalousies");
        leftJalousie.open();
        rightJalousie.open();
    } else if (strcmp("CLOSE_ALL", command) == 0) {
        debug("Closing both jalousies");
        leftJalousie.close();
        rightJalousie.close();
    } else if (strcmp("OPEN_LEFT", command) == 0) {
        debug("Openning left jalousie");
        leftJalousie.open();
    } else if (strcmp("OPEN_RIGHT", command) == 0) {
        debug("Openning right jalousie");
        rightJalousie.open();
    } else if (strcmp("CLOSE_LEFT", command) == 0) {
        debug("Closing left jalousie");
        leftJalousie.close();
    } else if (strcmp("CLOSE_RIGHT", command) == 0) {
        debug("Closing right jalousie");
        rightJalousie.close();
    } else if (strcmp("NOOP", command) == 0) {
        debug("Turning off both jalousies");
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
