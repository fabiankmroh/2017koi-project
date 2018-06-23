
const int ledPin = 9;           // 아날로그 출력 (PWM) LED핀을 9번에 설정

void setup() {
  Serial.begin(9600);           // 9600 속도로 시리얼 통신 시작
  
  pinMode(ledPin,OUTPUT);        // 9번LED 핀을 출력으로 설정
                                // analogWrite 구동되는 핀은 출력 선언하지 않아도 된다. 
  }
                           

void loop() {
  byte brightness;                // brightness는 8비트 (0 ~255) 값을 저장하는 변수

 
  if (Serial.available()) {               //시리얼 데이터가 입력이 되면
    
    brightness =Serial.read();           // 0 ~255 사이의 값을 바이트로 읽어 저장
    
    analogWrite(ledPin,brightness);      // 설정된 밝기로LED켜라
  }
}

