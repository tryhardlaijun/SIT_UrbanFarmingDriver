// AS7341Sensor.h
#ifndef AS7341SENSOR_H
#define AS7341SENSOR_H

#include <Arduino.h>
#include <DFRobot_AS7341.h>

class AS7341Sensor {
public:
    AS7341Sensor();
    bool begin();
    void readSpectralData(float data[10]); // Adjusted for 10 channels
    int readFlickerData();
private:
    DFRobot_AS7341 as7341;
};

#endif // AS7341SENSOR_H

