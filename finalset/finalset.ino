#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>



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

void setup() {

  Serial.begin(9600);

  // Temp Sensor
  dht.begin();

  sensor_t sensor;

  dht.temperature().getSensor(&sensor);
  Serial.println("Temperature");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" *C");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" *C");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" *C");


  dht.humidity().getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.println("Humidity");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println("%");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println("%");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println("%");
  Serial.println("------------------------------------");

  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000;

  // Sound Sensor
  pinMode(soundDetectedPin, INPUT) ;

  // Button Sensor
  pinMode(2, INPUT);


}

void loop()
{
 
  // Photoresistor
  int sensorReading = analogRead(A0);
  Serial.println(sensorReading);

  int range = map (sensorReading, sensorMin, sensorMax, 0, 3);
  switch (range) {
    case 0: Serial.println("dark"); break;
    case 1: Serial.println("dim"); break;
    case 2: Serial.println("medium");
      break;
    case 3:
      Serial.println("bright");
      break;
  }
  delay(1000);

  // Temp Sensor
  delay(delayMS);

  sensors_event_t event;

  // Temperature Output
  dht.temperature().getEvent(&event);

  if (isnan(event.temperature)) {
    Serial.println("Temp Reading Error");
  }

  else {
    Serial.print("Temperature: ");
    Serial.print(event.temperature);
    Serial.println(" *C");
  }

  delay(1000);

  // Humidity Output

  dht.humidity().getEvent(&event);

  if (isnan(event.relative_humidity)) {
    Serial.println("Humiditiy Reading Error");
  }
  else {
    Serial.print("Humidity: ");
    Serial.print(event.relative_humidity);
    Serial.println("%");
  }

  delay(1000);

  // Sound Sensor
  Serial.println("-----------------------------");
  Serial.println("Sound Sensor");

  soundDetectedVal = digitalRead(soundDetectedPin) ; //소리 값을 읽어서 저장
  Serial.println(soundDetectedVal);
  if (soundDetectedVal == LOW) { // 소리가 들리면
    lastSoundDetectTime = millis(); // 소리가 들린시간 기록
    if (!bAlarm) {
      Serial.println("LOUD, LOUD"); bAlarm = true;
    }
  } else {
    if ( (millis() - lastSoundDetectTime) > soundAlarmTime && bAlarm) {
      Serial.println("quiet");
      bAlarm = false;
    }
  }

}




