
const int in1 =6;               // 6번 핀으로 모터의 in1 제어
const int in2 =2;               // 2번 핀으로 모터의 in2 제어
const int enA = 9;              // 9번 핀으로 모터의 속도 제어

void setup() {
  pinMode(in1, OUTPUT);    // 6번 핀을 출력핀으로 설정
  pinMode(in2, OUTPUT);    // 2번 핀을 출력핀으로 설정
  pinMode(enA, OUTPUT);    // 9번 핀을 출력핀으로 설정

  Serial.begin(9600);     // 9600속도로 시리얼 통신 시작
}


void loop() {
  if (Serial.available()) {       //시리얼모니터에서데이터가들어오면
    char input_data;                     // 시리얼 창에서 입력한 값을 저장하는 변수
    in_data =Serial.read();              // 입력 값이 in_data에저장

    if(input_data =='1') {                // 입력 값이 '1'이면
      digitalWrite(in1, HIGH);               // 정방향 회전
      digitalWrite(in2, LOW);                 
      analogWrite(enA, 255);                  // 최고 속도로 
                                              //값을 0~255 사이의 값으로 변환해보자
    }

    if (input_data =='2') {              // 입력 값이 '2'면
      digitalWrite(in1,LOW);                 // 역방향 회전
      digitalWrite(in2,HIGH);               
      analogWrite(enA, 125);                // 중간 속도로 
    }

    else {                                // 입력 값이 1이나 2가 아니면
      digitalWrite(in1,LOW);                  //회전정지
      digitalWrite(in2,LOW);                  
    }
  }
}


