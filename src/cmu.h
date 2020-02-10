/*
 * @filename : cmu.h
 *
 *  @date : Jan 29, 2020
 *  @description : Header file for clock initialization function
 *
 *    	@author : pshiralagi
 *    	@reference : https://siliconlabs.github.io/Gecko_SDK_Doc/efr32bg13/html/index.html
 */
#ifndef cmu_h
#define cmu_h
#include<em_cmu.h>
#include "energy.h"

void cmuInit(void);	//initializes the oscillator and selects the clock source
#endif
