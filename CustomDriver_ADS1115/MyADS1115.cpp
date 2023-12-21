// MyADS1115.cpp
#include "MyADS1115.h"

MyADS1115::MyADS1115() : ads() {}

void MyADS1115::begin() {
    if (!ads.begin()) {
        Serial.println("Failed to initialize ADS.");
        while (1);
    }
      // ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
    ads.setGain(GAIN_ONE);
      // ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
      // ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
      // ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
      // ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV
}

float MyADS1115::readVoltage(int channel) {
    int16_t adcValue = ads.readADC_SingleEnded(channel);
    return computeVolts(adcValue);
}

float MyADS1115::computeVolts(int16_t adcValue) {
    return ads.computeVolts(adcValue);
}

