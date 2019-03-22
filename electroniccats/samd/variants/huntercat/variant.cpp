/*
  Electronic Cats Hunter Cat Configuration File

  Based on Arduino SAMD21 configuration files,
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

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

#include "variant.h"

/*
 * Pin descriptions
 */
const PinDescription g_APinDescription[]=
{
// Digital  0/1 - Pins Extra and Analog
{ PORTA, 14, PIO_ANALOG,  (PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_EXTINT), ADC_Channel6, PWM0_CH0, TC0_CH0, EXTERNAL_INT_NMI }, // 0
{ PORTA, 15, PIO_ANALOG,  (PIN_ATTR_ANALOG|PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_EXTINT), ADC_Channel7, PWM0_CH1, TC0_CH1, EXTERNAL_INT_NMI }, // 1

// 2 - 3 - External Interrupt INT1 and INT2
{ PORTA, 8, PIO_DIGITAL,  (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_EXTINT), No_ADC_Channel, PWM0_CH2, TCC0_CH2, EXTERNAL_INT_6 },   // 2
{ PORTA, 9, PIO_DIGITAL,  (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_EXTINT), No_ADC_Channel, PWM0_CH3, TCC0_CH3, EXTERNAL_INT_7 },   // 3

//4..6 - LEDs
{ PORTA,  4, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM), No_ADC_Channel, PWM2_CH0, TC1_CH0, EXTERNAL_INT_NONE },  // 4 Yellow LED
{ PORTA,  5, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM), No_ADC_Channel, PWM2_CH1, TC1_CH1, EXTERNAL_INT_NONE }, // 5 Red LED
{ PORTA,  2, PIO_DIGITAL, (PIN_ATTR_DIGITAL), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 6 Green LED

// 7/8 - USB
// -------------------- 
{ PORTA, 24, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 7  USB DM
{ PORTA, 25, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 8 USB DP

// 9/10 - SWD/SERCOM1
{ PORTA, 30, PIO_SERCOM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },  // 9 SWDCLK
{ PORTA, 31, PIO_SERCOM, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM), No_ADC_Channel, PWM2_CH1, TC2_CH1, EXTERNAL_INT_NONE },// 10 SWDDIO

} ;

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TC1, TC2 } ;

// Multi-serial objects instantiation
SERCOM sercom0( SERCOM0 ) ;
SERCOM sercom1( SERCOM1 ) ;

Uart Serial1( &sercom1, PIN_SERIAL_RX, PIN_SERIAL_TX, PAD_SERIAL_RX, PAD_SERIAL_TX ) ;

void SERCOM1_Handler()
{
  Serial1.IrqHandler();
}

