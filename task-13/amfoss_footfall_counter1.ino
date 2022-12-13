#include <LiquidCrystal.h>

const int trigPin = 6;
const int echoPin = 7;
int count = 0;

long duration;
int distance;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  lcd.begin(16,2);
  lcd.clear();
  Serial.begin(9600);
}

void loop()
{
  lcd.clear();
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)/29.1;
  delay(500);
  
  if (distance <100)
  {
    count++;
  }
  
  lcd.clear();
  lcd.print(count);
  delay(1000);
}
