/***************************
This code is shared by elecrow.com
it is public domain, enjoy!
it is used to control 28BYJ stepper
it can be changed to control almost all the 4-wire or 5-wire stepper.
*************************/

/*
The time Series to control the stepper
--make your making more easy!
*/
byte CCW[8] = {0x09,0x01,0x03,0x02,0x06,0x04,0x0c,0x08};
byte CW[8] = {0x08,0x0c,0x04,0x06,0x02,0x03,0x01,0x09}; 

const int stop_key = 14;  //stop_button connect to Arduino-A0
byte  change_angle=18;  //change the parameter to change the angle of the stepper

void Motor_CCW()    //the steper move 360/64 angle at CouterClockwise 
{
  for(int i = 0; i < 8; i++)
  
    for(int j = 0; j < 8; j++)
    {
     if(digitalRead(stop_key)==0)
      {
      PORTB =0xf0;
      break;
      }
      PORTB = CCW[j];
      delayMicroseconds(2000);
    }    
}
void Motor_CW()  //the steper move 360/64 angle at Clockwise
{
  for(int i = 0; i < 8; i++)
  
    for(int j = 0; j < 8; j++)
    {
    if(digitalRead(stop_key)==0)
      {
      PORTB =0xf0;
      break;
      } 
      PORTB = CW[j];
      delayMicroseconds(2000);
    }
}

void setup()
{
  pinMode(stop_key,INPUT);
  digitalWrite(stop_key,HIGH);
  Serial.begin(57600);
  DDRB=0xff;
  PORTB = 0xf0;  
  for(int k=0;k<change_angle;k++) 
  {
  Motor_CCW();  
  }
 }

void loop()
{
 Motor_CCW();  //make the stepper to anticlockwise rotate
// Motor_LR(); //make the stepper to clockwise rotate
}
