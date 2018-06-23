
#include <Servo.h>       // 서보 라이브러리 포함

Servo myservo;           // 서보를 제어하기 위한 객체 myservo 생성, 최대 12개 생성가능

int potpin =0;           // 가변 저항을 A0핀에 연결
int val;                 // 가변저항 값을 저장할 변수 설정

void setup() {
  myservo.attach(9);      // 9번 핀에 서보 모터 부착
}


void loop() {
  val =analogRead(potpin);        // 가변 저항 값 읽어 저장 ( 0 ~ 1023)
  val =map(val,0,1023,0,180);     // 가변 저항 값 맵핑 ( 0~ 180)
  myservo.write(val);             // 서보의 위치 설정
  delay(15);                      // 서보가 도착할 때 까지 기다린다.
}

