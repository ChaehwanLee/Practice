int melody[] = {262, 294, 330, 349, 392, 440, 494, 523};
int mycount = 1;
void setup() {
  // 피에조부저에 진동판이 있고 이 진동판이 진동될 때 주파수(1초에 떨리는 횟수)가 활용(주파수는 미리 정의가 되어있다. -237페이지)
  // 피에조부저는 전기적인 신호를 소리로 변환해주는 소자
  // tone(핀의번호, 진동주파수, 진동을 발생시키는 시간)
  // tone(7, 330, 1000);
  Serial.begin(9600);

}

void loop() {
  if(mycount<=3) {
    for(int = i;i<8;i++){
      tone(7, melody[i], 2000);
      delay(500);
      // noTone(7);
    }
    noTone(7); //tone()에 의해 소리가 나는 페이조부저의 소리를 끄는 함수 
    Serial.println("test:"+(String)mycount);
  }
  mycount++;
  delay(1000);

}