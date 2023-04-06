/* 
 * File:   Main_Timer1.c
 * Author: abelh
 *
 * Created on 29 de marzo de 2023, 03:45 PM
 */

#include <xc.h>
#include <pic18f4550.h>
#include "Configuracion.h"
#include "TIMER1.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
 * 
 */
int main(int argc, char** argv) {
    ADCON1 = 0x0F;
    //Configurar RB0 COMO SALIDA
    TRISCbits.TRISC1 = 0; 
    //Estado inicial RB0 APAGADO
    LATCbits.LATC1 = 0;
    
    //Configurar RA0 COMO SALIDA
    TRISAbits.TRISA0 = 0; 
    //Estado inicial RA0 APAGADO
    LATAbits.LATA0 = 0;
    
    Interrupt_global();
    Interrupt_TIMER();
    Timer1_enable();
    for(;;){
        /*Temporizar 10 segundos*/    
        if(cont>=2){
            LATAbits.LATA0 = ~LATAbits.LATA0;
            cont = 0;
        } 
        
        
    }
    
    return (EXIT_SUCCESS);
}

