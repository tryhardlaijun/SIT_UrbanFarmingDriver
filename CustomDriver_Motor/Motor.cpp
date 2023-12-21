#include "Motor.h"

Motor::Motor(int pwmPin, int dirPin, int pwmChannel, int freq, int resolution) {
    this->pwmPin = pwmPin;
    this->dirPin = dirPin;
    this->pwmChannel = pwmChannel;
    this->freq = freq;
    this->resolution = resolution;
    this->highest = (1 << resolution) - 1; 

}

void Motor::setup(){
    ledcSetup(this->pwmChannel, this->freq, this->resolution);
    ledcAttachPin(this->pwmPin, this->pwmChannel);
}
void Motor::runMotor(bool direction, float pwmPercentage) {
    int dutyCycle = pwmPercentage * this->highest;
    digitalWrite(this->dirPin, direction);
    ledcWrite(this->pwmChannel, dutyCycle);
}

void Motor::stopMotor() {
    ledcWrite(this->pwmChannel, 0);
}

