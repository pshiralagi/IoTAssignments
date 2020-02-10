/*
 * @filename : cmu.c
 *
 *  @date : Jan 29, 2020
 *  @description : File containing clock initialization function
 *
 *    	@author : pshiralagi
 *    	@reference : https://siliconlabs.github.io/Gecko_SDK_Doc/efr32bg13/html/index.html
 */

#include"cmu.h"


/*
 * @brief : cmuInit initializes the oscillator and selects the clock source
 * For EM0 to EM2, LFXO is used
 * For EM3, ULFRCo is used
 * LFA clock branch is selcted
 * LFA and LETIMER0 clocks are enabled
 */

void cmuInit(void)
{
	if (energy_mode == 3)
	{
		CMU_OscillatorEnable(cmuOsc_ULFRCO, true, true);	//Enable Ultra low frequency RC oscillator for EM3
		CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_ULFRCO);	//Selecting A branch and ULFRCO
		CMU_ClockDivSet(cmuClock_LETIMER0, cmuClkDiv_1);		//Setting prescaler value
	}

	else if (energy_mode>=0 && energy_mode<3)
	{
		CMU_OscillatorEnable(cmuOsc_LFXO, true, true);		//Enable low frequency crystal oscillator for EM0, 1, 2
		CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFXO);	//Selecting A branch and LFXO
		CMU_ClockDivSet(cmuClock_LETIMER0, cmuClkDiv_4);		//Setting prescaler value
	}

	CMU_ClockEnable(cmuClock_LFA, true);					//Enabling LFA clock
	CMU_ClockEnable(cmuClock_LETIMER0, true);				//Enabling LETIMER0 post prescale divider
}
