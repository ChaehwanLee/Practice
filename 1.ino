int inputdata = 0;
void setup() {
  Serial.begin(9600);

}

void loop() {
  delay(1000);
  inputdata = Serial.read();
  if(inputdata >100){
    Serial.println(inputdata);
    Serial.println("OK");
    } else {
      Serial.println("Fail");
      }

}

