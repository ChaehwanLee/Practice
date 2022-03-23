void setup() {
  Serial.begin(9600);

}

void loop() {
   // 리턴값이 없고 매개변수가 없는 함수의 호출
   show();
   // 리턴값이 없고 매개변수가 있는 함수의 호출
   show2(10);
   show2(20);
   show2(2);
   show2(100);
   delay(2000);
}

// 리턴값이 없고 매개변수가 없는 함수
void show(){
  for(int i=1; i<=5; i++) {
    Serial.print("*");
  }
  Serial.println();
}

// 2. 리턴값이 없고 매개변수가 있는 함수

void show2(int count){
  for(int i=1; i<=count; i++) {
    Serial.print("*");
  }
  Serial.println();
}

// 하나의 이름으로 로직을 묶어주는 것, 하나의 이름을 사용하면 반복할 때 편하게 사용가능 

// 3. 리턴값이 있고 매개변수가 있는 함수
int test(int num1, num2) {
  int result = num1*num2;
  return result; //함수를 모두 실행하고 마지막 문장에서 호출한 곳으로 넘겨줄 데이터를 return명령문과 함께 정의
  }

  