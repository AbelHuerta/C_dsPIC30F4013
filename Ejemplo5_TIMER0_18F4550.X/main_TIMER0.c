/* 
 * File:   main_TIMER0.c
 * Author: abelh
 *
 * Created on 17 de marzo de 2023, 05:42 PM
 */

#include <xc.h>
#include <pic18f4550.h>
#include "Configuracion.h"
#include "Interrupciones.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



int main(int argc, char** argv) {
    //Configurar RB0 COMO SALIDA
    TRISBbits.TRISB0 = 0; 
    //Estado inicial RB0 APAGADO
    LATBbits.LATB0 = 0;
    
    //Configurar RA0 COMO SALIDA
    TRISAbits.TRISA0 = 0; 
    //Estado inicial RA0 APAGADO
    LATAbits.LATA0 = 0;
    
    
    Interrupt_global();
    Interrupt_TIMER();
    Timer0_enable();
    
    for(;;){
    /*Temporizar 10 segundos*/    
        if(cont>=10){
            LATAbits.LATA0 = 1;
            
        }
    }
    
    
    return (EXIT_SUCCESS);
}

