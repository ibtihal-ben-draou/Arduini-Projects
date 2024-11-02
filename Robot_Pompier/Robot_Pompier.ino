
#include <Servo.h>
Servo myservo;
 
int pos = 0;    
boolean fire = false;
 
/*-------defining Inputs------*/
#define Left_S A0      // left sensor
#define Right_S A2      // right sensor
#define Forward_S A1 //forward sensor
 
/*-------defining Outputs------*/
#define LM1 2       // left motor
#define LM2 4       // left motor
 #define enB 3      //VITESE
#define RM1 6       // right motor
#define RM2 7       // right motor
#define enA 10
#define pump1 11
#define pump2 9

 
void setup()
{
  pinMode(Left_S, INPUT);
  pinMode(Right_S, INPUT);
  pinMode(Forward_S, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(pump1, OUTPUT);
   pinMode(pump2, OUTPUT);
   analogWrite(enA,100); 
analogWrite(enB,100); 
 
  myservo.attach(13);
  myservo.write(90); 
}
 
void put_off_fire()
{
    delay (500);
 
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);

       delay(50);
      
  
   digitalWrite(pump1, HIGH);
   digitalWrite(pump2, LOW);
   delay(500);
    
    for (pos = 90; pos <= 160; pos += 1) { 
    myservo.write(pos); 
    delay(30);  
  }
  for (pos = 160; pos >=20; pos -= 1) { 
    myservo.write(pos); 
    delay(30);
 
         }
  
   digitalWrite(pump1, LOW);
   digitalWrite(pump2, LOW);
  myservo.write(90);
  
  fire=false;
}
 
void loop()
{
   myservo.write(90); //Sweep_Servo();  
 
    if (digitalRead(Left_S) ==0 && digitalRead(Right_S)==0 && digitalRead(Forward_S) ==0) //If Fire not detected all sensors are zero
    {
    //Do not move the robot
    digitalWrite(LM1,LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW  );
    digitalWrite(RM2, LOW);
    }
    
    else if (digitalRead(Forward_S) ==0) //If Fire is straight ahead
    {
    //Move the robot forward
    digitalWrite(LM1,LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1,LOW);
    digitalWrite(RM2, HIGH);
    
    fire = true;
    }
    
    else if (digitalRead(Left_S) ==0) //If Fire is to the left
    {
    //Move the robot left
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
      delay(300); 
       digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
       
    }
    
    else if (digitalRead(Right_S) ==0) //If Fire is to the right
    {
    //Move the robot right
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    delay(300); 
       digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
      
    }
    
delay(300); //Slow down the speed of robot
 
     while (fire == true)
     {
      put_off_fire();
     }
}
