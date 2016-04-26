#include <Manchester.h>
/*

  RECEIVER

  from the experiments the in lumoino manual:
      "Remote Control"

  This is based on the sketch: https://www.arduino.cc/en/Tutorial/Knob
  Differences:

  Only attach the servo to the RX module
  Only attach the potentiometer to the TX module


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

#define RX_PIN 4        // The Pin where your Photodiode is plugged-in.
#define SIGNAL_PIN 9    // The pin where you can plug in an LED or a servo. How to connect a servo? have a look here: http://www.arduino.cc/en/Tutorial/Knob
#define LED_PIN 13      // This uses the built-in led on the Arduino UNO board.
// But any plugged in LED on pin 13 will also work.

int val = 0;
int moo = 1;

void setup() {

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, moo);

  man.workAround1MhzTinyCore();         // needed if you decide to use an 1Mhz Attiny85/84 chipset. just ignore for now.

  man.setupReceive(RX_PIN, MAN_1200);  // this sets up the pin where your photodiode is plugged in. Also the speed is set here with MAN_1200.
  man.beginReceive();               //start listening for next message right after you retrieve the message

  Serial.begin(9600);


}


void loop() {

  if (man.receiveComplete()) {        // we wait until we receive a message. if so we continue with the following lines.

    uint16_t m = man.getMessage();    // the message is stored in the variable "m".


    val = map(m, 0, 1023, 255, 0);    // this scales down the message with the range 0-1023 to a range of 0-255 and saves it to the variable "val".
    analogWrite(SIGNAL_PIN, val);     // the variable "val" changes the voltage on the SIGNAL_PIN.

    man.beginReceive();               //start listening for next message right after you retrieve the message

    moo = ++moo % 2;                    // if the message is received correctly this toggles the
    digitalWrite(LED_PIN, moo);         // LED on pin 13 on and off. So if the led is blinking you know that it's working!

    Serial.println(m);
  }

}


