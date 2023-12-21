// AS7341Sensor.cpp
#include "AS7341Sensor.h"

AS7341Sensor::AS7341Sensor() {

}

bool AS7341Sensor::begin() {
  int retryCount = 0;
  while (as7341.begin() != 0) {
    Serial.println("IIC init failed, retrying...");
    delay(1000);
    if (++retryCount >= 5) {
      Serial.println("Failed to initialize after 5 retries.");
      return false;
    }
  }
  return true;
}

void AS7341Sensor::readSpectralData(float data[10]) { // Adjusted for 10 channels
    DFRobot_AS7341::sModeOneData_t data1;
    DFRobot_AS7341::sModeTwoData_t data2;

    as7341.startMeasure(as7341.eF1F4ClearNIR);
    data1 = as7341.readSpectralDataOne();

    as7341.startMeasure(as7341.eF5F8ClearNIR);
    data2 = as7341.readSpectralDataTwo();

    data[0] = data1.ADF1;
    data[1] = data1.ADF2;
    data[2] = data1.ADF3;
    data[3] = data1.ADF4;
    data[4] = data2.ADF5;
    data[5] = data2.ADF6;
    data[6] = data2.ADF7;
    data[7] = data2.ADF8;
    data[8] = data2.ADCLEAR; // Clear channel
    data[9] = data2.ADNIR;   // NIR channel
}

int  AS7341Sensor::readFlickerData(){
    return as7341.readFlickerData();
}
