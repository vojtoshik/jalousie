#ifndef PUSH_BUTTON_SWITCH_H
#define PUSH_BUTTON_SWITCH_H

#include "ToggleSwitch.h"

class PushButtonSwitch {
private:

    ToggleSwitch* toggleSwitch;

    long long turnOffAfter = 0;

    unsigned int shortPushTime = 500;
    unsigned int longPushTime  = 10000;

    void init(char* switchName, unsigned int shortPushTime, unsigned int longPushTime);
public:
    PushButtonSwitch(char* switchName, long shortPushTime, long longPushTime);
    PushButtonSwitch(char* switchName);

    void push(unsigned int ms);

    void shortPush();
    void longPush();

    void release();

    void loop();
};

#endif
