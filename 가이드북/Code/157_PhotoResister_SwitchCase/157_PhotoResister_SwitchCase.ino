const int sensorMin =0;      // 실험을 통해 발견된 최소 센서값
const int sensorMax =600;    // 실험을 통해 발견된 최대 센서값

void setup() {
  Serial.begin(9600);       // 9600 속도로 시리얼 통신 시작
}


void loop() {
  
  int sensorReading = analogRead(A0);   // A0핀에서 조도 센서값을 읽는다
                                        // 센서값을 0~3까지 4가지로 맵핑한다.
  int range = map (sensorReading,sensorMin,sensorMax,0,3);

  
  switch(range) {           // 0~3 범위에 따라
    case 0:                        // 센서위에 손을 대고 센서 값이 0이 되면
      Serial.println("dark");           // 시리얼창에 dark프린트하고 줄바꿈
      break;
    case 1:                       // 센서위에 손을 가까이 대고 센서 값이 1이 되면
      Serial.println("dim");            // 시리얼창에 dim프린트하고 줄바꿈
      break;
    case 2:                       // 센서위에 손을 멀리하며 센서 값이 2가 되면
      Serial.println("medium");         // 시리얼창에 medium프린트하고 줄바꿈
      break;
    case 3:                      // 센서에 근처에 손을 대지 않고 센서값이 3이 되면
      Serial.println("bright");         // 시리얼창에 bright프린트하고 줄바꿈
      break;
  }
  delay(1);                      // 안정적으로 값을 읽기 위해 1밀리초 지연
}


