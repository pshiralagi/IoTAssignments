/*
 * @filename : fsm.c
 *
 *  @date : Feb 13, 2020
 *  @description : Contains Finite State Machine functions for bluetooth and I2C
 *
 *    	@author : pshiralagi
 *    	@reference : https://siliconlabs.github.io/Gecko_SDK_Doc/efr32bg13/html/index.html
 *    					Some code taken from soc-thermometer example code
 */

#include "fsm.h"
/* Flag for indicating DFU Reset must be performed */
uint8_t boot_to_dfu = 0;

/*
 * @brief : State machine function containing code for Bluetooth and I2C state machine,
 * includes connection closing interrupt disable (bonus)
 *
 * @param : evt is the gecko cmd packet returned from gecko_wait_event
 */
void gecko_pav_update(struct gecko_cmd_packet* evt)
{
	int8_t rssi_val;;
	/* Handle events */
		switch (BGLIB_MSG_ID(evt->header)) {
		  /* This boot event is generated when the system boots up after reset.
		   * Do not call any stack commands before receiving the boot event.
		   * Here the system is set to start advertising immediately after boot procedure. */
		  case gecko_evt_system_boot_id:
			/* Set advertising parameters. 250ms advertisement interval.
			 */
			  BTSTACK_CHECK_RESPONSE(gecko_cmd_le_gap_set_advertise_timing(0, ADV_MAX, ADV_MIN, 0, 0));

			/* Start general advertising and enable connections. */
			  BTSTACK_CHECK_RESPONSE(gecko_cmd_le_gap_start_advertising(0, le_gap_general_discoverable, le_gap_connectable_scannable));
			break;


		case gecko_evt_le_connection_opened_id:
			BTSTACK_CHECK_RESPONSE(gecko_cmd_le_connection_set_parameters(evt->data.evt_le_connection_opened.connection, CON_MIN, CON_MAX, SLAVE_LAT, SUP_TIM));
			  /*	Initialize timer	*/
			  letimerInit();
			  break;

		  /* This event is generated when we get rssi value and then we set tx_power accordingly	*/
		case gecko_evt_le_connection_rssi_id:
			/* Critical section used to ensure connection is not reset due to timeout	*/
			rssi_val = evt->data.evt_le_connection_rssi.rssi;
			if((rssi_val) > -35)
			{
				CORE_DECLARE_IRQ_STATE;
				CORE_ENTER_CRITICAL();
				gecko_cmd_system_halt(1);
				gecko_cmd_system_set_tx_power(-250);
				gecko_cmd_system_halt(0);
				CORE_EXIT_CRITICAL();
			}
			if(((rssi_val)<=-35)&&(rssi_val>-45))
			{
				CORE_DECLARE_IRQ_STATE;
				CORE_ENTER_CRITICAL();
				gecko_cmd_system_halt(1);
				gecko_cmd_system_set_tx_power(-200);
				gecko_cmd_system_halt(0);
				CORE_EXIT_CRITICAL();
			}
			if(((rssi_val)<=-45)&&(rssi_val>-55))
			{
				CORE_DECLARE_IRQ_STATE;
				CORE_ENTER_CRITICAL();
				gecko_cmd_system_halt(1);
				gecko_cmd_system_set_tx_power(-150);
				gecko_cmd_system_halt(0);
				CORE_EXIT_CRITICAL();
			}
			if((rssi_val<=-55)&&(rssi_val>-65))
			{
				CORE_DECLARE_IRQ_STATE;
				CORE_ENTER_CRITICAL();
				gecko_cmd_system_halt(1);
				gecko_cmd_system_set_tx_power(-50);
				gecko_cmd_system_halt(0);
				CORE_EXIT_CRITICAL();
			}
			if((rssi_val<=-65)&&(rssi_val>-75))
			{
				CORE_DECLARE_IRQ_STATE;
				CORE_ENTER_CRITICAL();
				gecko_cmd_system_halt(1);
				gecko_cmd_system_set_tx_power(0);
				gecko_cmd_system_halt(0);
				CORE_EXIT_CRITICAL();
			}
			if((rssi_val<=-75)&&(rssi_val>-85))
			{
				CORE_DECLARE_IRQ_STATE;
				CORE_ENTER_CRITICAL();
				gecko_cmd_system_halt(1);
				gecko_cmd_system_set_tx_power(50);
				gecko_cmd_system_halt(0);
				CORE_EXIT_CRITICAL();
			}
			if(rssi_val <= -85)
			{
				CORE_DECLARE_IRQ_STATE;
				CORE_ENTER_CRITICAL();
				gecko_cmd_system_halt(1);
				gecko_cmd_system_set_tx_power(80);
				gecko_cmd_system_halt(0);
				CORE_EXIT_CRITICAL();
			}
			break;

			/*	This case contains all external signal events, which covers the I2C state machine	*/
		  case gecko_evt_system_external_signal_id:
			  current_state = evt->data.evt_system_external_signal.extsignals;
			  switch(evt->data.evt_system_external_signal.extsignals)
			  		  {
			  		  case(load_power_management_on):
							  BTSTACK_CHECK_RESPONSE(gecko_cmd_le_connection_get_rssi(evt->data.cmd_le_connection_get_rssi.connection));
			  				  lpm_on();
			  		  	  	  energyConfig();
			  		  	  	  ms_sleep(80);
			  		  	  	  break;
			  		  case(I2C_write_start):
			  				  temp_i2c_write();
			  		  	  	  LOG_INFO("I2C WRITE");
			  		  	  	  break;
			  		  case(I2C_read_break):
			  				  ms_sleep(10);
			  		  	  	  break;
			  		  case(I2C_read_wait):
			  				  temp_i2c_read();
			  		  	  	  break;
			  		  case(I2C_read_complete):
			  				  temp_read_complete();
			  		  	  	  lpm_off();
							  clear_event_interrupt();
							  send_temp();
			  		  	  	  break;
			  		  default:
			  			  LOG_ERROR("State does not exist");
			  		  }
			break;

			/*	This case is entered if bluetooth connection is closed	*/
		  case gecko_evt_le_connection_closed_id:
			  /* Restart advertising after client has disconnected */
			BTSTACK_CHECK_RESPONSE(gecko_cmd_le_gap_start_advertising(0, le_gap_general_discoverable, le_gap_connectable_scannable));
			LETIMER_IntDisable(LETIMER0, LETIMER_IEN_UF);
			CORE_DECLARE_IRQ_STATE;
			CORE_ENTER_CRITICAL();
			gecko_cmd_system_halt(1);
			gecko_cmd_system_set_tx_power(80);
			gecko_cmd_system_halt(0);
			CORE_EXIT_CRITICAL();
			break;

		  default:
			break;
		}
}


