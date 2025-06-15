

#ifndef PINGUINO_H
#define	PINGUINO_H

#ifdef	__cplusplus
extern "C" {
#endif

#define BUT1_MASK 0x0080
#define BUT1_PRESSED() !(PORTB&BUT1_MASK)

#define LEDR_MASK 0x0020
#define LEDR_INV() PORTCINV=LEDR_MASK

void gpio_setup();

#ifdef	__cplusplus
}
#endif

#endif	/* PINGUINO_H */

