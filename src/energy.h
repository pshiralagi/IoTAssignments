/*
 * @filename : energy.h
 *
 *  @date : Jan 29, 2020
 *  @description : Header file containing function to enter different energy modes
 *
 *    	@author : pshiralagi
 */

#ifndef energy_h
#define energy_h

#include "main.h"
#include <sleep.h>

#define energy_mode sleepEM3	//Sleep mode selected, this mode will be entered (not this mode - 1)

void energyConfig(void);
void goToSleep(void);

#endif
