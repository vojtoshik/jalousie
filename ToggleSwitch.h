#ifndef TOGGLE_SWITCH_H
#define TOGGLE_SWITCH_H

class ToggleSwitch {
private:
    bool isTurnedOn = false;
    char* name;

    int pinId;
public:
    ToggleSwitch(int pinId, char* switchName);

    void turnOn();
    void turnOff();

    bool isOn();

    char* getName();
};

#endif
