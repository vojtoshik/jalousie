#ifndef JALOUSIE_SWITCH_H
#define JALOUSIE_SWITCH_H

#include "BiDirectionalPushButtonSwitch.h"

class JalousieSwitch : public BiDirectionalPushButtonSwitch {
private:
    const unsigned int FULL_WAY_DURATION = 5000;
    const unsigned int SHORT_PUSH_DURATION = 500;

public:
    JalousieSwitch(int pinUpId, int pinDownId, char* switchName);

    void open();
    void close();

    void up();
    void down();
};

#endif
