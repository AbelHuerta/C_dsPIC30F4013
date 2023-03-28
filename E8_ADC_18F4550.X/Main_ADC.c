/* 
 * File:   Main_ADC.c
 * Author: abelh
 *
 * Created on 28 de marzo de 2023, 10:29 AM
 */

#include <xc.h>
#include <pic18f4550.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>

#include "Configuracion.h"
#include "ADC.h"
#include "I2C.h"
#include "LCD_I2C.h"

/*
 * VARIABLES
 */
float tension;
uint8_t  bufferTx[20];  //CARACTERES A TRANSMITIR
uint16_t data;          //CONVERSION ADC


int main(int argc, char** argv) {
    //TRISAbits.RA1 = 1;
    
    Master_Mode();
    LCD_I2C_Init();
    ADC_Conversion();
    LCD_I2C_WriteText(0,0,"LECTURA ADC");
    for(;;){
        data = ADC_Read(AN0);
        tension = (data * 5.0)/1023.0;
        sprintf(bufferTx,"%.02f",tension);
		LCD_I2C_WriteText(1,0,bufferTx);
		__delay_ms(100);
                
        
    }
       
    return (EXIT_SUCCESS);
}

