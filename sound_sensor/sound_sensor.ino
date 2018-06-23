int soundDetectedPin =10;
int soundDetectedVal =HIGH;
boolean bAlarm =false;
unsigned long lastSoundDetectTime; int soundAlarmTime =500;

void setup(){
Serial.begin(9600); pinMode(soundDetectedPin,INPUT) ;
}

void loop(){
soundDetectedVal =digitalRead(soundDetectedPin) ; //소리 값을 읽어서 저장
Serial.println(soundDetectedVal);
if(soundDetectedVal == LOW) { // 소리가 들리면
lastSoundDetectTime =millis(); // 소리가 들린시간 기록
if(!bAlarm) { Serial.println("LOUD, LOUD"); bAlarm =true;
}
} else {
if( (millis() -lastSoundDetectTime) >soundAlarmTime && bAlarm) { Serial.println("quiet");
bAlarm =false;
} }
}
