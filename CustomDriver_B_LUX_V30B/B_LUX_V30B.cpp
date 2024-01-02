// LightSensor.cpp
#include "B_LUX_V30B.h"

LightSensor::LightSensor(uint8_t cEN, uint8_t scl, uint8_t sda) 
    : sensor(cEN, scl, sda) {
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


