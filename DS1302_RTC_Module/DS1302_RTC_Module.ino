#include <DS1302RTC.h>
#include <Time.h>


DS1302RTC RTC(27, 29, 31);


void setup()
{
  Serial.begin(9600);
  digitalWrite(DS1302_GND_PIN, LOW);
  pinMode(DS1302_GND_PIN, OUTPUT);
  digitalWrite(DS1302_VCC_PIN, HIGH);
  pinMode(DS1302_VCC_PIN, OUTPUT);
}

void loop()
{
  // Display abbreviated Day-of-Week in the lower left corner
  Serial.print(dayShortStr(weekday()));

  // Display date in the lower right corner
  lcd.setCursor(5, 1);
  lcd.print(" ");
  print2digits(day());
  lcd.print("/");
  print2digits(month());
  lcd.print("/");
  lcd.print(year());

  // Warning!
  if(timeStatus() != timeSet) {
    lcd.setCursor(0, 1);
    lcd.print(F("RTC ERROR: SYNC!"));
  }

  delay ( 1000 ); // Wait approx 1 sec
}


