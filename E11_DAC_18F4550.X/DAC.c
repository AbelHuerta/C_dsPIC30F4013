
#include "DAC.h"


void MCP4725_WriteComand(uint16_t data){
    uint8_t high;
    uint8_t low;
    
    I2C_Start();
    //DIRECCION DEL DISPOSITIVO (A2=0,A1=0,A0=0)
    I2C_ADDRESS_SLAVE(DIREC_MCP4725,I2C_WRITE);
    I2C_Write_Data(0b01000000);
    high = (data >> 4); //(C2=0;C1=1;C0=0) ;Write DAC Register
    low = (data & 0b1111)<<4;
    
    I2C_Write_Data(high);
    I2C_Write_Data(low);
    
    I2C_Stop();
    
}
/*
uint16_t MCP4725_LCD(uint16_t data){
    uint8_t high;
    uint8_t low;
    uint16_t valor;
    
    high = (data >> 4); //(C2=0;C1=1;C0=0) ;Write DAC Register
    low = (data & 0b1111)<<4;
    
    
    return valor;
}
*/


