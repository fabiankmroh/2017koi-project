const int sensorMin =0;
const int sensorMax =900;
void setup() { Serial.begin(9600);
}
// 실험을 통해 발견된 최소 센서값 // 실험을 통해 발견된 최대 센서값
// 9600 속도로 시리얼 통신 시작
    
void loop()
{
  int sensorReading = analogRead(A0); // A0 핀에서 조도 센서값을 읽는다
  Serial.println(sensorReading);
  
  int range = map (sensorReading,sensorMin,sensorMax,0,3);
  switch(range) { // 0~3 범위에 따라
    case 0: Serial.println("dark"); break;
    case 1: Serial.println("dim"); break;
    case 2: Serial.println("medium");
      break;
    case 3:
      Serial.println("bright");
      break; 
  }
  delay(1000);
}

