int timer =100;           // 정수형 변수 timer에 100을 넣는다.
int ledPins[] ={          // 정수형 변수 ledPins에 2,7,4,6,5,3 번 핀을 순서대로 배열
  2,7,4,6,5,3
};       
int pinCount =6;           // 정수형 변수 pinCount에 LED 핀의 개수 대입. (배열의 길이)

void setup() {
  
  for(int thisPin =0; thisPin < pinCount; thisPin++) { // thinPin 0부터 5까지 (인덱스)
    pinMode(ledPins[thisPin], OUTPUT);                 // ledPins의 각 핀을 출력으로 
  }
}


void loop() {
 
  for(int thisPin =0; thisPin <pinCount; thisPin++) { //0번~5번 인덱스 순서대로
   
    digitalWrite(ledPins[thisPin],HIGH);             // LED 켠다.
    delay(timer);                                    // 100밀리초동안 기다린다.

    digitalWrite(ledPins[thisPin],LOW);              // LED끈다. 
   }  


  for(int thisPin = pinCount -1; thisPin >=0; thisPin--) { //5번~0번 인덱스 순서대로
    
    digitalWrite(ledPins[thisPin], HIGH);            // LED 켠다.
    delay(timer);                                    // 100밀리초동안 기다린다.
    digitalWrite(ledPins[thisPin], LOW);             // LED끈다.
  }
}