/*	@brief : Function to disable I2C interrupts and clear the event	*/
void clear_event_interrupt(void)
{
  	  CORE_DECLARE_IRQ_STATE;
  	  CORE_ENTER_CRITICAL();
  	  NVIC_DisableIRQ(I2C0_IRQn);
  	  SLEEP_SleepBlockEnd(energy_mode_i2c+1);
  	  CORE_EXIT_CRITICAL();

}

/*	@brief : Function to convert temperature from float to format which can be sent over radio and then send the data	*/
void send_temp(void)
{
	CORE_DECLARE_IRQ_STATE;
	CORE_ENTER_CRITICAL();
	int32_t tempf = temperature_c * 1000;
	CORE_EXIT_CRITICAL();
	uint8_t tempBuf[5];
	uint8_t flags = 0x00;   /* HTM flags set as 0 for Celsius, no time stamp and no temperature type. */
	uint32_t temperature;   /* Stores the temperature data read from the sensor in the correct format */
	uint8_t *p = tempBuf;

	  /* Convert flags to bitstream and append them in the HTM temperature data buffer (htmTempBuffer) */
	  UINT8_TO_BITSTREAM(p, flags);

	  /* Convert sensor data to correct temperature format */
	  temperature = FLT_TO_UINT32(tempf, -3);
	  /* Convert temperature to bitstream and place it in the HTM temperature data buffer (htmTempBuffer) */
	  UINT32_TO_BITSTREAM(p, temperature);

	  /* Send indication of the temperature in htmTempBuffer to all "listening" clients.
	   * This enables the Health Thermometer in the Blue Gecko app to display the temperature.
	   *  0xFF as connection ID will send indications to all connections. */
	  BTSTACK_CHECK_RESPONSE(gecko_cmd_gatt_server_send_characteristic_notification(
		0xFF, gattdb_temperature_measurement, 5, tempBuf));

}
