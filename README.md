[![Build Status](https://travis-ci.org/ElectronicCats/Arduino_Boards_Index.svg?branch=gh-pages)](https://travis-ci.org/ElectronicCats/Arduino_Boards_Index) 

# Electronic Cats Arduino Boards

Board definitions for Electronic Cats-manufactured AVR, ARM, and ESP-based Arduino boards.
Based on sparkfun Arduino_Boards to implement diferents cores.

This repository contains support for the following Electronic Cats Arduino-compatible development boards.

**IMPORTANT NOTE:** These board files have been updated for compatibility with Arduino version 1.8 and higher. Some boards (e.g. SAMD) may not compile correctly with earlier versions of Arduino. If you need compatibility with earlier versions of Arduino, you can choose previous releases of these boards from the Boards Manager.


#### SAMD (ARM Cortex-M0+) Boards

* [Meow Meow](https://electroniccats.com/gomeow/)

* [CatWAN USB-Stick](https://www.tindie.com/products/electroniccats/catwan-usb-stick/)

* [CatWAN Relay](https://www.tindie.com/products/electroniccats/catwan-relay-board/)


### Installation Instructions

To add board support for our products, start Arduino and open the Preferences window (**File** > **Preferences**). Now copy and paste the following URL into the 'Additional Boards Manager URLs' input field:

	https://electroniccats.github.io/Arduino_Boards_Index/package_electroniccats_index.json


If there is already an URL from another manufacturer in that field, click the button at the right end of the field. This will open an editing window allowing you to paste the above URL onto a new line.


### SAMD Installation Instructions

Open the Boards Manager window by selecting **Tools** > **Board**, scroll to the top of the board list, and select **Boards Manager**. Now type "Electronic Cats" (without quotes) into the "filter your search" field at the top of the window.
 

### Notes
* Information on compiling and programming the bootloaders can be found in the bootloaders directory.

**Have fun!**<br>
\-Your friends at Electronic Cats

