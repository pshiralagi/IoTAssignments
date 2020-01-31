/*
 * @filename : energy.c
 *
 *  @date : Jan 29, 2020
 *  @description : File containing letimer initialization function
 *
 *    	@author : pshiralagi
 */

#include "energy.h"

/*	@brief : Function to initialize various energy modes	*/
void energyConfig(void)
{
	SLEEP_Init_t init_values = {0};		//Null for this assignment

	SLEEP_InitEx(&init_values);
	if ((energy_mode < 3) && (energy_mode > 0))	//If energy mode to be entered is EM1 or EM2
	{
		SLEEP_SleepBlockBegin((energy_mode+1));	//Blocked from entering deeper sleep modes

	}


}

/*	@brief : Function to go to sleep based on energy mode	*/
void goToSleep(void)
{
	if ((energy_mode < 3) && (energy_mode > 0))	//If energy mode to be entered is EM1 or EM2
	{
		SLEEP_Sleep();
	}
	else if (energy_mode == 3)					//If energy mode to be entered is EM3
	{
		EMU_EnterEM3(true);
	}
	else if (energy_mode == 4)					//If energy mode to be entered is EM4 (Need to verify this)
	{
		SLEEP_ForceSleepInEM4();
	}
}
