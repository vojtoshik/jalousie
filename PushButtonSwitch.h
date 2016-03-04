#ifndef PUSH_BUTTON_SWITCH_H
#define PUSH_BUTTON_SWITCH_H

#include "ToggleSwitch.h"

class PushButtonSwitch {
private:

    ToggleSwitch* toggleSwitch;

    long long turnOffAfter = 0;
public:
    PushButtonSwitch(char* switchName);

    void push(unsigned int ms);
    void release();

    void loop();
};

#endif
