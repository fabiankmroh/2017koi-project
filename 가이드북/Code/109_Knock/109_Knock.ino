
const int ledPin =13;       // LED를 13번 핀에 연결
const int knockSensor =A0;  // 피에조 부저를 아날로그 핀 A0에 연결
const int threshold =100;   // 노크인지 결정할 임계 값

int sensorReading =0;      // 센서 핀에서 읽은 값을 저장하는 변수. 0으로 초기화
int ledState = LOW;        // 마지막 LED 상태를 저장하는 변수. LED를 끈 상태로 초기화

void setup() {
  pinMode(ledPin, OUTPUT);  // LED핀을 OUTPUT으로 설정
  Serial.begin(9600);       // 9600속도로 시리얼 통신 시작
}


void loop() {
  
  sensorReading = analogRead(knockSensor); // 센서 값을 읽어 sensorReading 변수에 저장

  
  if(sensorReading >= threshold) {     //센서 값이 100보다 크면
    
    ledState =! ledState;                   // LED 상태를 반전 (LOW->HIGH)
    
    digitalWrite(ledPin,ledState);          // LED를 켜라
    
    Serial.println("Knock!");               // 시리얼 창에 “Knock!”를 프린트
  }
  delay(100);                // 직렬 포트 버퍼 오버로드를 피하기 위해 100밀리초 지연
}

