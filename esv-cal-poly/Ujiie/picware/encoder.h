/**	==========================================================================
 *	File: encoder_driver.h
 *	==========================================================================
 *
 *	History:
 *		2011-04-27 B. Ujiie file created.
 *
 *	Description:
 *		Encoder driver header file
 */

#ifndef	_ENCODER_H
#define	_ENCODER_H

#include "main.h"

void initEncoder( void );

void setEncoderWheelRadius( float );

void getEncoderStep( void );

void updateEncoder( int );

unsigned int getEncoderDel( int );
unsigned int getEncoderNew( int );
unsigned int getEncoderOld( int );
float getEncoderSpeed( int );

void __attribute__((__interrupt__)) _INT0Interrupt(void);
void __attribute__((__interrupt__)) _INT1Interrupt(void);

void __attribute__((__interrupt__)) _QEI1Interrupt(void);
void __attribute__((__interrupt__)) _QEI2Interrupt(void);

//void encoder_setup ( void );
//
//void encoder_set_tire_radius ( float _radius );
//
//float encoder_get_stepsize( void );

#endif
