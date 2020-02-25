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

/*	@brief : Initializing i2c for temperature readings	*/
void tempInit(void);

/*	@brief : Calculating temp value in celsius as obtained from I2C buffer	*/
void temp_read_complete(void);

//Variables
float temperature_c;


#endif
