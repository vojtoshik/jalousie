#include <Arduino.h>

#include "JalousiePin.h"
#include "debug.h"

JalousiePin::JalousiePin() {}

JalousiePin::JalousiePin(long shortActivationMillis, long longActivationMillis) {
    init(shortActivationMillis, longActivationMillis);
}

void JalousiePin::init(unsigned int shortActivationMillis, unsigned int longActivationMillis) {
    this->shortActivationMillis = shortActivationMillis;
    this->longActivationMillis = longActivationMillis;
}

void JalousiePin::activatePin(unsigned int ms) {
    this->turnOffAfter = millis() + ms;

    debug("Got a command to activate pin for %d milliseconds", ms);

    if (!this->isOn) {
        debug("Pin is off, so activating it...");
        // here goes code to activate pin
        this->isOn = true;        
    }
}

void JalousiePin::activateShort() {
    this->activatePin(this->shortActivationMillis);
}

void JalousiePin::activateLong() {
    this->activatePin(this->longActivationMillis);
}

void JalousiePin::activate(unsigned int ms) {
    this->activatePin(ms);
}

void JalousiePin::deactivate() {
    debug("Pin deactivation called");
    this->turnOffAfter = 0;
    if (this->isOn) {
        debug("Pin is active, turning it off...");
        this->isOn = false;
        // here goes code to deactivate
    }
}

void JalousiePin::work() {
    if (this->isOn && millis() > this->turnOffAfter) {
        debug("It's time to turn off this pin");
        this->deactivate();
    }
}
