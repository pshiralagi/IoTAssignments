/*
 * @filename : letimer.h
 *
 *  @date : Jan 29, 2020
 *  @description : File containing clock initialization function
 *
 *    	@author : pshiralagi
 */
#ifndef letimer_h
#define letimer_h
#include <em_letimer.h>
#include "cmu.h"


/*	Defines		*/
#define led_period (3000)		//Interval at which LED has to be switched on
#define led_on_time (3000)		//Interval for which LED has to stay on

/*	Functions	*/
void letimerInit(void);
void timerWaitUs(uint32_t us_wait);
uint16_t calc_led_period, calc_led_on_time;

volatile uint8_t irq_flg;
volatile uint8_t event_word;
#endif
