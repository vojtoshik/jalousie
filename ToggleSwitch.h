#ifndef TOGGLE_SWITCH_H
#define TOGGLE_SWITCH_H

class ToggleSwitch {
private:
    bool isTurnedOn = false;
    char* name;
public:
    ToggleSwitch(char* switchName);

    void turnOn();
    void turnOff();

    bool isOn();

    char* getName();
};

#endif
