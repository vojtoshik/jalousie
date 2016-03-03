#include "WiFiUtilities.h"

#include <ESP8266WiFi.h>

#include "debug.h"
#include "config.h"

bool connectionInitialized = false;

void verifyWifiIsConnected() {

  if (!connectionInitialized) {
    debug("Initializing WiFi connection to \"%s\" using \"%s\" as a password", WIFI_SSID, WIFI_PASSWORD);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    connectionInitialized = true;
  }

  int status = WiFi.status();
  boolean wasInterrupted = status != WL_CONNECTED;

  while (status != WL_CONNECTED) {
    debug("WiFi connection is down. Status: %d", status);
    status = WiFi.status();
    delay(2000);
  }

  if (wasInterrupted) {
    debug("WiFi connection is up!");
    debug("===== Connection Info =====");
    debug("SSID: %s", WiFi.SSID().c_str());
    IPAddress ip = WiFi.localIP();
    debug("IP: %d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
    debug("===========================");
  }
}
