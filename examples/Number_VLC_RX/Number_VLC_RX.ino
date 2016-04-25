#include <Manchester.h>

/*

  RECEIVER

  from the experiments the in lumoino manual:
      "At the speed of light"
      "How to increase the reception"

  To reveive a number from the corresponding transmitter.
  
  
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

#define RX_PIN 8                        // The Pin where your Photodiode is plugged-in.
#define LED_PIN 13                      // This uses the built-in led on the Arduino UNO board.
                                        // But any plugged in LED on pin 13 will also work.

uint8_t moo = 1;                        //last led status on LED_PIN

void setup() {
  
  pinMode(LED_PIN, OUTPUT);  
  digitalWrite(LED_PIN, moo);
  
  man.workAround1MhzTinyCore();         // needed if you decide to use an 1Mhz Attiny85/84 chipset. just ignore for now.
  
  man.setupReceive(RX_PIN, MAN_1200);   // this sets up the pin where your photodiode is plugged in. Also the speed is set here with MAN_1200.
  man.beginReceive();                   // here we start to listen to incoming messages from the transmitter and retreives it.
  
}
  
void loop() {
    
  if (man.receiveComplete()) {          // we wait until we receive a message. if so we continue with the following lines.
    
    uint16_t m = man.getMessage();      // the message is stored in the variable "m".
    
    man.beginReceive();                 //start listening for next message right after you retrieve the message.
    
    moo = ++moo % 2;                    // if the message is received correctly this toggles the 
    digitalWrite(LED_PIN, moo);         // LED on pin 13 on and off. So if the led is blinking you know that it's working!
    
    }
}
