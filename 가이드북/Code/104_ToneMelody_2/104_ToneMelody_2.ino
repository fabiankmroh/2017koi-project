
#include "pitches.h"

int buzzer=8;            //피에조 부저를 8번에 연결

                              //연주할 음계
int melody[] ={NOTE_G7,NOTE_G7,NOTE_A7,NOTE_A7,NOTE_G7,
                NOTE_G7,NOTE_E7,NOTE_G7,NOTE_G7,NOTE_E7,
                NOTE_E7,NOTE_D7,NOTE_G7,NOTE_G7,NOTE_A7,
                NOTE_A7,NOTE_G7,NOTE_G7,NOTE_E7,NOTE_G7,
                NOTE_E7,NOTE_D7,NOTE_E7,NOTE_C7
               };
                            //음의길이, 4:4분음표, 2:2분음표
int noteDurations[] ={4,4,4,4,4,4,2,4,4,4,4,1,4,4,4,4,4,4,2,4,4,4,4,1};

void setup() {
  for(int thisNote =0; thisNote <24; thisNote++)
  {
    int noteDuration =1000 /noteDurations[thisNote];
    tone(buzzer, melody[thisNote], noteDuration);   //8번핀에 피에조 부저 연결
    int pauseBetweenNotes =noteDuration *1.30;          //음표 구분 시간
    delay(pauseBetweenNotes);                           //delay

    noTone(speakerpin);                               //음악 재생을 멈춤
  }
}

void loop() {
}


