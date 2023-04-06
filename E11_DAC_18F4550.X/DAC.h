/* 
 * File:   DAC.h
 * Author: abelh
 *
 * Created on 3 de abril de 2023, 03:31 PM
 */

#ifndef DAC_H
#define	DAC_H

#include <xc.h>
#include <pic18f4550.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "Configuracion.h"
#include "I2C.h"

/*
 *MACRO
 */
#define DIREC_MCP4725 0xC0

void MCP4725_WriteComand(uint16_t data);
uint16_t MCP4725_LCD(uint16_t data);



#endif	/* DAC_H */

