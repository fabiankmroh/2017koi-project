
#include <LiquidCrystal.h>             // LCD를 사용하기 위한 라이브러리 포함

const int rs =12, en =11, d4 =5, d5 =4, d6 =3, d7 =2;  // LCD 인터페이스 핀을 연결
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);             // 라이브러리 초기화 

void setup() {
  lcd.begin(16,2);                              // LCD의 열(세로)과 행(가로) 수를 설정
}


void loop() {
 
  lcd.setCursor(0,0);                         // 커서를 (0,0) 좌측 상단에 위치시킨다
  
  for(int thisChar = 0; thisChar <10; thisChar++) {     
    lcd.print(thisChar);                      // 0~9 까지 숫자를 LCD에 나타낸다
    delay(500);                               // 0.5초 동안
  }

  lcd.setCursor(16,1);                       // 커서를 (16,1) 우츨하단에 위치시킨다
  
  lcd.autoscroll();                          // 자동 스크롤하도록 설정
  
  for(int thisChar = 0; thisChar <10; thisChar++) {
    lcd.print(thisChar);                     // 0~9 까지 숫자를 LCD에 나타낸다
    delay(500);                              // 0.5초 동안
  }
 
  lcd.noAutoscroll();                        // 자동 스크롤 해지

  lcd.clear();                                // 다음 루프로 가기 전 화면을 지운다.
}

