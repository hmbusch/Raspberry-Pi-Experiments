/*
 * Simple serial mirror program for Arduino
 * https://github.com/hmbusch/Raspberry-Pi-Experiments
 *
 * Original by Joonas Pihlajamaa (http://www.joonaspihlajamaa.com/)
 * 
 * Hendrik Busch, http://www.icanmakeit.de/, 2013
 * Released under a Creative Commons Attribution-NonCommercial-ShareAlike 3.0 
 *
 * This small sketch is part of a project to try out and realise serial
 * communication between the Raspberry Pi and the Arduino in order to benefit
 * from Arduino's pin capability and Raspberry Pi processing power and
 * operating system.
 *
 * The sketch continously reads incoming bytes on the serial line and just
 * mirrors them back onto the serial line, so that the sending site will 
 * receive whatever it sent back. This program in inteded for verify basic 
 * serial operation.
 *
 * WARNING: When using a 5 volt Arduino, you need to put a logic level converter
 * between the Arduino and the Raspberry Pi, because the latter only runs on 3.3V
 * and unfiltered serial communication with a 5V device will fry your Raspberry.
 * You have been warned.
 *
 * This sketch is basically the one published at:
 * http://codeandlife.com/2012/07/29/arduino-and-raspberry-pi-serial-communication/
 * 
 */
 
/**
 * Initialise serial communication at the desired baud rate
 */
void setup() 
{
  Serial.begin(9600);
}

/**
 * Reads every incoming byte from the serial line and immediately writes
 * it back.
 */
void loop() 
{
  byte incomingByte;
  
  if(Serial.available() > 0) 
  {
    // read the available byte
    incomingByte = Serial.read();

    // simply write it back to serial
    Serial.write(incomingByte); 
  }
}
