/*
 * @filename : energy.h
 *
 *  @date : Jan 29, 2020
 *  @description : Header file containing function to enter different energy modes
 *
 *    	@author : pshiralagi
 *    	@reference : https://siliconlabs.github.io/Gecko_SDK_Doc/efr32bg13/html/index.html
 */

#ifndef energy_h
#define energy_h


#include <sleep.h>
#include "energy.h"
#include "log.h"
#include <em_emu.h>

#define energy_mode sleepEM1	//Sleep mode selected, this mode will be entered (not this mode - 1) after completing events
#define energy_mode_i2c sleepEM1 //Sleep mode to enter during i2c transactions and waits

void energyConfig(void);	//Function to initialize various energy modes
void goToSleep(void);		//Function to go to sleep based on energy mode
void sleep_em1(void);		//Function to sleep in EM1

#endif
