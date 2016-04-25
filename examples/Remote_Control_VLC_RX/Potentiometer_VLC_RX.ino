#include <Manchester.h>
#include <Servo.h>
/*

  Manchester Receiver example
  
  In this example receiver will receive one 16 bit number per transmittion

  try different speeds using this constants, your maximum possible speed will 
  depend on various factors like transmitter type, distance, microcontroller speed, ...

  MAN_300 0
  MAN_600 1
  MAN_1200 2
  MAN_2400 3
  MAN_4800 4
  MAN_9600 5
  MAN_19200 6
  MAN_38400 7

*/

#define RX_PIN 9        // The Pin where your Photodiode is plugged-in.
#define SIGNAL_PIN 5    // The pin where you can plug in an LED or a servo. How to connect a servo? have a look here: http://www.arduino.cc/en/Tutorial/Knob
#define LED_PIN 13      // This uses the built-in led on the Arduino UNO board.
                        // But any plugged in LED on pin 13 will also work.

int val = 0;

void setup() {
  
  pinMode(LED_PIN, OUTPUT);  
  analogWrite(LED_PIN, val);

  man.workAround1MhzTinyCore();         // needed if you decide to use an 1Mhz Attiny85/84 chipset. just ignore for now.
  
  man.setupReceive(RX_PIN, MAN_1200);  // this sets up the pin where your photodiode is plugged in. Also the speed is set here with MAN_1200.
  man.beginReceive();                  // here we start to listen to incoming messages from the transmitter and retreives it.
}


void loop() {
  
  if (man.receiveComplete()) {        // we wait until we receive a message. if so we continue with the following lines.
    
    uint16_t m = man.getMessage();    // the message is stored in the variable "m".
    
    man.beginReceive();               //start listening for next message right after you retrieve the message
    
    val = map(m, 0, 1023, 0, 255);    // this scales down the message with the range 0-1023 to a range of 0-255 and saves it to the variable "val".
    analogWrite(SIGNAL_PIN, val);     // the variable "val" changes the voltage on the SIGNAL_PIN.
  }
  
}


