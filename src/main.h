/*
 * @filename : main.h
 *
 *  @date : Jan 29, 2020
 *  @description : main header file
 *
 *    	@author : pshiralagi
 *    	@reference : https://siliconlabs.github.io/Gecko_SDK_Doc/efr32bg13/html/index.html
 */

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

//Functions
void toggleLed(void);
void initApp(void);

#define INCLUDE_LOG_DEBUG 1




