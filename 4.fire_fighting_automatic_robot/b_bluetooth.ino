void bluetooth(void)
{
    if (Serial.available() > 0)
 {
   received = Serial.read();
   Received = received;
   if(Received != 83)
   {
      if(Received == 85)  // for taking control with mobile
      {
        Serial.println("in control");
        while(true)
        {
          received = Serial.read();
          if(received == 117)      // for losing control from mobile
          {
               digitalWrite(pump,HIGH);
               Serial.println("control lost");
                break;
          }
          else if(received == 86)  // to start motor pump
          {
             digitalWrite(pump,LOW);  
          }
          else if(received == 118)
          {
             digitalWrite(pump,HIGH);  // TO OFF MOTOR PUMP
          }
 //*****************************************************************
          else if(received == 70)
          {
              digitalWrite(LM1,0);
              digitalWrite(RM1,0);
              digitalWrite(LM2,1);
              digitalWrite(RM2,1);                  // for DRIVING THE CAR IN FORWARD DIRECTION
              delay(400);
              while(received == 70)
             {
                  Serial.println("forward");
                   received = Serial.read();

              }
              digitalWrite(LM1,0);
              digitalWrite(RM1,0);
              digitalWrite(LM2,0);
              digitalWrite(RM2,0);
           }
//*******************************************************************************
            else if(received == 66)
           {
               digitalWrite(LM1,1);
               digitalWrite(RM1,1);
               digitalWrite(LM2,0);
               digitalWrite(RM2,0);
               delay(400);
               while(received == 66)
              {                                      // FOR DRIVING THE CAR IN BACKWARD DIRECTION
                 Serial.println("backward");
                 received = Serial.read();

              }
              digitalWrite(LM1,0);
              digitalWrite(RM1,0);
              digitalWrite(LM2,0);
              digitalWrite(RM2,0);
            }
//******************************************************************************************
           else if(received == 76)
           {
               digitalWrite(LM1,1);
               digitalWrite(RM1,0);
               digitalWrite(LM2,0);
               digitalWrite(RM2,0);
               delay(400);
               while(received == 76)
              {                                      // FOR DRIVING THE CAR IN left DIRECTION
                 Serial.println("left");
                 received = Serial.read();

              }
              digitalWrite(LM1,0);
              digitalWrite(RM1,0);
              digitalWrite(LM2,0);
              digitalWrite(RM2,0);
            }
//*********************************************************************************************
           else if(received == 82)
           {
               digitalWrite(LM1,0);
               digitalWrite(RM1,1);
               digitalWrite(LM2,0);
               digitalWrite(RM2,0);
               delay(400);
               while(received == 82)
              {                                      // FOR DRIVING THE CAR IN right DIRECTION
                 Serial.println("right");
                 received = Serial.read();

              }
              digitalWrite(LM1,0);
              digitalWrite(RM1,0);
              digitalWrite(LM2,0);
              digitalWrite(RM2,0);
            }
        }
      }
   }

 }
  
}
