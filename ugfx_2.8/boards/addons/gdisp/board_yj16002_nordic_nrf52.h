#ifndef _GDISP_LLD_BOARD_H
#define _GDISP_LLD_BOARD_H

#include "nrf_gpio.h"
#include "nrf_drv_spi.h"
#include "app_util_platform.h"
#include "boards.h"

#define PIN_CS			PIN_GPIO0  //12
#define PIN_SCK			PIN_GPIO1  //14
#define PIN_MOSI		PIN_GPIO2  //13
#define PIN_DC			PIN_GPIO3  //20
#define PIN_RESET		PIN_GPIO4  //19
//#define PIN_BUSY		PIN_GPIO5  //24

#define SPI_INSTANCE	0

static const nrf_drv_spi_t spi = NRF_DRV_SPI_INSTANCE(SPI_INSTANCE);
static uint32_t _spi_xfer_done = false;

static void spi_event_handler(nrf_drv_spi_evt_t const * p_event,
                       void *                    p_context)
{
    _spi_xfer_done = true;
}


static GFXINLINE bool_t init_board(GDisplay* g)
{
	nrf_drv_spi_config_t spi_config;
	ret_code_t err = NRF_SUCCESS;

	(void)g;

	// Initialize RESET pin
	nrf_gpio_cfg_output(PIN_RESET);

	// Initialize RESET pin
	nrf_gpio_cfg_output(PIN_DC);
	
	// Initialize BUSY pin
#if 0
	nrf_gpio_cfg_input(PIN_BUSY, NRF_GPIO_PIN_NOPULL);
#endif

	// Initialize RESET pin
	nrf_gpio_cfg_output(PIN_CS);

	// Initialize SPI
	spi_config.sck_pin		= PIN_SCK;
	spi_config.mosi_pin		= PIN_MOSI;
	spi_config.miso_pin		= NRF_DRV_SPI_PIN_NOT_USED;
	spi_config.ss_pin		= NRF_DRV_SPI_PIN_NOT_USED;	// We have to control the CS line ourself for burst writes > 255 bytes
	spi_config.irq_priority	= APP_IRQ_PRIORITY_LOW;
	spi_config.orc			= 0xFF;
	spi_config.frequency	= NRF_DRV_SPI_FREQ_4M;
//	spi_config.frequency = NRF_DRV_SPI_FREQ_125K;
	spi_config.mode			= NRF_DRV_SPI_MODE_0;
	spi_config.bit_order	= NRF_DRV_SPI_BIT_ORDER_MSB_FIRST;
	err = nrf_drv_spi_init(&spi, &spi_config, spi_event_handler, 0);
	if (err != NRF_SUCCESS) {
		return FALSE;
	}

	return TRUE;
}

static GFXINLINE void post_init_board(GDisplay* g)
{
	(void)g;
}

static GFXINLINE void setpin_reset(GDisplay* g, bool_t state)
{
	(void)g;

	if (state) {
		nrf_gpio_pin_set(PIN_RESET);
	} else {
		nrf_gpio_pin_clear(PIN_RESET);
	}
}

static GFXINLINE bool_t getpin_busy(GDisplay* g)
{
	(void)g;
#if 0	
	if (nrf_gpio_pin_read(PIN_BUSY) == 1) {
		return TRUE;
	} else {
		return FALSE;
	}
#else
	return FALSE;
#endif
}

static GFXINLINE void acquire_bus(GDisplay* g)
{
	(void)g;

	nrf_gpio_pin_clear(PIN_CS);
}

static GFXINLINE void release_bus(GDisplay* g)
{
	(void)g;

	nrf_gpio_pin_set(PIN_CS);
}

static GFXINLINE void write_cmd(GDisplay* g, uint8_t cmd)
{
	ret_code_t rc;
	(void)g;

	nrf_gpio_pin_clear(PIN_DC);
        _spi_xfer_done = false;
	do{
		rc = nrf_drv_spi_transfer(&spi, &cmd, 1, 0, 0);
	}while (rc == NRF_ERROR_BUSY);

	while (!_spi_xfer_done)
          ;
}

static GFXINLINE void write_data(GDisplay* g, uint8_t data)
{
	ret_code_t rc;
	(void)g;
	
	nrf_gpio_pin_set(PIN_DC);
        _spi_xfer_done = false;
	do{
		rc = nrf_drv_spi_transfer(&spi, &data, 1, 0, 0);
	}while (rc == NRF_ERROR_BUSY);

	while (!_spi_xfer_done)
          ;
}

static GFXINLINE void write_data_burst(GDisplay* g, uint8_t* data, uint8_t length)
{
	ret_code_t rc;
	(void)g;
	
	nrf_gpio_pin_set(PIN_DC);
        _spi_xfer_done = false;
	do{
		rc = nrf_drv_spi_transfer(&spi, data, length, 0, 0);
	}while (rc == NRF_ERROR_BUSY);
	
	while (!_spi_xfer_done)
          ;
}

static GFXINLINE void set_backlight(GDisplay* g, uint8_t value)
{
	(void)g;
	return;
}

#endif /* _GDISP_LLD_BOARD_H */
