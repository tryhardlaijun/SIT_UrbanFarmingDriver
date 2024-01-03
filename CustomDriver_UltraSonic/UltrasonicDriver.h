// UltrasonicSensor.h
#ifndef UltrasonicDriver
#define UltrasonicDriver

class UltrasonicSensor {
public:
    UltrasonicSensor(int trigPin, int echoPin);
    void begin();
    float readDistance();

private:
    const int trigPin;
    const int echoPin;
    const float speedOfSound = 343.0; // Speed of sound in m/s
};

#endif // ULTRASONIC_SENSOR_H

