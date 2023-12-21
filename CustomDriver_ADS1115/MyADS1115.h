// MyADS1115.h
#ifndef MY_ADS1115_H
#define MY_ADS1115_H

#include <Arduino.h>
#include <Adafruit_ADS1X15.h>

class MyADS1115 {
public:
    MyADS1115();
    void begin();
    float readVoltage(int channel);

private:
    Adafruit_ADS1115 ads;
    float computeVolts(int16_t adcValue);
};

#endif // MY_ADS1115_H

