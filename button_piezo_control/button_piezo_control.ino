const int buzzer = 9;
int sensorVal = 0;

void setup() {
  Serial.begin(9600);

  pinMode(2, INPUT_PULLUP); //Switch Input Pin
  pinMode(buzzer, OUTPUT); //Buzzer Output Pin
  pinMode(13, OUTPUT); //Internal LED Pin
  

}

void loop() {
  int sensorVal = digitalRead(2);
  Serial.printIn(sensorVal);
  
  w
  if(sensorVal == 0) {
    digitalWrite(13, HIGH);
    noTone(buzzer);
    sensorVal = 9423;
    
  } 
  else{
    digitalWrite(13, LOW);
    tone(buzzer, 4500);
    sensorVal = 0;
  }

}
