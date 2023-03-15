/* 
 * File:   main_LCD.c
 * Author: abelh
 *
 * Created on 16 de enero de 2023, 12:48 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Configuracion.h"
#include <libpic30.h>
#include "Dspic_LCD.h"

#define izquierda 0
#define derecha   1

void Corrimiento_LCD_dsPIC(bool Modo);
uint8_t i=0;

/*
 * 
 */
int main(int argc, char** argv) {
    LCD_dsPIC_Init();
//    LCD_dsPIC_SetCursor(1,FILA1);
//    LCD_dsPIC_Print_Char('2');
//    LCD_dsPIC_SetCursor(1,FILA2);
//    LCD_dsPIC_Print_Char('0');
//    LCD_dsPIC_SetCursor(1,FILA3);
//    LCD_dsPIC_Print_Char('2');
//    LCD_dsPIC_SetCursor(1,FILA4);
//    LCD_dsPIC_Print_Char('3');
    
//    LCD_dsPIC_SetCursor(0,FILA1);
//    LCD_dsPIC_Print_String("********************");
//    LCD_dsPIC_SetCursor(0,FILA2);
//    LCD_dsPIC_Print_String("    PRUEBA DSPIC   ");
//    LCD_dsPIC_SetCursor(0,FILA3);
//    LCD_dsPIC_Print_String("        2023       ");
//    LCD_dsPIC_SetCursor(0,FILA4);
//    LCD_dsPIC_Print_String("********************");
    for(;;){
        Corrimiento_LCD_dsPIC(derecha);
    }
    return (EXIT_SUCCESS);
}

void Corrimiento_LCD_dsPIC(bool Modo){
    if(Modo == izquierda){
        for(i=8;i>0;i--){
            LCD_dsPIC_SetCursor(i,FILA1);
            LCD_dsPIC_Print_String("PRUEBA DSPIC");
            __delay_ms(300);
            LCD_dsPIC_Clear();
            LCD_dsPIC_Home();
        }  
    }
    
    if(Modo == derecha ){
            for(i=0;i<8;i++){
            LCD_dsPIC_SetCursor(i,FILA1);
            LCD_dsPIC_Print_String("PRUEBA DSPIC");
            __delay_ms(300);
            LCD_dsPIC_Clear();
            LCD_dsPIC_Home();
        }
    }
    
}
