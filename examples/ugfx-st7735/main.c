/*
*
*/
#include <stdint.h>
#include <stdbool.h>

#include <blessed/evtloop.h>

#include "timer.h"

#include "boards.h"

#include "gfx.h"

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

void drawScreen(void) {
	char *msg = "uGFX2.8";
	font_t		font1, font2, font3;

//	font1 = gdispOpenFont("DejaVuSans24*");
	font1 = gdispOpenFont("fixed_10x20");
	font2 = gdispOpenFont("fixed_5x8");
	font3 = gdispOpenFont("fixed_7x14");

	gdispClear(White);
	gdispDrawString(gdispGetWidth()-gdispGetStringWidth(msg, font1)-3, 30, msg, font1, Black);
	
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
	bsp_board_init(BSP_INIT_LEDS);
        bsp_board_led_on(0);

	timer_init();
	timer1ms = timer_create(TIMER_REPEATED);
	timer_start(timer1ms, TIMER_MILLIS(1), inc_tick);

	gfxInit();
	drawScreen();

	evt_loop_run();

	return 0;
}
