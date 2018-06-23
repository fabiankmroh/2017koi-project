
void setup() {
  Serial.begin(9600);    // 9600 속도로 통신 시작 (디버깅용)
}                        // A0에 조도센서 연결. 아날로그 입출력은 핀모드 생략가능


void loop() {
 
  int sensorReading = analogRead(A0);      // A0핀의 조도 센서값을 읽어 저장
  
  Serial.println(sensorReading);           // 센서 값을 시리얼 창에 프린트 후 줄바꿈

  int thisPitch =map(sensorReading, 400, 1000, 120, 1500);
                                       // 조도 센서 값을 120~1500Hz 소리 주파수로 맵핑

  tone(9, thisPitch, 10);                 // 9번 핀에 연결된 스피커에 10밀리초 출력
  delay(1);                               // 안전성을 위해 1밀리초 지연
}


