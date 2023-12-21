#include "SCD4xSensor.h"

SCD4xSensor::SCD4xSensor() : co2(0), temperature(0), humidity(0) {}

bool SCD4xSensor::begin() {
    Wire.begin();
    return mySensor.begin();
}

bool SCD4xSensor::readData() {
    mySensor.measureSingleShot();
    if (mySensor.readMeasurement()) {
        co2 = mySensor.getCO2();
        temperature = mySensor.getTemperature();
        humidity = mySensor.getHumidity();
        return true;
    }
    return false;
}

float SCD4xSensor::getCO2() const {
    return co2;
}

float SCD4xSensor::getTemperature() const {
    return temperature;
}

float SCD4xSensor::getHumidity() const {
    return humidity;
}

void SCD4xSensor::setTemperatureOffset(float offset) {
    changeSensorSetting([&]() { mySensor.setTemperatureOffset(offset); });
}

void SCD4xSensor::setSensorAltitude(uint16_t altitude) {
    changeSensorSetting([&]() { mySensor.setSensorAltitude(altitude); });
}

void SCD4xSensor::setAmbientPressure(uint32_t pressure) {
    changeSensorSetting([&]() { mySensor.setAmbientPressure(pressure); });
}

void SCD4xSensor::persistSettings() {
    mySensor.persistSettings();
}

void SCD4xSensor::changeSensorSetting(const std::function<void()>& settingFunc) {
    stopPeriodicMeasurement();
    settingFunc();
    startPeriodicMeasurement();
}

void SCD4xSensor::stopPeriodicMeasurement() {
    mySensor.stopPeriodicMeasurement();
}

void SCD4xSensor::startPeriodicMeasurement() {
    mySensor.startPeriodicMeasurement();
}

template <typename T>
T SCD4xSensor::readSensorSetting(const std::function<T()>& readFunc) {
    stopPeriodicMeasurement();
    T value = readFunc();
    startPeriodicMeasurement();
    return value;
}

float SCD4xSensor::getTemperatureOffset() {
    return readSensorSetting<float>([&]() { return mySensor.getTemperatureOffset(); });
}

uint16_t SCD4xSensor::getSensorAltitude() {
    return readSensorSetting<uint16_t>([&]() { return mySensor.getSensorAltitude(); });
}
