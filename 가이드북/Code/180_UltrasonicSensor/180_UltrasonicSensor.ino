void setup() {
  pinMode(13,OUTPUT);     // 13번에tiger핀연결
  pinMode(12,INPUT);      // 12번 핀에 echo핀 연결

  Serial.begin(9600);    // 9600속도로 시리얼 통신 시작
}


void loop() {

  float Duration,Distance;

  digitalWrite(13, HIGH);                       // 초음파 쏜다.
  delay(10);                                    // 10밀리초 동안
  digitalWrite(13, LOW);                        // 초음파 끈다.

  Duration =pulseIn(12, HIGH);                 //  echo핀이HIGH 유지한 시간 저장
  Distance =((float)(340 *Duration) /10000) /2;             //거리를 cm로환산

  Serial.print(Distance);                     // 시리얼 창에 줄바꿈 없이 거리 출력
  Serial.println("cm");                       // 단위 출력

}

