
int led = 9;           // 아날로그 출력 (PWM) LED핀을 9번에 설정

void setup() {
   // analogWrite 구동되는 핀은 출력 선언하지 않아도 된다.
}                           

void loop() {
  
  for(int fadeValue =0 ; fadeValue <=255; fadeValue +=5) {  
                                               // 0 ~ 255 사이의 값을 5씩 늘리면서 
    analogWrite(ledPin,fadeValue);                // 점점 밝게 LED 켜라
              
    delay(30);                                    // 30밀리초 기다림
  }

  for(int fadeValue =255 ; fadeValue >=0; fadeValue -=5) {
                                               // 255 ~ 0 사이의 값을 5씩 줄이면서 
    analogWrite(ledPin,fadeValue);                   // 점점 어둡게 LED 켜라
   
    delay(30);
  }
}

