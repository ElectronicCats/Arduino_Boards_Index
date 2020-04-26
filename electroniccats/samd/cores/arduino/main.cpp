/*
  Copyright (c) 2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#define ARDUINO_MAIN
#include "Arduino.h"

// Weak empty variant initialization function.
// May be redefined by variant files.
void initVariant() __attribute__((weak));
void initVariant() { }

// Initialize C library
extern "C" void __libc_init_array(void);

/*
 * \brief Main entry point of Arduino application
 */
int main( void )
{
  init();

  __libc_init_array();

  initVariant();

  delay(1);

  #if defined(USBCON)
    #if defined(USE_TINYUSB)
      Adafruit_TinyUSB_Core_init();
    #else
      USBDevice.init();
      USBDevice.attach();
    #endif
  #endif

  setup();

  for (;;)
  {
    loop();

     #if defined(USE_TINYUSB) && defined(USBCON)
       tud_task();
     #endif

    if (serialEventRun) serialEventRun();
  }

  return 0;
}

#if defined(USE_TINYUSB) && defined(USBCON)
void yield(void)
{
  tud_task();
}
#endif
