
#include <LiquidCrystal.h>             // LCD를 사용하기 위한 라이브러리 포함

const int rs =12, en =11, d4 =5, d5 =4, d6 =3, d7 =2;  // LCD 인터페이스 핀을 연결
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);             // 라이브러리 초기화 

void setup() {
  lcd.begin(16,2);                              // LCD의 열(세로)과 행(가로) 수를 설정
  lcd.print("hello, world!");                   // LCD창에 메시지 출력
  delay(1000);                                  // 1초동안
}

void loop() {
  // 문자열의 길이 13개를 왼쪽으로 스크롤              
  for(int positionCounter = 0; positionCounter < 13; positionCounter++) {
                                              
    lcd.scrollDisplayLeft();                           // 한 위치씩 왼쪽으로 스크롤
                                                       
    delay(150);                                        // 150밀리초간
  }

  // 문자열의 길이 13+열수 16 총 29개 위치를 오른쪽으로 스크롤
  for(int positionCounter = 0; positionCounter < 29; positionCounter++) {
                         
    lcd.scrollDisplayRight();                          // 한 위치씩 오른쪽으로 스크롤
                                                       
    delay(150);                                       // 150밀리초간
  }

  // 왼쪽으로 16개 위치 스크롤하여 중심으로 이동
  for(int positionCounter = 0; positionCounter < 16; positionCounter++) {
    
    lcd.scrollDisplayLeft();                          // 한 위치씩 왼쪽으로 스크롤
    // wait a bit:
    delay(150);                                       // 150밀리초간
  }

  delay(1000);                             // 한 루프 돌면 1초 기다린다      

}

