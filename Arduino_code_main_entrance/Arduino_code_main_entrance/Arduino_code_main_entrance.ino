/*
 Name:    Arduino_code_main_entrance.ino
 Created: 06/04/2021 10:33:01 AM
 Author:  Shalini Pandurangan
*/
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include "DHT.h"
 
#define SS_PIN 10
#define RST_PIN 9
#define DHTPIN 6     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
#define fan 5

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
Servo myServo; //define servo name

int maxHum = 34.50;
int maxTemp = 27;
DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  dht.begin();
  mfrc522.PCD_Init();   // Initiate MFRC522
  myServo.attach(2); //servo pin
  myServo.write(90); //servo start position
  pinMode(fan, OUTPUT);
  Serial.println("Put your card to the reader...");
  Serial.println();

}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "59 35 F7 B1") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
    delay(500);
    myServo.write(180);
    delay(5000);
    myServo.write(90);
  }
 
 else   {
    Serial.println(" Access denied");
    delay(1000);
  }
} 
