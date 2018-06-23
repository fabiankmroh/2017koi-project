
#include <LiquidCrystal.h>             // LCD를 사용하기 위한 라이브러리 포함

const int rs =12, en =11, d4 =5, d5 =4, d6 =3, d7 =2;  // LCD 인터페이스 핀을 연결
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);             // 라이브러리 초기화 

int thisChar ='a';                                     // thisChar에 a저장

void setup() {
  lcd.begin(16,2);                           // LCD의 열(세로)과 행(가로) 수를 설정
  lcd.cursor();                              // 커서를 켠다.
}


void loop() {
 
  if(thisChar =='m') {                   // thisChar 가 m이면 방향을 바꾸어
    lcd.rightToLeft();                           // 다음 글자부터 왼쪽으로 나타내라
  }

  if(thisChar =='s') {                  // thisChar 가 s이면
    // go left for the next letter              
    lcd.leftToRight();                          // 다음 글자부터 오른쪽으로 나타내라
  }

  if(thisChar >'z') {                    // thisChar 가 z를 벗어나면
    // go to (0,0):
    lcd.home();                                 // (0,0)으로 가라
    thisChar ='a';                              // 초기부터 다시 시작
  }

  lcd.write(thisChar);                 // thisChar 값을 LCD에 나타내어라
  
  delay(1000);                         // 1초동안
  
  thisChar++;                          // thisChar 값을 하나씩 증가
}

