
void setup(){
 Serial.begin(9600);                     // 9600 속도로 시리얼통신 시작
 Serial.println(" LM35DZ센서이용 ");
 Serial.println(" 온도 읽기 ");          // A0핀에 온도센서 연결. 아날로그 입력생략.
}

void loop() {
    int Val = analogRead(A0);        // 아날로그 A0핀의 온도센서 값(0~1023)을 읽는다.
    float Voltage =Val * 5.0 / 1024;      // 실제 전압 값을 구한다.
    float TempC = Voltage * 100;                  // 전압 값을 섭씨온도로 변환한다.
    float TempF = TempC * 9.0 / 5.0 + 32.0;       // 전압 값을 화씨온도로 변환한다.

    Serial.println(TempC);                // 섭씨 온도 출력
    Serial.println(“ Celsius”);
    Serial.println(TempF);                // 화씨 온도 출력
    Serial.println(“ Fahrenheit”);
    delay(1000);
}

