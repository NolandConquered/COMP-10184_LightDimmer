// I, Nolan Carter, student number 000817341, certify that this material is my original work.
// No other person's work has been used without due acknowledgement and neither have I made my work available to anyone else.

#include <Arduino.h>
int led; // stores weither the led should be on or off

void setup() {
  // configure the USB serial monitor 
  Serial.begin(115200); 
 
  // configure pin D5 as digital input - this is the pushbutton 
  pinMode(D5, INPUT_PULLUP); 
 
  // configure pin D4 as a digital output - this is the LED 
  pinMode(D4, OUTPUT); 

  led = 0;
}

void loop() {
  int iButton;
  int iVal; 
  
  iButton = digitalRead(D5); // reads button value
  iVal = analogRead(A0); // reads variable resistor value
  
  if (iButton == 0) // checks if the button is pressed
  {
    if (led == 0) // checks weither the led is on or off and switchs it
    {
      led = 1; // set led on
    }
    else{
      led = 0; // set led off
    }
  }

  if (led == 1)
  {
    analogWrite(D4, iVal/4); // gets brightness level from variable resistor
  }
  else{
    analogWrite(D4, 255); // led is off
  }

  delay(300); // debounce
}
