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

//void event_scheduler(uint32_t event_word);	//FSM, event handler
void clear_event_interrupt(void);	//Clear I2C in NVIC and clear interrupt word
void gecko_pav_update(struct gecko_cmd_packet* evt);
void send_temp(void);

enum states {
	load_power_management_on = 1,
	I2C_write_start,
	I2C_read_break,
	I2C_read_wait,
	I2C_read_complete,
	num_states
};	//enum with various states

uint8_t current_state, next_state;

#endif
