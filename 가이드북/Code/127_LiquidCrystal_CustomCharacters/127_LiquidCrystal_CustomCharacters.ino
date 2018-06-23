
#include <LiquidCrystal.h>             // LCD를 사용하기 위한 라이브러리 포함

const int rs =12, en =11, d4 =5, d5 =4, d6 =3, d7 =2;  // LCD 인터페이스 핀을 연결
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);             // 라이브러리 초기화 

//특수문자 만들기
byte heart[8] ={
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte smiley[8] ={
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

byte frownie[8] ={
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};

byte armsDown[8] ={
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte armsUp[8] ={
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};

void setup() {
  
  lcd.begin(16,2);                             // LCD의 열(세로)과 행(가로) 수를 설정

  // 새로운 문자 정의
  lcd.createChar(0,heart);                   
  lcd.createChar(1,smiley); 
  lcd.createChar(2,frownie);
  lcd.createChar(3,armsDown);
  lcd.createChar(4,armsUp);
  
  lcd.setCursor(0,0);                           // 커서 위치를 좌측 상단으로 설정
 
  // LCD에 문자 쓰기
  lcd.print("I ");
  lcd.write(byte(0));                           // 0바이트에 저장된 heart를 쓴다.
  lcd.print(" Arduino! ");
  lcd.write((byte)1);                         // 1바이트에 저장된 heart를 쓴다.

}

void loop() {
  
  int sensorReading = analogRead(A0);       // A0의 가변저항값을 읽는다.
 
  int delayTime = map(sensorReading,0,1023,200,1000);  // 저항값을 200 – 1000으로 맵핑
  
  lcd.setCursor(4,1);                       //하단 5번째 위치에 커서를 설정
  
  lcd.write(3);                             // 3번에 저장된 팔 아래 내린 사람 그린다.
  delay(delayTime);                         // 가변저항 값만큼 지연
  lcd.setCursor(4,1);                       //하단 5번째 위치에 커서를 설정
 
  lcd.write(4);                             // 4번에 저장된 팔 위로 든 사람 그린다.
  delay(delayTime);                         // 가변저항 값만큼 지연
}



