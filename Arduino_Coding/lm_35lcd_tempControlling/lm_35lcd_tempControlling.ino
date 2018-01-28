
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int buttonPinU = 7;
const int buttonPinL = 6;
const int sensorPin = A0;
const int OutPin =1;
int buttonState = 0;
int count=10;
int sensorValue=0;

void setup() {
  // set up the LCD's number of columns and rows:
    pinMode(buttonPinU, INPUT);
    pinMode(buttonPinL, INPUT);
    pinMode(OutPin, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Temperature:");
}

void loop() {

  sensorValue = analogRead(sensorPin);
  if(digitalRead(buttonPinU)==1)
  {
    count++;
    
  }
  if(digitalRead(buttonPinL)==1)
  {
    count--; 
  }

  if(sensorValue>count)
  {
    digitalWrite(OutPin, HIGH);
  }
  else{
    digitalWrite(OutPin, LOW);
  }

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
 // lcd.print(millis() / 1000);
  lcd.print(count);
  lcd.setCursor(4, 1);
  lcd.print(sensorValue);
  delay(250);
 
}
