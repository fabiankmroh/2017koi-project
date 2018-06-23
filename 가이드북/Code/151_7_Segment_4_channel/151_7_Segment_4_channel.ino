
// 7 세그먼트LED와 연결되는 아두이노 핀 설정
int nPinA =6;
int nPinB =7;
int nPinC =8;
int nPinD =9;
int nPinE =10;
int nPinF =11;
int nPinG =12;
int nPinDP =13;   // 소수점

// 자리수를 결정하는 핀과 연결되는 아두이노 핀 설정
int nPinDig1 =2;   // DIG1 천자리
int nPinDig2 =3;  // DIG2 백자리
int nPinDig3 =4;  // DIG3 십자리
int nPinDig4 =5;  // DIG4 일자리

// 각 자리수에 표시할 값 계산에 필요한 변수 설정
int nDig1 =0;  // 천자리값
int nDig2 =0;  // 백자리값
int nDig3 =0;  // 십자리값
int nDig4 =0;  // 일자리값

int val =0;    // 표시할숫자를저장하는변수

int digitpin[5] ={ -1, nPinDig1, nPinDig2, nPinDig3, nPinDig4 };

const int DELAY =5000; // 자리수에 숫자를 표시하는시간(밀리초)

// 0~9를 표시하기 위한 배열
int narrNumber[10][7] ={
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},    // 0
  {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW},       // 1
  {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH},    // 2
  {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH},    // 3
  {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH},     // 4
  {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH},    // 5
  {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH},   // 6
  {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW},      // 7
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},   // 8
  {HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH}     // 9
};


void setup() {
  // 4 Digit 7 Segment LED 에 연결되는 아두이노 핀 모드 설정
  pinMode(nPinDig1, OUTPUT);
  pinMode(nPinDig2, OUTPUT);
  pinMode(nPinDig3, OUTPUT);
  pinMode(nPinDig4, OUTPUT);

  pinMode(nPinA, OUTPUT);
  pinMode(nPinB, OUTPUT);
  pinMode(nPinC, OUTPUT);
  pinMode(nPinD, OUTPUT);
  pinMode(nPinE, OUTPUT);
  pinMode(nPinF, OUTPUT);
  pinMode(nPinG, OUTPUT);
  pinMode(nPinDP, OUTPUT);
}

void loop()
{
  // 표시하기 위한 숫자설정: 루프를 한 번 돌때마다1씩 증가
  val++;
  // 숫자를 표시하기 위해 각 자리수를 계산
  nDig1 =(val /1000) %10;
  nDig2 =(val /100) %10;
  nDig3 =(val /10) %10;
  nDig4 =val %10;

  // 1000 단위 숫자를 표시
  if(val >=1000)
  {
    pickDigit(1);
    pickNumber(nDig1);
    delayMicroseconds(DELAY);
  }

  // 100 단위 숫자를 표시
  if(val >=100)
  {
    pickDigit(2);
    pickNumber(nDig2);
    delayMicroseconds(DELAY);
  }

  // 10 단위 숫자를 표시
  if(val >=10)
  {
    pickDigit(3);
    pickNumber(nDig3);
    delayMicroseconds(DELAY);
  }

  // 1 단위 숫자를 표시
  if(val >=0)
  {
    pickDigit(4);
    pickNumber(nDig4);
    delayMicroseconds(DELAY);
  }
}


// 숫자n을표시한다.
void pickNumber(int n)
{
  digitalWrite(nPinA,narrNumber[n][0]);
  digitalWrite(nPinB,narrNumber[n][1]);
  digitalWrite(nPinC,narrNumber[n][2]);
  digitalWrite(nPinD,narrNumber[n][3]);
  digitalWrite(nPinE,narrNumber[n][4]);
  digitalWrite(nPinF,narrNumber[n][5]);
  digitalWrite(nPinG,narrNumber[n][6]);
}



