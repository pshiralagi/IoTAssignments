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
/* Flag for indicating DFU Reset must be performed */
uint8_t boot_to_dfu = 0;
uint8_t current_state, next_state;
void send_temp(void);

/*	@brief : Function to schedule and perform events and then go to sleep based on selected mode using a FSM	*/
void event_scheduler(uint32_t event_word)
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
				  sleep_em1();
#ifdef INCLUDE_LOGGING
		  	  	  next_state = current_state+1;
#endif
		  	  	  break;
		  case(I2C_read_start):
				  ms_sleep(10);
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
		  	  	  event_word = 0;
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

void gecko_pav_update(struct gecko_cmd_packet* evt)
{
//	int16_t rssi;
	/* Handle events */
		switch (BGLIB_MSG_ID(evt->header)) {
		  /* This boot event is generated when the system boots up after reset.
		   * Do not call any stack commands before receiving the boot event.
		   * Here the system is set to start advertising immediately after boot procedure. */
		  case gecko_evt_system_boot_id:
			/* Set advertising parameters. 100ms advertisement interval.
			 * The first two parameters are minimum and maximum advertising interval, both in
			 * units of (milliseconds * 1.6). */
			gecko_cmd_le_gap_set_advertise_timing(0, 250, 250, 0, 0);
//
//			/* Start general advertising and enable connections. */
			gecko_cmd_le_gap_start_advertising(0, le_gap_general_discoverable, le_gap_connectable_scannable);
			break;


		case gecko_evt_le_connection_opened_id:
			  /*	Initialize timer	*/
			  letimerInit();
			  break;



		  /* This event is generated when the software timer has ticked. In this example the temperature
		   * is read after every 1 second and then the indication of that is sent to the listening client. */
//		case gecko_evt_le_connection_rssi_id:
//
//			rssi = gecko_cmd_le_connection_get_rssi(evt->data.cmd_le_connection_get_rssi.connection);
//			if(rssi > -35)
//			{
//				gecko_cmd_system_set_tx_power(-25);
//			}
//			if((rssi<=-35)&&(rssi>-45))
//			{
//				gecko_cmd_system_set_tx_power(-20);
//			}
//			if((rssi<=-45)&&(rssi>-55))
//			{
//				gecko_cmd_system_set_tx_power(-15);
//			}
//			if((rssi<=-55)&&(rssi>-65))
//			{
//				gecko_cmd_system_set_tx_power(-10);
//			}
//			if((rssi<=-65)&&(rssi>-75))
//			{
//				gecko_cmd_system_set_tx_power(-5);
//			}
//			if((rssi<=-75)&&(rssi>-85))
//			{
//				gecko_cmd_system_set_tx_power(5);
//			}
//			if(rssi <= -85)
//			{
//				gecko_cmd_system_set_tx_power(5);
//			}
//			break;
		  case gecko_evt_system_external_signal_id:

			  event_scheduler(evt->data.evt_system_external_signal.extsignals);

			  send_temp();
			  //gecko_external_signal(0x00);
			break;

		  case gecko_evt_le_connection_closed_id:
			/* Check if need to boot to dfu mode */
			if (boot_to_dfu) {
			  /* Enter to DFU OTA mode */
			  gecko_cmd_system_reset(2);
			} else {
			  /* Stop timer in case client disconnected before indications were turned off */
			  gecko_cmd_hardware_set_soft_timer(0, 0, 0);
			  /* Restart advertising after client has disconnected */
			  gecko_cmd_le_gap_start_advertising(0, le_gap_general_discoverable, le_gap_connectable_scannable);
			}
			LETIMER_IntDisable(LETIMER0, LETIMER_IEN_UF);
			break;

		  /* Events related to OTA upgrading
			 ----------------------------------------------------------------------------- */

		  /* Checks if the user-type OTA Control Characteristic was written.
		   * If written, boots the device into Device Firmware Upgrade (DFU) mode. */
		  case gecko_evt_gatt_server_user_write_request_id:
			if (evt->data.evt_gatt_server_user_write_request.characteristic == gattdb_ota_control) {
			  /* Set flag to enter to OTA mode */
			  boot_to_dfu = 1;
			  /* Send response to Write Request */
			  gecko_cmd_gatt_server_send_user_write_response(
				evt->data.evt_gatt_server_user_write_request.connection,
				gattdb_ota_control,
				bg_err_success);

			  /* Close connection to enter to DFU OTA mode */
			  gecko_cmd_le_connection_close(evt->data.evt_gatt_server_user_write_request.connection);
			}
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
//  	  event_word &= ~0x1;
  	  CORE_EXIT_CRITICAL();

}

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
	  gecko_cmd_gatt_server_send_characteristic_notification(
		0xFF, gattdb_temperature_measurement, 5, tempBuf);

}
