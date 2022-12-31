// ---------------------------
// MQ-x <--> ESP <--> Led
// DATA <--> D34
//           D4  <--> (-)
// ---------------------------
//DONE 

// giá trị digital
//int cambien = 34;
//int giatri;
//
//void setup() {
//  Serial.begin(9600);
//  pinMode(cambien, INPUT); //Cảm biến nhận tín hiệu
//}
//
//void loop() {
//  giatri = digitalRead(cambien); //Đọc giá trị cảm biến và gán vào biến giatri
//  Serial.print("Giá trị cảm biến: ");
//  Serial.println(giatri);
//  delay(200);
//}

//-------------------------------------
// giá trị analog
//int cambien = 34;
//int giatri;
//
//void setup() {
//  Serial.begin(9600);
//  pinMode(cambien, INPUT); //Cảm biến nhận tín hiệu
//}
//
//void loop() {
//  giatri = analogRead(cambien); //Đọc giá trị cảm biến và gán vào biến giatri
//  Serial.print("Giá trị cảm biến: ");
//  Serial.println(giatri);
//  delay(200);
//}

// -------------------------------------------------------
// kết hợp đèn led báo hiệu
int cambien = 34; //Cảm biến nối chân số 5 Arduino
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

  if (giatri > 600){ //Nếu giá trị cảm biến gas lớn hơn 600
    digitalWrite(den, HIGH); //Đèn sáng
  }
  else {
    digitalWrite(den, LOW); //Đèn tắt
  } 
  
  Serial.print("Giá trị cảm biến: ");
  Serial.println(giatri);
  delay(200);
}
