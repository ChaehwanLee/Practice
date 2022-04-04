#include <Servo.h>

Servo myservo;
int angle = 90;

void setup() {
  myservo.attach(10);
  Serial.begin(9600);

}

void loop() {
  if(digitalRead(13) == HIGH) { //+버튼 
    angle = angle+20;
    if(angle<180) {
      angle = 180;
      }
    myservo.write(angle);
    }
  if(digitalRead(12) == HIGH) { //-버튼 
    angle = angle-20;
    if(angle<0) {
      angle = 0;
      }
    myservo.write(angle);
    }
  Serial.println(angle);
  delay(100);

}

#include <SoftwareSerial.h>
// 블루투스 통신을 할 수 있는 SoftwareSerial 객체를 생성
SoftwareSerial myBTSerial(2,3); //SoftwareSerial (rxPin, txPin)
void setup() {
  Serial.begin(9600);
  myBTSerial.begin(9600); //블루투스 통신을 시작

}

void loop() {
  // 블루투스 통신으로 수신된 데이터 있으면
  if(myBTSerial.available()){
    // 블루트스 통신을 통해 읽은 데이터를 시리얼모니터 출력
    Serial.write(myBTSerial.read());
  }
    // 시리얼 통신으로 수신된 데이터가 있으면
  if(Serial.available()){
    // 시리얼 통신으로 입력된 데이터를 블루투스로 출력
    myBTSerial.write(Serial.read());
  }
}