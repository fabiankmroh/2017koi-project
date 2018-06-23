
#include <OneWire.h>                       // OneWire라이브러리 포함
#include <DallasTemperature.h>             // DallasTemperature라이브러리 포함

#define ONE_WIRE_BUS 2                 // 데이터 핀을 2번에 연결

OneWire oneWire(ONE_WIRE_BUS);         // OneWire 장치와 통신하기 위해 oneWire 객체생성

DallasTemperature sensors(&oneWire);   // oneWire 참조를 전달

void setup()
{
  
  Serial.begin(9600);            // 9600 속도로 시리얼 통신 시작
  Serial.println("Dallas Temperature IC Control Library Demo");

  sensors.begin();              // 라이브러리 시작
}


void loop() {

  Serial.print(" Requesting temperatures...");
  sensors.requestTemperatures();           // 온도를 얻기 위한 명령을 시리얼로 보낸다.
  Serial.println("DONE");

  Serial.print("Temperature is: ");
  Serial.print(sensors.getTempCByIndex(0));     // 0은 onewire의 첫 번째 IC
  delay(1000);
}


