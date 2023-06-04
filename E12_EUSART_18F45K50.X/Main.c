#define _XTAL_FREQ 16000000UL // UL -> 32bits

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>
#include "Configuracion.h"
#include "UART.h"


void main(void){
    //CONFIGURACION DE RELOJ
    OSC_16Mhz_Init();
    
    //Puerto D 
    ANSELDbits.ANSD6 = 0;
    ANSELDbits.ANSD7 = 0;
    
    TRISDbits.RD6 = 1;
    TRISDbits.RD7 = 1;
    
    //LLamada de funciones
    Interrupt_global();
    Interrupt_UART();
    
    //baudios
    Init_UART(9600,HIGH_SPEED);
    
    
    
    for(;;){
        
       
        
		
        
    }   
    return;
}

void __interrupt() EUSART_ISR(void){
    
    while (PIR1bits.TXIF == 0);
    
    //bufferLen = sprintf(bufferTx,"%.02f\r\n",dato);
    Uart_cadena_Write( "asd",4);
        
    //DESABILITA LA INTERRUPCION
    PIE1bits.TXIE = 0;
    
    
}