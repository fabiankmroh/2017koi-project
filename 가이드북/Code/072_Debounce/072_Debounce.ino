
const int buttonPin =2;     // 버튼 스위치 핀을 2번으로 설정
const int ledPin = 13;      // LED 핀을 13번으로 설정 

int ledState =HIGH;          // 출력핀을 HIGH로 설정
int buttonState;             // 현재 버튼 스위치 상태를 읽어 저장하는 변수
int lastButtonState =LOW;    // 이전 버튼 스위치 상태를 읽어 저장. LOW로 초기화

unsigned long lastDebounceTime =0;    // 출력핀이 마지막으로 전환된 시간 저장.
unsigned long debounceDelay =50;      // 안정된 상태가 될 때까지 기다리는 시간 (밀리초) 

void setup() {
  pinMode(ledPin, OUTPUT);             // LED 핀을 출력으로 설정
  pinMode(buttonPin, INPUT);           // 버튼스위치 핀을 입력으로 설정

  digitalWrite(ledPin,ledState);       // ledState에 따라 LED를 켜고 끈다 
}


void loop() {
 
  int reading = digitalRead(buttonPin);   // 버튼 상태를 읽어 reading 변수에 저장

  if(reading != lastButtonState) {     // 노이즈 또는 누르기로 버튼 상태가 변경되면
    
    lastDebounceTime =millis();          // debouncing timer를 재설정하고
  }
    
  // 읽은 값이 무엇이든 debounce 지연보다 오래 있었으면
  if((millis() -lastDebounceTime) > debounceDelay) { 
    if(reading != buttonState) {             // 버튼 상태가 바뀌면
      buttonState =reading;                 // 버튼 상태를 저장하고

      if(buttonState ==HIGH) {                       // 새로운 버튼 상태가 HIGH면
        ledState =!ledState;                         // LED 상태를 바꾼다 
      }
    }
  }
 
  digitalWrite(ledPin,ledState);         // ledState에 저장된 값으로 LED를 on/off 
  // reading변수의 값을 lastButtonState (다음 loop에서 사용)에 저장 
  lastButtonState =reading;
}


