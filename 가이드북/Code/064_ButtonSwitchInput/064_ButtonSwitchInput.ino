void setup() {
  
  Serial.begin(9600);
 
  pinMode(2, INPUT);                     // 2번 핀을 버튼 스위치 입력 핀으로 설정
  pinMode(13, OUTPUT);                   // 내장 LED핀을 출력으로 설정

}

void loop() {
  
  int sensorVal = digitalRead(2);  // sensorVal 변수에 2번 핀의 버튼 입력 값을 받는다.
  
  Serial.println(sensorVal);       // 버튼의 값을 시리얼 창에 한 줄씩 나타내라.

 
  if(sensorVal == HIGH) {          // 버튼이 눌려있으면 
    digitalWrite(13, HIGH);        // LED 켜고
  } else{                          // 버튼이 안 눌려 있으면
    digitalWrite(13, LOW);         // LED를 꺼라
  }
}

