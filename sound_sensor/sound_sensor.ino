// Declaration and initialization of the input pin
int Analog_Eingang = A1;
  
void setup ()
{
  pinMode (Analog_Eingang, INPUT);
       
  Serial.begin (9600);
}
  
// The program reads the current value of the input pins
// and outputs it via serial out 
void loop ()
{
  float Analog;

    
  // Current value will be read and converted to the voltage
  Analog = analogRead (Analog_Eingang); 
    
  // and outputted here
  Serial.print (Analog, 4); 

  
  Serial.println ("----------------------------------------------------------------");
  delay (200);
}
