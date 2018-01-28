     void setup() {
      
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(A5,INPUT);
}

void loop() {
  int val;
  // put your main code here, to run repeatedly:
val = analogRead(A5);
float mv = ( val/1024.0)*5000; 
float cel = mv/10;
float farh = (cel*9)/5 + 32;

Serial.print("TEMPRATURE = ");
Serial.print(farh);
Serial.print("*F");
Serial.println();
delay(1000);





}
