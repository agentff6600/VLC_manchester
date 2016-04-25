#include <Manchester.h>

/*

  TRANSMITTER

  from the experiments in the lumoino manual:
      "At the speed of light"
      "How to increase the reception"

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

#define TX_PIN 13                       // The Pin where your LED is plugged-in.
                                        
uint16_t transmit_data = 0;             // here we will store your message to send. The message is just a number.

void setup() {
  
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, moo);
  
  man.workAround1MhzTinyCore();        // needed if you decide to use an 1Mhz Attiny85/84 chipset. just ignore for now.
  
  man.setupTransmit(TX_PIN, MAN_1200); //TRANSMITTER AND RECEIVER MUST HAVE THE SAME SPEED
  
}

void loop() {                          // the follow programm will be repeated to infinity and beyond.
  
  man.transmit(transmit_data);         // here we tell arduino to send the current message/number.
  
  moo = ++moo % 2;                     // after the message is sent this toggles the 
  digitalWrite(LED_PIN, moo);          // LED on pin 13 on and off. So if the led is blinking you know that it's sending messages!
    
}
