int W_Sensor =A0;       // 센서를 아날로그 A0핀에 연결
int sensorVal;          // 센서값을 저장하는 변수
 
void setup() {
  Serial.begin(9600);   // 9600속도로 시리얼 통신 시작
}


void loop() {
  sensorVal = analogRead(W_Sensor);    // 센서 값을 읽어 저장
 
  Serial.print("sensor value : ");     // 시리얼 창에 줄 바꿈 없이 메시지 출력
  Serial.println(sensorVal);           // 센서 값 출력후 줄 바꿈
 
  delay(1000);                         // 1초 지연
}

