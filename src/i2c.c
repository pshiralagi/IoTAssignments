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

//Variables
uint8_t write_buffer_data = {0xF3};//Measure temperature, no hold, master mode connabd
uint8_t write_buffer_len = sizeof(write_buffer_data);
//Externs
I2C_TransferSeq_TypeDef write_seq;
I2C_TransferSeq_TypeDef read_seq;
uint8_t temp[2];

/*
 * @brief : Function to initialize i2c with default values
 *
 */
uint8_t current_state, next_state;
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


/*	@brief : Function to enable interrupt for i2c0 and write value	*/
void temp_i2c_write(void)
{
	NVIC_EnableIRQ(I2C0_IRQn);
	I2C_TransferReturn_TypeDef ret = I2C_TransferInit(I2C0, &write_seq);
	if (ret != i2cTransferInProgress)
	{
		LOG_ERROR("Tansfer unsuccessful");
	}

}

/*	@brief : Function to read value from temp sensor	*/
void temp_i2c_read(void)
{
	I2C_TransferReturn_TypeDef ret = I2C_TransferInit(I2C0, &read_seq);
	if (ret != i2cTransferInProgress)
	{
		LOG_ERROR("Tansfer unsuccessful");
	}
}

/*	@brief : I2C0 interrupt handler	*/
void I2C0_IRQHandler(void)
{
	CORE_DECLARE_IRQ_STATE;
	CORE_ENTER_CRITICAL();
	I2C_TransferReturn_TypeDef i2c_return_transfer_status;
	i2c_return_transfer_status = I2C_Transfer(I2C0);
	if (i2c_return_transfer_status != i2cTransferInProgress)
	{
		LOG_INFO("Transfer complete with status %d", i2c_return_transfer_status);
		next_state = current_state+1;
	}
	else
	{
		LOG_ERROR("Error!");
	}
	CORE_EXIT_CRITICAL();

}
