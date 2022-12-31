// ---------------------------------- //
//    LCD <--> ESP32 <--> DHT11       //
//    SDA <-->  D21                   //
//    SCL <-->  D22                   //
//              D32  <--> DATA        //
// ---------------------------------- //
// DONE
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

const int DHTPIN = 32;
const int DHTTYPE = DHT11;   // Khai báo kiểu cảm biến là DHT11
//const int DHTTYPE = DHT22;   // DHT 22 
//const int DHTTYPE = DHT21;   // DHT 21 

LiquidCrystal_I2C lcd(0x27,16,2);
DHT dht(DHTPIN, DHTTYPE); //Khai báo thư viện chân cảm biến và kiểu cảm biến

byte degree[8] = {
  0B01110,
  0B01010,
  0B01110,
  0B00000,
  0B00000,
  0B00000,
  0B00000,
  0B00000
}; // ký tự độ C

void setup() {
  Serial.begin(9600);

  dht.begin(); //Khởi động cảm biến

  lcd.init(); //Khởi động LCD                    
  lcd.backlight(); //Mở đèn
  lcd.setCursor(0,0);
  lcd.createChar(1, degree);
}

void loop() {
  float doam = dht.readHumidity(); //Đọc độ ẩm

  float doC = dht.readTemperature(); //Đọc nhiệt độ C

//  float doF = dht.readTemperature(true); //Đọc nhiệt độ F

  // Kiểm tra cảm biến có hoạt động hay không
  if (isnan(doam) || isnan(doC) ) {
    Serial.println("Không có giá trị trả về từ cảm biến DHT");
// thêm vào cho vui    
    lcd.setCursor(0,0); 
    lcd.print("KHONG CO GIA TRI");
    
    lcd.setCursor(0,1);
    lcd.print("     ");
    
    lcd.setCursor(5,1);
    lcd.print("NO DATA ");

    lcd.setCursor(13,1);
    lcd.print("   ");
    return;
  }
  else{
    Serial.print("Độ ẩm: ");
    Serial.print(doam);
    Serial.print("%");
    
    lcd.setCursor(0,0);
    lcd.print("DO AM   :");
    lcd.setCursor(9,0); //con trỏ vị trí số 9, hiện ô số 10
    lcd.print(doam);
    lcd.setCursor(14,0); //Con trở ở vị trí 15, hiện ô 16
    lcd.print(" %");
    
    Serial.print("Nhiệt độ: ");
    Serial.print(doC);
    Serial.print("°C ");

    lcd.setCursor(0,1);
    lcd.print("NHIET DO:");
    lcd.setCursor(9,1);
    lcd.print(doC);
    lcd.setCursor(14,1);
    lcd.write(1);
    lcd.print("C");
  }
  delay(1000);
}
