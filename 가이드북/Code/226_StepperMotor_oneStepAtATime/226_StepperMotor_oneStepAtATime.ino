
#include <Stepper.h>
 
const int stepsPerRevolution = 32;  // 스텝 수. 모터 당 스텝 수에 맞게 바꿀 수 있다.

Stepper myStepper(stepsPerRevolution,8,9,10,11); //객체생성. 아두이노 8~11번 핀에 연결

int stepCount =0;                 // 모터의 스텝수를 저장

void setup() {  
  Serial.begin(9600);             // 9600속도로 시리얼 통신 시작
}


void loop() {

  myStepper.step(1);                   // 모터를 한 단계 수행
  Serial.print("steps:");              // steps:를 시리얼 창에 줄바꿈 없이 출력
  Serial.println(stepCount);           // 시리얼 창에 스텝 수 출력 후 줄바꿈
  stepCount++;                         // 스텝수 1 증가
  delay(500);                          // 0.5초 기다림

}

