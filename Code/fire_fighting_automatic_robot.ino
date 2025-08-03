/*------ Arduino Fire Fighting Robot ver 2.0 Code by hobby project---- */
 
#include <Servo.h>            //include servo.h library
Servo myservo; 
int pos = 0;    
boolean fire = false;



int Left = 4 ;         // left sensor
int Right =5 ;        // right sensor
int Forward= 6;       //front sensor
int GAS_SENSOR =7;    //Gas sensor
int LM1 =8 ;          // left motor
int LM2 =9  ;         // left motor
int RM1 =10 ;         // right motor
int RM2 =11 ;         // right motor
int pump =12  ;       //water pumb

int Received = 0;
int received = 0;

void setup()
{

  pinMode(Left, INPUT);
  pinMode(Right, INPUT);
  pinMode(Forward, INPUT);
  pinMode(GAS_SENSOR, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(pump, OUTPUT);
 digitalWrite(pump,1);
  myservo.attach(13);
  myservo.write(90); 
  Serial.begin(9600);

}

 
void loop()
{
  for(int i = 0;i<8;i++)
  {
      bluetooth();
      delay(10);
  }
Serial.println("out of control");
  myservo.write(90); //Sweep_Servo();  
  
  
  if (digitalRead(Left) ==1 && digitalRead(Right)==1 && digitalRead(Forward) ==1) 
    {
    delay(500);
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
    }
    else if (digitalRead(Forward) ==0) 
    {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    fire = true;
    
    }
    
    else if (digitalRead(Left) ==0)
    {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    fire = true;
    }
    
    else if (digitalRead(Right) ==0) 
    {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    fire = true;
    }  
     if(digitalRead(GAS_SENSOR)== 0)
    {
     Serial.println("Gas is Detected.");
     fire = true;
    }
   
     while (fire == true)
     {
      put_off_fire();
      Serial.println("Fire Detected.");
     }
 }
