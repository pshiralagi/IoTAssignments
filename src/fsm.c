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

/*	@brief : Function to schedule and perform events and then go to sleep based on selected mode	*/
void event_scheduler(void)
{
	uint8_t current_state, next_state;
	current_state = load_power_management_on;
	next_state = current_state;
	  /* Check if any event flag is set */
	  while (event_word != 0)
	  {
		  switch(current_state)
		  {
		  case(load_power_management_on):
				  lpm_on();
		  	  	  next_state = current_state+1;
		  	  	  break;
		  case(power_up_sequence_wait):
				  ms_sleep(80);
		  	  	  sleep_em1();
		  	  	  next_state = current_state+1;
		  	  	  break;
		  case(I2C_write_start):
				  temp_i2c_write();
		  	  	  next_state = current_state+1;
		  	  	  break;
		  case(I2C_write_complete):
				  temp_write_complete();
		  	  	  next_state = current_state+1;
		  	  	  break;
		  case(I2C_read_start):
				  temp_i2c_read();
		  	  	  next_state = current_state+1;
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
			  LOG_ERROR("State changing from %d to %d", current_state, next_state);
			  current_state = next_state;
		  }
	  }

}

void clear_event_interrupt(void)
{
  	  CORE_DECLARE_IRQ_STATE;
  	  CORE_ENTER_CRITICAL();
  	  NVIC_DisableIRQ(I2C0_IRQn);
  	  event_word &= ~0x01;
  	  CORE_EXIT_CRITICAL();

}
