
#include <Servo.h>         // 서보 라이브러리 포함

Servo myservo;            // 서보를 제어하기 위한 객체 myservo 생성

int pos =0;                // 서보의 위치를 저장. 초기값 0

void setup() {
  myservo.attach(9);      // 9번 핀에 서보 모터 부착
}


void loop() {

  for(pos = 0; pos <= 180; pos += 1) {     // 0 ~180 도 까지 1도 씩 증가하면서
    myservo.write(pos);                        // 지정된 각도로 움직여라
    delay(15);                                 // 서보가 도착할 때 까지 기다린다.
  }

  for(pos = 180; pos >= 0; pos -= 1) {     // 180 ~ 0 도 까지 1도 씩 감소하면서
    myservo.write(pos);                         // 지정된 각도로 움직여라
    delay(15);                                  // 서보가 도착할 때 까지 기다린다.
  }
}

