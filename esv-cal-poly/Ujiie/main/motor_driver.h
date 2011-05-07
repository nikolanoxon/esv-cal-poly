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

#ifndef	_MOTOR_DRIVER_H
#define	_MOTOR_DRIVER_H

#define MOTOR_INPUT_MAX	100.0
#define MOTOR_INPUT_MID	0.0
#define	MOTOR_INPUT_MIN -100.0

#define	MOTOR_DUTY_CYCLE_MAX_PERCENT	20.0
#define MOTOR_DUTY_CYCLE_MID_PERCENT	15.0
#define MOTOR_DUTY_CYCLE_MIN_PERCENT	10.0

#define	MOTOR_DUTY_CYCLE_MAX	12500.0
#define	MOTOR_DUTY_CYCLE_MID	MOTOR_DUTY_CYCLE_MAX / 2.0
#define	MOTOR_DUTY_CYCLE_MIN	0.0

#include "main.h"

void motor_task ( void );

void motor_setup ( void );

void motor_config_pwm ( void );

void motor_enable_pwm ( void );

void motor_disable_pwm ( void );

void motor_set_pwm ( unsigned int duty );

void motor_set_speed ( float speed );

void motor_set_brake ( float brake );

#endif
