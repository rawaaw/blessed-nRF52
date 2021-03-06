/**
 * Copyright (c) 2012 - 2018, Nordic Semiconductor ASA
 * 
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 * 
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 * 
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 * 
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 * 
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */
#ifndef YJ16002_H
#define YJ16002_H

#ifdef __cplusplus
extern "C" {
#endif

#include "nrf_gpio.h"


//#define LED_START      11
#define LED_0          11 // beacon board
//#define LED_STOP       12

#define LEDS_ACTIVE_STATE 1

#define BSP_LED_0      LED_0

#define LEDS_INV_MASK  0x00000000

#define BUTTONS_NUMBER 0
#define LEDS_NUMBER    1

#define LEDS_LIST { LED_0 }

// UART pins
#define RX_PIN_NUMBER  18
#define TX_PIN_NUMBER  16
//#define CTS_PIN_NUMBER 17
//#define RTS_PIN_NUMBER 15
#define HWFC           true

//TWI pins
#define ARDUINO_SCL_PIN    13    // beacon SCL signal pin
#define ARDUINO_SDA_PIN    14    // beacon SDA signal pin

//GPIO
#define PIN_GPIO0      12        //ST7735 PIN_CS
#define PIN_GPIO1      15        //ST7735 PIN_SCK
#define PIN_GPIO2      13        //ST7735 PIN_MOSI
#define PIN_GPIO3      11        //ST7735 PIN_DC
#define PIN_GPIO4      14        //ST7735 PIN_RESET

#define PIN_GPIO9      9         //receiver BTN1 / beacon GP9 
#define PIN_GPIO10     10        //receiver BTN2 / beacon GP10



#ifdef __cplusplus
}
#endif

#endif
