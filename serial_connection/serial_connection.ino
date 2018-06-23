int val;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(val++);
  delay(2000);
}

