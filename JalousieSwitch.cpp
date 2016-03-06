#include "JalousieSwitch.h"

JalousieSwitch::JalousieSwitch(int pinUpId, int pinDownId, char *switchName)
        : BiDirectionalPushButtonSwitch(pinUpId, pinDownId, switchName) {

}

void JalousieSwitch::open() {
    this->pushUp(this->FULL_WAY_DURATION);
}

void JalousieSwitch::close() {
    this->pushDown(this->FULL_WAY_DURATION);
}

void JalousieSwitch::up() {
    this->pushUp(this->SHORT_PUSH_DURATION);
}

void JalousieSwitch::down() {
    this->pushDown(this->SHORT_PUSH_DURATION);
}
