/* 
 * File:   main_display.c
 * Author: abelh
 *
 * Created on 16 de enero de 2023, 07:01 PM
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Configuracion.h"
#include <libpic30.h>
#include <xc.h>

uint16_t Display_16seg[11] = {0XFF00,0XDDFF,0X7788,0X77C0,0X7773,0X7744,0X7704,0X33FC,0X7700,0X7740,0XDD21};
uint8_t  Display_7seg_A[10]  = {0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};
uint8_t  Display_7seg_7447[10] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09};
uint8_t i=0,j=0;
 /*
 */
void Ejemplo1(void);
void Ejemplo2(void);

int main(int argc, char** argv) {
    ADPCFG = 0xFFFF;
    TRISB = 0x00;
    TRISD = 0x00;
    LATB = Display_7seg_7447[0];
    LATD = Display_7seg_7447[0];
    
    for(;;){
        //for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                LATB = Display_7seg_7447[j];
                //LATD = Display_7seg_7447[i];
                __delay_ms(1000);
            }
        //}
    }
    
    return (EXIT_SUCCESS);
}

void Ejemplo1(void){
    ADPCFG = 0x0FFF;
    TRISB = 0x0000; //SALIDA
    LATB = Display_16seg[0];
    
    for(;;){
        LATB = Display_16seg[i];
        __delay_ms(100);
        i++;
        if(i==11) i = 0;
    }
    
}
void Ejemplo2(void){
    ADPCFG = 0x0FFF;
    TRISB = 0x0000; //SALIDA
    LATB = Display_7seg_A[0];
    
    for(;;){
        
        for(i=0;i<10;i++){
        LATB = Display_7seg_A[i];
        __delay_ms(100);
        }
    }
}
