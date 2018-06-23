
// 출처: HobbyComponents.com

#define SCL_PIN 8                    // 8번 핀에 SCL핀 연결
#define SDO_PIN 9                    // 9번 핀에 SDO핀 연결

byte Key;                            //키의 상태를 저장

void setup()
  Serial.begin(9600);                // 9600속도로 시리얼 통신 시작

  pinMode(SCL_PIN,OUTPUT);           // 8번 핀을 출력으로 설정
  pinMode(SDO_PIN,INPUT);            // 9번 핀을 입력으로 설정
}


void loop() {
    Key = Read_Keypad();           // Read_Keypad() 함수 호출, 키패드 현재 상태 읽기

  if (Key)                         // 키를 누른 경우
    Serial.println(Key);               // 시리얼 모니터에 출력
    delay(100);                        // 0.1초 지연
}


byte Read_Keypad (void){

  byte Count;             
  byte Key_State =0;


  for (Count =1; Count <= 16; Count++){    // 1~16까지 Count를 하나씩 증가시키면서
  
    digitalWrite(SCL_PIN,LOW); 

    if (! digitalRead(SDO_PIN))
      Key_State =Count;

    digitalWrite(SCL_PIN, HIGH);
  }

  return Key_State;
}


