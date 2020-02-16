/*
 * @filename : letimer.h
 *
 *  @date : Jan 29, 2020
 *  @description : File containing clock initialization function
 *
 *    	@author : pshiralagi
 *    	@reference : https://siliconlabs.github.io/Gecko_SDK_Doc/efr32bg13/html/index.html
 */
#ifndef letimer_h
#define letimer_h
#include <em_letimer.h>
#include "cmu.h"
#include <em_core.h>


/*	Defines		*/
#define primary_period (3000)		//Primary interrupt interval
#define on_time (3000)		//Secondary/alternate interrupt if required

/*	Functions	*/
void letimerInit(void);	//Initialize letimer0
void timerWaitUs(uint32_t us_wait);	//Blocking wait function, input in us
void ms_sleep(uint32_t ms_wait);	//Function to generate timer interrupt at parameter value of time in milliseconds

uint16_t calc_primary_period, calc_secondary_period;
extern uint16_t overflow_count;
volatile uint8_t irq_flg;
volatile uint8_t event_word;
#endif
