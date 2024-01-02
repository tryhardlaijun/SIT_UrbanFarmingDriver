// LightSensor.h
#ifndef B_LUX_V30B
#define B_LUX_V30B

#include <Arduino.h>
#include <Wire.h>
#include <DFRobot_B_LUX_V30B.h>

class LightSensor {
    public:
        LightSensor(uint8_t cEN, uint8_t scl = SCL, uint8_t sda = SDA);

        void begin();
        float readLux();

    private:
        DFRobot_B_LUX_V30B sensor;
};

#endif

