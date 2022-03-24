int push_btn1 = 12; 
int push_btn2 = 13;
int led_pin = 4;
int btn_state1 = 0;
int btn_state2 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(push_btn1, INPUT); //디지털 신호를 읽기 위해 핀모드 설정
  pinMode(push_btn2, INPUT); //디지털 신호를 읽기 위해 핀모드 설정
  pinMode(led_pin, OUTPUT);

}

void loop() {
  //delay(1000);
  //입력핀으로 설정한 12번 핀의 입력된 현재 값을 읽어서 btn_state에 저
  btn_state1 = digitalRead(push_btn1); //12번 풀업 기본상태가 1
  btn_state2 = digitalRead(push_btn2); //13번 풀다운 기본상태가 0 
  if(btn_state1==0) {
    led_on(led_pin);
    }
  if(btn_state2==1) {
    led_off(led_pin);
    }
  
   delay(1000);
  }
void led_on(int pin) {
  digitalWrite(pin,HIGH);
  }

void led_off(int pin) {
  digitalWrite(pin,LOW);
  }