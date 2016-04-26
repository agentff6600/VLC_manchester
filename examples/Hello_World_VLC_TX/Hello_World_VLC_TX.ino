
#include <Manchester.h>

/*

  TRANSMITTER

  from the experiments in the lumoino manual:
      "Remote Control!"

  To transmit a number from the corresponding receiver.
  The transmitted message is a number from 0 to infinity (not really but thats another story)
  
  
  Based on the github repository of mchr3k. Amazing work! https://github.com/mchr3k/arduino-libs-manchester

  TRANSMITTER AND RECEIVER MUST HAVE THE SAME SPEED
  Try different speed settings using these constants:
  
  MAN_300   (you can see the flickering of the LED)
  MAN_600
  MAN_1200  (best)
  MAN_2400
  MAN_4800
  MAN_9600
  MAN_19200
  MAN_38400 (very hard to read by the photodiode)
  
*/

#define TX_PIN 13  //pin where your transmitter is connected

uint8_t data[15] = "work.ff6600.ch";      //the array with the string "hello world". 12 defines how long the array is. "hello world" has 11 symbol. to that 

void setup() {
  
  man.workAround1MhzTinyCore();         //add this in order for transmitter to work with 1Mhz Attiny85/84
  
  man.setupTransmit(TX_PIN, MAN_1200);  //TRANSMITTER AND RECEIVER MUST HAVE THE SAME SPEED
}

void loop() {                           // the follow programm will be repeated to infinity and beyond.
  
  man.transmitArray(15, data);          // here we tell arduino to send the message.
   
}
