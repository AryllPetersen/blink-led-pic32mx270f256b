/*
    Author: Aryll Petersen
    Creation Date: 6/9/26 5:59 pm 
*/

#include <xc.h> // MCU library
#include "config.h" // device configuration

// __delay_ms(): Creates a delay
// Code from https://forum.microchip.com/s/topic/a5C3l000000Md3kEAC/t380199
#define _XTAL_FREQ 16000000 // 16MHz Primary Oscillator
#define TICK_PER_MS (_XTAL_FREQ/2/1000)
void __delay_ms(uint32_t ms)
{
    uint32_t Start=_CP0_GET_COUNT();
    uint32_t Duration=TICK_PER_MS*ms;
    while((_CP0_GET_COUNT()-Start)<Duration);
}

int main() {
    ANSELAbits.ANSA0 = 0; // Set RA0 to be digital
    TRISAbits.TRISA0 = 0; // Set RA0 to be output
    
    while (1) {
        LATAbits.LATA0 = 1; // Drive RA0 High
        __delay_ms(1000); // 1s delay
        LATAbits.LATA0 = 0; // Drive RA0 Low
        __delay_ms(1000); // 1s delay
    }
    
    return 0;
}