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

#define ADV_MAX (0x0400) //Max advertising, each increment is 0.625 milliseconds (400*0.625 = 250)
#define ADV_MIN (0x0400) //Min advertising, each increment is 0.625 milliseconds (400*0.625 = 250)
/*  - Time = Value x 1.25 ms
*  - Range: 0x0006 to 0x0c80 */
#define CON_MAX (0x0060) //Max connection interval  Time = Value x 1.25 ms
#define CON_MIN (0x0060) //Min connection interval  Time = Value x 1.25 ms
#define SLAVE_LAT (0x0004) //Slave latency value is a multiple by which the time of the number of connections is multiplied
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
