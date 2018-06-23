
#include <Stepper.h>
 
const int stepsPerRevolution = 32;  // 스텝 수. 모터 당 스텝 수에 맞게 바꿀 수 있다.

Stepper myStepper(stepsPerRevolution,8,9,10,11); //객체생성. 아두이노 8~11번 핀에 연결

void setup() {
  myStepper.setSpeed(60);           // 60 rpm로 속도 조절. 0~200 범위
  Serial.begin(9600);               // 9600속도로 시리얼 통신 시작
}


void loop() {
  Serial.println("clockwise");                   // 시리얼 모니터에 시계방향 출력
  myStepper.step(stepsPerRevolution);            // 시계방향으로 한바퀴 회전
  delay(500);

  Serial.println("counterclockwise");            // 시리얼 모니터에 반 시계방향 출력
  myStepper.step(- stepsPerRevolution);          // 반시계방향으로 한바퀴 회전
  delay(500);
}

