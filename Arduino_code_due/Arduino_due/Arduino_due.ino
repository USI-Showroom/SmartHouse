
/*
 Name:    Arduino_due.ino
 Created: 06/04/2021 10:25:01 AM
 Author:  Shalini Pandurangan
*/
#include <Servo.h>
#include "DHT.h"
#include <SPI.h>
#include <MFRC522.h>

//#define SS_PIN 10
//#define RST_PIN 9


#define DHTPIN 2
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

Servo myservo;  // create servo object to control a servo
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;
//Servo myservo7;
//Servo myservo8;
Servo myservo9;
Servo myservo10;
Servo myservo11;
Servo myservo12;
Servo myservo13;
Servo myservo14;
Servo myservo15;
Servo myservo16;
Servo myservo17;
Servo myservo18;
Servo myservo19;


//MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

int val = 10;
float hum; 
float temp;

void setup() {
  Serial.begin(9600);
  dht.begin();
  SPI.begin(); 
//  mfrc522.PCD_Init(); 
  pinMode(33, INPUT);// set pin as input
  pinMode(53, INPUT);
  pinMode(39, INPUT);// set pin as input
  pinMode(49, INPUT);
  pinMode(43, INPUT);// set pin as input
  pinMode(45, INPUT);
  pinMode(30, INPUT);// set pin as input
  pinMode(34, INPUT);
  pinMode(42, INPUT);// set pin as input
  pinMode(32, INPUT);
  pinMode(35, INPUT);// set pin as input
//  pinMode(52, INPUT);
//  pinMode(37, INPUT);
  pinMode(22, OUTPUT);// set pin as output
  myservo3.write(10);
  myservo4.write(10);
//  myservo.write(22);
//  myservo1.write(24);
  myservo2.write(10);
  myservo9.attach(10);
  myservo2.attach(41); //ROOM 1
  myservo3.attach(44); //ROOM 2
  myservo4.write(80);
  myservo4.attach(8); // ROOM 3
  myservo5.write(0);
  myservo6.write(0);
  myservo5.attach(5);
  myservo6.attach(36);
//  // myservo7.attach();
//  myservo8.attach(50);
  myservo9.write(10);//ROOM4
  myservo9.attach(24);//change
  myservo10.write(10);
  myservo10.attach(38);//ROOM5
  myservo11.write(90);
  myservo14.write(40);
  myservo11.attach(7);//change
  myservo14.attach(4);
  myservo12.write(0);
  myservo13.write(190);
  myservo12.attach(26);// change
  myservo13.attach(28);
//myservo5.attach(2); 
  myservo.write(46);
  myservo15.write(90);//new
  myservo18.write(90);//new
  myservo16.write(0);//new
  myservo17.write(180);
  myservo15.attach(13);//new
  myservo16.attach(12);//new
  myservo17.attach(11);//new
  myservo18.attach(10);//new
  myservo19.write(0);//new
  myservo19.attach(6);//new
}

