#include <Arduino.h>


struct Ultrasound
{
  int trig;
  int echo;
  long distance;
  long duration;
  int isFoundCar;
  int prevFoundCar;
};

void initUltrasound(struct Ultrasound *us, int trig, int echo)
{
  us->trig = trig;
  us->echo = echo;
  pinMode(us->echo, INPUT);
  pinMode(us->trig, OUTPUT);
}

void usDetectCar(struct Ultrasound *us)
{
  if (us->distance <= 5)
  {
    us->isFoundCar = 1;
  }
  else
  {
    us->isFoundCar = 0;
  }
  
  // us->prevFoundCar = us->isFoundCar;
}

void ultrasoundLoop(struct Ultrasound *us)
{
  // delayMicroseconds(1000);
 digitalWrite(us->trig, LOW); 
 delayMicroseconds(5); 
 digitalWrite(us->trig, HIGH); 
 delayMicroseconds(5); 
 digitalWrite(us->trig, LOW); //ใช้งานขา trig
 
 us->duration = pulseIn(us->echo, HIGH); //อ่านค่าของ echo
 us->distance = (us->duration/2) / 29.1; //คำนวณเป็น centimeters

//  usDetectCar(us);
}



void ultradebug(struct Ultrasound *us)
{
  Serial.printf("t%d e%d dst%lu dur%lu\n", us->trig, us->echo, us->distance, us->duration);
}