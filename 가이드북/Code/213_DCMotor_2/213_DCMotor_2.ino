
int DCmotor =3;                  // 모터를 트랜지스터 통해 PWM 3번 핀에 연결

void setup() {
  pinMode(DCmotor, OUTPUT);       // 3번 핀을 출력으로 설정
} 


void loop() {
  for(int i =0; i <256; i++)  {      // 0~255까지 1씩 증가하면서 
    analogWrite(DCmotor, i);             // 모터의 속도를 증가시키며 돌려라.
    delay(50);                           // 50밀리초동안
  }
  delay(3000);                      // 3초동안 지연
  
  for(int i =255; i >=0; i--) {     // 255~ 0까지 1씩 감소하면서 
    analogWrite(DCmotor,i);              // 모터의 속도를 감소시키며 돌려라.
    delay(50);                           // 50밀리초동안
  }
  
  delay(3000);                     // 3초동안 지연
}

