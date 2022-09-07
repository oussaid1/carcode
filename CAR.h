#ifndef CAR_h
#define CAR_h
#include <Arduino.h>

class Car {
  public:
    int w1F ;
    int w1B;
    int w2F ;
    int w2B;
    bool obstracted ;
    int speedx;
    /////////Constructor////////
  public:  
  Car(int w1F, int w1B, int w2F, int w2B,int speedx, bool obstracted = false);
    void init() ;
    void drive();
    void stopDrive() ;
    void driveForward() ;
    void driveBackWards();
    void turnLeft();
    void turnRight() ;
    void accelerate();
    void slowDown();
};


#endif
