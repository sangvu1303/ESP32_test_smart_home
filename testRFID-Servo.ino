#include <SPI.h>
#include <MFRC522.h>
#include <ESP32Servo.h>
 
#define SS_PIN 5
#define RST_PIN 27

Servo myservo;
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

int pos=0; 

void setup() {
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  
  Serial.println("Approximate your card to the reader...");
  Serial.println();
  
  pinMode(4,OUTPUT);
  myservo.attach(13);
}
void loop() {
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
  
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
  
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  
  for (byte i = 0; i < mfrc522.uid.size; i++) {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i]);
     
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i]));
  }
  
  Serial.println();
  Serial.print("Message : ");
  
  content.toUpperCase();
  if (content.substring(1) == "67 39 144 167" | content.substring(1) == "7E 32 30 00" | content.substring(1) == "44 7E 37 FE" | content.substring(1) == "95 79 1C 53" | content.substring(1) == "F5 BC 0C 53" | content.substring(1) == "F7 73 A1 D5") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
    
    digitalWrite(4,1);
    for (pos = 0; pos <=180; pos +=1) {
      myservo.write(pos);
      delay(5);
    }
  delay(1000);
  for (pos = 180; pos >= 20; pos -=1) {
     myservo.write(pos);
     delay(5);
     digitalWrite(4, 0);
  }
  }else{
    Serial.println(" Access denied");
    delay(1000);
  }
}
