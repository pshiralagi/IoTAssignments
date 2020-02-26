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

  /*	Initialize i2c to read temperature	*/
  tempInit();

  /* Infinite loop */
  while (1)
  {
	  struct gecko_cmd_packet* evt;

	  /*	Bluetooth wait handling, returns data which is primarily used to select a state in gecko_pav_update	*/
	  evt = gecko_wait_event();

	  /*	State machine containing bluetooth states and I2C states integrated together	*/
	  gecko_pav_update(evt);


  }
}






