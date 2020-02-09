/*
 * @filename : i2c.c
 *
 *  @date : Feb 6, 2020
 *  @description : File containing functions for i2c communication
 *
 *    	@author : pshiralagi
 */
//Includes
#include "i2c.h"

uint8_t write_buffer_data = {0xF3};
uint8_t write_buffer_len = sizeof(write_buffer_data);

void init_i2c(void)
{
	I2CSPM_Init_TypeDef i2cInit = I2CSPM_INIT_DEFAULT;
	I2CSPM_Init(&i2cInit);

}

void TempTransferInit_i2c(void)
{

	write_seq.addr = TEMP_ADDR << 1;
	write_seq.flags = I2C_FLAG_WRITE;
	write_seq.buf[0].data = &write_buffer_data;
	write_seq.buf[0].len = write_buffer_len;
	read_seq.addr = TEMP_ADDR << 1;
	read_seq.flags = I2C_FLAG_READ;
	read_seq.buf[0].data = temp;
	read_seq.buf[0].len = sizeof(temp);

}

float GetTemp_i2c(void)
{
	uint16_t temp_cat;
	float celsius;
	I2C_TransferReturn_TypeDef ret;
	ret = I2CSPM_Transfer(I2C0, &write_seq);
	if(ret == i2cTransferDone)
	{
		LOG_INFO("Write successful %d", ret);
	}
	if(ret == i2cTransferInProgress)
	{
		LOG_INFO("Write in progress %d", ret);
	}
	if(ret == i2cTransferNack)
	{
		LOG_INFO("Nack on write %d", ret);
	}
	if(ret == i2cTransferBusErr)
	{
		LOG_INFO("Bus error on write %d", ret);
	}
	if(ret == i2cTransferArbLost)
	{
		LOG_INFO("Arbitration lost on write %d", ret);
	}
	if(ret == i2cTransferUsageFault)
	{
		LOG_INFO("Usage fault on write %d", ret);
	}
	if(ret == i2cTransferSwFault)
	{
		LOG_INFO("SW fault on write %d", ret);
	}
	timerWaitUs(500000);
	ret = I2CSPM_Transfer(I2C0, &read_seq);
	timerWaitUs(500000);
	temp_cat = (temp[0]<<8) | temp[1];
	celsius = (((175.72*temp_cat)/65536)-(46.85));
	if(ret == i2cTransferDone)
	{
		LOG_INFO("Read successful %d", ret);
	}
	if(ret == i2cTransferInProgress)
	{
		LOG_INFO("Read in progress %d", ret);
	}
	if(ret == i2cTransferNack)
	{
		LOG_INFO("Nack on read %d", ret);
	}
	if(ret == i2cTransferBusErr)
	{
		LOG_INFO("Bus error on read %d", ret);
	}
	if(ret == i2cTransferArbLost)
	{
		LOG_INFO("Arbitration lost on read %d", ret);
	}
	if(ret == i2cTransferUsageFault)
	{
		LOG_INFO("Usage fault on read %d", ret);
	}
	if(ret == i2cTransferSwFault)
	{
		LOG_INFO("SW fault on read %d", ret);
	}
	return celsius;
}
