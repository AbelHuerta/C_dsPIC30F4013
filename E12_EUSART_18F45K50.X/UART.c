#include <pic18f45k50.h>

#include "UART.h"



void Init_UART(uint16_t baudios,uint8_t speed){
    uint8_t  LOW_baud,HIGH_baud;
    uint16_t X;
    
    //GENERADOR DE BAUDIOS 16-BIT
    BAUDCON1bits.BRG16 = 1; // BRG16 = 1
    
    //ASINCRONO
    TXSTA1bits.SYNC = 0;
    RCSTA1bits.SPEN = 1;
    //BAUDIOS
    X_VALUE(baudios,speed,X,LOW_baud,HIGH_baud);
    
    SPBRG1  = LOW_baud;
    SPBRGH1 = HIGH_baud;
    
    //SELECIONA LA TRANSMISION DE 8 BITS
    TXSTA1bits.TX9 = 0;
    
    //PARIEDAD . SIN PARIEDAD YA QUE NO SE SELECCIONO TX DE 9 BITS
    
    //BIT STOP;
    
    //HABILITAR TX 
    TXSTA1bits.TXEN = 1;
    return;
}

void Uart_caracter_Write(uint8_t caracter){
    while(!TXSTA1bits.TRMT); //SI ESTA VACIO
    
    
    TXREG1 = caracter;
    return;
}

void Uart_cadena_Write(uint8_t *cadena, uint8_t size){
    while(size-->0){
		Uart_caracter_Write(*cadena);
	 	cadena++;
	}
	return;    
    
}

void Interrupt_global(void){
    //PRIORIDAD DE INTERRUPCIONES
    RCONbits.IPEN = 0;
    
    //ACTIVAR INTERRUPCIONES GLOBALES
    INTCONbits.GIE_GIEH = 1;
    
    //ACTIVAR INTERRUPCIONES DE PERIFERICOS
    INTCONbits.PEIE_GIEL = 1;
}

void Interrupt_UART(void){
    
    //HABLILTA LA INTERRUPCION DE TRANSMISION
    PIE1bits.TXIE = 1;
}
