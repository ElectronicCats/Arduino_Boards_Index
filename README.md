[![Build Status](https://travis-ci.org/ElectronicCats/Arduino_Boards_Index.svg?branch=gh-pages)](https://travis-ci.org/ElectronicCats/Arduino_Boards_Index) 

# Electronic Cats Arduino Boards

**Installation Instruction**

By itself SAMD21 isn´t powerful, the suport with Arduino´s IDE is the special thing with. With only a clics pair, copies and pastes, you can add support for ARM cortex- M0+to your Arduino IDE...

**Installation soport for SAMD**

You must intall the last Arduino´s SAMD boards (version 1.6.11 or later) 

In the menu´s bar select tools -> Board -> Boards Manager -> Arduino SAMD Boards 32 bit M0.

You should write Arduino SAMD in the serch bar and then you can see the board and do clic in install. 

Board definitions for Electronic Cats-manufactured AVR, ARM, and ESP-based Arduino boards.
Based on sparkfun Arduino_Boards to implement diferents cores.

This repository contains support for the following Electronic Cats Arduino-compatible development boards.

**IMPORTANT NOTE:** These board files have been updated for compatibility with Arduino version 1.8 and higher. Some boards (e.g. SAMD) may not compile correctly with earlier versions of Arduino. If you need compatibility with earlier versions of Arduino, you can choose previous releases of these boards from the Boards Manager.

#### Microcontroller supported

- SAMD21
- SAML21
- SAMD11
- SAMR34 or RAK4260
- SAMD51


#### SAMD (ARM Cortex-M0+) Boards by Electronic Cats

* [Meow Meow](https://electroniccats.com/producto/meowmeow/)

* [CatWAN USB-Stick](https://electroniccats.com/producto/catwan_usb-stick/)

* [CatWAN Relay](https://electroniccats.com/producto/catwan-relay-board/)

* [CatWAN Citizen](https://electroniccats.com)

* [Bast Pro Mini M0](https://electroniccats.com)


### Installation Instructions

**Install SAMD support**

You must install the boards SAMD of Arduino(vertions 1.6.11 o posterior) 

In the menú bar selec tools --> boards --> Board Manager --> Arduino SAMD Boards 32 bit M0.

In the search bar write  "SAMD" en then you can see the boards, do clic in install and wait to finish to installe.

![](https://cdn-learn.adafruit.com/assets/assets/000/028/792/original/adafruit_products_arduinosamd162.png)

**Install "Electronic Cats" soport**

To add board support for our products, start Arduino and open the Preferences window (**File** > **Preferences**). Now copy and paste the following URL into the 'Additional Boards Manager URLs' input field:

	https://electroniccats.github.io/Arduino_Boards_Index/package_electroniccats_index.json


- If there is already an URL from another manufacturer in that field, click the button at the right end of the field. This will open an editing window allowing you to paste the above URL onto a new line.

- Press the "OK" button.
- Open the "boards manager" that is in tools --> Board --> board manager.
- Now write "Electronic Cats" (without quotes) in the search bar.
- Click in install, jus wait to finish to install and only close the window. 

![](https://github.com/ElectronicCats/MeowMeow/wiki/assets/Paso1_IDE.png)

- In tools --> Boards, scroll to down in the board´s list you can see the Electronic Cat´s boards.

![](https://github.com/ElectronicCats/MeowMeow/wiki/assets/Paso2_IDE.png)


### Notes
* Information on compiling and programming the bootloaders can be found in the bootloaders directory.

**Have fun!**<br>
\-Your friends at Electronic Cats


