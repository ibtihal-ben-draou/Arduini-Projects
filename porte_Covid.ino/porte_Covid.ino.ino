
#include <Servo.h>   // Déclaration de la bibliotheque du servo
int servo = 8; // le servo est declare dans pin digital n° 8 
Servo servoA;        
int buzzer = 7;      // buzzer est declaré dans pin digital n° 7
int t=0;
int pin10 = 10;      //led jaune
int pin11=11;        //led rouge
int sensor = A0;     // le capteur
float temp;
float tempc;

#include <Wire.h>                      // declaration de la bibliothèque de l'afficheur
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27, 16, 2);
void setup() {
servoA.attach(servo = 8);
servoA.write(90);                     // la position initiale du servoA est 90°
delay(500);                          // le temps entre les executions en ms

 
pinMode (buzzer, OUTPUT);        // le mode du pin (output or input)
pinMode (pin10, OUTPUT);
pinMode (pin11, OUTPUT);
pinMode (sensor, INPUT);
lcd.init();                     // vider l'afficheur au début
lcd.backlight();
lcd.setCursor (0,0);            // (ligne, colonne)=(0,0)
lcd.print ("  ARDUINO  ");        // afficher "arduino"
lcd.setCursor (0,1);              // (ligne, colonne)=(0,1)
lcd.print ("TEMPRETURE COVID");   // afficher "TEMPERATURE COVID"
delay (3000);
Serial.begin(9600);              // affichage du résultats au pc (moniteur série)
} void loop() {
delay(2000);
t=t+2;
temp=analogRead(sensor);        // fonctionnement du capteur
tempc=(temp*5)/10;

Serial.println("______");                  // concernant moniteur série
Serial.println("Temperature Logger");
Serial.print("Time in Seconds= ");
Serial.println(t);
Serial.print("Temp in deg Celcius = ");
Serial.println(tempc);
lcd.setCursor(0,0);
lcd.print ("Temp in C = ");
lcd.println(tempc);
lcd.setCursor (0,1);
if(temp>=50.00){
  servoA.write(0);
 delay(500);
 digitalWrite(pin11, HIGH); //ON  
  digitalWrite(buzzer,HIGH); //ON
 digitalWrite(pin10, LOW); }//led vert OFF 
     delay (500);
if(temp<=50.00){
  delay(300); 
 servoA.write(90);
       delay(500);
digitalWrite(pin10, HIGH); //led vert ON 
 digitalWrite(buzzer, LOW); //BUZZER OFF digitalWrite(pin11, LOW); //LED ROUGE OFF
 digitalWrite(pin11, LOW);
delay(500);
}
}
