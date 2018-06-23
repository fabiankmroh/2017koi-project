int timer =100;           // delay 시간을 먼저 설정

void setup() {
  // for문을 사용하여 2번부터 7번 핀 까지 출력설정
  for(int thisPin =2; thisPin <8; thisPin++) {
    pinMode(thisPin,OUTPUT);
  }
}

void loop() {
  
  for(int thisPin =2; thisPin <8; thisPin++) {   // 2번 핀부터 7번 핀까지 순차적으로
  
    digitalWrite(thisPin,HIGH);                 // LED를 켠다
    delay(timer);                               // 100밀리초 동안 기다리고
    digitalWrite(thisPin,LOW);                  // LED를 끈다.
    }
  

  
  for(int thisPin =7; thisPin >=2; thisPin--) {    // 7번 핀부터 2번 핀까지 순차적으로
    
    digitalWrite(thisPin,HIGH);                    // LED를 켠다
    delay(timer);                                  // 100밀리초 동안 기다리고
    digitalWrite(thisPin,LOW);                     //LED를 끈다.
  }

