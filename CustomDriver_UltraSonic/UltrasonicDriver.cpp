#include "UltrasonicDriver.h"
#include "Arduino.h"

UltrasonicSensor::UltrasonicSensor(int trigPin, int echoPin)
: trigPin(trigPin), echoPin(echoPin) {}

void UltrasonicSensor::begin() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

float UltrasonicSensor::readDistance() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(15);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(40);
    digitalWrite(trigPin, LOW);

    float duration = pulseIn(echoPin, HIGH);
    return (duration * speedOfSound) / 20000.0; // Convert to distance
}

