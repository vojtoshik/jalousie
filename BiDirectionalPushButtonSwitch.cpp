#include "BiDirectionalPushButtonSwitch.h"

BiDirectionalPushButtonSwitch::BiDirectionalPushButtonSwitch(char *switchName) {
    this->buttonUp = new PushButtonSwitch(switchName);
    this->buttonDown = new PushButtonSwitch(switchName);
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