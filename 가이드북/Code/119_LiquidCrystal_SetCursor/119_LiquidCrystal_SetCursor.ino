
#include <LiquidCrystal.h>             // LCD를 사용하기 위한 라이브러리 포함

const int rs =12,en =11,d4 =5,d5 =4,d6 =3,d7 =2;  // LCD 인터페이스 핀을 연결
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);             // 라이브러리 초기화 

const int numRows =2;
const int numCols =16;

void setup() {

  lcd.begin(numCols,numRows);                // LCD의 열(세로)과 행(가로) 수를 설정
}

void loop() {
                    
  for(int thisLetter ='a'; thisLetter <= 'z'; thisLetter++) {   //A~Z까지 ASCII값으로
    
    for(int thisRow =0; thisRow < numRows; thisRow++) {       //0행부터
   
      for(int thisCol =0; thisCol < numCols; thisCol++) {       //0열~15열까지
        
        lcd.setCursor(thisCol, thisRow);                         // 커서 위치에
       
        lcd.write(thisLetter);                                   // 문자 인쇄
        delay(200);                                              // 0.2초 지연
      }
    }
  }
}

