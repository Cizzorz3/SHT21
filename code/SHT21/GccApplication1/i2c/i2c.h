/*
 * File:   i2c.h
 * Author: Mohamed Adel
 *
 * Created on September 26, 2022, 11:18 AM
 */

#ifndef I2C_H
#define	I2C_H
#include <avr/io.h>

void i2c_init(void);
void i2c_start(void);
void i2c_send(uint8_t data);
void i2c_stop(void);
uint8_t i2c_read(void);

#endif	/* I2C_H */

