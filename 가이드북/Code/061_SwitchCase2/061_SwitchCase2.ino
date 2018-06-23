void setup() {
  
  Serial.begin(9600);                          // 9600속도로 시리얼 통신 시작
  
  for(int thisPin =2; thisPin <7; thisPin++) {  // 2~6번 핀을LED 출력으로 설정
    pinMode(thisPin, OUTPUT);
  }
}

void loop() {
 
  if(Serial.available() >0) {        // 시리얼 데이터가 들어오면
    int inByte =Serial.read();       //  데이터 값을 읽어 inByte 변수에 저장


    switch(inByte) {               //받은 문자에 따라 다른 실행을 해라.       
      case 'a':                         // inByte 변수에 저장값이 ‘a’ 일 경우
        digitalWrite(2,HIGH);                 // 2번 LED를 켠다
        break;                                
      case 'b':                         // inByte 변수에 저장값이 ‘b’ 일 경우
        digitalWrite(3,HIGH);                 // 3번 LED를 켠다
        break;
      case 'c':                         // inByte 변수에 저장값이 ‘c’ 일 경우
        digitalWrite(4,HIGH);                 // 4번 LED를 켠다
        break;
      case 'd':                         // inByte 변수에 저장값이 ‘d’ 일 경우
        digitalWrite(5,HIGH);                 // 5번 LED를 켠다
        break;
      case 'e':                         // inByte 변수에 저장값이 ‘e’ 일 경우
        digitalWrite(6,HIGH);                 // 6번 LED를 켠다
        break;
       
      default:                         // 위 case에 일치하는 것이 없으면
        for(int thisPin =2; thisPin <7; thisPin++) {        // 2~6번 LED를 모두 끈다.
          digitalWrite(thisPin, LOW);
        }
    }
  }
}

