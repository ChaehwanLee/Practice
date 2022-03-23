
void setup() {
  Serial.begin(9600);

}

void loop() {
  int returnVal1 = sum(10,20);
  int myarr1[]={10,20,90,100,200};
  int myarr2[]={99,58,100,100,89,78};
  int returnVal2=sumArray2(myarr1,sizeof(myarr1)/sizeof(int));
  int returnVal3=sumArray2(myarr2,sizeof(myarr2)/sizeof(int));
  Serial.println("========");
  Serial.println(returnVal1);
  sum2(30, 40);
  Serial.println(returnVal2);
  Serial.println(returnVal3);
  delay(2000);
  int data = Serial.parseInt();
  Serial.println(getGrade(data)); // 리턴값을 변수에 저장하지 않고 바로 출력 
  Serial.println("========");
  delay(2000);
}

char getGrade(int score) { //4번
  char grade = '\0';
//  Serial.println(score/10);
  if(score>100 || score<0) {
    Serial.println("잘못입력");  
  }else{
    switch(score/10) {
      case 10:
      case 9:
        grade = 'A';
        break;
      case 8:
        grade = 'B';
        break;
      case 7:
        grade = 'C';
        break;
      case 6:
        grade = 'D';
        break;
      default:
        grade = 'F';
      }
    
    }
    return grade;
}


int sumArray2(int arr[], int arraysize) {
  int total = 0;
  for(int i=0; i<arraysize;i++) {
    total = total + arr[i];
  }
  return total;
}

int sumArray(int arr[5]) { // 3번 
  int total = 0;
  for(int i=0; i<5;i++) {
    total = total + arr[i];
  }
  return total;
}

int sum(int num1, int num2) { //1번 
  int result = num1 + num2;
  return result;
}

void sum2(int num1, int num2) {//2번 
  int result = num1 + num2;
  Serial.println(result);
  return;
}