#include "ultrasound_utils.h"



const int led = 13; //ประกาศขา led
const int relay = 10;
struct Ultrasound *us1;


// long duration, distance; //ประกาศตัวแปรเก็บค่าระยะ

void setup() {
  Serial.begin(31250);

 
  initUltrasound(us1, 4, 5);

  pinMode(led, OUTPUT);
  pinMode(relay, OUTPUT);
}

void loop() {
  // relay 

delayMicroseconds(1000);
 digitalWrite(us1->trig, LOW); 
 delayMicroseconds(5); 
 digitalWrite(us1->trig, HIGH); 
 delayMicroseconds(5); 
 digitalWrite(us1->trig, LOW); //ใช้งานขา trig
 
 us1->duration = pulseIn(us1->echo, HIGH); //อ่านค่าของ echo
 us1->distance = (us1->duration/2) / 29.1; //คำนวณเป็น centimeters
 Serial.print(us1->distance); 
 Serial.print(" cm\n");


 if(us1->distance <= 5){ //ระยะการใช้งาน
  digitalWrite(led, HIGH);
 } //เงื่อนไข ถ้าระยะน้อยกว่า 5cm ให้ led ติด
 else{
  digitalWrite(led, LOW);
 }

 int newRelayStatus =  !digitalRead(relay);
//  Serial.println(newRelayStatus);
//   // Serial.println("abc");
  digitalWrite(relay, newRelayStatus);
  // digitalWrite(led, !digitalRead(led));

  // Serial.println("ABC test");
  delay(3000);

}