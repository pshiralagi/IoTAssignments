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

/*
 * @brief : Function to initialize required GPIO pins in required mode
 *
 */
void gpioInit();
void gpioLed0SetOn();	//Sets LED 0
void gpioLed0SetOff();	//Clears LED 0
void gpioLed1SetOn();	//Sets LED 1
void gpioLed1SetOff();	//Clears LED 1

/*
 * @brief : Function to deinitialize required GPIO pins
 *
 */
void tempGpioDeInit(void);

/*
 * @brief : Function to reinitialize required GPIO pins after deinitializing before sleep
 *
 */
void tempGpioReInit(void);		//Resets required GPIO for LPM to restart peripherals
void toggleLed(void);	//Toggles LEDs

/*	@brief : Re-initialize GPIO pins for LPM OFF	*/
void lpm_off(void);

/*	@brief : Re-initialize GPIO pins for LPM ON	*/
void lpm_on(void);

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
