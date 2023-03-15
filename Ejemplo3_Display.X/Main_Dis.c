/* 
 * File:   Main_Dis.c
 * Author: LENOVO
 *
 * Created on 20 de septiembre de 2021, 08:41 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Configuracion.h"
#include <libpic30.h>
#include <p33FJ32MC204.h>

void Ejemplo4(void);
void Ejemplo3(void);
void Ejemplo2(void);
void Ejemplo1(void);

uint16_t Display_16Seg[11]  = {0xFF00,0XDDFF,0X7788,0X77C0,0X7773,0x7744,0x7704,0x33FC,0X7700,0X7740,0XDD21 };
uint8_t Display_7Seg_A[10] = {0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};
//uint8_t Display_7Seg_C[10] = {0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};
uint8_t Display7seg_7447[10]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09};
uint8_t i,j=0;
uint8_t unidades,decenas=0;
uint8_t Cuenta= 0;
int main(int argc, char** argv) {

   AD1PCFGL  = 0X01FF; 
   TRISB = 0X00;
   TRISC &= ~(1<<0) & ~(1<<1);
   LATC &= ~(1<<0) & ~(1<<1); 
   LATB  = Display_7Seg_A[0];

    for(;;){
        unidades = Cuenta%10;
        decenas = Cuenta/10;
        for(i=0;i<255;i++){
            LATB = Display_7Seg_A[unidades];
            LATC &= ~(1<<1);//habilitar las unidades
        __delay_ms(1);
            LATC |= (1<<1);
            
             LATB = Display_7Seg_A[decenas];
            LATC &= ~(1<<0);
            __delay_ms(1);
             LATC |= (1<<1);
        }   
        Cuenta++;
        if(Cuenta == 100) Cuenta=0;
        
    
    }
    
    
    
    
    return (EXIT_SUCCESS);
}
void Ejemplo4(void){
 AD1PCFGL  = 0X01FF; 
   TRISA |= (1<<0) | (1<<1);
   TRISB = 0X00;
   TRISC = 0X00;
   LATB  = Display7seg_7447[0];
   LATC = Display7seg_7447[0];
    for(;;){
  
          for(i=0;i<10;i++){
             for(j=0;j<10;j++){
                 LATB = Display7seg_7447[j];
                 LATC = Display7seg_7447[i];
                 __delay_ms(200);
        }
       }
     
    }
}

void Ejemplo3(void){
   AD1PCFGL  = 0X01FF; 
   TRISA |= (1<<0) | (1<<1);
   TRISB = 0X00;
   TRISC = 0X00;
   LATB  = Display_7Seg_A[0];
   LATC = Display_7Seg_A[0];
    for(;;){
  
        if((PORTA &(1<<0))==0){
            while((PORTA &(1<<0))==0);
            unidades++;
            if(unidades == 10){
                unidades=0;
                decenas++;
            }
            if(decenas == 10) decenas=0; 
        }
        
        if((PORTA &(1<<1))!=0){
            while((PORTA &(1<<1))!=0);
            unidades--;
            if((decenas ==0 )&& (unidades == 255)){
                unidades = 0;
            }
            if((decenas>0)&&(unidades ==255)){
                unidades = 9;
                decenas--;
            }
        }
        
          LATB  = Display_7Seg_A[unidades];
          LATC = Display_7Seg_A[decenas];
     
    }

}
void Ejemplo2(void){
   AD1PCFGL  = 0X01FF; 
   TRISB = 0X00;
   TRISC = 0X00;
   LATB  = Display_7Seg_A[0];
   LATC = Display_7Seg_A[0];
    for(;;){
  
        for(i=0;i<10;i++){
             for(j=0;j<10;j++){
                 LATB = Display_7Seg_A[j];
                 LATC = Display_7Seg_A[i];
                 __delay_ms(200);
        }
       }
        
    }

}
void Ejemplo1(void){
 AD1PCFGL  = 0X01FF; 
   TRISB = 0X0000; 
   LATB = Display_16Seg[0];
   
    for(;;){
        LATB = Display_16Seg[i];
        __delay_ms(500);
        i++;
        if(i==11) i=0;
        
    }
    

}