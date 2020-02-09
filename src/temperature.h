/*
 * @filename : temperature.h
 *
 *  @date : Feb 6, 2020
 *  @description : Header file containing functions to read temperature
 *
 *    	@author : pshiralagi
 */
#ifndef temperature_h
#define temperature_h

//Includes
#include "letimer.h"
#include "i2c.h"

//Function declarations
void tempInit(void);
void check_temp_event(void);



#endif
