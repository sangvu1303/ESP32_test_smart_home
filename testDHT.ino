// DONE
#include <DHT.h>
#define chandht 32 
#define loaidht DHT11

int NVZ1 = 33;// khai báo chân digital 10 cho cảm biến
int Led = 14;//kháo báo chân digital 8 cho đèn LED

DHT dht(chandht,loaidht);

float nhietdo;
float doam;
float anhsang;

void setup() {
  Serial.begin(115200);
  pinMode(chandht,INPUT);
  dht.begin();
  pinMode(Led,OUTPUT);//pinMode xuất tín hiệu đầu ra cho led
  pinMode(NVZ1,INPUT);//pinMode nhận tín hiệu đầu vào cho cảm biê

}

void loop() {
  nhietdo = dht.readTemperature();
  doam = dht.readHumidity();
  anhsang = digitalRead(NVZ1);//lưu giá trị 
  digitalWrite(Led,anhsang);
  
  Serial.print("Nhiệt độ : ");
  Serial.println(nhietdo);
  Serial.print("Độ ẩm : ");
  Serial.println(doam);
  Serial.print("Ánh Sáng : ");
  Serial.println(anhsang);
  
  delay(1000);
}
