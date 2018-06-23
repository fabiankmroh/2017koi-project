
const int buttonPin =2;     // 버튼 스위치 핀을 2번으로 설정
const int ledPin = 13;      // LED 핀을 13번으로 설정 

int buttonState =0;       // buttonState 변수는 버튼 스위치 상태를 저장, 0으로 초기화

void setup() {
  pinMode(ledPin, OUTPUT);   // LED 핀을 출력으로 설정
  pinMode(buttonPin, INPUT);  // 버튼스위치 핀을 입력으로 설정
}


void loop() {
 
  buttonState =digitalRead(buttonPin);   // 버튼 상태를 읽어 buttonState 변수에 저장

  if(buttonState == HIGH) {              // 버튼이 눌렸다면(HIGH) 
    digitalWrite(ledPin,HIGH);               // LED를 켜고   

  } else{                                // 버튼이 눌려있지 않다면
    digitalWrite(ledPin,LOW);               // LED를 끈다
  }
}

