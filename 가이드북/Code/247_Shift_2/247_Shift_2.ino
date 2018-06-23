
/*
 This sketch turns reads serial input and uses it to set the pins
 of a 74HC595 shift register.

 Created 22 May 2009
 Created 23 Mar 2010
 by Tom Igoe
*/



int atchPin = 8;           // 74HC595의 ST_CP를 8번 핀에 연결  

int lockPin = 12;          // 74HC595의 SH_CP를 12번 핀에 연결

int ataPin = 11;           // 74HC595의 DS 핀을 11번에 연결


void setup() {
  pinMode(latchPin,OUTPUT);      // 래치 핀을 출력으로 설정
  pinMode(clockPin,OUTPUT);      // 클럭 핀을 출력으로 설정
  pinMode(dataPin,OUTPUT);       // 데이터 핀을 출력으로 설정
  Serial.begin(9600);            // 9600속도로 시리얼 통신 시작 
  Serial.println("reset");       // 시리얼창에 메시지 출력후 줄바꿈
}


void loop() {
  if (Serial.available() >0) {
    // ASCII에서 '0'~ '9' 문자는 48~57의 값으로 표현된다.
    // 따라서 0 ~ 9로 실제 값을 얻기 위해 48을 뺀다.
    int bitToSet =Serial.read() -48;
 
    registerWrite(bitToSet,HIGH);   //  HIGH로 설정된 비트를 시프트 레지스터에 쓴다.
  }
}

void registerWrite(int whichPin, int whichState) {

  byte bitsToSend =0;      // 전송할 비트 저장

  digitalWrite(latchPin,LOW);   // 비트를 이동하는 동안 래치핀 출력을 끈다

  bitWrite(bitsToSend,whichPin,whichState);  // bitsToSend의 다음 최상위 비트를 켠다.

  shiftOut(dataPin,clockPin,MSBFIRST,bitsToSend);  // 비트를 시프트 아웃한다

  digitalWrite(latchPin,HIGH);    // LED가 켜지도록 래치 출력을 켠다.
}



