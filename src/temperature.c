/*
 * @filename : temperature.c
 *
 *  @date : Feb 6, 2020
 *  @description : File containing functions to obtain temperature reading from on board sensor
 *
 *    	@author : pshiralagi
 */

//Includes
#include "temperature.h"

void tempInit(void)
{
	init_i2c();
	TempTransferInit_i2c();

}

void check_temp_event(void)
{
	float temperature_c;
	event_word &= 0x01;
	temperature_c = GetTemp_i2c();
	LOG_INFO("Temperature is %f", temperature_c);
}
