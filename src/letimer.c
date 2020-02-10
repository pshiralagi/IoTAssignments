/*
 * @filename : letimer.c
 *
 *  @date : Jan 29, 2020
 *  @description : File containing letimer initialization function
 *
 *    	@author : pshiralagi
 *    	@reference : https://siliconlabs.github.io/Gecko_SDK_Doc/efr32bg13/html/index.html
 */

#include "letimer.h"

/*
 * @brief : Initialization routine for letimer0
 */

void letimerInit(void)
{
	LETIMER_Init_TypeDef letimer_default =  {false, false, true, false, 0, 0, letimerUFOANone, letimerUFOANone, letimerRepeatFree, 0} ;	//Instance of default values
	LETIMER_Init(LETIMER0, &letimer_default);		//Initialization of letimer0 with default values
	//calc_led_period = ((CMU_ClockFreqGet(cmuClock_LETIMER0))*(led_period - led_on_time))/1000;//calculating ledperiod
	calc_led_on_time = ((CMU_ClockFreqGet(cmuClock_LETIMER0))*(led_on_time))/1000;//calculating ledontime
	LETIMER_CompareSet(LETIMER0, 0, calc_led_on_time);		//Comparator 0, value to be loaded set
	LETIMER_IntEnable(LETIMER0, LETIMER_IF_UF);					//Enable interrupts
	NVIC_EnableIRQ(LETIMER0_IRQn);
	LETIMER_Enable(LETIMER0, true);
	event_word = 0;
	//irq_flg = 0;		//Initializing flag toggled in interrupt

}

void LETIMER0_IRQHandler(void)
{
	uint32_t flag = LETIMER_IntGet(LETIMER0);

	/*Code for LED blinking in assignment 2*/
//	if(irq_flg == 0)
//	{
//		LETIMER_CompareSet(LETIMER0, 0, calc_led_on_time);	//setting period when led should be switched off
//		irq_flg = 1;
//	}
//	else if(irq_flg == 1)
//	{
//		LETIMER_CompareSet(LETIMER0, 0, calc_led_period);		//setting period when led should switch on
//		irq_flg = 0;
//	}

	/*	Code to set event 1	*/
	/*Setting event handler flag for assignment 2*/
	CORE_DECLARE_IRQ_STATE;
	CORE_ENTER_CRITICAL();
	event_word |= 0x01;
	CORE_EXIT_CRITICAL();
	LETIMER_IntClear(LETIMER0, flag);					//clearing the flag
	LETIMER_CompareSet(LETIMER0, 0, calc_led_on_time);		//setting period when led should switch on

}
/*	@brief : Blocking function to wait us_wait us of time	*/
void timerWaitUs(uint32_t us_wait)
{
	uint32_t max_cnt, us_cnt, clk_freq, current_cnt;
	max_cnt = LETIMER_CompareGet(LETIMER0, 0);
	clk_freq = CMU_ClockFreqGet(cmuClock_LETIMER0);
	us_cnt = ((us_wait/1000)*clk_freq)/(1000);
	current_cnt = LETIMER_CounterGet(LETIMER0);
	if (us_cnt < current_cnt)
	{
		while (LETIMER_CounterGet(LETIMER0) != (current_cnt - us_cnt))
		{
			;
		}
	}
	else if (us_cnt >= current_cnt)
	{
		while (LETIMER_CounterGet(LETIMER0) != (max_cnt - (us_cnt - current_cnt)))
		{
			;
		}
	}

}
