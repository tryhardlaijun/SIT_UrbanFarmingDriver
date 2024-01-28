// LightSensor.cpp
#include "B_LUX_V30B.h"

LightSensor::LightSensor(uint8_t scl, uint8_t sda) 
    // first parameter is option, 0 is meaningless
    : sensor(0, scl, sda) {
    // Constructor implementation
}

void LightSensor::begin() {
    // Initialization code
    sensor.begin();
}

float LightSensor::readLux() {
    // Code to get the intensity of light
    return sensor.lightStrengthLux();
}


