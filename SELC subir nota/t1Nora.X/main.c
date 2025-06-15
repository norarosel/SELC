#include <xc.h>
#include "timer.h"
#include "pinguino.h"

void timer_setup () {
//Interrupt with frequency 1KHz
//Hacer en casa
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

int main (void) {
  gpio_setup();  
  timer2_start();
  
  while (1) {
      if (BUT1_PRESSED()) {
        timer2_reset();
        LEDR_INV();
      
    }
  }
  return 1;
}
