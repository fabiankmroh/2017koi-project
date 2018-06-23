

const int buzzer = 9; //buzzer to arduino pin 9


void setup(){
 
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output

}

void loop(){
 
  tone(buzzer, 4500); // Send 4.5KHz sound signal...
  delay(5000);        // ...for 5 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1 sec
  
}
