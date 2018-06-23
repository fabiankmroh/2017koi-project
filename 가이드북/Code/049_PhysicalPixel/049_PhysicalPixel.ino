const int ledPin =13;         //  LED pin을 13번으로 설정
int incomingByte;             //  시리얼 데이터를 저장하기 위한 정수형 변수 설정

void setup() {
  
  Serial.begin(9600);         //  9600속도로 시리얼 통신 시작
 
  pinMode(ledPin,OUTPUT);     // LED pin을 출력으로 설정
}

void loop() {
                             
  if(Serial.available() >0) {            // 시리얼 데이터가 들어오면 
  
    incomingByte =Serial.read();         // 데이터를 읽어서 incomingByte 변수에 넣고
   
    if(incomingByte =='H') {                    // incomingByte 변수에 들어오 값이 H면
      digitalWrite(ledPin,HIGH);                // LED를 켜라.
    }
    
    if(incomingByte =='L') {                    // incomingByte 변수에 들어오 값이 L면
      digitalWrite(ledPin,LOW);                 // LED를 꺼라.
    }
  }
}

