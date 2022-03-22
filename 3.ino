void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
//  char val = 0;
//  if(Serial.available()){
//    char val = Serial.read();
//    switch(val) {
//      case 'a':
//        Serial.println("led_on");
//        break;
//      case 'b':
//        Serial.println("led_off");
//        break;
//      default:
//        Serial.println("restart");
//      
//      }
//    }
    char val=0;
    if(Serial.available()){
      char val = Serial.read();
      switch(val) {
        case 'a':
        Serial.println("led_on");
        digitalWrite(LED_BUILTIN, HIGH);
        delay(1000);
        break;
        case 'b':
        Serial.println("led_off");
        digitalWrite(LED_BUILTIN, LOW);
        delay(1000);
        break;
        default:
          Serial.println("restart");
        }
      }

}