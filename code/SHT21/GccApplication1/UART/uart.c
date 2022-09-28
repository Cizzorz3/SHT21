/*
 * File:   uart.c
 * Author: Mohamed Adel
 *
 * Created on September 26, 2022, 11:18 AM
 */

#include "uart.h"
void uart_init(void)
{
	//Baud rate
	UBRRL = 51;
	
	Clear_Bit(UCSRA,U2X);
	//Frame
	Sit_Bit(UCSRB,TXEN);
	Clear_Bit(UCSRA,UDRE);
	//Enable
	Sit_Bit(UCSRB,RXEN);
	
}
void uart_send(uint8_t Data)
{
	while(!Read_Bit(UCSRA,UDRE));
	UDR = Data;
	
}
void uart_sendstring(char* str)
{
	while (*str)
	{
		uart_send(*str++);
	}
}