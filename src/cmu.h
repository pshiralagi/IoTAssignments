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

/*
 * @brief : cmuInit initializes the oscillator and selects the clock source
 * For EM0 to EM2, LFXO is used
 * For EM3, ULFRCo is used
 * LFA clock branch is selcted
 * LFA and LETIMER0 clocks are enabled
 */
void cmuInit(void);

#endif
