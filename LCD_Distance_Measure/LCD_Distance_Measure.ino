#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
const int trigPin = 9;
const int echoPin = 10;
long duration;
int Cm,Inch;
void setup() {
//lcd.begin(16,2); 

// Initializes the dimensions of LCD screen
Serial.begin(9600);
lcd.init();
lcd.backlight();
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  Cm= duration*0.034/2;
  Inch = duration*0.0133/2;
  lcd.setCursor(0,0); 
  lcd.print("distance: "); 
  lcd.print(Cm);
  lcd.print(" cms");
  delay(10);
  lcd.setCursor(0,1);
  lcd.print("distance: ");
  lcd.print(Inch);
  lcd.print(" inches");

  Serial.prinln(String(Cm));

  delay(1000);

  Serial.flush();
}
