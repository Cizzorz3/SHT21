/*
 * File:   uart.h
 * Author: Mohamed Adel
 *
 * Created on September 26, 2022, 11:18 AM
 */


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>

#define Read_Bit(reg,bit) ((reg>>bit)&1)
#define Sit_Bit(reg,bit) (reg |= (1<<bit))
#define Clear_Bit(reg,bit) (reg &=~ (1<<bit))
#define Toggle_Bit(reg,bit) (reg ^= (1<<bit))
#define Read_Bit(reg,bit) ((reg>>bit)&1)



void uart_init(void);
void uart_send(uint8_t Data);
void uart_sendstring(char* str);




#endif /* UART_H_ */