/**	==========================================================================
 *	File: servo_driver.h
 *	==========================================================================
 *
 *	History:
 *		2011-03-11 B. Ujiie file created.
 *
 *	Description:
 *		Servo driver header file
 */

#ifndef	_SERVO_H
#define	_SERVO_H

#define	SERVO_DUTY_CYCLE_MAX_PERCENT	18.0
#define SERVO_DUTY_CYCLE_MID_PERCENT	14.0
#define SERVO_DUTY_CYCLE_MIN_PERCENT	10.0

#define SERVO_ANGLE_MAX_INDEX	30.0
#define SERVO_ANGLE_MID_INDEX	0.0
#define SERVO_ANGLE_MIN_INDEX	-30.0

#define SERVO_ANGLE_INT_MAX_INDEX 120.0
#define SERVO_ANGLE_INT_MIN_INDEX -120.0
#define SERVO_ANGLE_INT_MID_INDEX 0.0

#define	SERVO_DUTY_CYCLE_MAX			12500.0
#define	SERVO_DUTY_CYCLE_MID			SERVO_DUTY_CYCLE_MAX / 2.0
#define	SERVO_DUTY_CYCLE_MIN			0.0

#include "main.h"

void initServo( void );

void configServoPWM( void );

void enableServoPWM( void );

void disableServoPWM( void );

void setServoPWM( unsigned int );

void setServoAngleInt( int );

void setServoAngleInt2( int );

void setServoAngle( float );

void setServoZero( void );

#endif
