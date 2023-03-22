/* 
 * File:   Main_I2C.c
 * Author: abelh
 *
 * Created on 22 de marzo de 2023, 12:10 AM
 */

#include <xc.h>
#include <pic18f4550.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "Configuracion.h"
#include "I2C.h"
/*
 * 
 */
int i;
int main(int argc, char** argv) {
    ADCON1 = 0x0F;
    Master_Mode();
    /*I2C_Start();
    I2C_ADDRESS_SLAVE(0xA0,0x00);
    I2C_ADDRESS_SLAVE(0x40,0x00);
    I2C_ADDRESS_SLAVE(0x10,0x00);
    I2C_Stop();
    */
    
    for(;;){
        for(i=0;i<=255;i++){
            I2C_Start();
            I2C_ADDRESS_SLAVE(0x40,I2C_WRITE);
            I2C_Write_Data(i);
            I2C_Stop();
            __delay_ms(500);
        }
        
    }
    return (EXIT_SUCCESS);
}

