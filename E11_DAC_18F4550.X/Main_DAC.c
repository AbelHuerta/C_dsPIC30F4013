/* 
 * File:   Main_DAC.c
 * Author: abelh
 *
 * Created on 3 de abril de 2023, 03:29 PM
 */

#include <xc.h>
#include <pic18f4550.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>

#include "Configuracion.h"
#include "I2C.h"
#include "LCD_I2C.h"
#include "DAC.h"
#include "ADC.h"

/*
 * 
 */
//#define button PORTAbits.RA5
uint16_t ValorConvertido = 0;
float voltaje;
char bufferVolt[16],bufferDac[16];



int main(int argc, char** argv) {

    
    Master_Mode();
    LCD_I2C_Init();
    ADC_Conversion();
    
    LCD_I2C_WriteText(0,0,"-----PIC18F4550-----");
    LCD_I2C_WriteText(1,0,"       MCP4725      ");
    __delay_ms(1500);
    
    for(;;){        
        
        
        ValorConvertido = ADC_Read(AN0);//Se lee el valor analogico convertido a digital;
        //voltaje = (ValorConvertido * 5.0)/1023.0;
        //sprintf(bufferVolt,"Volt: %.2fV",voltaje);
        //LCD_I2C_WriteText(2,0,bufferVolt);
        
        MCP4725_WriteComand((uint16_t)ValorConvertido);//Se escribe la direccion del MCP;
        
        __delay_ms(50);
        
    }

    
    
    return (EXIT_SUCCESS);
}

