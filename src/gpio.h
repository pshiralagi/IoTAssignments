/*
 * gpio.h
 *
 *  Created on: Dec 12, 2018
 *      Author: Dan Walkes
 *      Co author: Pshiralai
 */

#ifndef SRC_GPIO_H_
#define SRC_GPIO_H_
#include "letimer.h"

void gpioInit();	//Initializes required gpios
void gpioLed0SetOn();	//Sets LED 0
void gpioLed0SetOff();	//Clears LED 0
void gpioLed1SetOn();	//Sets LED 1
void gpioLed1SetOff();	//Clears LED 1
void tempGpioDeInit(void);		//Clears required GPIOs for LPM
void tempGpioReInit(void);		//Resets required GPIO for LPM to restart peripherals
void toggleLed(void);	//Toggles LEDs
void lpm_off(void);	//De-initialize required pins, LPM OFF
void lpm_on(void);	//Re-initialize required pins, LPM ON

#define	LED0_port gpioPortF
#define LED0_pin 4
#define LED1_port gpioPortF
#define LED1_pin 5
#define SCL_port gpioPortC
#define SCL_pin 10
#define SDA_port gpioPortC
#define SDA_pin 11
#define enable_port gpioPortD
#define enable_pin 15

//#define GPIO_SET_DISPLAY_EXT_COMIN_IMPLEMENTED 	1
//#define GPIO_DISPLAY_SUPPORT_IMPLEMENTED		1

#endif /* SRC_GPIO_H_ */
