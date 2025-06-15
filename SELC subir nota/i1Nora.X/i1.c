#include <xc.h>
#include <sys/attribs.h>	//ISR MACRO

#ifdef __MPLAB_DEBUGGER_SIMULATOR
#define WAIT()
#else
#define WAIT() asm volatile("wait")
#endif

#define GIE()  asm volatile("ei")
#define GID()  asm volatile("di")

void timer_setup () {
    T2CON= 0x000;
    PR2 = 39999;
    IFS0bits.T2IF= 0;
    IEC0bits.T2IE = 1;
    IPC2bits.T2IP = 5;
    INTCONSET = _INTCON_MVEC_MASK;
    GIE();
}
volatile int tick = 0;
void __ISR(_TIMER_2_VECTOR, IPL5AUTO) timer2_ISR (void) {
IFS0bits.T2IF = 0;
tick++;
}
void led_setup() {
TRISACLR = 0x0400; //LED as output
TRISBCLR = 0x8000;
ANSELBCLR = 0x8000;
}

int main () {
int timeout_led1, timeout_led2;
timeout_led1 = tick + 200; //Now + 200 (period for LED1)
timeout_led2 = tick + 250; //Now + 250 (period for LED2)
led_setup();
timer_setup();
GIE();
while (1) {
if (tick > timeout_led1) {
PORTAINV = 0x0400;
//Add instruction to be periodic
} else if (tick > timeout_led2) {
PORTBINV = 0x8000;
//Add instruction to be periodic
} else {
WAIT();
}
}
}