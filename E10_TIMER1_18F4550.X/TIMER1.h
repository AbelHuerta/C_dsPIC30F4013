/* 
 * File:   TIMER1.h
 * Author: abelh
 *
 * Created on 29 de marzo de 2023, 03:47 PM
 */

#ifndef TIMER1_H
#define	TIMER1_H

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
// T = (4/12MHz) * 8 * (65535 - TMR0)
// Para la temporizacion de 0.17 seg = 170mS
// 0.17 =  (4/12MHz) * 8 * (65535 - TMR0)
// LA activacion de la bandera de interrupcion ocurrira cada
// TMR1 = 1785 conteos 
// en Hexadecimal 
// TMR1 = 06F9

/*
 * VARIABLES
 */
int  cont  = 0;

/*
 * FUNCIONES
 */
void Timer1_enable(void);
void Interrupt_global(void);
void Interrupt_TIMER(void);

#endif	/* TIMER1_H */

