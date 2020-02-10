/*
 * @filename : temperature.c
 *
 *  @date : Feb 6, 2020
 *  @description : File containing functions to obtain temperature reading from on board sensor
 *
 *    	@author : pshiralagi
 *    	@reference : https://siliconlabs.github.io/Gecko_SDK_Doc/efr32bg13/html/index.html
 */

//Includes
#include "temperature.h"

/*	Initializing i2c for temperature readings	*/
void tempInit(void)
{
	init_i2c();
	TempTransferInit_i2c();

}

/*	@brief: Checking temperature, includes load power management	*/
void check_temp_event(void)
{
	gpioReInit();
	timerWaitUs(80000);//Waiting for maximum boot time
	float temperature_c;
	CORE_DECLARE_IRQ_STATE;
	CORE_ENTER_CRITICAL();//Entering critical state
	event_word &= ~0x01;
	CORE_EXIT_CRITICAL();
	temperature_c = GetTemp_i2c();
	temperature_c = (((175.72*temperature_c)/65536)-(46.85));//Converting value read to degrees celsius
	gpioDeInit();
	LOG_INFO("Temperature is %f", temperature_c);
}
