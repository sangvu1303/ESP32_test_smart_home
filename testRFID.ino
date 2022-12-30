// -------------------------------------------------
// RFID <--> ESP32
// 3.3V <--> 3.3V
// RST  <--> D27
// GND  <--> GND
// MISO <--> D19
// MOSI <--> D23
// SCK  <--> D18
// SDA  <--> D5
// DONE
// -------------------------------------------------

#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN  27
#define SS_PIN  5

MFRC522 mfrc522(SS_PIN, RST_PIN);
void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
}

void loop() {
  if(! mfrc522.PICC_IsNewCardPresent()){return;} // card mới
  if(! mfrc522.PICC_ReadCardSerial()){return;} // đọc card

  mfrc522.PICC_DumpToSerial(&(mfrc522.uid)); // serial đọc dữ liệu
}
