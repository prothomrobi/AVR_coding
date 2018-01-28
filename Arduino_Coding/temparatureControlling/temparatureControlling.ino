#include <LiquidCrystal.h>
LiquidCrystal lcd{8,7,6,5,4,3};

int tempInc=12;
int tempSet=11;
int tempDec=10;
int led=9;
int temp=A5;
int buttonState = 0;


void setup() { 
 // Setup the number of columns and rows that are available on the LCD. 
 lcd.begin(16, 2);
 //lcd.noDisplay();

 // Set the button pin as an input.
 pinMode(tempInc, INPUT);

 // Set the LCD display backlight pin as an output.
 pinMode(temp, OUTPUT);

 // Turn off the LCD backlight.
 digitalWrite(temp, LOW);
}

void loop() { 
 buttonState = digitalRead(tempInc);
 if (buttonState == HIGH)
 {
 // Print some text to the LCD.
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("Temp increasing");

 // Turn the backlight on.
 digitalWrite(temp, HIGH);

 // Display the text on the LCD.
 lcd.display();

 // Wait for 2 seconds and write next line.
 delay(2000);
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("Welcome to Arduino");
 // Wait for 10 seconds and write next line.
 delay(1000);
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("Add Your Name Here");
 // Wait for 10 seconds and turn off.
 delay(10000);
 lcd.noDisplay();
 digitalWrite(temp, LOW);
 }
}
