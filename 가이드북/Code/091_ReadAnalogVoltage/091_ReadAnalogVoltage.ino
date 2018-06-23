
void setup() {
 
  Serial.begin(9600);    // 9600 속도로 시리얼 통신 시작
                         // 아날로그 입출력 핀은 선언하지 않아도 된다. 
}                       

void loop() {

                                       // 가변저항의 가운데 핀을 A0핀에 연결 
  int sensorValue = analogRead(A0);    // 가변저항 값을 읽어 sensorValue에 저장
                                       // sensorValue에는 0~1023 범위의 정수 값이 저장

  float voltage =sensorValue *(5.0 /1023.0);     //아날로그 판독 값을 전압 0~5V 로 변환
                                       // 연산 결과 값이 실수형이므로 float 변수에 저장
  Serial.println(voltage);             // 전압값을 읽어 시리얼 창에 한 줄씩 프린트
}

