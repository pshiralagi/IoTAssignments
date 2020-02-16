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


//Includes
#include <i2cspm.h>
#include "main.h"
//Function declarations
void init_i2c(void);				//Initialized i2c0
void TempTransferInit_i2c(void);	//Initializing i2c values to write and read from temperature sensor
void temp_i2c_write(void);			//Function to write command value to i2c temp sensor
void temp_i2c_read(void);			//Function to read value from temp sensor

extern uint8_t temp[2];					//2 bytes stored after data is read

//Variables
extern I2C_TransferSeq_TypeDef write_seq;	//Write sequence
extern I2C_TransferSeq_TypeDef read_seq;	//Read sequence


#define TEMP_ADDR (0x40)	//Address of temp sensor
#endif
