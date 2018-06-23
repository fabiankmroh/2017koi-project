
int led = 9;           // 아날로그 출력 (PWM) LED핀을 9번에 설정
int brightness =0;     // LED 밝기를 저장하는 변수
int fadeAmount =5;     // fade 저장 변수 

// the setup routine runs once when you press reset:
void setup() {
  
  pinMode(led,OUTPUT);      // 9번 핀을 출력으로 선언 
}                           // analogWrite 구동되는 핀은 출력 선언하지 않아도 된다. 


void loop() {
  
  analogWrite(led,brightness);       // 9번 핀의 밝기를 설정

   brightness = brightness + fadeAmount;   // 루프를 돌때마다 fadeAmount만큼 밝기 변화
 
  if (brightness <= 0 || brightness >= 255) {    // 밝기변화의 양 끝이면 
    fadeAmount = -fadeAmount;                       // 방향을 바꾼다
  }
   
  delay(30);                                       // 30밀리초 기다린다.
}


