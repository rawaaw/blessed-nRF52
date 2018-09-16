#include "../../../gfx.h"

#if GFX_USE_OS_RAW32

extern uint32_t _ticks_1ms; /* defined in main module (see examples/ugfx-st7735/main.c) */

	void _init(void)
	{
	}

	systemticks_t gfxSystemTicks(void)
	{
		return _ticks_1ms;
	}

	systemticks_t gfxMillisecondsToTicks(delaytime_t ms)
	{
		return ms;
	}
#endif
	