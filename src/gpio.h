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

void gpioInit();
void gpioLed0SetOn();
void gpioLed0SetOff();
void gpioLed1SetOn();
void gpioLed1SetOff();
void gpioDeInit();
void gpioReInit();
void toggleLed(void);

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
#endif /* SRC_GPIO_H_ */
