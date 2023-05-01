#include <AccelStepper.h>
#define motorInterfaceType 1

const int DIR1 = 7;
const int STEP1 = 8;
const int DIR2 = 10;
const int STEP2 = 12;

AccelStepper myStepper1(motorInterfaceType, STEP1, DIR1);
AccelStepper myStepper2(motorInterfaceType, STEP2, DIR2);

void setup() {
  myStepper1.setMaxSpeed(1000);
  myStepper1.setAcceleration(700);
  myStepper1.setSpeed(1000);
  myStepper1.moveTo(50000);

  myStepper2.setMaxSpeed(1000);
  myStepper2.setAcceleration(700);
  myStepper2.setSpeed(1000);
  myStepper2.moveTo(50000);
}

void loop() {
    if (myStepper1.distanceToGo() == 0 && myStepper2.distanceToGo() == 0) {
    myStepper1.moveTo(-myStepper1.currentPosition());
    myStepper2.moveTo(-myStepper2.currentPosition());
  }
  myStepper1.run();
  myStepper2.run();
}