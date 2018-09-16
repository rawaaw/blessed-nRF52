#if !defined __BOARD_ST7735_H__
#define __BOARD_ST7735_H__
#define ST7735_TYPE_R TRUE
#include "boards/addons/gdisp/board_yj16002_nordic_nrf52.h"
#define write_data_byte(g, data) write_data(g, data)
#endif
