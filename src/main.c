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

  /*	Configurations for different energy modes	*/
  if(energy_mode == 1 || energy_mode == 2)
	  energyConfig();

  /*	Initialize i2c to read temperature	*/
  tempInit();

  /*	Initialized LCD to display data	*/
//  displayInit();


  /* Infinite loop */
  while (1)
  {
	  struct gecko_cmd_packet* evt;

	  /*	Checks if events are sent and performs them if needed and then sleeps	*/
	  evt = gecko_wait_event();

	  gecko_pav_update(evt);


  }
}






