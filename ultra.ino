
int triger = 10; // 10번핀은 트리거
int echo = 9; // 9번핀은 에코
void setup() {
  pinMode(triger,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}

void loop() {
  // 초음파 신호를 보내기
  // => triger 핀의 입력이 low 에서 high로 변하는 순간부터 시간을 측정하고 다시 low로 변경되는 시점까지의 시간을 마이크로초단위로 변환
  digitalWrite(triger,LOW);
  delayMicroseconds(2);
  digitalWrite(triger,HIGH);
  delayMicroseconds(10);
  digitalWrite(triger,LOW);

  // 초음파 신호를 수신
  // => 초음파를 발생시키고 수신될까지의 시간을 측정
  // =>echo핀으로 high신호가 들어오는 시점의 시간을 반환 - pulseIn함수
  // low - high 로 변하는 시점부터 측정을 하려면 HIGH
  // high - low 로 변하는 시점부터 측정을 하려면 LOW로 정의
  double duration = pulseIn(echo,HIGH); //마이크로초
  // 거리계산
  // 시간, 속력
  double distance = 340 * duration / 10000 / 2; // 백만, 미터 00 두개 지우면 cm

  // 측정한 거리를 출력
  Serial.print(distance);
  Serial.println("cm");
  delay(500);
  
}