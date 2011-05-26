/**	==========================================================================
 *	File: motor_driver.h
 *	==========================================================================
 *
 *	History:
 *		2011-03-11 B. Ujiie file created.
 *
 *	Description:
 *		Motor driver header file
 */

#ifndef	_MOTOR_H
#define	_MOTOR_H

#define MOTOR_INPUT_MAX	100.0
#define MOTOR_INPUT_MID	0.0
#define	MOTOR_INPUT_MIN -100.0

#define	MOTOR_DUTY_CYCLE_MAX_PERCENT	20.0
#define MOTOR_DUTY_CYCLE_MID_PERCENT	15.0
#define MOTOR_DUTY_CYCLE_MIN_PERCENT	10.0

#define MOTOR_THROTTLE_INT_MAX_INDEX 120.0
#define MOTOR_THROTTLE_INT_MIN_INDEX -120.0
#define MOTOR_THROTTLE_INT_MID_INDEX 0.0

#define	MOTOR_DUTY_CYCLE_MAX	12500.0
#define	MOTOR_DUTY_CYCLE_MID	MOTOR_DUTY_CYCLE_MAX / 2.0
#define	MOTOR_DUTY_CYCLE_MIN	0.0

#include "main.h"

void initMotor( void );

void configPWM( void );

void enablePWM( void );

void disablePWM( void );

void setMotorPWM( unsigned int );

void setMotorSpeedInt( int );

void setMotorSpeed( float );

void setMotorBrake( float );

#endif
