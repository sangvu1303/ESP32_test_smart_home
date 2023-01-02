// -------------------------------------------------
// RFID <--> ESP32
// 3.3V <--> 3.3V
// RST  <--> D5
// GND  <--> GND
// MISO <--> D19
// MOSI <--> D23
// SCK  <--> D18
// SDA  <--> D17 / TX2
// DONE
// -------------------------------------------------

#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN  5
#define SS_PIN  17

// đọc toàn bộ dữ liệu
//MFRC522 mfrc522(SS_PIN, RST_PIN);
//void setup() {
//  Serial.begin(9600);
//  SPI.begin();
//  mfrc522.PCD_Init();
//}
//
//void loop() {
//  if(! mfrc522.PICC_IsNewCardPresent()){return;} // card mới
//  if(! mfrc522.PICC_ReadCardSerial()){return;} // đọc card
//
//  mfrc522.PICC_DumpToSerial(&(mfrc522.uid)); // serial đọc dữ liệu
//}

// đọc dữ liệu UID tối giản
//int  UID[4], i;
//MFRC522 mfrc522(SS_PIN, RST_PIN);
//
//void setup() {
//  Serial.begin(9600);
//  SPI.begin();
//  mfrc522.PCD_Init();
//}
//
//void loop() {
//  if(! mfrc522.PICC_IsNewCardPresent()){return;} // card mới
//  if(! mfrc522.PICC_ReadCardSerial()){return;} // đọc card
//
//  Serial.print("UID của thẻ: ");
//
//  for(byte i = 0; i < mfrc522.uid.size; i++){
//    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : " ");
//    UID[i] = mfrc522.uid.uidByte[i];
//    Serial.print(UID[i]);
////    Serial.print(UID[i], HEX); // đọc số hex
//  }
//  Serial.print("   ");
//
//  mfrc522.PICC_HaltA();
//  mfrc522.PCD_StopCrypto1();
//}

// ứng dụng đóng mở dùng 2 thẻ
//int UID[4], i;
////int ID1[4] = {43, 27, 90, A7}; //thẻ mở // chú ý: thẻ ko nhận số hex
////int ID2[4] = {DC, FD, FD, 32}; //thẻ đóng
//int ID1[4] = {67, 39, 144, 167}; //thẻ mở 
//int ID2[4] = {220, 253, 253, 50}; //thẻ đóng
//int led = 2;
//
//MFRC522 mfrc522(SS_PIN, RST_PIN);
//
//void setup() {
//  Serial.begin(9600);
//  pinMode(led,OUTPUT);
//  digitalWrite(led,LOW);
//  
//  SPI.begin();
//  mfrc522.PCD_Init();
//}
//
//void loop() {
//  if(! mfrc522.PICC_IsNewCardPresent()){return;} // card mới
//  if(! mfrc522.PICC_ReadCardSerial()){return;} // đọc card
//
//  Serial.print("UID của thẻ: ");
//
//  for(byte i = 0; i < mfrc522.uid.size; i++){
//    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : " ");
//    UID[i] = mfrc522.uid.uidByte[i];
//    Serial.print(UID[i]);
//  }
//  Serial.print("   ");
//
//  if(UID[i] == ID1[i]){
//    digitalWrite(led,HIGH);
//    Serial.println("Đèn mở");
//  }
//  else if(UID[i] == ID2[i]){
//    digitalWrite(led,LOW);
//    Serial.println("Đèn tắt");
//  }
//  else {
//    Serial.println("Sai thẻ");
//  }
//  mfrc522.PICC_HaltA();
//  mfrc522.PCD_StopCrypto1();
//}

// ứng dụng đóng mở chỉ dùng 1 thẻ
int UID[4], i;
int ID1[4] = {67, 39, 144, 167}; //thẻ đóng mở
int led = 2; // (+) <--> D2 & (-) <--> GND
int dem = 0;

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
  
  SPI.begin();
  mfrc522.PCD_Init();
}

void loop() {
  if(! mfrc522.PICC_IsNewCardPresent()){return;} // card mới
  if(! mfrc522.PICC_ReadCardSerial()){return;} // đọc card

  Serial.print("UID của thẻ: ");

  for(byte i = 0; i < mfrc522.uid.size; i++){
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : " ");
    UID[i] = mfrc522.uid.uidByte[i];
    Serial.print(UID[i]);
  }
  Serial.print("   ");

  if(UID[i] == ID1[i]){
    dem ++;
    Serial.print("số đếm: ");
    Serial.println(dem);

    if((dem % 2) == 1)//số lẻ thì mở
    {
      digitalWrite(led,HIGH);
      Serial.println("Đèn mở");
    }
    else if((dem % 2) == 0){
      digitalWrite(led,LOW);
      Serial.println("Đèn tắt");
    }
    else{
    Serial.println("Sai thẻ");
    }
  }  
  
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
}
