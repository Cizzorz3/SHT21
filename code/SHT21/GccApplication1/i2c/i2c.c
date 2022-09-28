/*
 * File:   i2c.c
 * Author: Mohamed Adel
 *
 * Created on September 26, 2022, 11:18 AM
 */

#include "i2c.h"
void i2c_init(void)
{
	TWSR  = 0x00;
	TWBR  = 0x47;
	TWCR |= (1<<TWEN);
	TWAR  = 0b1000000;
}
void i2c_start(void)
{
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	while((TWCR&(1<<TWINT))==0);
	
}
void i2c_send(uint8_t data)
{
	TWDR = data;
	TWCR= (1<<TWINT) | (1<<TWEN);
	while(!(TWCR&(1<<TWINT)));
}
void i2c_stop(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}
uint8_t i2c_read(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	while((TWCR & (1<<TWINT))==0);

	return TWDR ;
}
char I2C_Read_Nack()		/* I2C read nack function */
{
	TWCR=(1<<TWEN)|(1<<TWINT);	/* Enable TWI and clear interrupt flag */
	while(!(TWCR&(1<<TWINT)));	/* Wait until TWI finish its current job */
	return TWDR;		/* Return received data */
}
char I2C_Read_Ack()		/* I2C read ack function */
{
	TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA); /* Enable TWI, generation of ack */
	while(!(TWCR&(1<<TWINT)));	/* Wait until TWI finish its current job */
	return TWDR;			/* Return received data */
}

