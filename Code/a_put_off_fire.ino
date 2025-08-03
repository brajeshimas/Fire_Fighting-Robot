 
void put_off_fire()
{
  
 
    delay(400);//change this value to change the distance
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
    digitalWrite(pump,LOW);
    delay(500);
 
 
    for (pos = 50; pos <= 110; pos += 1) { 
    myservo.write(pos); 
    delay(10);  
  }
  for (pos = 110; pos >= 50; pos -= 1) { 
    myservo.write(pos); 
    delay(10);
  }
  digitalWrite(pump,HIGH);
  myservo.write(90); 
  fire=false;
}
