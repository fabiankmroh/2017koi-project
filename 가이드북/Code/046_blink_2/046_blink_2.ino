int ledPin = 13;               //ledPin이라는 변수에 LED와 연결될 핀 번호 13번 저장
 
void setup() {
  pinMode(ledPin,OUTPUT);       // 13번핀이 출력모드(OUTPUT)로 설정
}

void loop() { 
  digitalWrite(ledPin,HIGH);   // 13번 핀에 디지털 신호 1 (HIGH) 을 준다. LED 켜짐 
  delay(1000);                 // 1000밀리초 (=1초) 동안 기다린다. 
    digitalWrite(ledPin,LOW);  // 13번 핀에 디지털 신호 0 (LOW) 을 준다. LED 꺼짐
  delay(1000);                 // 1000밀리초 (=1초) 동안 기다린다. 
}

