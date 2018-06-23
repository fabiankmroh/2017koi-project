const int sensorPin =A0;    // A0핀에 조도센서 연결
const int ledPin =9;        // 9번 핀에 LED 연결

int sensorValue =0;         // 조도 센서 값을 저장
int sensorMin =1023;        // 센서 최솟값을 1023으로 설정
int sensorMax =0;           // 센서 최댓값을 0으로 설정


void setup() {
 
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  while(millis() < 5000) {                     // 5초동안
    sensorValue = analogRead(sensorPin);           //센세 값을 읽어 저장

    if(sensorValue > sensorMax) {                  //센서 값이 최댓값 보다 크면
      sensorMax = sensorValue;                           // 최댓값으로 재설정
    }

    if(sensorValue < sensorMin) {                  //센서 값이 최솟값 보다 작으면
      sensorMin = sensorValue;                           // 최솟값으로 재설정
    }
  }

  digitalWrite(13,LOW);                            // LED 끈다. 보정 끝. 
}

void setup() {
 
  sensorValue = analogRead (sensorPin);

  // 센서값을 읽어 0~255 값으로 변환
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  // 0~255 값을 벗어날 때
  sensorValue = constrain(sensorValue, 0, 255);

  
  analogWrite(ledPin,sensorValue);    // 센서값으로 LED 밝기를 조절
}


