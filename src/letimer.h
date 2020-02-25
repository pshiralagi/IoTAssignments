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
#include "main.h"
#include <em_core.h>


/*	Defines		*/
#define primary_period (3000)		//Primary interrupt interval in milliseconds
#define on_time (3000)		//Secondary/alternate interrupt if required in milliseconds

/*	Functions	*/

/*
 * @brief : Initialization routine for letimer0
 */
void letimerInit(void);

/*	@brief : Blocking function to wait us_wait us of time
 *  @param : us_wait in us
 */
void timerWaitUs(uint32_t us_wait);	//Blocking wait function, input in us

/*	@brief : Function to generate an interrupt after the given ms_wait time in milliseconds
 *	@param : ms_wait is the time to interrupt at in milliseconds
 *	 */
void ms_sleep(uint32_t ms_wait);	//Function to generate timer interrupt at parameter value of time in milliseconds

/*	Variables	*/
uint16_t calc_primary_period, calc_secondary_period;
extern uint16_t overflow_count;
volatile uint8_t irq_flg;
#endif
