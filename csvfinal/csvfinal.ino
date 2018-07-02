//Temp Library

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

//Gyro Library
#include <MPU6050_tockn.h>
#include <Wire.h>

#define OUTPUT_READABLE_YAWPITCHROLL

// Photoresistor

const int sensorMin = 0;
const int sensorMax = 845;

// Temp Sensor (Libraries Included at the Top)

#define DHTPIN   3
#define DHTTYPE   DHT11

DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;

// Sound Sensor
int soundDetectedPin = 10;
int soundDetectedVal = HIGH;
boolean bAlarm = false;
unsigned long lastSoundDetectTime; int soundAlarmTime = 500;

// For timer setup
unsigned long counter = 0;
unsigned long total_sum = 0 ; 
unsigned long current_time, last_time;

// Gyro Sensor
const int MPU=0x68;  
int16_t GyX,GyY,GyZ;

void setup() {

  Serial.begin(9600);

  // Temp Sensor
  dht.begin();

  sensor_t sensor;

  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000;

  // Sound Sensor
  pinMode(soundDetectedPin, INPUT) ;
  
  // Gyro Sensor
  Wire.begin();      //Wire 라이브러리 초기화
  Wire.beginTransmission(MPU); //MPU로 데이터 전송 시작
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     //MPU-6050 시작 모드로
  Wire.endTransmission(true);

  last_time = millis();
}

int getGyroValue()
{
  int weighted_sum;

  Wire.beginTransmission(MPU);    //데이터 전송시작
  Wire.write(0x3B);               // register 0x3B (ACCEL_XOUT_H), 큐에 데이터 기록
  Wire.endTransmission(false);    //연결유지
  Wire.requestFrom(MPU,14,true);  //MPU에 데이터 요청
  //데이터 한 바이트 씩 읽어서 반환
  Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  
  //시리얼 모니터에 출력
  //Serial.print("sqrt(GyX^2 + Gy^2 + Gz^2) = "); 
  weighted_sum = sqrt(pow(GyX, 2) + pow(GyY, 2) + pow(GyZ, 2));
  Wire.beginTransmission(MPU);    //데이터 전송시작
  Wire.write(0x3B);               // register 0x3B (ACCEL_XOUT_H), 큐에 데이터 기록
  Wire.endTransmission(false);    //연결유지
  Wire.requestFrom(MPU,14,true);  //MPU에 데이터 요청

  return(weighted_sum);
}

void loop()
{

  // Sound Sensor
  soundDetectedVal = digitalRead(soundDetectedPin) ; //소리 값을 읽어서 저장
  counter++;
  total_sum += soundDetectedVal;
  if (soundDetectedVal == LOW) { // 소리가 들리면
    lastSoundDetectTime = millis(); // 소리가 들린시간 기록
    if (!bAlarm) {
      bAlarm = true;
    }
  } else {
    if ( (millis() - lastSoundDetectTime) > soundAlarmTime && bAlarm) {
      bAlarm = false;
    }
  }

  current_time = millis();
  if( current_time - last_time > 1000 ){ // Operations done under 1 sec are placed
    
        // photo register value 
         int sensorReading = analogRead(A0);
         Serial.print(sensorReading);
         Serial.print(", ");

          // Temp Sensor
  
         sensors_event_t event;
  
         // Temperature Output
         dht.temperature().getEvent(&event);

          Serial.print(event.temperature);
         Serial.print(", ");

         // Humidity Output

          dht.humidity().getEvent(&event);

           Serial.print(event.relative_humidity);
          Serial.print(", ");

          // Sound sensor output
          int average = total_sum / counter;
          if(average  > 0){
            average = 1;
          }
          Serial.print(average );
          total_sum = 0 ;
          counter = 0;
          Serial.print(", ");

          // Gyro Sensor
          Serial.print(getGyroValue());
  
          Serial.println();

          // timer reset
          last_time = current_time;

    }
  
}




