
int LED =13;            // LED를 13번 핀에 연결 (내장 LED)
int Sensor =A0;         // 아날로그 A0핀에 센서 연결
int threshold =50;      //테스트를 통해 원하는 임계값을 정한다.
int Sound;

void setup() {
  Serial.begin(9600);   // 9600속도로 시리얼 통신 시작
  pinMode(LED,OUTPUT);  // LED연결된 7번 핀을 출력으로 설정
}


void loop() {

  Sound = analogRead(Sensor);     // 센서값을 읽어 저장한다.

// 주변 소리에 대해 센서값을 테스트한다. 이 테스트를 통해 임계값을 수정할 수 있다.
//   Serial.print(Sound);         
//   delay(1000);
   
  if(Sound >= threshold) {         // 센서 값이 임계값 이상이면
   
    Serial.println(" Alarm!!");        // 시리얼창에 메시지를 표시한다.
    digitalWrite(LED,HIGH);            // LED를 켠다.
  
  } else {                         // 센서 값이 임계값 미만이면
    digitalWrite(LED,LOW);             // LED를 끈다.
  }
}

