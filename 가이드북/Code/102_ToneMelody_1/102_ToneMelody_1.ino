
#include "pitches.h"                    // 라이브러리 추가

int melody[] ={                         // 연주할 음계
  NOTE_C4,NOTE_G3,NOTE_G3,NOTE_A3,NOTE_G3,0,NOTE_B3,NOTE_C4 
};

int noteDurations[] ={                  // 음의 길이: 4 = 4분음표, 8 = 8분 음표
  4,8,8,4,4,4,4,4
};


void setup() {
  
  for (int thisNote =0; thisNote <8; thisNote++) {         // 8개 음표를 설정

    // 음표 길이를 계산하려면 1초를 음표 유형으로 나눈 값을 취한다.
    //예: 4분 음표 = 1000 / 4,  8분 음표 = 1000/8
    int noteDuration =1000 /noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);      // 피에조 부저 +극을 8번에 연결

    // 음을 구별하기 위해 음표 사이의 최소 시간을 설정한다.
    // 음표의 지속시간 + 30% 가 잘 작동하는 것 같다.
    int pauseBetweenNotes = noteDuration *1.30;
    delay(pauseBetweenNotes);
   
    noTone(8);    // 음악 재생을 멈춘다.
  }
}


void loop() {
  // 반복할 것이 없다.  viod loop{}을 생략하면 오류가 나다. 
}


