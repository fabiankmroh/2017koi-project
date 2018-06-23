
int PIRpin =2;               // 적외선센서2번핀에연결
int led =13;                 // LED를13번핀에연결
int PIRstate =0;             // PIR 상태를꺼짐으로초기화
int sensorRedaing =0;        // 센서 값0 (LOW) 으로초기화

void setup() {
  pinMode(PIRpin, INPUT);    // 적외선센서의핀을INPUT모드로선언
  pinMode(led, OUTPUT);      // 13번LED센서의핀을OUTPUT모드로선언

  Serial.begin(9600);        // 시리얼통신속도설정
}


void loop() {

  sensorRedaing = digitalRead(PIRpin);  // 적외선 인체 감지 센서에서 값을 읽는다.

  
  if(sensorRedaing == HIGH) {           // 센서 값이HIGH(1)일 경우
    digitalWrite(led, HIGH);              // LED를켜고

    if(PIRstate == LOW) {                 // PIR 상태가꺼짐이면
      Serial.println("Detected!");        // 시리얼창에 Detected를 프린트
      PIRstate = HIGH;                    // PIR 상태를 켜짐으로 바꾼다.
    }
  }

  else{                                // 센서 값이LOW(0)일경우
    digitalWrite(led, LOW);               // LED를끄고

    if(PIRstate == HIGH) {                // PIR 상태가 켜짐이면
      Serial.println("Ended");            // 시리얼창에 Ended를 프린트
      PIRstate = LOW;                     // PIR 상태를 꺼짐으로 바꾼다
    }
  }
}

