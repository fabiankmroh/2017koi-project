
int buzzer =8;                  // 부저를 8번 핀에 연결

void setup(){
  pinMode(buzzer, OUTPUT);      // 부저를 출력으로 설정
}


void setup() {
  digitalWrite(buzzer,HIGH);       // 부저 소리를 내라
  delay(50);                          // 50밀리초 동안
  digitalWrite(buzzer,LOW);       // 부저 소리를 꺼라
  delay(100);                         // 100밀리초 동안
}

