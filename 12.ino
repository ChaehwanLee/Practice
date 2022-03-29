#include "DHT.h"
#define DHTTYPE DHT11
#define DHTPIN A0
DHT mydht11(DHTPIN,DHTTYPE); // DHT11 객체생성

void setup() {
  Serial.begin(9600);
  mydht11.begin();

}

void loop() {
  float humidity_val = mydht11.readHumidity(); //습도측정
  float temp_val = mydht11.readTemperature(); //섭씨온도측정
  float f_temp_val = mydht11.readTemperature(true);//화씨온도측정
  delay(2000);
  if(isnan(humidity_val) || isnan(temp_val) || isnan(f_temp_val)) { //isnan not a number, 온도값은 실수 0.00 
      Serial.println("fail~~~~");
      return; // 현재작업을 종료
    }
    // 화면에 출력하기
    Serial.print("humidity:");
    Serial.print(humidity_val);
    Serial.print("%\t");
    Serial.print("temp_val:");
    Serial.print(temp_val);
    Serial.print("C\t");
    Serial.print("f_temp_val:");
    Serial.print(f_temp_val);
    Serial.println("F\t");
    Serial.println("=================================================");
//    delay(2000);
}
