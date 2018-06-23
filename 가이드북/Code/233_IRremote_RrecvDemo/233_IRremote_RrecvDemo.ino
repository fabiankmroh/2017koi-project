
#include <IRremote.h>                  // 라이브러리 포함

int RECV_PIN =11;                      // IR 수신센서 신호선을 11번에 연결

IRrecv irrecv(RECV_PIN);               // 수신 객체생성

decode_results results;                // 수신

void setup()
{
  Serial.begin(9600);                  // 9600속도로 시리얼 통신 시작
  Serial.println("Enabling IRin");      // IRpin 초기화를 시리얼 창에 프린트
  irrecv.enableIRIn();                  // 수신시작
  Serial.println("Enabled IRin");       // 초기화 완료를 시리얼 창에 프린트
}


void loop() {
  if(irrecv.decode(&results)) {           // 수신된 내용이 있다면
    Serial.println(results.value, HEX);         // 수신된 값을 시리얼 창에 프린트
    irrecv.resume();                            // 다음 값을 받기 
  }
  delay(100);                            // 100밀리초마다 수신
}

