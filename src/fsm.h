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

//All values are converted to hex
#define ADV_MAX (0x0190) //Max advertising, each increment is 0.625 milliseconds (400*0.625 = 250) 400 is hex 190
#define ADV_MIN (0x0190) //Min advertising, each increment is 0.625 milliseconds (400*0.625 = 250)
/*  - Time = Value x 1.25 ms
*  - Range: 0x0006 to 0x0c80 */
#define CON_MAX (0x003C) //Max connection interval  Time = Value x 1.25 ms
#define CON_MIN (0x003C) //Min connection interval  Time = Value x 1.25 ms
#define SLAVE_LAT (0x0003) //Slave latency value is a multiple by which the time of the number of connections is multiplied, must connect on 4th cycle
#define SUP_TIM (600)	//The value in milliseconds must be larger than (1 + latency) * max_interval * 2, where max_interval is given in milliseconds

/*	@brief : Function to disable I2C interrupts and clear the event	*/
void clear_event_interrupt(void);

/*
 * @brief : State machine function containing code for Bluetooth and I2C state machine,
 * includes connection closing interrupt disable (bonus)
 *
 * @param : evt is the gecko cmd packet returned from gecko_wait_event
 */
void gecko_pav_update(struct gecko_cmd_packet* evt);

/*	@brief : Function to convert temperature from float to format which can be sent over radio and then send the data	*/
void send_temp(void);

/*	I2C states	*/
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
