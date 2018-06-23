
const int buttonPin =2;     // 버튼 스위치 핀을 2번으로 설정
const int ledPin = 13;      // LED 핀을 13번으로 설정 

int buttonPushCounter =0;        // 버튼 누른 횟수를 저장하는 변수
int buttonState = 0;             // 현재 버튼 스위치 상태를 읽어 저장하는 변수
int lastButtonState = 0;         // 이전 버튼 스위치 상태를 읽어 저장

void setup() {
  pinMode(ledPin, OUTPUT);             // LED 핀을 출력으로 설정
  pinMode(buttonPin, INPUT);           // 버튼스위치 핀을 입력으로 설정

  Serial.begin(9600);                  // 9600속도로 시리얼 통신 초기화
}

void loop() {
  
  buttonState =digitalRead(buttonPin);  // 버튼 스위치 값을 읽어 buttonState에 저장

  
  if(buttonState != lastButtonState) {  // 버튼 상태가 바뀌었으면
    
    if(buttonState == HIGH) {               // 버튼이 off에서 on으로 바뀌었으면
      
      buttonPushCounter ++;                      // 버튼누른 횟수를 증가
      Serial.println("on");                      // 시리얼 창에 “on” 쓰고 줄바꿈
      Serial.print("number of button pushes: "); // 시리얼 창에 “~: ” 쓰고 
      Serial.println(buttonPushCounter);         // 연결해서 버튼 누른 횟수 쓰고 줄바꿈 
    } else{                                // 버튼이 on에서 off으로 바뀌었으면
     
      Serial.println("off");                     // 시리얼 창에 “off” 쓰고 줄바꿈
    }
    
    delay(50);                               //바운싱을 방지하기 위해 50밀리초 지연
  }
    
    
   //현재 buttonstate를 다음 루프에서 lastButtonState로 사용
  lastButtonState = buttonState;  

    
  if(buttonPushCounter %4 == 0) {      // 버튼 누른 횟수를 4로 나누어 떨어지면    
    digitalWrite(ledPin,HIGH);           // LED 켠다
  } else{                              // 버튼 누른 횟수가 4의 배수가 아니면
    digitalWrite(ledPin,LOW);            // LED 끈다 
  }

