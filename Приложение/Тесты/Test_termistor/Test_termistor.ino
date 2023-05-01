#include <GyverNTC.h>

float filT = 0;
GyverNTC therm(0, 10000, 3950);

void setup() {
  Serial.begin(9600);
}

void loop() {
  //фильтр от 0.1 до 1.0 для точных показаний
  filT += (therm.getTemp() - filT) * 0.5;
  Serial.println(filT);
}