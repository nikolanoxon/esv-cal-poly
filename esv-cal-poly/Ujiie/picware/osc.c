/**	==========================================================================
 *	File: osc_driver.c
 *	==========================================================================
 *
 *	History:
 *		2010-08-13 T. Cooke file created.
 *
 *	Description:
 *		Sets up dsPIC33F to use internal fastRC with PLL
 *		to acheive an 80MHz / 40MIPS clock speed with no
 *		external oscillators.
 */

/**	All other include files for osc_driver.c are defined
 *	in this file.
 */
#include "osc.h"


/**	==========================================================================
 *	Function: ppl_setup
 *	==========================================================================
 *
 *	History:
 *		2010-08-13 T. Cooke function created.
 *
 *	Description:
 *		Sets up the prescaler, postscaler, and PLL divisor
 *		to achieve a clock speed of 80MHz running on the
 *		internal fastRC oscillator. The function will not exit
 *		until PPL has locked (sped up to desired frequency).	
 *
 *	Variable(s):
 *		@param	void
 *		@return	void
 */

void ppl_setup(void)
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
