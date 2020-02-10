/*
 * @filename : i2c.c
 *
 *  @date : Feb 6, 2020
 *  @description : File containing functions for i2c communication and specific temperature routines
 *
 *    	@author : pshiralagi
 *    	@reference : https://siliconlabs.github.io/Gecko_SDK_Doc/efr32bg13/html/index.html
 */
//Includes
#include "i2c.h"

uint8_t write_buffer_data = {0xF3};//Measure temperature, no hold, master mode connabd
uint8_t write_buffer_len = sizeof(write_buffer_data);

/*
 * @brief : Function to initialize i2c with default values
 *
 */
void init_i2c(void)
{
	I2CSPM_Init_TypeDef i2cInit = I2CSPM_INIT_DEFAULT;
	I2CSPM_Init(&i2cInit);

}

/*
 * @brief : Initializing i2c values to write and read from temperature sensor
 *
 */
void TempTransferInit_i2c(void)
{
	//Write sequence setup
	write_seq.addr = TEMP_ADDR << 1;	//7 bit address hence left shift by 1
	write_seq.flags = I2C_FLAG_WRITE;
	write_seq.buf[0].data = &write_buffer_data;
	write_seq.buf[0].len = write_buffer_len;
	//Read sequence setup
	read_seq.addr = TEMP_ADDR << 1;
	read_seq.flags = I2C_FLAG_READ;
	read_seq.buf[0].data = temp;		//2 byte value read
	read_seq.buf[0].len = sizeof(temp);

}
/*
 * @brief : Function to write and read from temperature senso
 *
 */
uint16_t GetTemp_i2c(void)
{
	uint16_t temp_cat;
//	float celsius;
	I2C_TransferReturn_TypeDef ret;
	ret = I2CSPM_Transfer(I2C0, &write_seq);//Measure temperature, no hold, master mode
	/*	Error handling	*/
	if(ret == i2cTransferDone)
	{
		LOG_INFO("Write successful %d", ret);
	}
	if(ret == i2cTransferInProgress)
	{
		LOG_ERROR("Write in progress %d", ret);
	}
	if(ret == i2cTransferNack)
	{
		LOG_ERROR("Nack on write %d", ret);
	}
	if(ret == i2cTransferBusErr)
	{
		LOG_ERROR("Bus error on write %d", ret);
	}
	if(ret == i2cTransferArbLost)
	{
		LOG_ERROR("Arbitration lost on write %d", ret);
	}
	if(ret == i2cTransferUsageFault)
	{
		LOG_ERROR("Usage fault on write %d", ret);
	}
	if(ret == i2cTransferSwFault)
	{
		LOG_ERROR("SW fault on write %d", ret);
	}
	timerWaitUs(5000);//Wait for write to complete
	ret = I2CSPM_Transfer(I2C0, &read_seq);
	temp_cat = (temp[0]<<8) | temp[1];//Reading both bytes to 16 bit value
//	celsius = (((175.72*temp_cat)/65536)-(46.85));//Converting value read to degrees celsius
	//Error handling for read
	if(ret == i2cTransferDone)
	{
		LOG_INFO("Read successful %d", ret);
	}
	if(ret == i2cTransferInProgress)
	{
		LOG_ERROR("Read in progress %d", ret);
	}
	if(ret == i2cTransferNack)
	{
		LOG_ERROR("Nack on read %d", ret);
	}
	if(ret == i2cTransferBusErr)
	{
		LOG_ERROR("Bus error on read %d", ret);
	}
	if(ret == i2cTransferArbLost)
	{
		LOG_ERROR("Arbitration lost on read %d", ret);
	}
	if(ret == i2cTransferUsageFault)
	{
		LOG_ERROR("Usage fault on read %d", ret);
	}
	if(ret == i2cTransferSwFault)
	{
		LOG_ERROR("SW fault on read %d", ret);
	}
	return temp_cat;//Returning temperature in celsius
}
