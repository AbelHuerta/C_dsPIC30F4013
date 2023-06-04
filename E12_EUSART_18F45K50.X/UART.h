/* 
 * File:   UART.h
 * Author: abelh
 *
 * Created on 4 de junio de 2023, 12:22 PM
 */

#ifndef UART_H
#define	UART_H

//Librerias
#include <stdint.h>


//DEFINE
#define _XTAL_FREQ                           16000000UL
#define HIGH_SPEED                           1
#define ASINCRONO                            0  
#define X_VALUE(baud,speed,X,X_low,X_high)   if(speed == 1){                                                 \
                                                X = (uint16_t)(((_XTAL_FREQ / baud) / 4) - 1)               ;\
                                                X_low  = (uint8_t)(X & 0xFF)                                ;\
                                                X_high = (uint8_t)((X >>8)&0xFF)                            ;\
                                                TXSTA1bits.BRGH = 1                                         ;\
                                            }

//PROTOTIPO DE FUNCIONES

void Init_UART(uint16_t baudios,uint8_t speed);
void Uart_caracter_Write(uint8_t caracter);
void Uart_cadena_Write(uint8_t *cadena, uint8_t size);

void Interrupt_global(void);
void Interrupt_UART(void);


/*
 * se configura el UART
 * genera caracteres
 */

//PROTOTIPO DE VARIABLES



#endif	/* UART_H */

