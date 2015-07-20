/*
*	BlinkWithNoDelay
*
*	This is an example of how to blink an LED using the NoDelay library
*	This allows you to execute code without the use of the delay() function
*	and without having to setup many variables for each time you want to
*	run code in a delay less manner
*	Written by Mario Avenoso of Mtech Creations
*	Based off of the Blink Without Delay example http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
*	7/10/15

*/

#include<NoDelay.h>

noDelay LEDtime(1000);//Creats a noDelay varible set to 1000ms
int LEDpin = 13;
int ledState = LOW;

void setup() {
  pinMode(LEDpin, OUTPUT);
}

void loop() {
 
  if(LEDtime.update())//Checks to see if set time has past
  {
    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(LEDpin, ledState);
  }
    
}
