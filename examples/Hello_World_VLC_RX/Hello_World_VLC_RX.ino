
#include <Manchester.h>
#include <Keyboard.h>

/*

  RECEIVER

  YOU WILL NEED AN ARDUINO LEONARDO OR SIMILIAR TO USE THIS SKETCH!

  from the experiments the in lumoino manual:
      "Remote Control!"

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

#define RX_PIN 4      // The Pin where your Photodiode is plugged-in.
#define LED_PIN 13    // This uses the built-in led on the Arduino UNO board.
                      // But any plugged in LED on pin 13 will also work.          

#define BUFFER_SIZE 15  //This is the variable that sets how long your message is that you want to receive.

uint8_t moo = 1;
uint8_t buffer[BUFFER_SIZE];

void setup() {
  pinMode(LED_PIN, OUTPUT);  
  digitalWrite(LED_PIN, moo);
  
  man.setupReceive(RX_PIN, MAN_1200);           // this sets up the pin where your photodiode is plugged in. Also the speed is set here with MAN_1200.
  man.beginReceiveArray(BUFFER_SIZE, buffer);   // here we start to listen to incoming messages from the transmitter and retreives it.
  
  Keyboard.begin();                             // This is necessary to use the Arduino as a Keyboard. It will write on your computer!
  
  while (!Serial);
  Serial.print("Ready, Freddy");
}

void loop() {
  
  if (man.receiveComplete()) {                  // we wait until we receive a message. if so we continue with the following lines.
    //uint8_t receivedSize = 0;

    for (int i=0; i < BUFFER_SIZE; i++){        // Here we assemble the received message into a readable message.
      
      Keyboard.write(buffer[i]);
      }
      Keyboard.println();
   
    man.beginReceiveArray(BUFFER_SIZE, buffer);   //start listening for next message right after you retrieve the message.
    
    moo = ++moo % 2;                              // if the message is received correctly this toggles the
    digitalWrite(LED_PIN, moo);                   // LED on pin 13 on and off. So if the led is blinking you know that it's working!
  }
}
