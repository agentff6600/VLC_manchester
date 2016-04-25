
# Lumoino - talking lights

This is the library for the project "lumoino". 

The Arduino sketches are based on the instructions of the booklet "lumoino - talking light".

The lumoino project is a master degree project done at KTH during spring 2016.
The intend is to provide examples for users to play around with Visible Light Communication with basic components like LEDs and photodiodes.

##Installation in Arduino
1. Download the zip file of this repository.
2. Open the Arduino IDE (download [here](http://www.arduino.cc))
3. Go to Sketch -> Include library -> Add .zip Library...
4. Select "lumoino-master.zip" a press "Choose"
5. Done!

##Future work

This project is just the beginning and shows a fraction of what is possible in Visbible Light Communication.

Possible ideas for this project:
- Use LED as a receiver too
- Bi-directional communication (like in [this paper](http://www.merl.com/publications/docs/TR2003-35.pdf "this paper"))
- iOS and Android app to make use of the rolling shutter effect
- Simple "light to audio" interface using the microphone port (like in [this paper](https://www.disneyresearch.com/publication/from-sound-to-sight-using-audio-processing-to-enable-visible-light-communication/ "this paper"))
- A pure data patch (using the "light to audio" interface)

## Credits

This project would not be possible without the awesome work of mchr3k. The Arduino Manchester Encoding library is an essential piece of this project and is very easy to understand! One has to mention it was originally intended for Radio Frequency communication but it works just fine with Visible Light Communication via LED and photodiodes as well. :)

Full details available on the [Arduino Manchester Encoding site](http://mchr3k.github.com/arduino-libs-manchester/)
