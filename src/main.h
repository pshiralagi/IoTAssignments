/*
 * @filename : main.h
 *
 *  @date : Jan 29, 2020
 *  @description : main header file
 *
 *    	@author : pshiralagi
 *    	@reference : https://siliconlabs.github.io/Gecko_SDK_Doc/efr32bg13/html/index.html
 */
#ifndef main_h
#define main_h

#include "gecko_configuration.h"
#include "gpio.h"
#include "native_gecko.h"
#include "letimer.h"
#include "cmu.h"
#include "energy.h"
#include <em_emu.h>
#include "temperature.h"
#include <sleep.h>
#include <em_core.h>
#include "fsm.h"
#include "i2c.h"
#include<gatt_db.h>
#include<infrastructure.h>
#include "gecko_ble_errors.h"

//Functions
int appMain(gecko_configuration_t *config);	//main function, consists some initializations and calls to functions




#endif



