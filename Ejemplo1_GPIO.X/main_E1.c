/* 
 * File:   main_E1.c
 * Author: abelh
 *
 * Created on 11 de enero de 2023, 02:57 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "Configuracion.h"
#include <libpic30.h>
#include <math.h>
#include <xc.h>

/*
 * FUNCIONES
 */
void ejemplo1_bitabit(void);
void ejemplo2_mascara(void);
void ejemplo3_corrimiento(void);
void ejemplo4_corrimiento2(void);
void ejemplo5_bit(void);
void ejemplo6_entrada(void);

/*
 * VARIABLE GLOBAL
 */
int i=0;

int main(int argc, char** argv) {
    // SALIDAS  -> 0
    // ENTRADAS -> 1
    
    asm("nop");
//    TRISB = 0x0F00;                 //HEXADECIMAL
//    TRISA = 2048;                     //DECIMAL
//    TRISC = 0b1010000000000000;     //BINARIO

//CONFIGURACION BIT A BIT
//    ADPCFGbits.PCFG0 = 1; //AN0 -> DIGITAL
//    TRISBbits.TRISB0 = 0;   //salida
//    TRISAbits.TRISA11= 0;   //salida
    
    
//CONFIGURACION MEDIANTE ENMASCARAMIENTO
//    ADPCFG |= (1<<0);
//    TRISB &= ~(1<<0);
//    TRISA &= ~(1<<0);
    
//CORRIMIENTO
    ADPCFG= 0xFFFF;      //ANX -> DIGITAL
    TRISB &= ~(1<<10) & ~(1<<11);      //SALIDA
    TRISB |= (1<<0);                 //ENTRADA
    
    
    while(true){
        if(PORTBbits.RB0 == 0){
            while(PORTBbits.RB0 == 0);
            __delay_us(20);
            LATB |= (1<<10);
            LATB &= ~(1<<11);
        }
        if(PORTBbits.RB0 != 0){
            while(PORTBbits.RB0 != 0);
            __delay_us(20);
            LATB |= (1<<11);
            LATB &= ~(1<<10);
        }
    }
    
    
    return (EXIT_SUCCESS);
}

void ejemplo1_bitabit(void){
        LATBbits.LATB0 = 1;
        LATAbits.LATA11= 0;
        __delay_ms(100);
        LATBbits.LATB0 = 0;
        LATAbits.LATA11= 1;
        __delay_ms(100);
}
void ejemplo2_mascara(void){
    LATB |= (1<<0);
        LATA &= ~(1<<0);
        __delay_ms(100);
        LATB &= ~(1<<0);
        LATA |= (1<<0);
        __delay_ms(100);
}
void ejemplo3_corrimiento(void){
    for(i=0;i<=16;i++){
            PORTB = pow(2,i)-1;
            __delay_ms(100);
        }
        for(i=16;i>0;i--){
            PORTB = pow(2,i)-1;
            __delay_ms(100);
        }
}
void ejemplo4_corrimiento2(void){
   while(i<16){
            LATB |= (1<<i);
            __delay_ms(100);
            i++;
        }
        i--;
        while(i>=0){
            LATB &= ~(1<<i);
            __delay_ms(100);
            i--;
        }
        i=0; 
}
void ejemplo5_bit(void){
    if(PORTBbits.RB0 == 0){
            LATBbits.LATB10 = 1;
            LATBbits.LATB11 = 0;
        }else{
            LATBbits.LATB10 = 0;
            LATBbits.LATB11 = 1;    
        }
}
void ejemplo6_entrada(void){
        if((PORTB & (1<<0))==0){ // PORTBbits.RB0 != 0
            LATB |= (1<<10);
            LATB &= ~(1<<11);
        }else{
            LATB &= ~(1<<10);
            LATB |=  (1<<11);
        } 
}