void loop() {
//  Written for Robojax on Dec 28, 2017
  int detect = digitalRead(53);//back_IR_1
  int detect1 = digitalRead(33);//front_IR_1
  int detect2 = digitalRead(39);//back_IR_2
  int detect3 = digitalRead(49);//front_IR_2
  int detect4 = digitalRead(43);//back_IR_3
  int detect5 = digitalRead(45);//front_IR_3
  int detect6 = digitalRead(30);//front_IR_4
  int detect7 = digitalRead(34);//back_IR_4
  int detect8 = digitalRead(42);//front_IR_5
  int detect9 = digitalRead(32);//back_IR_5
  int detect10 = digitalRead(35);//garage
//  int detect10 = digitalRead(35);//front_IR_garage_from_house
//  int detect11 = digitalRead(37);//back_IR_garage_from_house
  
  if (detect1 == LOW) {
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    Serial.println("1"); // ROOM 1


    myservo2.write(100);
    delay(1000);
    myservo2.write(10);
    myservo11.write(0);//change
    myservo14.write(130);
    delay(1000);
    if(hum > 23 || temp > 20 ){
      Serial.println("humidity");
      Serial.println(hum);
      Serial.println("Temperature");
      Serial.println(temp);
      digitalWrite(22, HIGH);
    }
   }
  else {

//    Serial.println("1");
    if (detect == LOW) {
      digitalWrite(22, LOW);
      myservo2.write(100);
      delay(1000);
      myservo2.write(10);
      myservo11.write(90);
      myservo14.write(40);
    }
  }                                                                     

  if (detect3 == LOW) { 
    Serial.println("2"); // ROOM 2
    myservo3.write(80);
    delay(1000);
    myservo3.write(10);
    delay(500);
    myservo15.write(0);//new
    myservo18.write(180);//new
   }
  else {

    Serial.println("2");
    if (detect2 == LOW) {
      myservo3.write(80);
      delay(1000);
      myservo3.write(10);
      myservo15.write(90);//new
      myservo18.write(90);//new
    }
  }
  
  if (detect5 == LOW) { 
    Serial.println("frnt_receve"); // ROOM 3
    myservo4.write(10);
    delay(1000);
    myservo4.write(80);
    myservo16.write(90);//new
    myservo17.write(90);
   }
  else {
    
    if (detect4 == LOW) {
      Serial.println("back receive");
      myservo4.write(10);
      delay(1000);
      myservo4.write(80);
      myservo16.write(0);//new
      myservo17.write(180);
    }
  }
  
  if (detect6 == LOW) {
    Serial.println("Obastacle on the way");  // ROOM 4
    myservo9.write(90);
    delay(2000);
    myservo9.write(10);
    delay(500);
    myservo5.write(80);
    myservo6.write(90);
    delay(500);
    delay(500);
   }
   else {

    Serial.println("All clear");
    if (detect7 == LOW) {
      delay(1000);
      myservo9.write(90);
      delay(1000);
      myservo9.write(10);
      delay(500);
      myservo5.write(0);
      myservo6.write(0);
    }
  }
//  
  if (detect8 == LOW) {  
    Serial.println("Obastacle on the way"); // ROOM 5
    myservo10.write(90);
    delay(2000);
    myservo10.write(10);
    delay(500);
    myservo12.write(90);
    myservo13.write(90);
    delay(500);
   }
   else {

    Serial.println("All clear");
    if (detect9 == LOW) {
      delay(1000);
      myservo10.write(90);
      delay(1000);
      myservo10.write(10);
      delay(100);
      myservo12.write(0);
      myservo13.write(190);
      delay(500);
    }
  }
  
  if (detect10 == LOW) {  
    Serial.println("Obastacle on the way"); // Garage
    myservo19.write(90);
    delay(1000);
    myservo19.write(0);
    delay(500);
   }
  
//  
//  if (detect5 == LOW) {  
//    Serial.println("Obastacle on the way"); // ROOM 6
//    myservo10.write(90);
//    delay(2000);
//    myservo10.write(10);
//    delay(500);
//    myservo8.write(90);
//    myservo9.write(90);
//    delay(500);
//   }
//   else {
//
//    Serial.println("All clear");
//    if (detect4 == LOW) {
//      delay(1000);
//      myservo10.write(90);
//      delay(1000);
//      myservo10.write(10);
//      delay(100);
//      myservo8.write(10);
//      myservo9.write(10);
//      delay(500);
//    }
//  }
//  if (detect5 == LOW) {
//    Serial.println("Obastacle on the way"); // GARAGE
//    myservo10.write(90);
//    delay(2000);
//    myservo10.write(10);
//    delay(500);
//    myservo8.write(90);
//    myservo9.write(90);
//    delay(500);
//   }
//   else {
//
//    Serial.println("All clear");
//    if (detect4 == LOW) {
//      delay(1000);
//      myservo10.write(90);
//      delay(1000);
//      myservo10.write(10);
//      delay(100);
//      myservo8.write(10);
//      myservo9.write(10);
//      delay(500);
//    }
//  }
  delay(300);
}
