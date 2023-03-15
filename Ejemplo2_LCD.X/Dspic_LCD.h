/* 
 * File:   Dspic_LCD.h
 * Author: abelh
 *
 * Created on 16 de enero de 2023, 12:47 PM
 */

#ifndef DSPIC_LCD_H
#define	DSPIC_LCD_H

#include <stdint.h>
#include <xc.h>

#define E    LATBbits.LATB0
#define RS   LATBbits.LATB1
#define D4   LATBbits.LATB2
#define D5   LATBbits.LATB3
#define D6   LATBbits.LATB4
#define D7   LATBbits.LATB5

typedef enum{
    FILA1 = 1,
    FILA2,
    FILA3,
    FILA4
}Ubicacion;

void LCD_dsPIC_cmd(uint8_t a);
void LCD_dsPIC_Databus(uint8_t a);
void LCD_dsPIC_Init(void);
void LCD_dsPIC_SetCursor(uint8_t x,uint8_t y);
void LCD_dsPIC_Print_Char(char a);
void LCD_dsPIC_Print_String(char *a);
void LCD_dsPIC_Write_New_Char(uint8_t a);
void LCD_dsPIC_Clear(void);
void LCD_dsPIC_Home(void);

#endif	/* DSPIC_LCD_H */

