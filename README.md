# MidiForArduino
Do you want to build your own MIDI device for cheap? This fork should help! MidiForArduino Allows users to build a device with slide potentiometers and buttons, to create a MIDI Device, The limit of the devices is however many Analogue and Digital pins on your arduino. if you need help, Don't Fret- Just create a Issue. schematics and photos below. Some cases I reccomend if you have a 3d printer, Search on Thingiverse for a Deej case. They allow spots for faders and buttons. This code / repo is not related to Deej, But if you are intrested in build an Windows Audio Controller, Please check out the repo here: https://github.com/Miodec/deej | The schematic is very simple, as it doesn't require a-lot of work. Thank you also to: https://github.com/arduino-libraries/MIDIUSB for the Repo to use for MIDI control. Its a simple Schematic as you just need to connect the Sliders to the Arduino analog and buttons to digital. The max faders for an arduino micro is 10 and 10 buttons or however you want to configurate it. Ground is daisy chained as well as 5v, so following this schematic can be very easy.  Below is the schematic, Credit to [Deej Wiring](https://github.com/omriharel/deej/blob/master/docs/faq/assets/wiring-methods.png). for a wiring schematic on how to wire your slides/buttons/potentiometers. Below is the picture. PS: I cannot help you hook this device up to any software such as Abelton; But it works as any device so if your software reads midi; it should work. You will need Bomes Midi Translator to take your midi controls to actual fader movements.

![wiring-methods](https://github.com/Willtheham/MidiForArduino/assets/109185939/badf9956-dc5b-41a3-8577-9496bc264f78)


So, If you want to use MIDI without a UsbHID compatible board, like a Mega5260, you can use the [setup](https://diyelectromusic.wordpress.com/2022/03/22/arduino-and-usb-midi/) and scroll down to Serial midi over USB. It explains it perfectly, and on how to use it. Then all you need is a midi loopback app, and whatever you want to control. Ill be using bomes midi translator so i can use it for Ma2 and abelton.

I will be unable to provide support for this code and project, I have used this and tried this, but I reccomend you find a good repo to help. You require to use [hairless](https://projectgus.github.io/hairless-midiserial/) to connect the strings between the arduino and the midi after your done with the code after you edit it to your parameters. You will also need *not stated in the setup* [LoopMIDI](https://www.tobias-erichsen.de/software/loopmidi.html), so you have a midi device specifically for your arduino, just click the plus and name it "Arduino MIDI" or whatever you want. Then connect the strings and your pretty much done, Other than what I just provided I cannot help you. 
