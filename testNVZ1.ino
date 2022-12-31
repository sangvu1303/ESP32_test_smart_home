// --------------------------
// NVZ1 <--> ESP32
// DATA  <-->  D33
// --------------------------
// DONE

// đọc giá trị digital
//int cambien = 33; 
//int giatri;
//
//void setup() {
//  Serial.begin(9600);
//
//  pinMode(cambien, INPUT); //Cảm biến nhận tín hiệu
//}
//
//void loop() {
//  giatri = digitalRead(cambien); //Đọc giá trị cảm biến và gán vào biến giatri
//  Serial.print("Giá trị cảm biến: ");
//  Serial.println(giatri);
//  delay(1000);
//}

// ---------------------------------------------
// đọc giá trị analog
//int cambien = 33; 
//int giatri;
//
//void setup() {
//  Serial.begin(9600);
//
//  pinMode(cambien, INPUT); //Cảm biến nhận tín hiệu
//}
//
//void loop() {
//  giatri = analogRead(cambien); //Đọc giá trị cảm biến và gán vào biến giatri
//  Serial.print("Giá trị cảm biến: ");
//  Serial.println(giatri);
//  delay(1000);
//}

// ----------------------------------------------
// đọc giá trị analog và ứng dụng đèn ngủ
int cambien = 33;
int giatri;

int den = 4;

void setup() {
  Serial.begin(9600);

  pinMode(den, OUTPUT); 
  digitalWrite(den, LOW); //Mặc định đèn tắt
  pinMode(cambien, INPUT); //Cảm biến nhận tín hiệu
}

void loop() {
  giatri = analogRead(cambien); //Đọc giá trị analog của cảm biến và gán vào biến giatri

  if (giatri > 4000) //Nếu giá trị quang trở lớn hơn 1000
  {
    digitalWrite(den, HIGH); //Đèn sáng
  }
  else{
    digitalWrite(den, LOW); //Đèn tắt
  }
  
  Serial.print("Giá trị cảm biến: ");
  Serial.println(giatri);
  delay(1000);
}
