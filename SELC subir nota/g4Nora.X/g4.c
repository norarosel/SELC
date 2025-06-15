#include <xc.h>

void
delay(int loops) {
    while(loops--);
}

int main () {
  TRISACLR = 0x0400;
  while (1) {
    IFS0bits.INT4IF = 0;
    while (!IFS0bits.INT4IF);
    PORTAINV = 0x0400;
    delay(1000);  //Anti-rebote
  }
  return 1;
}

