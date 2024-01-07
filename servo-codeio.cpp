#include <Servo.h>

Servo leftMotor;
Servo rightMotor;

int leftMotorPin = 9;
int rightMotorPin = 10;

void setup() {
  Serial.begin(9600);
  
  leftMotor.attach(leftMotorPin);
  rightMotor.attach(rightMotorPin);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == 'F') {
      moveForward();
    } else if (command == 'B') {
      moveBackward();
    } else if (command == 'L') {
      turnLeft();
    } else if (command == 'R') {
      turnRight();
    } else if (command == 'S') {
      stopCar();
    }
  }
}

void moveForward() {
  leftMotor.writeMicroseconds(1700);
  rightMotor.writeMicroseconds(1300);
}

void moveBackward() {
  leftMotor.writeMicroseconds(1300);
  rightMotor.writeMicroseconds(1700);
}

void turnLeft() {
  leftMotor.writeMicroseconds(1300);
  rightMotor.writeMicroseconds(1300);
}

void turnRight() {
  leftMotor.writeMicroseconds(1700);
  rightMotor.writeMicroseconds(1700);
}

void stopCar() {
  leftMotor.writeMicroseconds(1500);
  rightMotor.writeMicroseconds(1500);
}
