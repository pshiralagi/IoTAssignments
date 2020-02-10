/*
 * @filename : main.c
 *
 *  @date : Jan 29, 2020
 *  @description : file containing calls to functions. This program blinks an LED periodically and goes to sleep
 *  				based on user inputs
 *
 *    	@author : pshiralagi
 *
 *    	@reference : https://siliconlabs.github.io/Gecko_SDK_Doc/efr32bg13/html/index.html
 */

#include "main.h"


int appMain(gecko_configuration_t *config)
{

  /*	Initialize stack	*/
  gecko_init(config);

  /*	Initialize required gpios	*/
  gpioInit();

  /*	Initialize clocks	*/
  cmuInit();

  /*	Initialize timer	*/
  letimerInit();

  /*	Configurations for different energy modes	*/
  energyConfig();

  /*	Initialize i2c to read temperature	*/
  tempInit();

  /* Infinite loop */
  while (1)
  {
	  /* Check if any event flag is set */
	  while (event_word != 0)
	  {
		  /* Check if event 1 is set */
		  if(event_word & (1<<0))
		  {
			  check_temp_event();//Event 1, flag clears, checks temperature over i2c
		  }

	  }
	  /* If energy mode required is not 0, go to sleep */
	  CORE_DECLARE_IRQ_STATE;
	  CORE_ENTER_CRITICAL();
	  if (energy_mode != 0)
	  {
		  goToSleep();
	  }
	  CORE_EXIT_CRITICAL();

  }
}



/*	@brief : Function to toggle LED based on flag set in interrupt (Assignment 2)	*/
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




