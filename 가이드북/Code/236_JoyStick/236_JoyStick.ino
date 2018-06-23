
int JoyStick_X =A0;        // x축을 아날로그 A0핀에 연결
int JoyStick_Y =A1;        // y축을 아날로그 A1핀에 연결
int JoyStick_SW =3;        // 버튼스위치를3번 핀에 연결

void setup() {
  pinMode(JoyStick_SW, INPUT_PULLUP);   // 스위치에 내부 풀업저항 사용
  Serial.begin(9600);                   // 9600 속도로 시리얼 통신 시작
}


void loop() {
  int x, y, sw;
  
  x = analogRead(JoyStick_X);      // X축의 아날로그 값을 읽어 저장
  y = analogRead(JoyStick_Y);      // Y축의 아날로그 값을 읽어 저장
  sw = digitalRead(JoyStick_SW);   // 버튼 스위치의 상태 저장(0 or 1)
  
  Serial.print(x);              // X축 값 프린트하고 줄 바꿈 없음
  Serial.print("  ");
  Serial.print(y);              // Y축 값 프린트 하고 줄 바꿈 없음
  Serial.print("  ");
  Serial.println(sw);           // 버튼 상태(누르면 0, 안 누르면 1) 프린트하고 줄 바꿈
  delay(100);                   // 0.1초 대기
}


