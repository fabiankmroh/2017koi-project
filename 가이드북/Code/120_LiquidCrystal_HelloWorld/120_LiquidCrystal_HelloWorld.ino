
#include <LiquidCrystal.h>             // LCD를 사용하기 위한 라이브러리 포함

const int rs =12,en =11,d4 =5,d5 =4,d6 =3,d7 =2;  // LCD 인터페이스 핀을 연결
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);             // 라이브러리 초기화 

void setup() {
  
  lcd.begin(16,2);                              // LCD의 열(세로)과 행(가로) 수를 설정
  lcd.print("hello, world!");                   // LCD창에 메시지 출력
}

void loop() {
                    
  lcd.setCursor(0,1);                 // 커서를 0열 1행으로 설정. 1행은 두 번째 열
  
  lcd.print(millis() /1000);           // 재설정 후 밀리초를 초로 변환해서 출력
}


