//int led1 = 13;
//int led2 = 12;
//int led3 = 11;
//int led4 = 10;
//int led5 = 9;

void setup() {
  for(int i=13; i>8; i--) { // for(초기화; 조건; 증감식) i-- => i = i - 1 / i++ => i = i + 1
    pinMode(i, OUTPUT);
    }
}

void loop() {
  for(int i=13; i>8; i--) {
    digitalWrite(i, HIGH); // LED On
    delay(1000);
  }
  for(int i=9; i<14; i++) {
    digitalWrite(i, LOW); // LED Off
    delay(1000);
  }
    
}
