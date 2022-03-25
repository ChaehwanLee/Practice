int push_btn = 12;
int led_pin = 8;
int btn_state = 0; //버튼의 현재 상태값을 저장하는 변수 - 0,1
int led_state = 0; //내가 만든 것이므로 내가 바꿨다는 것을 표시해줘야

void setup() {
  Serial.begin(9600);
  pinMode(push_btn, INPUT); //디지털신호를 읽기 위해 핀모드를 설정
  pinMode(led_pin, OUTPUT);

}

void loop() {
  //delay(1000);
  // 입력핀으로 설정한 12번 핀의 입력된 현재 값을 읽어서 btn_state에 저장
  btn_state = digitalRead(push_btn);
  Serial.println(btn_state);
    if(btn_state==HIGH) {
      if(led_state==0) {
        digitalWrite(led_pin,HIGH);
        led_state = 1; // led의 상태값을 다시 설정 
        Serial.println("led_on:"+(String)led_state);
      }else{
        digitalWrite(led_pin,LOW);
        led_state = 0;
        Serial.println("led_off:"+(String)led_state);
   }
  }
  delay(500);
}