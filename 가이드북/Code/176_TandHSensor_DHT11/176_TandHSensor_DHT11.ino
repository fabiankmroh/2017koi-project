#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN            2         // DHT 센서를 2번 핀에 연결한다.

// 사용하는 센서를 고른다. 사용하지 않는 센서는 주석 처리하여 코드를 막아준다.
#define DHTTYPE           DHT11     // DHT 11를 사용한다.
//#define DHTTYPE           DHT22     // DHT 22 (AM2302)
//#define DHTTYPE           DHT21     // DHT 21 (AM2301)

DHT_Unified dht(DHTPIN,DHTTYPE);

uint32_t delayMS


void setup() {
  Serial.begin(9600);      // 9600 속도로 시리얼 통신 시작
 
  dht.begin();             // DHT 센서 시작
  Serial.println("DHTxx Unified Sensor Example");

  // 온도센서 정보 프린트
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.println("Temperature");
  Serial.print ("Sensor:    "); Serial.println(sensor.name);
  Serial.print ("Driver Ver: ); Serial.println(sensor.version);
  Serial.print ("Unique ID: "); Serial.println(sensor.sensor_id);
  Serial.print ("Max Value: "); Serial.print(sensor.max_value); Serial.println(" *C");
  Serial.print ("Min Value: "); Serial.print(sensor.min_value); Serial.println(" *C");
  Serial.print ("Resolution:"); Serial.print(sensor.resolution); Serial.println(" *C");  
  Serial.println("------------------------------------");

  // 습도센서 정보 프린트
  dht.humidity().getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.println("Humidity");
  Serial.print ("Sensor:     "); Serial.println(sensor.name);
  Serial.print ("Driver Ver: "); Serial.println(sensor.version);
  Serial.print ("Unique ID:  "); Serial.println(sensor.sensor_id);
  Serial.print ("Max Value:  "); Serial.print(sensor.max_value); Serial.println("%");
  Serial.print ("Min Value:  "); Serial.print(sensor.min_value); Serial.println("%");
  Serial.print ("Resolution: "); Serial.print(sensor.resolution); Serial.println("%");  
  Serial.println("------------------------------------");

  // 센서를 읽는 시간
  delayMS =sensor.min_delay /1000;
}


void loop() {
  // Delay between measurements.
  delay(delayMS);
  
  sensors_event_t event;  
  dht.temperature().getEvent(&event);  // Get temperature event and print its value.
  if(isnan(event.temperature)) {
    Serial.println("Error reading temperature!");
  }
  else{
    Serial.print("Temperature: ");
    Serial.print(event.temperature);
    Serial.println(" *C");
  }
  
  dht.humidity().getEvent(&event);   // Get humidity event and print its value.
  if(isnan(event.relative_humidity)) {
    Serial.println("Error reading humidity!");
  }
  else{
    Serial.print("Humidity: ");
    Serial.print(event.relative_humidity);
    Serial.println("%");
  }
}


