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

void encoder_setup ( void );

void encoder_set_tire_radius ( float _radius );

float encoder_get_stepsize( void );

void encoder_read ( void );

#endif
