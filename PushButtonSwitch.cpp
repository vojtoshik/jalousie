#include <Arduino.h>

#include "PushButtonSwitch.h"
#include "debug.h"

PushButtonSwitch::PushButtonSwitch(char* switchName) {
    this->toggleSwitch = new ToggleSwitch(switchName);
}

void PushButtonSwitch::push(unsigned int timeInMs) {
    this->turnOffAfter = millis() + timeInMs;
    this->toggleSwitch->turnOn();
}

void PushButtonSwitch::release()  {
    this->toggleSwitch->turnOff();
}

void PushButtonSwitch::loop() {
    if (this->toggleSwitch->isOn() && millis() > this->turnOffAfter) {
        debug("It's time to release the button");
        this->toggleSwitch->turnOff();
    }
}
