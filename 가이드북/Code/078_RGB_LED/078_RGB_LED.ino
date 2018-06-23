
int R_led =2;                  //2번핀에R핀연결
int G_led =3;                  //3번핀에G핀연결
int B_led =4; ;                //4 번핀에B핀연결
 
void setup() {
  pinMode(R_led, OUTPUT);     // 2번핀을출력으로설정
  pinMode(G_led, OUTPUT);     // 3번핀을출력으로설정
  pinMode(B_led, OUTPUT);     // 4번핀을출력으로설정

  Serial.begin(9600);         // 9600속도로시리얼통신시작
}


void loop() {
   Serial.println("RED on");        // 빨간색 LED 켜짐
    digitalWrite(R_led,HIGH);
    digitalWrite(G_led,LOW);
    digitalWrite(B_led,LOW);
    delay(1000);                    // 1초 동안

    Serial.println("GREEN on");       // 초록색 LED 켜짐
    digitalWrite(R_led,LOW);
    digitalWrite(G_led,HIGH);
    digitalWrite(B_led,LOW);
    delay(1000);                      // 1초 동안

    Serial.println("BLUE on");        // 파란색 LED 켜짐
    digitalWrite(R_led,LOW);
    digitalWrite(G_led,LOW);
    digitalWrite(B_led,HIGH);
    delay(1000);                     // 1초 동안    

    Serial.println("Yellow on");      // 노란색 LED 켜짐
    digitalWrite(R_led,HIGH);
    digitalWrite(G_led,HIGH);
    digitalWrite(B_led,LOW);
    delay(1000);                      // 1초 동안 

    Serial.println("Magenta on");     // 자주색 LED 켜짐
    digitalWrite(R_led,HIGH);
    digitalWrite(G_led,LOW);
    digitalWrite(B_led,HIGH);
    delay(1000);                      // 1초 동안 

   Serial.println("Cyan on");         // 청록색 LED 켜짐
   digitalWrite(R_led,LOW);
   digitalWrite(G_led,HIGH);
   digitalWrite(B_led,HIGH);
   delay(1000);                       // 1초 동안 

   Serial.println("White on");        // 흰색 LED 켜짐
   digitalWrite(R_led,HIGH);
   digitalWrite(G_led,HIGH);
   digitalWrite(B_led,HIGH);
   delay(1000);                       // 1초 동안 
}

