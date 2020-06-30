/*
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
 * Pins descriptions
 */
const PinDescription g_APinDescription[]=
{
  // ----------------------
  // 0/1 - SERCOM/UART (Serial1)
  { PORTA,  11, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PIN_ATTR_TIMER), PIN_ATTR_DIGITAL, TC4_CH1, ADC_Channel3, EXTERNAL_INT_9, GCLK_CCL_NONE }, // UART RX
  { PORTA,  10, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PIN_ATTR_TIMER), PIN_ATTR_DIGITAL, TC4_CH0, ADC_Channel2, EXTERNAL_INT_8, GCLK_CCL_NONE }, // UART TX
  
  // 2 - 3
  // (I2S SCK)
  { PORTB, 11, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PIN_ATTR_TIMER), (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG), NOT_ON_TIMER, ADC_Channel18, EXTERNAL_INT_10, GCLK_CCL_NONE }, //GPIO D2
  // (I2S Datain)
  { PORTA, 19, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PIN_ATTR_TIMER), (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG), TCC0_CH0, ADC_Channel16, EXTERNAL_INT_NMI, GCLK_CCL_NONE }, //GPIO D3

  // 4..6 
  // Digital High                  
  { PORTB, 22, PIO_MULTI, PER_ATTR_DRIVE_STRONG, PIN_ATTR_NONE, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // GPIO D4 / 
  { PORTA, 30, PIO_MULTI, PER_ATTR_DRIVE_STRONG, PIN_ATTR_DIGITAL, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // GPIO D5 /
  { PORTA, 31, PIO_MULTI, PER_ATTR_DRIVE_STRONG, PIN_ATTR_DIGITAL, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // GPIO D6 /

  //  7 - GPIO (CS)
  { PORTA, 13, PIO_MULTI, PER_ATTR_DRIVE_STRONG, PIN_ATTR_DIGITAL, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_13, GCLK_CCL_NONE }, // CS / EIC/EXTINT[13] *TCC2/WO[1] TCC0/WO[7] /GPIO D7
  
  // SPI 8, 9, 10
  { PORTA, 12, PIO_MULTI, PER_ATTR_DRIVE_STRONG, PIN_ATTR_NONE, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // MISO: SERCOM4/PAD[0] / GPIO D8
  { PORTA, 15, PIO_MULTI, PER_ATTR_DRIVE_STRONG, PIN_ATTR_DIGITAL, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // SCK: SERCOM4/PAD[3] /GPIO D9
  { PORTA, 14, PIO_MULTI, PER_ATTR_DRIVE_STRONG, PIN_ATTR_DIGITAL,TCC0_CH6, No_ADC_Channel, EXTERNAL_INT_4, GCLK_CCL_NONE }, // MOSI: SERCOM4/PAD[2] / GPIO D10

  // GPIO 11 & 12 I2C (original xtal pins)
  { PORTA, 0, PIO_MULTI, PER_ATTR_DRIVE_STRONG, PIN_ATTR_NONE, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // SDA
  { PORTA, 1, PIO_MULTI, PER_ATTR_DRIVE_STRONG, PIN_ATTR_NONE, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // SCL
  
  // 13 (LED)
  { PORTB, 23, PIO_MULTI, PER_ATTR_DRIVE_STRONG|PIN_ATTR_TIMER, PIN_ATTR_DIGITAL, TCC2_CH1, No_ADC_Channel, EXTERNAL_INT_1, GCLK_CCL_NONE }, // GPIO D13 / RED GREEN

  // 14..24 - Analog pins
  // -------------------- 
  { PORTA,  2, PIO_MULTI, PER_ATTR_DRIVE_STRONG, (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG), NOT_ON_TIMER, ADC_Channel0, EXTERNAL_INT_2, GCLK_CCL_NONE },        // A0 (Same as Y0)
  { PORTA,  3, PIO_MULTI, PER_ATTR_DRIVE_STRONG, PIN_ATTR_ANALOG, NOT_ON_TIMER, No_ADC_Channel, EXTERNAL_INT_NONE, GCLK_CCL_NONE },                      // A1 (Same as Y1)(DAC/VREFP)(AREF)
  { PORTA,  4, PIO_MULTI, PER_ATTR_DRIVE_STRONG, (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG), NOT_ON_TIMER, ADC_Channel4, EXTERNAL_INT_4, GCLK_CCL_NONE },        // A2 (Same as Y2)
  { PORTA,  5, PIO_MULTI, PER_ATTR_DRIVE_STRONG, (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG), NOT_ON_TIMER, ADC_Channel5, EXTERNAL_INT_5, GCLK_CCL_NONE },        // A3 (Same as Y3)
  { PORTA,  6, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PIN_ATTR_TIMER), (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG), TCC1_CH0, ADC_Channel6, EXTERNAL_INT_6, GCLK_CCL_NONE },  // A4 (Same as Y4)
  { PORTA,  7, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PIN_ATTR_TIMER), (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG), TCC1_CH1, ADC_Channel7, EXTERNAL_INT_7, GCLK_CCL_NONE },  // A5 (Same as Y5)
  { PORTB,  2, PIO_MULTI, PER_ATTR_DRIVE_STRONG, (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG), NOT_ON_TIMER, ADC_Channel10, EXTERNAL_INT_2, GCLK_CCL_NONE },       // A6 (Same as Y8)
  { PORTB,  3, PIO_MULTI, PER_ATTR_DRIVE_STRONG, (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG), NOT_ON_TIMER, ADC_Channel11, EXTERNAL_INT_NONE, GCLK_CCL_NONE },    // A7 (Same as Y9)
  { PORTB,  8, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PIN_ATTR_TIMER), (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG|PIN_ATTR_TIMER), TC4_CH0, ADC_Channel2, EXTERNAL_INT_8, GCLK_CCL_NONE },   // A8 (Same as Y14)
  { PORTB,  9, PIO_MULTI, (PER_ATTR_DRIVE_STRONG|PIN_ATTR_TIMER), (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG|PIN_ATTR_TIMER), TC4_CH1, ADC_Channel3, EXTERNAL_INT_9, GCLK_CCL_NONE },   // A9 (Same as Y15)
  { PORTA, 11, PIO_MULTI, PER_ATTR_DRIVE_STRONG, (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG), NOT_ON_TIMER, ADC_Channel19, EXTERNAL_INT_11, GCLK_CCL_NONE },                      // A10 

  // 25..27 - USB
  // --------------------  
  { PORTA, 22, PIO_MULTI, PER_ATTR_DRIVE_STRONG, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_TIMER, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // GPIO 26 - Host USB (not used)
  { PORTA, 24, PIO_MULTI, PER_ATTR_DRIVE_STRONG, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_TIMER, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // USB/DM
  { PORTA, 25, PIO_MULTI, PER_ATTR_DRIVE_STRONG, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_TIMER, EXTERNAL_INT_NONE, GCLK_CCL_NONE }, // USB/DP

} ;

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TC3, TC4, TC5 } ;

// Multi-serial objects instantiation
SERCOM sercom0( SERCOM0 ) ;
SERCOM sercom1( SERCOM1 ) ;
SERCOM sercom2( SERCOM2 ) ;
SERCOM sercom3( SERCOM3 ) ;
SERCOM sercom4( SERCOM4 ) ;
SERCOM sercom5( SERCOM5 ) ;

Uart Serial1( &sercom4, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX ) ;

void SERCOM4_Handler()
{
  Serial1.IrqHandler();
}

