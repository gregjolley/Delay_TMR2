#include <xc.h>
#include "Delay_TMR2.h"

void TMR2_conf_delay(){
    T2CON = 0x0202;
    TMR2 = 0x00;
    PR2 = 0xFFFF;
}

void delay_TMR2_mS(unsigned int delay_mS){
    
    unsigned int    compare;
    unsigned int    condition = 1;
    
    if(delay_mS > 2000){        // The delay is limited to 2 S
        delay_mS = 2000;
    }
    
    compare = delay_mS*32;
    TMR2 = 0x00;
    
    T2CONbits.TON = 1;
    while(condition){
        if(TMR2 > compare){
            condition = 0;
        }
    }
    T2CONbits.TON = 0;
}

void delay_TMR2_mS32(unsigned int delay_mS32){
    
    unsigned int    compare;
    unsigned int    condition = 1;
    
    
    compare = delay_mS32;
    TMR2 = 0x00;
    
    T2CONbits.TON = 1;
    while(condition){
        if(TMR2 > compare){
            condition = 0;
        }
    }
    T2CONbits.TON = 0;
}
