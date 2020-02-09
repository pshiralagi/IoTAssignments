/*
 * gpio.c
 *
 *  Created on: Dec 12, 2018
 *      Author: Dan Walkes
 */
#include "gpio.h"
#include "em_gpio.h"
#include <string.h>


/**
 * TODO: define these.  See the radio board user guide at https://www.silabs.com/documents/login/user-guides/ug279-brd4104a-user-guide.pdf
 * and GPIO documentation at https://siliconlabs.github.io/Gecko_SDK_Doc/efm32g/html/group__GPIO.html
 */



void gpioInit()
{
	/* LED enables */
	GPIO_DriveStrengthSet(LED0_port, gpioDriveStrengthWeakAlternateWeak);
	GPIO_PinModeSet(LED0_port, LED0_pin, gpioModePushPull, false);

	GPIO_DriveStrengthSet(LED1_port, gpioDriveStrengthWeakAlternateWeak);
	GPIO_PinModeSet(LED1_port, LED1_pin, gpioModePushPull, false);

	/*	I2C enables	*/
	GPIO_DriveStrengthSet(SCL_port, gpioDriveStrengthWeakAlternateWeak);
	GPIO_PinModeSet(SCL_port, SCL_pin, gpioModePushPull, false);
	GPIO_DriveStrengthSet(SDA_port, gpioDriveStrengthWeakAlternateWeak);
	GPIO_PinModeSet(SDA_port, SDA_pin, gpioModePushPull, false);
	GPIO_DriveStrengthSet(enable_port, gpioDriveStrengthWeakAlternateWeak);
	GPIO_PinModeSet(enable_port, enable_pin, gpioModePushPull, false);
	GPIO_PinOutSet(enable_port,enable_pin);
}

void gpioLed0SetOn()
{
	GPIO_PinOutSet(LED0_port,LED0_pin);
}
void gpioLed0SetOff()
{
	GPIO_PinOutClear(LED0_port,LED0_pin);
}
void gpioLed1SetOn()
{
	GPIO_PinOutSet(LED1_port,LED1_pin);
}
void gpioLed1SetOff()
{
	GPIO_PinOutClear(LED1_port,LED1_pin);
}
