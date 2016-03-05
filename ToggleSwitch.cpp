#include "ToggleSwitch.h"
#include "debug.h"


ToggleSwitch::ToggleSwitch(char* switchName) {
    name = switchName;
}

void ToggleSwitch::turnOn() {
    if (!this->isTurnedOn) {
        debug("Switch %s: turning on", name);
        // TODO: here goes code which actually turns power on
        this->isTurnedOn = true;
    }
}

void ToggleSwitch::turnOff() {
    if (this->isTurnedOn) {
        debug("Switch %s: turning off", name);
        //TODO: here goes code which actually turns power off
        this->isTurnedOn = false;
    }
}

bool ToggleSwitch::isOn() {
    return this->isTurnedOn;
}

char* ToggleSwitch::getName() {
    return name;
}

