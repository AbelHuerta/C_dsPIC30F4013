/* 
 * File:   Main_I2C_LCD.c
 * Author: abelh
 *
 * Created on 23 de marzo de 2023, 11:34 AM
 */

#include <xc.h>
#include <pic18f4550.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "Configuracion.h"
#include "I2C.h"
#include "LCD_I2C.h"
/*
 * 
 */
int i;
int main(int argc, char** argv) {
    ADCON1 = 0x0F;
    /*I2C_Start();
    I2C_ADDRESS_SLAVE(0xA0,0x00);
    I2C_ADDRESS_SLAVE(0x40,0x00);
    I2C_ADDRESS_SLAVE(0x10,0x00);
    I2C_Stop();
    */
    Master_Mode();
    LCD_I2C_Init();
    
    LCD_I2C_WriteText(0,0,"-------PRUEBA-------");
    LCD_I2C_WriteText(1,0,"        LCD         ");
    LCD_I2C_WriteText(2,0,"        I2C         ");
    LCD_I2C_WriteText(3,0,"-----PIC18F4550-----");
    
    for(;;){
        
        
    }
    return (EXIT_SUCCESS);
}

