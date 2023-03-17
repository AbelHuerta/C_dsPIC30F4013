
#include "Interrupciones.h"

void __interrupt() Estado(void){
    //Verificación de la interrupción deseada
    if(INTCONbits.TMR0IE && INTCONbits.TMR0IF) {
       //1. Código de atención de la interrupción
       LATBbits.LATB0 = ~LATBbits.LATB0;
       //2. Restablecimiento de las condiciones para que se pueda producir la interrupción
       TMR0H = 0x48;
       TMR0L = 0xE4; 
       //3. Restablecimiento de la bandera
       INTCONbits.TMR0IF = 0;
       //4. contador para la temporizacion de 10 segundos aumenta
       cont++;
     }
}

void Timer0_enable(void){
    //TIMER 0 APAGADO
    T0CONbits.TMR0ON = 0;
    //TIMER DE 16BITS
    T0CONbits.T08BIT = 0;
    //SALIDA DE RELOJ DEL CICLO DE SISTEMA (FOSC/4)
    T0CONbits.T0CS = 0;
    //SELECCION DE FLANCO DE SUBIDA
    T0CONbits.T0SE = 0;
    //ACTIVA EL PREESCALADOR
    T0CONbits.PSA = 0;
    //SELECCION DEL PREESCALADOR 1:256
    T0CONbits.T0PS2 = 1;
    T0CONbits.T0PS1 = 1;
    T0CONbits.T0PS0 = 1;
    //TMR0
    TMR0H = 0x48;
    TMR0L = 0xE4;
    //TIMER 0 ENCENDIDO
    T0CONbits.TMR0ON = 1;
    
}

void Interrupt_global(void){
    //Deshabilitar los niveles de prioridad en las interrupciones
    RCONbits.IPEN = 0;
    //Activación de interrupción global
    INTCONbits.GIE_GIEH = 1; 
    //Habilitación de interrupción periférica
    INTCONbits.PEIE_GIEL = 1;
}

void Interrupt_TIMER(void){
    //Habilita la interrupción de desbordamiento TMR0
    INTCONbits.TMR0IE = 1;
    //El registro TMR0 no se desbordó
    INTCONbits.TMR0IF = 0;
}