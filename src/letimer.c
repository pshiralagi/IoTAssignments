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
uint16_t overflow_count;
void letimerInit(void)
{
	LETIMER_Init_TypeDef letimer_default =  {false, false, true, false, 0, 0, letimerUFOANone, letimerUFOANone, letimerRepeatFree, 0} ;	//Instance of default values
	LETIMER_Init(LETIMER0, &letimer_default);		//Initialization of letimer0 with default values
	//calc_led_period = ((CMU_ClockFreqGet(cmuClock_LETIMER0))*(led_period - led_on_time))/1000;//calculating ledperiod
	calc_primary_period = ((CMU_ClockFreqGet(cmuClock_LETIMER0))*(primary_period))/1000;//calculating ledontime
	LETIMER_CompareSet(LETIMER0, 0, (calc_primary_period));		//Comparator 0, value to be loaded set
	LETIMER_CompareSet(LETIMER0, 1, 0xFFFF);
	LETIMER_IntEnable(LETIMER0, LETIMER_IEN_UF);					//Enable interrupts
	LETIMER_IntDisable(LETIMER0, LETIMER_IEN_COMP0);
	LETIMER_IntDisable(LETIMER0,LETIMER_IEN_COMP1);
	NVIC_EnableIRQ(LETIMER0_IRQn);
	LETIMER_Enable(LETIMER0, true);

}

/*	@brief : Interrupt handler for LETIMER0	*/
void LETIMER0_IRQHandler(void)
{
	/*	Code to set event 1	*/
	/*Setting event handler flag for assignment 2*/
	uint32_t flag = LETIMER_IntGetEnabled(LETIMER0);
	if(flag & LETIMER_IF_UF)
	{
		overflow_count++;
		gecko_external_signal(0x01);
	}
	if(flag & LETIMER_IF_COMP1)
	{
		LETIMER_CompareSet(LETIMER0,1,0xFFFF);
		LETIMER_IntDisable(LETIMER0,LETIMER_IEN_COMP1);
		CORE_DECLARE_IRQ_STATE;
		CORE_ENTER_CRITICAL();
		if(current_state == load_power_management_on)
		{
			gecko_external_signal(0x02);
		}
		if(current_state == I2C_read_break)
		{
			gecko_external_signal(0x04);
		}
		CORE_EXIT_CRITICAL();
	}
	LETIMER_IntClear(LETIMER0, flag);					//clearing the flag

}
/*	@brief : Blocking function to wait us_wait us of time
 *  @param : us_wait in us
 */
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

/*	@brief : Function to generate an interrupt after the given ms_wait time in milliseconds
 *	@param : ms_wait is the time to interrupt at in milliseconds
 *	 */
void ms_sleep(uint32_t ms_wait)
{
	uint32_t max_cnt, clk_freq, current_cnt, reload_val;
	max_cnt = LETIMER_CompareGet(LETIMER0, 0);
	clk_freq = CMU_ClockFreqGet(cmuClock_LETIMER0);
	current_cnt = LETIMER_CounterGet(LETIMER0);
	ms_wait = (ms_wait*clk_freq)/(1000);
	if (ms_wait < current_cnt)
	{
		reload_val = (current_cnt - ms_wait);

	}
	else if (ms_wait >= current_cnt)
	{
		reload_val = (max_cnt - (ms_wait - current_cnt));
	}

	LETIMER_CompareSet(LETIMER0,1,reload_val);
	LETIMER_IntEnable(LETIMER0, LETIMER_IEN_COMP1);

}
