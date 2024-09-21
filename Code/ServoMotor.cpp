#include "ServoMotor.h"

// Constructor
ServoMotor::ServoMotor() {
    feedbackPin = 0;    // feedback pin (change if needed)
    controlPin = 12;    // servo control pin (change if needed)
}

ServoMotor::startMotor() {

}

// Stop motor on the wheel from 1-6
// pos will be 0-5 rather than 1-6
ServoMotor::stopMotor(int pos) {

}




/*

int servopin = 13;
int pulse = 2500;
int feedbackPin = 0;


void setup()
{
  pinMode(servopin,OUTPUT);
  pinMode(feedbackPin,INPUT);
  Serial.begin(9600);
  
}

void loop()
{
  digitalWrite(servopin,HIGH);
  delayMicroseconds(pulse);
  digitalWrite(servopin,LOW);
  delay(20);
  int feedback = analogRead(feedbackPin);
  if(feedback < 150){
    delay(5000);
  }
  Serial.println(feedback);
}

*/
