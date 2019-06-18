#include <LinkedList.h>
#include <GaussianAverage.h>
#include <Gaussian.h>
const int xP = 2;
const int yP = 3;
float filteredax, filtereday;
GaussianAverage myAverage = GaussianAverage(30);
Gaussian mySavedAveragex;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(xP, INPUT);
  pinMode(yP, INPUT);
  
  myAverage = 0;
  filteredax = 0;
  filtereday = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  int px, py;
  int ax, ay;

  px = pulseIn(xP, HIGH);
  py = pulseIn(yP, HIGH);

  ax = ((px / 10) - 500) * 8;
  ay = ((py / 10) - 500) * 8;
  myAverage += ax;
  myAverage.process()
  /*filteredax = (filteredax * .8283) + (ax * .1717);
  filtereday = (filtereday * .8283) + (ay * .1717);*/
  Serial.print(ax);
  Serial.print("\t");
  Serial.print(mySavedAveragex);
  Serial.print("\t")
  /*Serial.print(filteredax);
  Serial.print("\t");*/
  Serial.print(ay);/*
  Serial.print("\t");
  Serial.print(filtereday);*/
  Serial.println();

  delay(10);

}
