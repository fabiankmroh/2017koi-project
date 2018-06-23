#define touchPin 2              // 터치 센서를 2번 핀에 연결
 
int ledPin =13;                // 13번에 연결된 내장 LED
 
void setup() {
  Serial.begin(9600);         // 9600속도로 시리얼 통신 시작
  pinMode(ledPin, OUTPUT);    // LED를 출력핀으로 설정
  pinMode(touchPin, INPUT);   // 터치 센서를 입력핀으로 설정
}


void loop() {
  int touchValue = digitalRead(touchPin);      // 터치 센서 상태를 저장

  if(touchValue == HIGH){                      // 터치 센서가 눌렸으면
    digitalWrite(ledPin,HIGH);                   // LED켜고
    Serial.println("TOUCHED");                   // 시리얼창에 TOUCHED 프린트한다.
  }

  else{                                        // 터치 센서가 안 눌렸으면
    digitalWrite(ledPin,LOW);                    // LED끄고
    Serial.println("not touched");               // 시리얼창에 not touched 프린트한다.
  } 
  delay(500);                                    // 0.5초 동안
  
}

