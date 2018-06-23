int soundDetectedPin =10;              // 모듈의 output핀을 10번 핀에 연결
int soundDetectedVal =HIGH;            // 소리값을 저장하는 변수
boolean bAlarm =false;                    

unsigned long lastSoundDetectTime;     //마지막으로 소리를 측정한 시간 저장하는 변수
int soundAlarmTime =500;               // 알람 소리 유지 하는 시간 0.5초

void setup(){
  Serial.begin(9600);                  // 9600속도로 시리얼 통신 시작
  pinMode(soundDetectedPin,INPUT) ;    // 소리 감지 연결된 10번 핀을 입력으로 설정
}


void loop(){
  soundDetectedVal =digitalRead(soundDetectedPin) ; //소리 값을 읽어서 저장

  if(soundDetectedVal == LOW) {   // 소리가 들리면
 
    lastSoundDetectTime =millis(); // 소리가 들린시간 기록
    
    if(!bAlarm) {
      Serial.println("LOUD, LOUD"); 
      bAlarm =true;
    }
  }  else {
    if( (millis() -lastSoundDetectTime) >soundAlarmTime  && bAlarm) {
      Serial.println("quiet");
      bAlarm =false;
    }
  }
}


