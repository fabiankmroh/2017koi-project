
void setup() { 
  Serial.begin(9600);            //시리얼 통신을 준비한다. 통신 속도는 9600으로 맞춘다.
 
}

void loop() { 
  Serial.println("Hello ARDUINO STORY~!");   //시리얼 창에 Hello World를 출력한다. 
  delay(1000);                               //1000밀리초 (=1초) 동안 기다린다. 
}

