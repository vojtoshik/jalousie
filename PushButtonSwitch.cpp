#include <Arduino.h>

#include "PushButtonSwitch.h"
#include "debug.h"

PushButtonSwitch::PushButtonSwitch(char* switchName) {
    init(switchName, this->shortPushTime, this->longPushTime);
}

PushButtonSwitch::PushButtonSwitch(char* switchName, long shortPushTime, long longPushTime) {
    init(switchName, shortPushTime, longPushTime);
}

void PushButtonSwitch::init(char* switchName, unsigned int shortPushTime, unsigned int longPushTime) {

    this->toggleSwitch = new ToggleSwitch(switchName);

    this->shortPushTime = shortPushTime;
    this->longPushTime = longPushTime;
}

void PushButtonSwitch::push(unsigned int timeInMs) {
    this->turnOffAfter = millis() + timeInMs;
    this->toggleSwitch->turnOn();
}

void PushButtonSwitch::shortPush() {
    this->push(this->shortPushTime);
}

void PushButtonSwitch::longPush() {
    this->push(this->longPushTime);
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
