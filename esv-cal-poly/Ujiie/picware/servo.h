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

#define SERVO_ANGLE_MAX_INDEX	90.0
#define SERVO_ANGLE_MID_INDEX	0.0
#define SERVO_ANGLE_MIN_INDEX	-90.0

#define	SERVO_DUTY_CYCLE_MAX			12500.0
#define	SERVO_DUTY_CYCLE_MID			SERVO_DUTY_CYCLE_MAX / 2.0
#define	SERVO_DUTY_CYCLE_MIN			0.0

#include "main.h"

void servo_task ( void );

void servo_setup ( void );

void servo_config_pwm ( void );

void servo_enable_pwm ( void );

void servo_disable_pwm ( void );

void servo_set_pwm ( unsigned int duty );

void servo_set_angle ( float angle );

void servo_set_zero ( void );

#endif
