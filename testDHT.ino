// DATA <--> D32
// DONE
#include <DHT.h>
#define chandht 32 
#define loaidht DHT11

int Led = 14;//kháo báo chân digital 8 cho đèn LED

DHT dht(chandht,loaidht);

float nhietdo;
float doam;

void setup() {
  Serial.begin(115200);
  pinMode(chandht,INPUT);
  dht.begin();
  pinMode(Led,OUTPUT);//pinMode xuất tín hiệu đầu ra cho led
}

void loop() {
  nhietdo = dht.readTemperature();
  doam = dht.readHumidity();
  
  Serial.print("Nhiệt độ : ");
  Serial.println(nhietdo);
  Serial.print("Độ ẩm : ");
  Serial.println(doam);
  
  delay(1000);
}
