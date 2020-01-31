/*
 * @filename : cmu.c
 *
 *  @date : Jan 29, 2020
 *  @description : File containing clock initialization function
 *
 *    	@author : pshiralagi
 */
#ifndef letimer_h
#define letimer_h
#include <em_letimer.h>
#include "main.h"


/*	Defines		*/
#define led_period (7000)		//Interval at which LED has to be switched on
#define led_on_time (1000)		//Interval for which LED has to stay on

/*	Functions	*/
void letimerInit(void);

uint16_t calc_led_period, calc_led_on_time;
volatile uint8_t irq_flg;
#endif
