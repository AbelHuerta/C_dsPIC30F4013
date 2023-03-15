#include "Dspic_LCD.h"
#include <stdint.h>
#include "Configuracion.h"
#include <libpic30.h>

Ubicacion Cursor = FILA1;
void LCD_dsPIC_Databus(uint8_t a){
    //0000 0001
    if(a & 0x01){
        D4 = 1;
    }else{
        D4 = 0;
    }
    
    //0000 0010
    if(a & 0x02){
        D5 = 1;
    }else{
        D5 = 0;
    }
    
    //0000 0100
    if(a & 0x04){
        D6 = 1;
    }else{
        D6 = 0;
    }
    
    //0000 1000
    if(a & 0x08){
        D7 = 1;
    }else{
        D7 = 0;
    }
}

void LCD_dsPIC_cmd(uint8_t a){
    E = 0;
    E = 1;
    LCD_dsPIC_Databus(a); //DATOS
    __delay_ms(2);
    E = 0;
}

void LCD_dsPIC_Init(void){
    
    TRISB &= ~(1<<0) & ~(1<<1) & ~(1<<2) & ~(1<<3) & ~(1<<4) & ~(1<<5); //SALIDAS
    LATB &= ~(1<<0) & ~(1<<1) & ~(1<<2) & ~(1<<3) & ~(1<<4) & ~(1<<5);  //INICIALIZA EN 0
    
    LCD_dsPIC_cmd(0x03);
    
    LCD_dsPIC_cmd(0x03);
    
    LCD_dsPIC_cmd(0x03);
    
    LCD_dsPIC_cmd(0x02);
    LCD_dsPIC_cmd(0x02);
    LCD_dsPIC_cmd(0x08);
    LCD_dsPIC_cmd(0x00);
    LCD_dsPIC_cmd(0x08);
    LCD_dsPIC_cmd(0x00);
    LCD_dsPIC_cmd(0x01);
    LCD_dsPIC_cmd(0x00);
    LCD_dsPIC_cmd(0x0C); //DISTINTO AL DATASHEET
    
}

void LCD_dsPIC_SetCursor(uint8_t x,uint8_t y){
    RS = 0;
    uint8_t m,n;
    switch(y){
        case FILA1:
            m = 0x80+x;
            n = (0x80+x)>>4; //D0 D1 D2 D3 (D4 D5 D6 D7)     
            LCD_dsPIC_cmd(n);
            LCD_dsPIC_cmd(m);
            break;
        case FILA2:
            m = 0xC0+x;
            n = (0xC0+x)>>4; //D0 D1 D2 D3 (D4 D5 D6 D7)     
            LCD_dsPIC_cmd(n);
            LCD_dsPIC_cmd(m);
            break;
        case FILA3:
            m = 0x94+x;
            n = (0x94+x)>>4; //D0 D1 D2 D3 (D4 D5 D6 D7)     
            LCD_dsPIC_cmd(n);
            LCD_dsPIC_cmd(m);
            break;
        case FILA4:
            m = 0xD4+x;
            n = (0xD4+x)>>4; //D0 D1 D2 D3 (D4 D5 D6 D7)     
            LCD_dsPIC_cmd(n);
            LCD_dsPIC_cmd(m);
            break;
    }
}

void LCD_dsPIC_Print_Char(char a){
    uint8_t m,n;
    m = a>>4;
    n = a;
    RS = 1;
    LCD_dsPIC_cmd(m);
    LCD_dsPIC_cmd(n);
}

void LCD_dsPIC_Print_String(char *a){
    char *ptr;
    ptr = a;
    while(*ptr){
    LCD_dsPIC_Print_Char(*ptr++);
    }
}

void LCD_dsPIC_Clear(void){
    RS=0;
    LCD_dsPIC_cmd(0x00);
    LCD_dsPIC_cmd(0x01);
}

void LCD_dsPIC_Home(void){
    RS=0;
    LCD_dsPIC_cmd(0x00);
    LCD_dsPIC_cmd(0x02);
}