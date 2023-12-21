#ifndef MOTOR_H
#define MOTOR_H
#include <M5StickCPlus.h>

class Motor {
  private:
    int pwmChannel;
    int freq;
    int resolution;
    int highest;

  public:
    int pwmPin;
    int dirPin;
    Motor(int pwmPin, int dirPin, int pwmChannel, int freq = 16000, int resolution = 8);
    void runMotor(bool direction, float pwmPercentage);
    void stopMotor();
    void setup();
};

#endif // MOTOR_H

