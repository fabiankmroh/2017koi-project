#include <Keypad.h>

const byte ROWS = 4;    // four rows
const byte COLS = 4;    // four columns

char hexaKeys[ROWS][COLS] ={   // 키패드 버튼 정의. 원하는 대로 바꿀 수 있다.
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] ={5,4,3,2};    //키패드의 행이 연결된 아두이노 핀 번호
byte colPins[COLS] ={6,7,8,9};    //키패드의 열이 연결된 아두이노 핀 번호

//키패드 객체 생성
Keypad customKeypad = Keypad( makeKeymap(hexaKeys),rowPins,colPins,ROWS,COLS); 


void loop() {
  Serial.begin(9600);              // 9600 속도로 시리얼 통신 시작
  }


void loop() {

  charcustomKey = customKeypad.getKey(); // 키패드에서 누른 키를 입력 받는다.
  
  if(customKey){
    Serial.println(customKey);          // 입력받은 문자를 출력한다. 
  }
}



