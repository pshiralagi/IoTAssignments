/*
 * @filename : main.c
 *
 *  @date : Jan 29, 2020
 *  @description : file containing calls to functions. This program blinks an LED periodically and goes to sleep
 *  				based on user inputs
 *
 *    	@author : pshiralagi
 *
 *    	@reference :
 */


#include "main.h"

int appMain(gecko_configuration_t *config)
{

  // Initialize stack
  gecko_init(config);
  gpioInit();
  cmuInit();
  letimerInit();
  energyConfig();

  gpioLed0SetOn();

  /* Infinite loop */
  while (1)
  {
	  toggleLed();
	  if (energy_mode != 0)
	  {
		  goToSleep();
	  }

  }
}

/*	@brief : Function to toggle LED based on flag set in interrupt	*/
void toggleLed(void)
{
	  if (irq_flg == 0)
	  {
		  gpioLed0SetOn();
	  }
	  if (irq_flg == 1)
	  {
		  gpioLed0SetOff();
	  }
}




