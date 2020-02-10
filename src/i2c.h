/*
 * @filename : i2c.h
 *
 *  @date : Feb 6, 2020
 *  @description : Header file for i2c protocols in i2c.c
 *
 *    	@author : pshiralagi
 *    	@reference : https://siliconlabs.github.io/Gecko_SDK_Doc/efr32bg13/html/index.html
 */
#ifndef i2c_h
#define i2c_h

//Defines
#define INCLUDE_LOG_DEBUG 1

//Includes
#include <i2cspm.h>
#include "gpio.h"
#include "letimer.h"
#include "log.h"

//Function declarations
void init_i2c(void);
void TempTransferInit_i2c(void);
uint16_t GetTemp_i2c(void);

//Variables
I2C_TransferSeq_TypeDef write_seq;
I2C_TransferSeq_TypeDef read_seq;
uint8_t temp[2];

#define TEMP_ADDR (0x40)
#endif
