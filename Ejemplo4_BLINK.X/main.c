/*
 * File:   main.c
 * Author: abelh
 *
 * Created on 24 de diciembre de 2022, 12:42 AM
 */


#include "xc.h"
#include <libpic30.h>
#include <stdlib.h>


// FOSC
#pragma config FOSFPR = HS2_PLL16       // Oscillator (HS2 w/PLL 16x)
#pragma config FCKSMEN = CSW_ON_FSCM_OFF// Clock Switching and Monitor (Sw Enabled, Mon Disabled)

// FWDT
#pragma config FWPSB = WDTPSB_16        // WDT Prescaler B (1:16)
#pragma config FWPSA = WDTPSA_512       // WDT Prescaler A (1:512)
#pragma config WDT = WDT_OFF            // Watchdog Timer (Disabled)

// FBORPOR
#pragma config FPWRT = PWRT_4           // POR Timer Value (4ms)
#pragma config BODENV = BORV20          // Brown Out Voltage (Reserved)
#pragma config BOREN = PBOR_OFF         // PBOR Enable (Disabled)
#pragma config MCLRE = MCLR_EN          // Master Clear Enable (Enabled)

// FGS
#pragma config GWRP = GWRP_OFF          // General Code Segment Write Protect (Disabled)
#pragma config GCP = CODE_PROT_OFF      // General Segment Code Protection (Disabled)

// FICD
#pragma config ICS = ICS_PGD            // Comm Channel Select (Use PGC/EMUC and PGD/EMUD)

//FIN = 20MHz/2 = 10MHz
//PLL x 16 => 10MHz * 16 = 160MHz => FOSC
//FCY = FOSC/4 = 160MHz/4 = 40MHz

#define FCY 40000000UL 
int main(void) {
    ADPCFG = 0x1FFF;
    TRISB = 0;
    LATB = 0;
    while(1){
        LATBbits.LATB0 = 1;
        __delay_ms(200);
        LATBbits.LATB0 = 0;
        __delay_ms(200);
    }
    
    return 0;
}
