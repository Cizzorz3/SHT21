/*
 * File:   main.c
 * Author: Mohamed Adel
 *
 * Created on September 26, 2022, 11:18 AM
 */



#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/delay.h>
#include "i2c/i2c.h"
#include "UART/uart.h"
#include <stdlib.h>
#include <stdio.h>
#define make16(msb, lsb)  ((msb << 8) | (lsb & 0xff))


int main(void) {
	float temp_final_val =0;
	float humidity_final_val=0;
    char temp_buffer[64] ;
    char humid_buffer[64];
    int temp_16bit=0 , humid_16bit=0;
   unsigned char temp_data[3];
   unsigned char humid_data[3];
    uint8_t direction = 0;
    direction =0x80;
    i2c_init();
	uart_init();
    while(1)
    {
        i2c_start();
        i2c_send(direction);
        i2c_send(0xF3);
        _delay_ms(100);
        i2c_start();
        _delay_ms(100);
        i2c_send(direction+1);
        _delay_ms(100);
        temp_data[0]=i2c_read();
        temp_data[1]=i2c_read();
       temp_data[2]=I2C_Read_Nack();
        i2c_stop();
        temp_16bit=make16(temp_data[0],temp_data[1]);
        temp_final_val = (-46.85 +(175.52*temp_16bit)/65536);
		sprintf(temp_buffer,"%2.3f",temp_final_val);
		uart_sendstring("Temp is : ");
		_delay_ms(100);
		uart_sendstring(temp_buffer);
		_delay_ms(200);
		uart_sendstring(" ");
		_delay_ms(200);
		
        i2c_start();
        i2c_send(direction);
       i2c_send(0xF5);
       _delay_ms(200);
       i2c_start();
      _delay_ms(200);
      i2c_send(direction+1);
        _delay_ms(200);
       humid_data[0]=i2c_read();
      humid_data[1]=i2c_read();
      humid_data[2]=I2C_Read_Nack();
      i2c_stop();
       humid_16bit=make16(humid_data[0],humid_data[1]);
       humidity_final_val = ((-6+(125.0*humid_16bit)/65536));
      sprintf(humid_buffer,"%2.3f",humidity_final_val);
      uart_sendstring("Humid is : ");
      uart_sendstring(humid_buffer);
      uart_sendstring(" ");
    }
    return 0 ;
}
