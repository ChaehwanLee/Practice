//RFID
#include <MFRC522.h>
#include <SPI.h>

// Slave와 통신할 수 있도록 ss핀과 reset핀을 셋팅하고 MFRC522클래스를 생성
#define SS_PIN 10
#define RESET_PIN 9
MFRC522 rfid(SS_PIN,RESET_PIN);
byte card_uid[]={144, 182, 255, 27};// 각자마다 다른 카드번호
// white{144, 182, 255, 27}
// blue {48, 12, 91, 28}

void setup() {
  //시리얼통신과 SPI 통신을 초기화하며 start
  Serial.begin(9600);
  SPI.begin();
  //MFRC522초기화
  rfid.PCD_Init();
}

void loop() {
  // 태그가 접촉되지 않거나 ID가 읽히지 않는 경우 체크
  // PICC_IsNewCardPresent() -> 태그가 접촉되면 1을 리턴
  // PICC_ReadCardSerial() -> id를 읽으면 1을 리턴
  if(!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()){
    delay(1000);
    return;
    }
    // 태그의 id를 출력
    // -> 태그의 고유ID(UID)
    //  UID는 식별자 - 장비를 식별하기 위해서 사용하는 값
    //               4가지 숫자가 조합
    //               MFRC522 라이브러리를 통해 접근할 수 있는 uid 객체의 uidByte배열에 저장되어 있다.
    Serial.print("카드의 Tag ID :");
    for(byte i=0; i<4; i++) {
      if(card_uid[i]==rfid.uid.uidByte[i]){
        Serial.print(rfid.uid.uidByte[i]);
        Serial.print(" ");
      }else{
        Serial.println("일치하는 카드가 아닙니다.");
        }
      
    }
    Serial.println();
    delay(1000);  
}      