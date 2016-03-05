#ifndef BI_DIRECTIONAL_PUSH_BUTTON_SWITCH_H
#define BI_DIRECTIONAL_PUSH_BUTTON_SWITCH_H

#include "PushButtonSwitch.h"

class BiDirectionalPushButtonSwitch {
private:
    PushButtonSwitch* buttonUp;
    PushButtonSwitch* buttonDown;
public:
    BiDirectionalPushButtonSwitch(int pinUpId, int pinDownId, char* switchName);

    void pushUp(unsigned int timeInMs);
    void pushDown(unsigned int timeInMs);

    void release();
    void loop();
};

#endif
