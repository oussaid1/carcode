#include <Servo.h>
#include "CAR.h"
#include "LED.h"
Servo myservo;
int servoPin = 12;
LED led1(2);
//////////////wheels pins//////////////////
int w1F = 5, w1B = 6, w2F = 3, w2B = 11;
//////////////////
int driveDirection = 2;
int pos = 0;
int speedv = 110;
int echoPin = 8;
int trigPin = 9;
long duration = 0;
int distance;
int proximity = 0;
///////////
bool shouldDrive = true;
////////
bool obstracted =  false;
//////////////////
int IRSensor = 10;
int LED = 4;
int BEEPER = 13;

Car car1(
  w1F,
  w1B,
  w2F,
  w2B,
  speedv,
  obstracted);
//////////////////////////////
///////////////////////////////
//////////////////////////////
void setup() {
  // attaches the servo on pin 9 to the servo object
  myservo.attach(servoPin);
  //// ultrasonic////
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  //////////
  //car1.init();
  car1.speedx = speedv;
  /////////////
  pinMode(IRSensor, INPUT); // IR Sensor pin INPUT
  pinMode(LED, OUTPUT); // LED Pin Output
  pinMode(BEEPER, OUTPUT); // BEEPER Pin Output

}




///////////////////////////////////////////
//////////////////////////////////////////
void loop() {

  readDistance();
  //readMotion();
  //////////////////
  car1.drive();


}



























/// Servo ///
// sweep Left
void sweepLR() {
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    delay(15);
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }
}
void sweepLeft() {
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    delay(15);
  }
}
// sweep Left
void sweepRight() {
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }
}


//////////////Ultrasonic///
void  readDistance() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if (distance < 30) {
    obstracted=true;
    digitalWrite(BEEPER, HIGH);
    car1.obstracted = true;
  } else {
      obstracted=false;
      digitalWrite(BEEPER, LOW);
    car1.obstracted = false;
  }
//  if (obstracted) {
//    digitalWrite(BEEPER, HIGH);
//    delay(distance * 100);
//    digitalWrite(BEEPER, LOW);
//    delay(distance * 100);
//  }
}

void readMotion() {
  int sensorStatus = digitalRead(IRSensor); // Set the GPIO as Input
  if (sensorStatus == 1) // Check if the pin high or not
  {
    // if the pin is high turn off the onboard Led
    digitalWrite(LED, HIGH); // LED LOW
    Serial.println("Obstacl Detected!"); // print Motion Detected! on the serial monitor window
    car1.obstracted = true;
    //car1.speedx=0;

  }
  else  {
    //else turn on the onboard LED
    digitalWrite(LED, LOW); // LED High
    Serial.println("Clear!"); // print Motion Ended! on the serial monitor window
    car1.obstracted = false;
    // car1.speedx=140;

  }
}
