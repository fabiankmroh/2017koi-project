const int ledPin = 13;         //  LED pin을 13번으로 설정

int ledState =LOW;             // 정수형 변수 ledState에 LED 값 넣음 (LOW=0)

unsigned long previousMillis =0;   // LED의 상태가 바뀐 시간을 저장하는 변수
                               
const long interval =1000;     // 깜빡이는 간격(1000밀리초)


void setup() {
   pinMode(ledPin,OUTPUT);
}


void loop() {
    unsigned long currentMillis =millis();           //  LED 상태가 변한 시간을 저장

                                                //LED가 깜빡일 시간인지 확인해서
  if(currentMillis -previousMillis >=interval) {    // 조건을 만족하면
       previousMillis = currentMillis;              //previousMillis에 현재 시간을 저장

      if(ledState ==LOW) {     //  LED가 꺼져있으면  
      ledState =HIGH;               //  LED를 켜고
    } else{                    //  LED가 켜져 있으면
      ledState =LOW;               //  LED를 끈다.
    }

       digitalWrite(ledPin,ledState); // ledState가 LOW면 LED끄고 HIGH면 켠다.
  }
}

