/**
 *  The MIT License (MIT)
 *
 *  Copyright (c) 2013 Paulo B. de Oliveira Filho <pauloborgesfilho@gmail.com>
 *  Copyright (c) 2013 Claudio Takahasi <claudio.takahasi@gmail.com>
 *  Copyright (c) 2013 João Paulo Rechi Vita <jprvita@gmail.com>
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

#include <stdint.h>
#include <stdbool.h>

#include <blessed/bluetooth.h>
#include <blessed/evtloop.h>

#include "boards.h"
#include "lm75b.h"

#include "nrf_delay.h"
#include "blessed/log.h"
//#include "nrf_log.h"
//#include "nrf_log_ctrl.h"
//#include "nrf_log_default_backends.h"

#define BLE_ADDRESS_ADDR		{ 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF }
#define BLE_ADDRESS_TYPE		BDADDR_TYPE_RANDOM
#define BLE_ADDRESS			{ BLE_ADDRESS_ADDR, BLE_ADDRESS_TYPE }


static uint8_t data[BCI_ADV_MTU_DATA];
static uint8_t len;
static uint32_t sample_no = 0;


int main(void)
{
  int16_t status;
  uint8_t mft[] = {
    0x4C, 0x00,		/* Apple's Company Identifier Code */
    0x02,			/* Device type: iBeacon */
    0x15,			/* Remaining length */
    0xAA, 0xAA, 0xAA, 0xAA,	/* UUID */
    0xAA, 0xAA, 0xAA, 0xAA,
    0xAA, 0xAA, 0xAA, 0xAA,
    0xAA, 0xAA, 0xAA, 0xAA,
    0xBB, 0xBB,		/* Major */
    0xCC, 0xCC,		/* Minor */
    0xDD			/* RSSI at 1 meter away */
  };

  log_init();

  bsp_board_init(BSP_INIT_LEDS);
  bsp_board_led_on(0);

  log_string("App. started.");

  twi_init();

#if 0
  BLUETOOTH_INIT(status);
  if (status < 0)
    return status;
#endif
  while (true){
    nrf_delay_ms(2000);
    LM75B_normal_mode();
    nrf_delay_ms(300);
    LM75B_read_data();
    LM75B_shutdown();

    log_printf("sample:%d Temperature: %d.%d Celsius degrees.", sample_no ++, LM75B_get_tC(), LM75B_get_tCf());

#if 0
    shutdown_sensor();
    twi_uninit();
    while (1){
      __WFE();
    }
#endif
#if 0
    len = bci_ad_put(data, BCI_AD_MFT_DATA, mft, sizeof(mft),
    						BCI_AD_INVALID);

    bci_set_advertising_data(data, len);
    bci_set_advertise_enable(BCI_ENABLE);

    evt_loop_run();
#endif
  }

  return 0;
}
