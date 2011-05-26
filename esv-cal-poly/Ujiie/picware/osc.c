#include "osc.h"

void initPPL(void)
{
	/*	Oscillator multipliers to acheive 80Mhz internal clock
	 *	speed.
	 */
	PLLFBD = 41;				// M=43 (PLL Feedback Divisor)
	CLKDIVbits.PLLPOST=0;		// N2=2	(PLL Postscaler)
	CLKDIVbits.PLLPRE=0;		// N1=2 (PLL Prescaler)


	/*	Initiate clock switch to Internal Free-Running Clock (FRC)
	 *	with PPL (NOSC = 0b001)
	 */
	__builtin_write_OSCCONH(0x01);
	__builtin_write_OSCCONL(0x01);


	/*	Wait for clock switch to occur. */
	while (OSCCONbits.COSC != 0b001);


	/*	Wait for PPL to lock */
	while(OSCCONbits.LOCK != 1) {};
}
