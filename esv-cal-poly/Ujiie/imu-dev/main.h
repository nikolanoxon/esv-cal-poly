/**	==========================================================================
 *	File: main.h
 *	==========================================================================
 *
 *	History:
 *		2010-08-13 T. Cooke file created.
 *
 *	Description:
 *		Main program header file.
 */

#ifndef	_MAIN_H
#define	_MAIN_H


/*	Define boolean logic. C programming language does not have true or false
 *	boolean logic terms "true" or "false."
 */
#define TRUE	1
#define FALSE	0

typedef signed char		int8_t;
typedef short int		int16_t;
typedef int				int32_t;
typedef long int		int64_t;

typedef unsigned char		uint8_t;
typedef unsigned short int	uint16_t;
typedef unsigned int		uint32_t;
typedef unsigned long int	uint64_t;



/*	Header that automatically loads correct chip header based
 *	on what is set in the configure:select_device of MPLAB IDE
 */
#include 	<p33Fxxxx.h>


/*	Header file that configures the internal oscillator to run at the specified
 *	frequency. For this particular application the microcontroller will run at
 *	approximately 80Mhz.
 */
#include 	"osc_driver.h"


/*	Define oscillator clock speed. Note: This definition must
 *	be called before calling/including libpic30 to use blocking
 *	delay routines.
 */
#define 	FCY 40000000ULL


/*	dsPIC C30 compiler specific header files. Note: pps.h includes the macros to
 *	unlock Peripheral Pin Select remapping to enable motor drivers, quadrature
 *	encoder chips, etc.
 */
#include 	<libpic30.h>
#include 	<pps.h>


/*	Standard C compiler libraries */
#include 	<stdlib.h>
#include 	<stdio.h>
#include 	<math.h>
#include 	<float.h>
#include	<delay.h>
#include	<timer.h>


/*	Programmer specified header files for each component driver. */
#include	"uart1.h"
#include	"uart2.h"
#include	"helper_driver.h"

/* Define constant Pi */
#define PI 3.14159

int main ( void );			//	Main program
void setup_IO ( void );		//	Input/Output setup

#endif
