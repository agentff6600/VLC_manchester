#include <Manchester.h>

/*
  REMOTE CONTROLL EMITTER TX FOR RGB LEDs
  
  You need for the emitter
    - Arduino UNO
    - RGB LED
    - Photodiode (SFH203)
    - Resistor 1MΩ
    - Potentiometer 1MΩ
    
  
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

uint16_t transmit_data = 0;             // here we will store your message to send. The message is just a number.

void setup() {

  man.workAround1MhzTinyCore();        // needed if you decide to use an 1Mhz Attiny85/84 chipset. just ignore for now.


}

void loop() {                          // the follow programm will be repeated to infinity and beyond.

  transmit_data = analogRead(A0);      // here we read the current value on the analog pin A0.

  int range = map(transmit_data, 0, 1023, 0, 2);

  switch (range) {

    case 0:                        // RED
      man.setupTransmit(TX_RED, MAN_1200);
      man.transmit(transmit_data);           // here we tell arduino to send the current message/number. In red. :)
      break;

    case 1:                        // GREEN
      man.setupTransmit(TX_GREEN, MAN_1200); // Here we reset the emitter. We use the color GREEN of the RGB LED.
      man.transmit(transmit_data);           // here we tell arduino to send the current message/number. In green. :)
      break;

    case 2:                        // BLUE
      man.setupTransmit(TX_BLUE, MAN_1200);  // Here we set up the emitter. We use the color BLUE of the RGB LED.
      man.transmit(transmit_data);           // here we tell arduino to send the current message/number. In blue. :)
      break;

  }
delay(1);
}
