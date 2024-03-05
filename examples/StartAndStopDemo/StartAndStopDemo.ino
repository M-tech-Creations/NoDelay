/*
*	StartAndStop
*
*	This is an example of how to use the start and stop function of the NoDelay library
*	This allows you to start the timer when you want or stop the timer from running at all
*	When you call start the timer will reset and begin at that moment, meaning if you want
*	something to start happening 10ms from a point, you first run start and in 10ms 
*	after you have called update it will happen (function call or returning true)
*	
*	Written by Mario Avenoso of Mtech Creations
*	
*	3/4/24

*/

#include<NoDelay.h>

noDelay LEDtime(1000,false);//Creats a noDelay varible set to 1000ms and with the timer stopped
int LEDpin = 13; //Set to your LEDPin


void setup()
{
	pinMode(LEDpin, OUTPUT);
    digitalWrite(LEDpin, LOW);
    Serial.begin(9600);
    Serial.println("Type g to start and s to stop:");
}

void loop()
{
    char command = ' ';
    if (Serial.available() > 0)
    {
        command = Serial.read();
    } 
    
    //Process the command entered to start or stop
    switch (command)
    {
    case 'g':
    case 'G':
        Serial.println("GO!");
        LEDtime.start(); // next update will trigger 1000ms from now
        break;
    case 's':
    case 'S':
        Serial.println("STOP!");
        LEDtime.stop();
        break;
    default:
        break;
    }

    if (LEDtime.update())//Checks to see if set time has past
    {
        // if the LED is off turn it on and vice-versa:
        digitalWrite(LEDpin, !digitalRead(LEDpin));
    }

}
