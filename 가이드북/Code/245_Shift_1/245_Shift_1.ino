
//**************************************************************//
//  Name    : shiftOutCode, Hello World
//  Author  : Carlyn Maw,Tom Igoe, David A. Mellis
//  Date    : 25 Oct, 2006
//  Modified: 23 Mar 2010
//  Version : 2.0
//  Notes   : Code for using a 74HC595 Shift Register           //
//          : to count from 0 to 255
//****************************************************************


int atchPin = 8;           // 74HC595의 ST_CP를 8번 핀에 연결  

int lockPin = 12;          // 74HC595의 SH_CP를 12번 핀에 연결

int ataPin = 11;           // 74HC595의 DS 핀을 11번에 연결


void setup() {
  pinMode(latchPin,OUTPUT);      // 래치 핀을 출력으로 설정
  pinMode(clockPin,OUTPUT);      // 클럭 핀을 출력으로 설정
  pinMode(dataPin,OUTPUT);       // 데이터 핀을 출력으로 설정
}

void loop() {
  // LED로 0 ~ 255 까지 카운트 숫자 표시
  
  for (int numberToDisplay =0; numberToDisplay <256; numberToDisplay++) {
   
    digitalWrite(latchPin,LOW);    // 래치 핀에 LOW신호. LED는 비트를 줄때까지 안 켜짐
    
    shiftOut(dataPin,clockPin,MSBFIRST,numberToDisplay);  // 비트 이동

    digitalWrite(latchPin,HIGH);         //래치 핀을 HIGH 신호 줘서 LED가 켜지게 한다.
   
    delay(500);           // 다음 값까지 0.5초 지연
  }
}  


