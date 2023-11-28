#ifndef MainPJ
#define MainPJ
#include "ultrasound_utils.hpp"
#include <Servo.h>


const int led = 1; //ประกาศขา led
const int relay = 10;

struct Ultrasound us1;
struct Ultrasound us2;
Servo sv1;
//  = {0, 0, 10.0l, 1.0l}; //10 is dist


void setup() {
  Serial.begin(9600);
  sv1.attach(3);
  initUltrasound(&us1, 4, 5);
  initUltrasound(&us2, 16, 0);


  pinMode(led, OUTPUT);
  pinMode(relay, OUTPUT);
}

void loop() {


  ultrasoundLoop(&us1);
  ultradebug(&us1);

  ultrasoundLoop(&us2);
  ultradebug(&us2);
  // usDetectCar(&us1);
  // usDetectCar(&us2);

  // if(us1.distance <= 5 && us2.distance <= 5){
  //   digitalWrite(led, HIGH);
  // } 
  // else{
  //   digitalWrite(led, LOW);
  // }
  // if (us1.isFoundCar && us1.isFoundCar != us1.prevFoundCar)
  // if (us1.isFoundCar)
  if (us1.distance <= 5)

  {
    // open in-servo 90 deg
    // sv1.write(90);
    digitalWrite(led, 1);
    // delay(3000);
  }
  else
  // if (us1.isFoundCar == 0)
  {
    digitalWrite(led, 0);
  }
  // // else
  // // {}
  // //   // delay()
  // // }
  // if (!us2.isFoundCar && !us2.isFoundCar)
  // {
  //   // close in-servo -90 deg
  // }

 int newRelayStatus =  !digitalRead(relay);
 digitalWrite(relay, newRelayStatus);
  delay(1000);

  // delay(5);

}
#endif