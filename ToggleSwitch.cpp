#include "ToggleSwitch.h"

#include <Arduino.h>

#include "debug.h"

ToggleSwitch::ToggleSwitch(int pinId, char* switchName) {
    name = switchName;
    this->pinId = pinId;

    pinMode(pinId, OUTPUT);
}

void ToggleSwitch::turnOn() {
    if (!this->isTurnedOn) {
        debug("[ %s ]: turning on", name);
        digitalWrite(pinId, HIGH);
        this->isTurnedOn = true;
    }
}

void ToggleSwitch::turnOff() {
    if (this->isTurnedOn) {
        debug("[ %s ]: turning off", name);
        digitalWrite(pinId, LOW);
        this->isTurnedOn = false;
    }
}

bool ToggleSwitch::isOn() {
    return this->isTurnedOn;
}

char* ToggleSwitch::getName() {
    return name;
}

