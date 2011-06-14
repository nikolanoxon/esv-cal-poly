#ifndef _MAIN_H
#define _MAIN_H


#define TRUE	1
#define FALSE	0
#define FCY 	40000000ULL
#define PI		3.14159

typedef signed char		int8_t;
typedef short int		int16_t;
typedef int				int32_t;
typedef long int		int64_t;

typedef unsigned char		uint8_t;
typedef unsigned short int	uint16_t;
typedef unsigned int		uint32_t;
typedef unsigned long int	uint64_t;

#include <p33Fxxxx.h>
#include <libpic30.h>
#include <pps.h>
#include <qei.h>

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <delay.h>
#include <timer.h>
#include <uart.h>

#include "osc.h"
#include "uart1.h"
#include "uart2.h"
#include "motor.h"
#include "servo.h"
#include "helper.h"
#include "encoder.h"

int main ( void );			
void setup ( void );



void __attribute__((__interrupt__)) _T2Interrupt(void);


#endif
