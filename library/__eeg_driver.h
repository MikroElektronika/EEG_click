/*
    __eeg_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __eeg_driver.h
@brief    EEG Driver
@mainpage EEG Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   EEG
@brief      EEG Click Driver
@{

| Global Library Prefix | **EEG** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Oct 2018.**      |
| Developer             | **Nemanja Medakovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _EEG_H_
#define _EEG_H_

/** 
 * @macro T_EEG_P
 * @brief Driver Abstract type 
 */
#define T_EEG_P    const uint8_t*

/** @defgroup EEG_COMPILE Compilation Config */              /** @{ */

//  #define   __EEG_DRV_SPI__                            /**<     @macro __EEG_DRV_SPI__  @brief SPI driver selector */
//  #define   __EEG_DRV_I2C__                            /**<     @macro __EEG_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __EEG_DRV_UART__                           /**<     @macro __EEG_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup EEG_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup EEG_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup EEG_INIT Driver Initialization */              /** @{ */

#ifdef   __EEG_DRV_SPI__
void eeg_spiDriverInit(T_EEG_P gpioObj, T_EEG_P spiObj);
#endif
#ifdef   __EEG_DRV_I2C__
void eeg_i2cDriverInit(T_EEG_P gpioObj, T_EEG_P i2cObj, uint8_t slave);
#endif
#ifdef   __EEG_DRV_UART__
void eeg_uartDriverInit(T_EEG_P gpioObj, T_EEG_P uartObj);
#endif

void eeg_gpioDriverInit(T_EEG_P gpioObj);
                                                                       /** @} */
/** @defgroup EEG_FUNC Driver Functions */                   /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_EEG_STM.c
    @example Click_EEG_TIVA.c
    @example Click_EEG_CEC.c
    @example Click_EEG_KINETIS.c
    @example Click_EEG_MSP.c
    @example Click_EEG_PIC.c
    @example Click_EEG_PIC32.c
    @example Click_EEG_DSPIC.c
    @example Click_EEG_AVR.c
    @example Click_EEG_FT90x.c
    @example Click_EEG_STM.mbas
    @example Click_EEG_TIVA.mbas
    @example Click_EEG_CEC.mbas
    @example Click_EEG_KINETIS.mbas
    @example Click_EEG_MSP.mbas
    @example Click_EEG_PIC.mbas
    @example Click_EEG_PIC32.mbas
    @example Click_EEG_DSPIC.mbas
    @example Click_EEG_AVR.mbas
    @example Click_EEG_FT90x.mbas
    @example Click_EEG_STM.mpas
    @example Click_EEG_TIVA.mpas
    @example Click_EEG_CEC.mpas
    @example Click_EEG_KINETIS.mpas
    @example Click_EEG_MSP.mpas
    @example Click_EEG_PIC.mpas
    @example Click_EEG_PIC32.mpas
    @example Click_EEG_DSPIC.mpas
    @example Click_EEG_AVR.mpas
    @example Click_EEG_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __eeg_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */

