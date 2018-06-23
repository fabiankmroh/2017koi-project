
int relayPin =3;
int sensorPin =A0;
int sensorValue;                      // 센서값을 읽어 저장
int threshold =300;                   // 센서의 임계값. 바꿀 수 있다.

void setup() {
  pinMode(Relaypin, OUTPUT);          // 릴레이를 출력으로 설정
  pinMode(sensorPin, INPUT);          // 조도센서를 입력으로 설정
}


void loop() {

  sensorValue =analogRead(sensorPin);
  
  if(sensorValue <=threshold) {             // 조도센서값이임계값이하이면
    digitalWrite(Relaypin,HIGH);              // 1채널릴레이ON
    delay(500);

  } else {                                 // 조도센서값이임계값초과하면
    digitalWrite(Relaypin,LOW);              // 1채널릴레이OFF
    delay(500);
  }
}

