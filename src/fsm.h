/*
 * @filename : fsm.h
 *
 *  @date : Feb 13, 2020
 *  @description : Header file for Finite State Machine functions
 *
 *    	@author : pshiralagi
 *    	@reference : https://siliconlabs.github.io/Gecko_SDK_Doc/efr32bg13/html/index.html
 */

#ifndef fsm_h
#define fsm_h

#include "main.h"

void event_scheduler(void);
void clear_event_interrupt(void);

enum states {
	load_power_management_on,
	power_up_sequence_wait,
	I2C_write_start,
	I2C_write_complete,
	I2C_read_start,
	I2C_read_complete,
	load_power_management_off,
	num_states
};

#endif
