#ifndef JALOUSIE_PIN_H
#define JALOUSIE_PIN_H

class JalousiePin {
private:
    bool isOn = false;
    long long turnOffAfter = 0;

    unsigned int shortActivationMillis = 500;
    unsigned int longActivationMillis  = 10000;

    void init(unsigned int shortActivationMillis, unsigned int longActivationMillis);
    void activatePin(unsigned int ms);

    void deactivate();
public:
    JalousiePin(long shortActivationMillis, long longActivationMillis);
    JalousiePin();

    void activateShort();
    void activateLong();
    void activate(unsigned int ms);

    void work();
};

#endif
