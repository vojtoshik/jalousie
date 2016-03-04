#include "JalousieSwitch.h"

JalousieSwitch::JalousieSwitch(char *switchName) {
    this->jalousieSwitch = new BiDirectionalPushButtonSwitch(switchName);
}

void JalousieSwitch::open() {
    this->jalousieSwitch->pushUp(this->FULL_WAY_DURATION);
}

void JalousieSwitch::close() {
    this->jalousieSwitch->pushDown(this->FULL_WAY_DURATION);
}

void JalousieSwitch::up() {
    this->jalousieSwitch->pushUp(this->SHORT_PUSH_DURATION);
}

void JalousieSwitch::down() {
    this->jalousieSwitch->pushDown(this->SHORT_PUSH_DURATION);
}

void JalousieSwitch::release() {
    this->jalousieSwitch->release();
}

void JalousieSwitch::loop() {
    this->jalousieSwitch->loop();
}