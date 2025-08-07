#include "Motors.hpp"
#include <Arduino.h>

Motors::Motors(){
        pinMode(AIN1, OUTPUT); 
        pinMode(AIN2, OUTPUT);
        pinMode(BIN1, OUTPUT); 
        pinMode(BIN2, OUTPUT);
        pinMode(PWMA, OUTPUT); 
        pinMode(PWMB, OUTPUT);
        pinMode(STBY, OUTPUT);

        digitalWrite(STBY, HIGH); // PWMable motors
}

void Motors::moveForward(int pid = 0) {
    digitalWrite(AIN1, HIGH); digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, HIGH); digitalWrite(BIN2, LOW);
    analogWrite(PWMA, currspeedL - pid); analogWrite(PWMB, currspeedR + pid);
  }
  
  void Motors::slightLeft() {
    analogWrite(PWMA, 180); analogWrite(PWMB, 180);
    digitalWrite(AIN1, LOW); digitalWrite(AIN2, HIGH);
    digitalWrite(BIN1, HIGH); digitalWrite(BIN2, LOW);
  }
  
  void Motors::slightRight() {
    analogWrite(PWMA, 180); analogWrite(PWMB, 180);
    digitalWrite(AIN1, HIGH); digitalWrite(AIN2, LOW);
    digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  }
  
  void Motors::turnLeft() {
    digitalWrite(AIN1, HIGH); digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, LOW); digitalWrite(BIN4, HIGH);
    analogWrite(PWMA, currspeedL); analogWrite(PWMB, 25);
  }
  
  void Motors::turnRight() {
    digitalWrite(AIN1, LOW); digitalWrite(AIN2, HIGH);
    digitalWrite(BIN1, HIGH); digitalWrite(BIN2, LOW);
    analogWrite(PWMA, 25); analogWrite(PWMB, currspeedR);
  }
  
  void Motors::stopMotors() {
    digitalWrite(AIN1, LOW); digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, LOW); digitalWrite(BIN2, LOW);
    analogWrite(PWMA, 0); analogWrite(PWMB, 0);
  }

  