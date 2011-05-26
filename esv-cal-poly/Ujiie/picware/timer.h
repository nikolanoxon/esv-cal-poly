#ifndef _TIMER_H
#define _TIMER_H

#include <p33Fxxxx.h> 

/*	Include the main header for the program */
#include "main.h"

/*	Header included from the C30 compiler */
#include <libpic30.h>

#include <stdio.h>
#include <uart.h>
#include <delay.h>

void initTimer( void );
void __attribute__((__interrupt__)) _T2Interrupt( void );

#endif
