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


#include <sleep.h>
#include "energy.h"
#include "log.h"
#include <em_emu.h>

#define energy_mode sleepEM2	//Sleep mode selected, this mode will be entered (not this mode - 1)

void energyConfig(void);
void goToSleep(void);

#endif
