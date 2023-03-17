/* 
 * File:   Interrupciones.h
 * Author: abelh
 *
 * Created on 17 de marzo de 2023, 05:43 PM
 */

#ifndef INTERRUPCIONES_H
#define	INTERRUPCIONES_H


#include <xc.h>
#include <pic18f4550.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/******************************************/
/****    CALCULO DE LA TEMPORIZACION   ****/
/******************************************/
// FCY = 48MHz
// Por el modulo de temporizacion (/4) -> 12MHz
// Por lo tanto:
// T = (4/FCY) * PRE * (65535 - TMR0)
// T = (4/12MHz) * 256 * (65535 - TMR0)
// Para la temporizacion de 1 seg
// 1 =  (4/12MHz) * 256 * (65535 - TMR0)
// LA activacion de la bandera de interrupcion ocurrira cada
// TMR0 = 18660 conteos 
// en Hexadecimal 
// TMR0 = 48E4

/*
 * VARIABLES
 */
int  cont  = 0;

/*
 * FUNCIONES
 */
void Timer0_enable(void);
void Interrupt_global(void);
void Interrupt_TIMER(void);

#endif	/* INTERRUPCIONES_H */

