#include <Adafruit_Sensor.h> #include <DHT.h>
#include <DHT_U.h>
#define DHTPIN 2 // DHT 센서를 2 번 핀에 연결한다.
// 사용하는 센서를 고른다. 사용하지 않는 센서는 주석 처리하여 코드를 막아준다.
     #define DHTTYPE
//#define DHTTYPE
//#define DHTTYPE
DHT11
DHT22
// DHT 11 를 사용한다. // DHT 22 (AM2302) // DHT 21 (AM2301)
 DHT21 DHT_Unified dht(DHTPIN,DHTTYPE);

uint32_t delayMS


18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
⦙
void setup() {
Serial.begin(9600); // 9600 속도로 시리얼 통신 시작
dht.begin(); // DHT 센서 시작 Serial.println("DHTxx Unified Sensor Example");
// 온도센서 정보 프린트
sensor_t sensor;
dht.temperature().getSensor(&sensor); Serial.println("------------------------------------"); Serial.println("Temperature");
Serial.print ("Sensor: "); Serial.println(sensor.name);
Serial.print ("Driver Ver: ); Serial.println(sensor.version);
Serial.print ("Unique ID: "); Serial.println(sensor.sensor_id);
Serial.print ("Max Value: "); Serial.print(sensor.max_value); Serial.println(" *C"); Serial.print ("Min Value: "); Serial.print(sensor.min_value); Serial.println(" *C"); Serial.print ("Resolution:"); Serial.print(sensor.resolution); Serial.println(" *C"); Serial.println("------------------------------------");
// 습도센서 정보 프린트 dht.humidity().getSensor(&sensor); Serial.println("------------------------------------"); Serial.println("Humidity");
           Serial.print ("Sensor:
Serial.print ("Driver Ver:
Serial.print ("Unique ID:
Serial.print ("Max Value:
Serial.print ("Min Value:
Serial.print ("Resolution: Serial.println("------------------------------------");
"); Serial.println(sensor.name);
"); Serial.println(sensor.version);
"); Serial.println(sensor.sensor_id);
"); Serial.print(sensor.max_value); Serial.println("%"); "); Serial.print(sensor.min_value); Serial.println("%"); "); Serial.print(sensor.resolution); Serial.println("%");
   // 센서를 읽는 시간
  delayMS =sensor.min_delay /1000;
}

void loop() {
  // Delay between measurements.
  delay(delayMS);
⦙
 sensors_event_t event;
dht.temperature().getEvent(&event); // Get temperature event and print its value. if(isnan(event.temperature)) {
Serial.println("Error reading temperature!"); }
else{
Serial.print("Temperature: "); Serial.print(event.temperature); Serial.println(" *C");
}
    dht.humidity().getEvent(&event); if(isnan(event.relative_humidity)) {
// Get humidity event and print its value. Serial.println("Error reading humidity!");
   } else{
Serial.print("Humidity: "); Serial.print(event.relative_humidity); Serial.println("%");
} }
}
