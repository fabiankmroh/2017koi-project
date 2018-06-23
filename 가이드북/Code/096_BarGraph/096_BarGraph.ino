
const int analogPin =A0;    // 가변저항 가운데 핀을 A0에 연결
const int ledCount =10;     // 막대그래프로 나타낼 LED의 수를 10개로 설정

int ledPins[] = {
  2,3,4,5,6,7,8,9,10,11     // LED 가 부착된 핀 번호의 배열
};   


void setup() {
  // for문을 이용해 핀을 모두 출력으로 설정
  for(int thisLed =0; thisLed < ledCount; thisLed++) {  
    pinMode(ledPins[thisLed],OUTPUT);
  }
}

void loop() {
  int sensorReading =analogRead(analogPin);                //가변저항 값을 읽어 저장
  
  // 읽어 들인 가변 저항 값 0~1023 값을 LED수 0~10까지 map함수를 이용해 매칭한다.
  int ledLevel = map (sensorReading, 0, 1023, 0, ledCount);   

 
  for (int thisLed = 0; thisLed < ledCount; thisLed ++ ) {
    
    
    if(thisLed < ledLevel) {    // LED핀 인덱스 값이 맵핑된 가변 저항값 보다 작으면
      digitalWrite(ledPins[thisLed],HIGH);   // 작은 인덱스 값을 가진 모든 LED를 켜고
    }
    // turn off all pins higher than the ledLevel:
    else{                      // LED핀 인덱스 값이 맵핑된 가변 저항값 보다 크면
      digitalWrite(ledPins[thisLed],LOW);    // 큰 인덱스 값을 가진 모든 LED를 꺼라
    }
  }
}

