/*
 * @filename : temperature.h
 *
 *  @date : Feb 6, 2020
 *  @description : Header file containing functions to read temperature
 *
 *    	@author : pshiralagi
 *    	@reference : https://siliconlabs.github.io/Gecko_SDK_Doc/efr32bg13/html/index.html
 */
#ifndef temperature_h
#define temperature_h

//Includes
#include "main.h"

//Function declarations
void tempInit(void);	//Initializing i2c for temperature readings
void check_temp_event(void);	//Checking temperature, includes load power management
void temp_write_complete(void);
void temp_read_complete(void);



#endif
