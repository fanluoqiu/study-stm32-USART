#ifndef SERIAL_H
#define SERIAL_H

#include "stm32f10x.h"
#include <stdio.h>
#include <stdarg.h>
void Serialprint_init(void);
void Serial_SendByte(uint8_t data);
void Serial_SendString(char *ch);
void Serial_print(char * format,...);
#endif

