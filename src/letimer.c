/*
 * @filename : letimer.c
 *
 *  @date : Jan 29, 2020
 *  @description : File containing letimer initialization function
 *
 *    	@author : pshiralagi
 */

#include"letimer.h"

/*
 * @brief : Initialization routine for letimer0
 */
bool on, off;

void letimerInit(void)
{
	LETIMER_Init_TypeDef letimer_default =  {false, true, true, false, 0, 0, letimerUFOANone, letimerUFOANone, letimerRepeatFree, 0} ;	//Instance of default values
	LETIMER_Init(LETIMER0, &letimer_default);		//Initialization of letimer0 with default values
	calc_led_period = ((CMU_ClockFreqGet(cmuClock_LETIMER0))*(led_period - led_on_time))/1000;
	calc_led_on_time = ((CMU_ClockFreqGet(cmuClock_LETIMER0))*(led_on_time))/1000;
	LETIMER_CompareSet(LETIMER0, 0, calc_led_on_time);		//Comparator 0, value to be loaded set
	LETIMER_IntEnable(LETIMER0, LETIMER_IF_UF);					//Enable interrupts
	NVIC_EnableIRQ(LETIMER0_IRQn);
	LETIMER_Enable(LETIMER0, true);
	irq_flg = 0;
	on = true;
	off = false;

}

void LETIMER0_IRQHandler(void)
{
	uint32_t flag = LETIMER_IntGet(LETIMER0);
	if(irq_flg == 0)
	{
		LETIMER_CompareSet(LETIMER0, 0, calc_led_on_time);	//setting period when led should be switched off
		irq_flg = 1;
	}
	else if(irq_flg == 1)
	{
		LETIMER_CompareSet(LETIMER0, 0, calc_led_period);		//setting period when led should switch on
		irq_flg = 0;
	}

	LETIMER_IntClear(LETIMER0, flag);					//clearing the flag
}

