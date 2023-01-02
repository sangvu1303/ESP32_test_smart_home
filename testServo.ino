// --------------------------
// SERVO <--> ESP32
// DATA  <-->  D25 / D26 (dây cam)
// --------------------------
// DONE


#include <ESP32Servo.h>

int servo = 25;
int goc;

Servo myServo;

void setup() { 
    Serial.begin(9600);    
    myServo.attach(servo); 
}

 
void loop() { 
    myServo.write(0);
    goc = myServo.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo.write(90);
    goc = myServo.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo.write(180);
    goc = myServo.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);

}

// ----------------------------------------------         
 
//int bientro = 25; 
//int servo = 13;  
//
//int giatribientro;
//int vitriservo;
//
//void setup(){
//  myservo.attach(servo);
//  Serial.begin(9600);
//}
//
//void loop() {
//  giatribientro = analogRead (bientro);
//  vitriservo = map (giatribientro,0,1023,0,180);
//
//  myservo.write(vitriservo);
//  
//  Serial.print("Góc Servo: "); Serial.println(vitriservo);
//  //delay(50);
//
//}


// ---------------------------------------------------------------

//int servo = 13;
//int vitri = 0;
//
//Servo myservo;
//
//void setup(){
//  myservo.attach(servo);
//}
//
//void loop(){
//  for(vitri = 0; vitri < 181; vitri++){
//    myservo.write(vitri);
//    //delay(10);
//  }
//  delay (5000);
//
//
//  for(vitri = 180; vitri > 0; vitri--){
//    myservo.write(vitri);
//    //delay(10);
//  }
//  delay(3000);
//}

// --------------------------------------------------------
//
//int nutnhando = 2;
//int nutnhanxanh = 4;
//
//int servo = 13;
//int vitri = 0;
//
//Servo myservo;
//
//void setup(){
//  myservo.attach(servo);
//  myservo.write (0);
//  
//  Serial.begin(9600);
//  pinMode(nutnhando, INPUT_PULLUP);
//  pinMode(nutnhanxanh, INPUT_PULLUP);
//}
//
//void loop(){
//  int trangthaido = digitalRead(nutnhando);
//  int trangthaixanh = digitalRead(nutnhanxanh);
//  
//  Serial.print("Trạng thái đỏ: ");
//  Serial.print(trangthaido);
//  Serial.print("    ");
//  Serial.print("Trạng thái xanh: ");
//  Serial.print(trangthaixanh);
//  Serial.print("    ");
//  Serial.print("Góc Servo: ");
//  Serial.println(vitri);
//  delay(200);
//
//  if (trangthaido == 0 && trangthaixanh == 1)   //Đỏ bấm, xanh không bấm {
//    myservo.write (vitri += 10);       //Thay thành vitri += 10 xem kết quả
//    if (vitri > 180){
//        vitri = 180;
//      }
//  }
//
//  else if (trangthaixanh == 0 && trangthaido == 1)  //Xanh bấm, đỏ không bấm {
//    myservo.write (vitri -= 10);
//    if (vitri < 0){
//        vitri = 0;
//      }
//  } 
//}
