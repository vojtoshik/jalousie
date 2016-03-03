#include "debug.h"
#include "Arduino.h"

#define DEBUG_ENABLED 1

#ifdef DEBUG_ENABLED
#include <stdarg.h>
#define SERIAL_COMMUNICATION_SPEED 9600 // bits per second
#endif

void setupSerial() {
#ifdef DEBUG_ENABLED
  Serial.begin(SERIAL_COMMUNICATION_SPEED);
  while (!Serial) {
    delay(10);
  }
#endif
}

void debug(char* debugString, ...) {
#ifdef DEBUG_ENABLED
  char buffer[200];
  va_list args;
  va_start(args, debugString);
  vsnprintf(buffer, 200, debugString, args);
  Serial.println(buffer);
  va_end(args);
#endif
}
