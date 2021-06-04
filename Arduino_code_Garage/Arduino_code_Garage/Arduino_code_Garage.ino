/*
 Name:    Arduino_code_Garage.ino
 Created: 06/04/2021 10:31:01 AM
 Author:  Shalini Pandurangan
*/

#include <SPI.h>  
#include <MFRC522.h>
#include <Servo.h>
#include <DHT.h>;

#define trigPin 5
#define echoPin 4
//#define DHTTYPE DHT22 
//#define DHTPIN 2

//DHT dht(DHTPIN, DHTTYPE);


int buzzerPin = 6;
bool first = true;
int duration, distance;

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
Servo myServo1;
Servo myServo2;


void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
//  dht.begin();
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode (buzzerPin, OUTPUT);
  Serial.println("Approximate your card to the reader...");
  Serial.println();
  myServo1.write(10);
  myServo1.attach(7);
  myServo2.write(170);
  myServo2.attach(8);

}

void loop() 
{
  digitalWrite(trigPin, HIGH);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  Serial.println(duration);

  
  if (duration > 180 && duration <= 200) 
  {
//      Serial.println("object detected \n");
      Serial.print("distance= ");              
//      Serial.print(duration);
      Serial.print(first);
      if(first == false){
      digitalWrite (buzzerPin, HIGH);
      delay (1000);
//      Serial.println("CLOSING DOOR");
      digitalWrite (buzzerPin, LOW);
      first = true;
      }
      myServo1.write(10); 
      myServo2.write(170);
      delay (500);
  }

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

  if (content.substring(1) == "99 75 03 B9") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println("OPENING DOOR");
    myServo1.write(92);
    myServo2.write(90);
    first = false;
    
   }
   
}
