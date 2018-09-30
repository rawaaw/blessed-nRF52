/*
*
*/
#include <stdint.h>
#include <stdbool.h>

#include <blessed/evtloop.h>

#include "timer.h"
#include "nrf_temp.h"

#include "boards.h"

#include "gfx.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

#define COLOR_SIZE	20
#define PEN_SIZE	25
#define OFFSET		3

#define COLOR_BOX(a)		(ev.x >= a && ev.x <= a + COLOR_SIZE)
#define PEN_BOX(a)			(ev.y >= a && ev.y <= a + COLOR_SIZE)
#define GET_COLOR(a)		(COLOR_BOX(a * COLOR_SIZE + OFFSET))
#define GET_PEN(a)			(PEN_BOX(a * 2 * PEN_SIZE + OFFSET))
#define DRAW_COLOR(a)		(a * COLOR_SIZE + OFFSET)
#define DRAW_PEN(a)			(a * PEN_SIZE + OFFSET)
#define DRAW_AREA(x, y)		(x >= PEN_SIZE + OFFSET + 3 && x <= gdispGetWidth() && \
							 y >= COLOR_SIZE + OFFSET + 3 && y <= gdispGetHeight())

uint32_t temp(void){

int32_t volatile temp;

  NRF_TEMP->TASKS_START = 1; /** Start the temperature measurement. */

  /* Busy wait while temperature measurement is not finished, you can skip waiting if you enable interrupt for DATARDY event and read the result in the interrupt. */
  /*lint -e{845} // A zero has been given as right argument to operator '|'" */
  while (NRF_TEMP->EVENTS_DATARDY == 0){}
  NRF_TEMP->EVENTS_DATARDY = 0;

  /**@note Workaround for PAN_028 rev2.0A anomaly 29 - TEMP: Stop task clears the TEMP register. */
  temp = (nrf_temp_read() / 4);

  /**@note Workaround for PAN_028 rev2.0A anomaly 30 - TEMP: Temp module analog front end does not power down when DATARDY event occurs. */
  NRF_TEMP->TASKS_STOP = 1; /** Stop the temperature measurement. */
  return temp;
}


void drawScreen(void) {
	char *msg = "uGFX2.8";
	char str[32];
        const point pntarray[6] = {{20,10}, {40,15}, {60,40}, {80,-10}, {100, -20}, {110, 5}};

	font_t		font1, font2, font3;

	font1 = gdispOpenFont("DejaVuSans36*");
//	font1 = gdispOpenFont("fixed_10x20");
	font2 = gdispOpenFont("fixed_5x8");
	font3 = gdispOpenFont("fixed_7x14");

	gdispClear(White);
#if 0          
	gdispDrawString(gdispGetWidth()-gdispGetStringWidth(msg, font1)-3, 30, msg, font1, Black);
	gdispDrawString(gdispGetWidth()-gdispGetStringWidth(msg, font1)-3, 60, msg, font2, Black);
	gdispDrawString(gdispGetWidth()-gdispGetStringWidth(msg, font1)-3, 90, msg, font3, Black);
	
	/* colors */
	gdispFillArea(0 * COLOR_SIZE + 3, 3, COLOR_SIZE, COLOR_SIZE, Black);	/* Black */
	gdispFillArea(1 * COLOR_SIZE + 3, 3, COLOR_SIZE, COLOR_SIZE, Red);		/* Red */
	gdispFillArea(2 * COLOR_SIZE + 3, 3, COLOR_SIZE, COLOR_SIZE, Yellow);	/* Yellow */
	gdispFillArea(3 * COLOR_SIZE + 3, 3, COLOR_SIZE, COLOR_SIZE, Green);	/* Green */
	gdispFillArea(4 * COLOR_SIZE + 3, 3, COLOR_SIZE, COLOR_SIZE, Blue);		/* Blue */
	gdispDrawBox (5 * COLOR_SIZE + 3, 3, COLOR_SIZE, COLOR_SIZE, Black);	/* White */

	/* pens */	
	gdispFillStringBox(OFFSET * 2, DRAW_PEN(1), PEN_SIZE, PEN_SIZE, "1", font1, Red, Blue, justifyCenter);
	gdispFillStringBox(OFFSET * 2, DRAW_PEN(2), PEN_SIZE, PEN_SIZE, "2", font3, White, Black, justifyCenter);
	gdispFillStringBox(OFFSET * 2, DRAW_PEN(3), PEN_SIZE, PEN_SIZE, "3", font1, Blue, Yellow, justifyCenter);
	gdispFillStringBox(OFFSET * 2, DRAW_PEN(4), PEN_SIZE, PEN_SIZE, "4", font3, White, Black, justifyCenter);
	gdispFillStringBox(OFFSET * 2, DRAW_PEN(5), PEN_SIZE, PEN_SIZE, "5", font2, White, Black, justifyCenter);
#endif
#if 0
        gdispDrawCircle(70, 40, 20, Red);
        gdispFillCircle(70, 40, 18, Blue);
        gdispFillArc(40, 60, 18, 0, 75, Yellow);
        gdispFillEllipse(40, 80, 18, 15, Green);
        gdispDrawPoly(1, 115, pntarray, 6, Black);
#endif
        gdispSetOrientation(GDISP_ROTATE_270);

        gdispDrawString(10, 40, "test str", font3, Black);
        for (int i = 0; i < 100000; i ++){
          sprintf(str, "%.4d", temp());
          gdispDrawString(10, 70, str, font1, Black);
          gfxSleepMilliseconds(1731);
          gdispDrawString(10, 70, str, font1, White);
          bsp_board_led_invert(0);
        }

	gdispCloseFont(font1);
	gdispCloseFont(font2);
}


uint32_t _ticks_1ms = 0;
static int16_t timer1ms;
static void inc_tick(void)
{
        _ticks_1ms ++;
#if 0
        if (!(_ticks_1ms % 1000))
          bsp_board_led_invert(0);
#endif
}

int main(void)
{
#if 1
  APP_ERROR_CHECK(NRF_LOG_INIT(NULL));
  NRF_LOG_DEFAULT_BACKENDS_INIT();

  NRF_LOG_INFO("uGFX usage example application started.")
  NRF_LOG_FLUSH();
#endif

  bsp_board_init(BSP_INIT_LEDS);
  bsp_board_led_on(0);

  nrf_temp_init();

  timer_init();
  timer1ms = timer_create(TIMER_REPEATED);
  timer_start(timer1ms, TIMER_MILLIS(1), inc_tick);

  gfxInit();
  drawScreen();

  evt_loop_run();

  return 0;
}
