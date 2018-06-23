#include <LiquidCrystal.h>             // LCD를 사용하기 위한 라이브러리 포함

const int rs =12, en =11, d4 =5, d5 =4, d6 =3, d7 =2;  // LCD 인터페이스 핀을 연결
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);             // 라이브러리 초기화 

void setup() {
  lcd.begin(16,2);                           // LCD의 열(세로)과 행(가로) 수를 설정
  Serial.begin(9600);                        // 9600 속도로 시리얼 통신 시작
}


void loop() {
  
  if(Serial.available()) {  // 시리얼 통신으로 문자가 도착하면
    
    delay(100);                // 전체 메시지가 도착할 때 까지 0.1초동안 기다린다.
    
    lcd.clear();               // 화면을 지운다.                      
    
    while(Serial.available() >0) {  // 문자가 들어오는 동안
      
      lcd.write(Serial.read());        // 읽은 문자를 LCD에 써라.
    }
  }
}

