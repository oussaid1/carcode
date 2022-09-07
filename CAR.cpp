
#include "CAR.h"

Car::Car(int w1Fv, int w1Bv, int w2Fv, int w2Bv,int speedxv, bool obstractedv = false) {
      w1F = w1Fv;
      w1B = w1Bv;
      w2F = w2Fv;
      w2B = w2Bv;
      obstracted = obstractedv;
      speedx = speedxv; 
      init();
    }

void Car::init() {
      Serial.println("Car Initialized");
      Serial.println("W1F =");
      Serial.println(w1F);
      Serial.println("W1B =");
      Serial.println(w1B);
      Serial.println("W2F =");
      Serial.println(w2F);
      Serial.println("W2B =");
      Serial.println(w2B);
      Serial.println("Obstracted =");
      Serial.println(obstracted);
      Serial.println("speedx =");
      Serial.println(speedx);
  ////////////////////
  pinMode(w1F, OUTPUT);
  pinMode(w1B, OUTPUT);
  /////////////////////
  pinMode(w2F, OUTPUT);
  pinMode(w2B, OUTPUT);
      }
    
    ////////
void Car::drive() {
   Serial.println("Driving.....!");
    Serial.println(speedx);
     if(obstracted){
    Serial.println("car obstracted");
   stopDrive();
   slowDown();  
   delay(500);
    driveBackWards();
     delay(200);
     turnLeft();
     delay(500);
     turnRight();
     delay(500);
     
   
  }else{
     Serial.println("car clear");
    driveForward();
  }
      
      
}
 // drive forward ///////////////
void Car:: driveForward() {
      analogWrite(w1F, speedx);
      analogWrite(w1B, 0);
      ///////////////////
      analogWrite(w2F, speedx);
      analogWrite(w2B, 0);
    }
//////drive Backwards///////////////////
void Car:: driveBackWards() {
      analogWrite(w1F, 0);
      analogWrite(w1B, speedx);
      ///////////////////
      analogWrite(w2F, 0);
      analogWrite(w2B, speedx);
    }
///// stop drive //////////////////////
void Car:: stopDrive() {
      analogWrite(w1F, 0);
      analogWrite(w1B, 0);
      ///////////////////
      analogWrite(w2F, 0);
      analogWrite(w2B, 0);
    }
///////////turn left /////////////////////
void Car:: turnLeft() {
      stopDrive();
      delay(500);
      analogWrite(w1F, 0);
      analogWrite(w1B, speedx);
      ////
      analogWrite(w2F, 0);
      analogWrite(w2B, 0);
      delay(500);
      stopDrive();
    }

////// turn right ////////////
void Car:: turnRight() {
      stopDrive();
      delay(500);
      analogWrite(w1F, 0);
      analogWrite(w1B, 0);
      ////
      analogWrite(w2F, 0);
      analogWrite(w2B, speedx);
      delay(500);
      stopDrive();
    }
//////// accelerate ///
void Car:: accelerate() {
  for(int i=speedx;i<255;i++){
     speedx+i;
  }
     
    }
//////// slow ///
void Car:: slowDown() {
      for(int i=speedx;i>0;i--){
     speedx+i;
  }
    }


    
