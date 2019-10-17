/*
  Copyright (c) 2017 MattairTech LLC. All right reserved.
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

#include "sam.h"
#include "variant.h"

#include <stdio.h>

/**
 * \brief SystemInit() configures the needed clocks and according Flash Read Wait States.
 */

// Constants for Clock generators
#define GENERIC_CLOCK_GENERATOR_MAIN      (0u)
#define GENERIC_CLOCK_GENERATOR_XOSC      (1u)
#define GENERIC_CLOCK_GENERATOR_OSCULP32K (2u) /* Initialized at reset for WDT (D21/D11) */
#define GENERIC_CLOCK_GENERATOR_OSC_HS    (3u)

// Constants for Clock multiplexers
#define GENERIC_CLOCK_MULTIPLEXER_DFLL    (0u)
#define GENERIC_CLOCK_MULTIPLEXER_FDPLL   (1u)
#define GENERIC_CLOCK_MULTIPLEXER_FDPLL96M_32K (2u)


void waitForSync( void ){
  while ( GCLK->STATUS.reg & GCLK_STATUS_SYNCBUSY );
}


void waitForDFLL( void ){
  while ( (SYSCTRL->PCLKSR.reg & SYSCTRL_PCLKSR_DFLLRDY) == 0 );
}


void SystemInit( void )
{
  /* Set 1 Flash Wait State for 48MHz (2 for the L21 and C21), cf tables 20.9 and 35.27 in SAMD21 Datasheet */
  NVMCTRL->CTRLB.bit.RWS = NVMCTRL_CTRLB_RWS_HALF_Val ;	// one wait state


  /* Turn on the digital interface clock */
  PM->APBAMASK.reg |= PM_APBAMASK_GCLK ;

  /* ----------------------------------------------------------------------------------------------
   * Software reset the GCLK module to ensure it is re-initialized correctly
   */

  GCLK->CTRL.reg = GCLK_CTRL_SWRST ;

  while ( (GCLK->CTRL.reg & GCLK_CTRL_SWRST) && (GCLK->STATUS.reg & GCLK_STATUS_SYNCBUSY) );	/* Wait for reset to complete */


  /* ----------------------------------------------------------------------------------------------
   * Enable DFLL48M clock (D21/L21) or RC oscillator (C21)
   */

  /* Remove the OnDemand mode, Bug http://avr32.icgroup.norway.atmel.com/bugzilla/show_bug.cgi?id=9905 */
  SYSCTRL->DFLLCTRL.bit.ONDEMAND = 0 ;
  waitForDFLL();
  
  /* Load NVM Coarse calibration value */
  uint32_t calib = (*((uint32_t *) FUSES_DFLL48M_COARSE_CAL_ADDR) & FUSES_DFLL48M_COARSE_CAL_Msk) >> FUSES_DFLL48M_COARSE_CAL_Pos;
  SYSCTRL->DFLLVAL.reg = SYSCTRL_DFLLVAL_COARSE(calib) | SYSCTRL_DFLLVAL_FINE(512);
  
  /* Write full configuration to DFLL control register */
  /* Configure internal clock for USB */
  SYSCTRL->DFLLMUL.reg = SYSCTRL_DFLLMUL_CSTEP( 31 ) | // Coarse step is 31, half of the max value
                          SYSCTRL_DFLLMUL_FSTEP( 0xA ) | // value from datasheet USB Characteristics
                          SYSCTRL_DFLLMUL_MUL( 0xBB80 ) ; // 1KHz USB SOF signal (48MHz Fcpu / 1KHz SOF)
                        
  SYSCTRL->DFLLCTRL.reg =  SYSCTRL_DFLLCTRL_USBCRM | /* USB correction */
                            SYSCTRL_DFLLCTRL_MODE | /* Closed loop mode */
                            SYSCTRL_DFLLCTRL_CCDIS ;
  waitForDFLL();

  
  /* Enable the DFLL */
  SYSCTRL->DFLLCTRL.reg |= SYSCTRL_DFLLCTRL_ENABLE ;
  waitForDFLL();
  
  /* Switch Generic Clock Generator 0 to DFLL48M. CPU will run at 48MHz */
  GCLK->GENDIV.reg = GCLK_GENDIV_ID( GENERIC_CLOCK_GENERATOR_MAIN ) ; // Generic Clock Generator 0
  waitForSync();

  GCLK->GENCTRL.reg = ( GCLK_GENCTRL_ID( GENERIC_CLOCK_GENERATOR_MAIN ) | GCLK_GENCTRL_SRC_DFLL48M | GCLK_GENCTRL_IDC | GCLK_GENCTRL_GENEN );
  waitForSync();

  SystemCoreClock=VARIANT_MCK ;


  PM->CPUSEL.reg  = PM_CPUSEL_CPUDIV_DIV1 ;
  PM->APBASEL.reg = PM_APBASEL_APBADIV_DIV1_Val ;
  PM->APBBSEL.reg = PM_APBBSEL_APBBDIV_DIV1_Val ;
  PM->APBCSEL.reg = PM_APBCSEL_APBCDIV_DIV1_Val ;


  /*
   * Disable automatic NVM write operations (errata reference 13134, applies to D21/D11/L21, but not C21)
   */
  NVMCTRL->CTRLB.bit.MANW = 1;
}
