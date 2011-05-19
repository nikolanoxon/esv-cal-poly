/**	==========================================================================
 *	File: osc_driver.h
 *	==========================================================================
 *
 *	History:
 *		2010-08-13 T. Cooke file created.
 *
 *	Description:
 *		Sets up dsPIC33F to use internal fastRC with PPL
 *		to achieve an 80MHz / 40MIPS clock speed with no
 *		external oscillators.
 */


#ifndef	_OSC_H
#define _OSC_H

/** Include main register/port addressing file built into
 *	C30 compiler.
 */
#include	"p33FJ64MC202.h"

void ppl_setup(void);

#endif
