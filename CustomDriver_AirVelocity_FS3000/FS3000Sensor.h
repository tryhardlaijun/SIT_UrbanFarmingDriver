#ifndef FS3000_SENSOR_H
#define FS3000_SENSOR_H

#include <Arduino.h>
#include <Wire.h>
#include <SparkFun_FS3000_Arduino_Library.h>

class FS3000Sensor {
public:
    FS3000Sensor();
    bool begin();
    float readMetersPerSecond();
    float readMilesPerHour();
    int readRaw();
    void setRange(bool is1005);
private:
    FS3000 sensor;
};

#endif // FS3000_SENSOR_H

