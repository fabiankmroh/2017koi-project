
const int analogPin =A0;    // 가변저항 가운데 핀을 A0에 연결
const int ledPin =13;       //  LED를 13번 핀에 연결
const int threshold =400;   // 아날로그 입력 범위의 임의의 임계값을 400으로 설정

void setup() {
  
  pinMode(ledPin, OUTPUT);   // LED를 출력 핀으로 설정
  
  Serial.begin(9600);        // 9600속도로 시리얼 통신 시작
}

void loop() {
  
  int analogValue = analogRead(analogPin);  // 가변저항 값을 읽어 analogValue에 저장

  
  if(analogValue > threshold) {     // analogValue에 저장된 값이 400보다 크면
    digitalWrite(ledPin, HIGH);     // LED를 켜고
  } else{                           // analogValue에 저장된 값이 400보다 작거나 같으면
    digitalWrite(ledPin, LOW);      // LED를 꺼라
  }


  Serial.println(analogValue);     // analogValue의 값을 시리얼 창에 한 줄씩 나타내라
  delay(1);                        // 안정적으로 읽을 수 있게 1밀리초 기다림
}

