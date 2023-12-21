#ifndef SCD4XSENSOR_H
#define SCD4XSENSOR_H

#include <Arduino.h>
#include <Wire.h>
#include "SparkFun_SCD4x_Arduino_Library.h"

class SCD4xSensor {
public:
    SCD4xSensor();
    bool begin();
    bool readData();
    float getCO2() const; // Keep const here
    float getTemperature() const; // Keep const here
    float getHumidity() const; // Keep const here
    void setTemperatureOffset(float offset);
    void setSensorAltitude(uint16_t altitude);
    void setAmbientPressure(uint32_t pressure);
    void persistSettings();
    float getTemperatureOffset();
    uint16_t getSensorAltitude();

private:
    SCD4x mySensor;
    float co2, temperature, humidity;
    void stopPeriodicMeasurement();
    void startPeriodicMeasurement();
    void changeSensorSetting(const std::function<void()>& settingFunc);
    template <typename T>
    T readSensorSetting(const std::function<T()>& readFunc);

};

#endif // SCD4XSENSOR_H

