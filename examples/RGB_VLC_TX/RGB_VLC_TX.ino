#include <Manchester.h>

/*

  TRANSMITTER

  from the experiments in the lumoino manual:
      "At the speed of light" (the RGB edition)

  Make sure you have an RGB LED with a common cathode (the longest leg). This will go into the pin "GND".
  Have a look at the picture "RGB_LED_SETUP.png" in the folder where this sketch is. Connect the RGB LED the following way.

  The anode for RED goes into PIN 13
  The anode for GREEN goes into PIN 12
  The anode for BLUE goes into PIN 11
  

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

#define TX_RED 13     //  The anode for RED goes into PIN 13
#define TX_GREEN 12   //  The anode for GREEN goes into PIN 12
#define TX_BLUE 11    //  The anode for BLUE goes into PIN 11

uint16_t transmit_data = 0;              // here we will store your message to send. The message is just a number.

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, moo);
  
  man.workAround1MhzTinyCore();          //add this in order for transmitter to work with 1Mhz Attiny85/84
  

void loop() {                            // the follow programm will be repeated to infinity and beyond.

  man.setupTransmit(TX_RED, MAN_1200);   // Here we set up the emitter. We use the color RED first of the RGB LED.
  man.transmit(transmit_data);           // here we tell arduino to send the current message/number. In red. :)
  transmit_data++;                       // and add 1 to the current number.

  man.setupTransmit(TX_GREEN, MAN_1200); // Here we reset the emitter. We use the color GREEN of the RGB LED.
  man.transmit(transmit_data);           // here we tell arduino to send the current message/number. In green. :)
  transmit_data++;                       // and add 1 to the current number.

  man.setupTransmit(TX_BLUE, MAN_1200);  // Here we set up the emitter. We use the color BLUE of the RGB LED.
  man.transmit(transmit_data);           // here we tell arduino to send the current message/number. In blue. :)
  transmit_data++;                       // and add 1 to the current number.

}
