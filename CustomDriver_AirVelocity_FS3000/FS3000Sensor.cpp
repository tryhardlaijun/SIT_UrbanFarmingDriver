#include "FS3000Sensor.h"

FS3000Sensor::FS3000Sensor() {
    // Constructor can be empty if no initialization is needed here
}

bool FS3000Sensor::begin() {
    // Initialize the FS3000 sensor
    return sensor.begin();
}

float FS3000Sensor::readMetersPerSecond() {
    // Return the airspeed in meters per second
    return sensor.readMetersPerSecond();
}

float FS3000Sensor::readMilesPerHour() {
    // Return the airspeed in miles per hour
    return sensor.readMilesPerHour();
}

int FS3000Sensor::readRaw() {
    // Return the raw sensor reading
    return sensor.readRaw();
}

void FS3000Sensor::setRange(bool is1005){
    if(is1005)
    {
        sensor.setRange(AIRFLOW_RANGE_7_MPS);
    }
    else{
        sensor.setRange(AIRFLOW_RANGE_15_MPS);
    }
}
