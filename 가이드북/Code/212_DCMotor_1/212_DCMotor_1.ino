
int DCmotor =3;                  // 모터를 트랜지스터 통해 PWM 3번 핀에 연결

void setup(){
  pinMode(DCmotor, OUTPUT);       // 3번 핀을 출력으로 설정
  Serial.begin(9600);              // 9600 속도로 시리얼 통신 시작

    while(!Serial);
  Serial.println("Input the Value of Speed from 0 to 255");    // 메시지 출력
}


void loop() {

  if(Serial.available()) {         // 시리얼 창에 값이 입력되면
  int speed = Serial.parseInt();        // 입력된 값을 숫자로 바꾸어 speed 변수에 저장
    
    if(speed >=0 && speed <= 255) {       // 0과 255 사이의 값이면
      analogWrite(DCmotor,speed);            // 값에 비례한 속도로 모터를 돌려라.
    }
  }
}

