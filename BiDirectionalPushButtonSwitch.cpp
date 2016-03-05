#include "BiDirectionalPushButtonSwitch.h"

BiDirectionalPushButtonSwitch::BiDirectionalPushButtonSwitch(int pinUpId, int pinDownId, char *switchName) {
    this->buttonUp = new PushButtonSwitch(pinUpId, switchName);
    this->buttonDown = new PushButtonSwitch(pinDownId, switchName);
}

void BiDirectionalPushButtonSwitch::pushDown(unsigned int timeInMs) {
    this->buttonUp->release();
    this->buttonDown->push(timeInMs);
}

void BiDirectionalPushButtonSwitch::pushUp(unsigned int timeInMs) {
    this->buttonDown->release();
    this->buttonUp->push(timeInMs);
}

void BiDirectionalPushButtonSwitch::release() {
    this->buttonUp->release();
    this->buttonDown->release();
}

void BiDirectionalPushButtonSwitch::loop() {
    this->buttonUp->loop();
    this->buttonDown->loop();
}
