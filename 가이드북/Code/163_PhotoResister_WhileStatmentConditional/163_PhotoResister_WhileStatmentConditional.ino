
const int sensorPin = A0;         // A0핀에 조도센서 연결
const int ledPin = 9;             // 9번 핀에LED 연결
const int indicatorLedPin = 13;   // 13번 핀에 내장 LED가 연결
const int buttonPin = 2;          // 2번핀에 버튼 스위치 연결

int sensorMin = 1023;             // 최소 센서값
int sensorMax = 0;                // 최대 센서값
int sensorValue =0;               // 센서에서 읽은 값을 저장. 0으로 초기화
  

void setup() {
 
  pinMode(indicatorLedPin, OUTPUT);      // 내장 LED를 출력핀으로 설정
  pinMode(ledPin, OUTPUT);               // 9번 LED를 출력핀으로 설정
  pinMode(buttonPin, INPUT);             // 버튼 스위치를 입력핀으로 설정
}


void loop() {

  while(digitalRead(buttonPin) == HIGH) {    // 버튼 스위치가 눌려져 있으면
    calibrate();                                 // calibrate( )함수를 호출해서 보정
  }

  digitalWrite(indicatorLedPin, LOW);        // 보정이 끝나면 내장 LED를 끈다

  sensorValue = analogRead(sensorPin);       // 조도 센서값을 읽어 저장
  sensorValue = map(sensorValue,sensorMin,sensorMax, 0, 255);  //센서값을 0~255로 보정
  sensorValue = constrain(sensorValue, 0, 255);   // 센서값이 보정 범위를 벗어나면 제한

  analogWrite(ledPin, sensorValue);   // 보정된 값으로 LED 밝기를 조절한다.
}


void calibrate() {

  digitalWrite(indicatorLedPin, HIGH);              // 내장 LED를 켜라

  sensorValue = analogRead(sensorPin);             // 조도 센서의 값을 읽어 저장

  if(sensorValue > sensorMax) {               // 조도 센서의 값이 1023보다 크면
    sensorMax = sensorValue;                       // 센서 값을 읽어 sensorMax에 저장
  }

  if (sensorValue < sensorMin) {             // 조도 센서의 값이 0보다 작으면
    sensorMin = sensorValue;                       // 센서 값을 읽어 sensorMin에 저장
  }
}


