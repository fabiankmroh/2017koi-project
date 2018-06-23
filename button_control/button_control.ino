void setup() {
  Serial.begin(9600);

  pinMode(2, INPUT); //Switch Input Pin
  pinMode(13, OUTPUT); //Internal LED Pin
  

}

void loop() {
  int sensorVal = digitalRead(2); 
  Serial.println(sensorVal);
  
  if(sensorVal == HIGH) {
    digitalWrite(13, HIGH);
    
  } 
  else{
    digitalWrite(13, LOW);
  }

}
