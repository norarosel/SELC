#include <xc.h>

#define CALC_PR 39999
#ifdef __MPLAB_DEBUGGER_SIMULATOR 
#define PR_VAL ((CALC_PR+1)/1000-1)
#else
#define PR_VAL CALC_PR
#endif

void timer2_start() {
    TMR2 = 0;
    PR2 = PR_VAL;
    T2CON = 0x8000;
}

void timer2_reset() {
    PR2 = PR2/2;
    TMR2 = 0;
    IFS0CLR = _IFS0_T2IF_MASK;
}
