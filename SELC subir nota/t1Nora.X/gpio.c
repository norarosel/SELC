#include <xc.h>
#include "pinguino.h"

void gpio_setup() {
  //RB7 como entrada digital (no puede ser anal�gica)
  //ANSELBCLR = BUT1_MASK;
  TRISBSET = BUT1_MASK;
    
  //RC5 como salida digital (no puede ser anal�gica)
  //ANSELCCLR = LEDR_MASK; 
  LATCSET = LEDR_MASK;
  TRISCCLR = LEDR_MASK;
}
