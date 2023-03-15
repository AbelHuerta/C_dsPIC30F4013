/* 
 * File:   Configuracion.h
 * Author: abelh
 *
 * Created on 16 de enero de 2023, 12:48 PM
 */

#ifndef CONFIGURACION_H
#define	CONFIGURACION_H

//FIN = 20MHz/2 = 10MHz
//PLL x 16 => 10MHz * 16 = 160MHz => FOSC
//FCY = FOSC/4 = 160MHz/4 = 40MHz

#define _XTAL_FREQ 20000000UL
#define FCY        40000000UL

#endif	/* CONFIGURACION_H */

