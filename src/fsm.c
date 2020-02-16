/*
 * @filename : fsm.c
 *
 *  @date : Feb 13, 2020
 *  @description : Contains Finite State Machine functions
 *
 *    	@author : pshiralagi
 *    	@reference : https://siliconlabs.github.io/Gecko_SDK_Doc/efr32bg13/html/index.html
 */

#include "fsm.h"

uint8_t current_state, next_state;

/*	@brief : Function to schedule and perform events and then go to sleep based on selected mode using a FSM	*/
void event_scheduler(void)
{
	current_state = load_power_management_on;
	next_state = current_state;
	  /* Check if any event flag is set */
	  while (event_word != 0)
	  {
		  switch(current_state)
		  {
		  case(load_power_management_on):
				  lpm_on();
		  	  	  energyConfig();
		  	  	  next_state = current_state+1;
		  	  	  break;
		  case(power_up_sequence_wait):
				  ms_sleep(80);
		  	  	  sleep_em1();
		  	  	  next_state = current_state+1;
		  	  	  break;
		  case(I2C_write_start):
				  temp_i2c_write();
		  	  	  LOG_INFO("I2C WRITE");
		  	  	  next_state = current_state+1;
		  	  	  break;
		  case(I2C_write_complete):
#ifdef INCLUDE_LOGGING
				  sleep_em1();
#endif
		  	  	  next_state = current_state+1;
		  	  	  break;
		  case(I2C_read_start):
				  ms_sleep(1);
				  sleep_em1();
				  temp_i2c_read();
		  	  	  LOG_INFO("I2C READ");
		  	  	  next_state = current_state+1;
		  	  	  break;
		  case(I2C_read_wait):
				  sleep_em1();
#ifdef INCLUDE_LOGGING
		  	  	  next_state = current_state+1;
#endif
		  	  	  break;
		  case(I2C_read_complete):
				  temp_read_complete();
		  	  	  next_state = current_state+1;
		  	  	  break;
		  case(load_power_management_off):
				  lpm_off();
		  	  	  clear_event_interrupt();
		  	  	  break;
		  default:
			  LOG_ERROR("State does not exist");
		  }
		  if (next_state != current_state)
		  {
			  LOG_INFO("State changing from %d to %d", current_state, next_state);
			  current_state = next_state;
		  }
	  }

}

/*	@brief : Function to disable I2C interrupts and clear the event	*/
void clear_event_interrupt(void)
{
  	  CORE_DECLARE_IRQ_STATE;
  	  CORE_ENTER_CRITICAL();
  	  NVIC_DisableIRQ(I2C0_IRQn);
  	  SLEEP_SleepBlockEnd(sleepEM3);
  	  event_word &= ~0x1;
  	  CORE_EXIT_CRITICAL();

}
