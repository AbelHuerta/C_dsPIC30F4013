/* 
 * File:   Configuracion.h
 * Author: abelh
 *
 * Created on 23 de marzo de 2023, 11:35 AM
 */

#ifndef CONFIGURACION_H
#define	CONFIGURACION_H

//FRECUENCIA DEL CRISTAL
#define _XTAL_FREQ  20000000UL

//PLL:
/*
 * Fint = 20MHz -> Fosc/5 = 4MHz == 96 MHzPLL
 * PLL Postscaler = 2
 * Fout = 96Mhz/2 = 48MHz
 */

//FRECUENCIA DEL PROGRAMA
#define FCY 48000000UL

#endif	/* CONFIGURACION_H */

