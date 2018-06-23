
#include <LiquidCrystal.h>             // LCD를 사용하기 위한 라이브러리 포함

const int rs =12,en =11,d4 =5,d5 =4,d6 =3,d7 =2;  // LCD 인터페이스 핀을 연결
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);             // 라이브러리 초기화 

void setup() {
  
  lcd.begin(16,2);                              // LCD의 열(세로)과 행(가로) 수를 설정
  lcd.print("hello, world!");                   // LCD창에 메시지 출력
}

void loop() {
  lcd.noDisplay();   // 화면 끄기
  delay(500);       // 0.5초 동안
 
  lcd.display();      // 화면 켜기
  delay(500);        // 0.5초 동안
}

