
#ifndef TIMER_H
#define	TIMER_H

#ifdef	__cplusplus
extern "C" {
#endif

#define TIMER2_ENDED() (IFS0&_IFS0_T2IF_MASK)
    
void timer2_start();
void timer2_reset();

#ifdef	__cplusplus
}
#endif

#endif	/* TIMER_H */

