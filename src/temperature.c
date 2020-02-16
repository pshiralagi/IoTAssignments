/*
 * @filename : temperature.c
 *
 *  @date : Feb 6, 2020
 *  @description : File containing functions to obtain temperature reading from on board sensor
 *
 *    	@author : pshiralagi
 *    	@reference : https://siliconlabs.github.io/Gecko_SDK_Doc/efr32bg13/html/index.html
 */

//Includes
#include "temperature.h"

I2C_TransferSeq_TypeDef write_seq;
I2C_TransferSeq_TypeDef read_seq;
uint8_t temp[2];

/*	@brief : Initializing i2c for temperature readings	*/
void tempInit(void)
{
	init_i2c();	/*	Initialization for I2C	*/
	TempTransferInit_i2c();

}

/*	@brief : Going to sleep until write is complete	*/
void temp_write_complete(void)
{
	logFlush();
	sleep_em1();
}

/*	@brief : Going to sleep until read is complete and then calculating temp value in celsius	*/
void temp_read_complete(void)
{
	uint16_t temp_cat;
	float temperature_c;
	temp_cat = (temp[0]<<8) | temp[1];//Reading both bytes to 16 bit value
	temperature_c = temp_cat;
	temperature_c = (((175.72*temperature_c)/65536)-(46.85));//Converting value read to degrees celsius
	LOG_ERROR("Temperature : %f", temperature_c);
}
