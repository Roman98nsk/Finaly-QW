#include <AccelStepper.h>

AccelStepper Stepper1(1,3,2);

int dir = 1; 
int i = 0;

void setup() {
  delay(100);
  Stepper1.setMaxSpeed(2000);
  Stepper1.setAcceleration(500);
}

void loop() {
if(Stepper1.distanceToGo()==0) {
  Stepper1.move(1600*dir);
  dir = dir*(-1);
  delay(1000);
  i++;
}

if (i < 4) {
  Stepper1.run();
} 
}