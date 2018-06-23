
const int knockSensor = A0;       // 피에조 부저를 아날로그 핀 A0에 연결
const int threshold = 3 ;         // 노크인지 결정할 임계 값

int sensorReading = 0;            // 센서 핀에서 읽은 값을 저장하는 변수. 0으로 초기화

void setup() {
  Serial.begin(9600);            // 9600 속도로 시리얼 통신 시작
}

void loop() {
     
  sensorReading = analogRead(knockSensor);   // 센서값을 읽어 저장                   
     
  while(sensorReading <threshold) {   // 센서값이 3보다 작으면
                                           // 아무것도 안한다.
  }
                                      // 센서값이 3이상이면 
  Serial.print(sensorReading);            // 시리얼 창에 센서값을 줄바꿈 없이 출력 
  Serial.println(" Knock!");              // 시리얼 창에 Knock! 출력하고 줄바꿈

  tone(knockSensor, 2093, 100);           // 부저를 7옥타브 도로 100밀리초간 소리낸다
  delay(250);                             // 250밀리초 지연

  noTone(knockSensor);                    // 소리 해제
  pinMode(knockSensor,INPUT);             // 피에조 부저를 다시 입력핀으로 설정
}

