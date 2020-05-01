# arduino-security-token
This project will get you ready an hardware security token using Arduino as HID, so basically creating a keyboard out of your AVR controller. The project is part of my "Microprocessor Systems" course of the Faculty of Automatic Control and Computer Science, Politehnica University of Bucharest.

Parts needed:
```
1 x Arduino UNO (or related)
1 x USB cable (an old one is fine)
2 x 68ohm resistor
1 x 1.5kohm resistor
1 x 10kohm resitor
1 x button
2 x 3.6v Zenner diode
    wires, breadboard
```

Before we dive into code, let's set up the connection:
```
USB:
  VCC to 5v Arduino
  D+ to pin 2 (using a 68ohm resistor)
  D+ to pin 5 (using a 1.5k reistor - this is the pull-up connection)
  D- to pin 4 (using a 68ohm resistor)
  GND to GND Arduino
Diodes:
  From GND to USB's D+/D- (white mark to D+/D-)
Button:
  GND to input pin of the button
  VCC to output pin of the button (using a 10kohm resistor)
  Wire from output pin to pin 10 of Arduino
```

Steps to set up your security token:
```
1. Download an older version of arduino (1.0.x) from [here](https://www.arduino.cc/en/main/OldSoftwareReleases)
2. Download the V-USB driver from [here](https://www.obdev.at/products/vusb/index.html)
3. Make sure your arduino to usb connection is correctly as stated above
4. Upload the code, unplug arduino then connect the external usb and press the button while in a .txt file (or any other text input fields)
```
** Note that wrongly setting up the connection can damage your Arduino and/or computer's USB port. **

If the example code is working, it will print "INSERT_TOKEN_HERE" in the text field.

There are not many other things to say about the code, but note that the following part is the one that produces the "magic":
  `UsbKeyboard.sendKeyStroke(token[i])` - it will send the key contained at token[i] to the computer.


This project is based on the V-USB implementation for AVR boards. The V-USB project contains three modules:
  - UsbDevice - a generic USB
  - UsbKeyboard - the one used in this project
  - UsbStream - for data streaming / communication)
  
Because this implementation follows the USB 1.0 standard and the device will act as a Human Interface Device, the project can be used on any Operating System (altough I tested it only on MacOS - some say that on Windows will automatically work and some say that you need to set-up things in Hardware Devices setting).
