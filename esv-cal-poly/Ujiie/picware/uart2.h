/**	==========================================================================
 *	File: uart1.h
 *	==========================================================================
 *
 *	History:
 *		2010-08-13 T. Cooke file created.
 *
 *	Description:
 *		UART1 program header file.
 */

#ifndef 	_UART2_H
#define 	_UART2_H

/*	Nifty header that automatically loads the right chip header as set in
 *	configure:select_device.
 */


#include 	<p33Fxxxx.h> 

/*	Include the main header for the program */
#include	"main.h"

/*	Header included from the C30 compiler */
#include 	<libpic30.h>

/*	Headers from the C programming language. Note: uart.h is an important
 *	header to include for this file.
 */
#include 	<stdio.h>
#include 	<uart.h>
#include	<delay.h>							

#define SCALE 3080L

void __attribute__( ( interrupt, no_auto_psv ) ) _U2TXInterrupt( void );
void __attribute__( ( interrupt, no_auto_psv ) ) _U2RXInterrupt( void );
void print_uart2( const char string[] );
void start_uart2( unsigned long baudrate );

#endif
