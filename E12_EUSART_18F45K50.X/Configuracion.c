#include "Configuracion.h"

volatile uint8_t  *const pOSCCON_REG = ((volatile uint8_t *)0xFD3);

//Desarrollo de funciones
void OSC_16Mhz_Init(void){   
    //Configurar el oscilador interno
    *pOSCCON_REG &= ~(1<<0);
    *pOSCCON_REG |=  (1<<1);
    //Configurar la frecuencia
    *pOSCCON_REG |=  (1<<4) | (1<<5) | (1<<6); 
}
