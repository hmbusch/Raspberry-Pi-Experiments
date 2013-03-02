/*
 * Simple sketch to switch an LED on and off w/ serial control
 * https://github.com/hmbusch/Raspberry-Pi-Experiments
 *
 * Hendrik Busch, http://www.icanmakeit.de/, 2013
 * Released under a Creative Commons Attribution-NonCommercial-ShareAlike 3.0 
 *
 * This small sketch is part of a project to try out and realise serial
 * communication between the Raspberry Pi and the Arduino in order to benefit
 * from Arduino's pin capability and Raspberry Pi processing power and
 * operating system.
 *
 * The sketch continously reads incoming bytes. If the incoming byte is a '0',
 * the LED on pin 13 is turned off; a '1' will turn the LED on. 'b' or 'B' 
 * will put the LED in flash mode.
 *
 */

/**
 * If true, flash mode is active.
 */
boolean flashMode = false; 

/**
 * The current state of the LED, the flash mode needs this
 * to determine the state to which to switch.
 */
int ledState = LOW;

/**
 * The time of the last LED state change in flash mode. The
 * time is measured using millis(), so it indicated the amount
 * of milliseconds since the Arduino was powered on.
 */
unsigned long lastFlash = 0;

/**
 * Initialise serial communication at the desired baud rate
 * and configure pin 13 for output.
 */
void setup() 
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

/**
 * Reads from the serial line and switches the LED on or off
 * as desired. Also manages the flash mode by measuring the time
 * between the last flash and now. If a threshold of 250ms is 
 * is reached, the LED state is inverted.
 */
void loop() 
{
  byte incomingByte;
 
  // when flash mode is active and 250ms since the last state change have passed...
  if(flashMode && millis() - lastFlash > 250)
  {
      // we're flashing right now
      lastFlash = millis();
      
      // invert the LED state
      if (ledState == LOW)
      {
        ledState = HIGH;
      }
      else
      {
        ledState = LOW;
      }
      
      // update LED with new state
      digitalWrite(13, ledState);
    }
  }
 
  // are there bytes waiting to be read? 
  if(Serial.available() > 0) 
  {
    // read the available byte
    incomingByte = Serial.read();
    
    // decide what to do, ignore all other bytes besides those mentioned here
    if ('1' == incomingByte)
    {
      Serial.write("Turning LED on\n");
      flashMode = false;
      ledState = LOW;
      digitalWrite(13, HIGH);
    }
    else if ('0' == incomingByte)
    {
      Serial.write("Turning LED off\n");
      flashMode = false;
      ledState = LOW;
      digitalWrite(13, LOW);
    }
    else if ('b' == incomingByte || 'B' == incomingByte)
    {
      Serial.write("Entering blink mode\n");
      flashMode = true;
    }
  }
}
