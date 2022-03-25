int led1 = 11;
int led2 = 10;
int led3 = 9;

int push_btn = 6;
int btn_state = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);

  pinMode(push_btn, INPUT);

}

void loop() {

  int readValue = analogRead(A0);
  int conValue = map(readValue,0,1023,0,255);
  
  if(readValue>=1 && readValue<300){
    analogWrite(led1, conValue);
    delay(10);
    }else{
      analogWrite(led1,0);
      }
    
  if(readValue>300 && readValue<701){
    analogWrite(led2,conValue);
    delay(10);
    }else{
      analogWrite(led2,0);
      }
    
  if(readValue>701 && readValue<1024){
    analogWrite(led3,conValue);  
    delay(10);  
    }else{
      analogWrite(led3,0);
      }

  Serial.print(readValue);
  Serial.print('\t');
  Serial.println(conValue);

  btn_state = analogRead(push_btn);
  if(btn_state == LOW){
    led_on();
    }
  if(btn_state == HIGH){
    led_off();
    } 
  delay(1000);
}

void led_on(){
  analogWrite(led1,1);
  analogWrite(led2,1);
  analogWrite(led3,1);
  }

void led_off(){
  analogWrite(led1,0);
  analogWrite(led2,0);
  analogWrite(led3,0);
  }

