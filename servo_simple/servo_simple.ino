#include <Servo.h> 
 
#define SERVO_PIN 9
 
Servo gServo;
 
void setup() 
{ 
    gServo.attach(SERVO_PIN); 
}
 
void loop() 
{ 
   gServo.write(0);
    delay(500);
	
    gServo.write(90);
    delay(500);
	
    gServo.write(180);
    delay(500);
    
    gServo.write(270);
    delay(500);
    
    gServo.write(360);
    delay(500);
    
}
