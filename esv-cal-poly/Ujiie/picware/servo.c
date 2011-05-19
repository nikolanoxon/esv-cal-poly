/**	==========================================================================
 *	File: motor_driver.c
 *	==========================================================================
 *
 *	History:
 *		2011-03-11 B. Ujiie file created.
 *
 *	Description:
 *		Sets servo motor to steer hobby steering servo connected to the
 *		R/C truck.
 */

#include "servo.h"

volatile unsigned int servo_register_max = 0;
volatile unsigned int servo_duty_cycle = 0;


/** ==========================================================================
 *	Function: motor_task
 *	==========================================================================
 *
 *	History:
 *		2010-03-17 B. Ujiie function created.
 *
 *	Description:
 *		Controls the driving D/C motor in a task/state oriented manner to
 *		reduce processor hoarding by any one process.
 *
 *	Variable(s):
 *		@param void
 *		@return void
 */

void servo_task ( void )
{
	/*	Initialize motor task state. Note: "static" declaration keeps variable
	 *	from reinitializing the next time the function is called.
	 */
	static int state = 0;

	switch ( state )
	{
		case 0:	
			break;
		case 1:
			break;
		default:
			break;
	}
	
	P1DC1 = servo_duty_cycle;
}


/** ==========================================================================
 *	Function: motor_setup
 *	==========================================================================
 *
 *	History:
 *		2010-03-17 B. Ujiie function created.
 *
 *	Description:
 *		Sets up motor driver to run D/C motor at specified PWM signals.
 *
 *	Variable(s):
 *		@param void
 *		@return void
 */

void servo_setup ( void )
{
	servo_config_pwm();

	servo_enable_pwm();
}


/** ==========================================================================
 *	Function: motor_config_pwm
 *	==========================================================================
 *
 *	History:
 *		2010-03-17 B. Ujiie function created.
 *
 *	Description:
 *		Configure dsPIC motor driver PWM settings to control D/C driving
 *		motor.
 *
 *	Variable(s):
 *		@param int frequency
 *		@return void
 */

void servo_config_pwm ( void )
{	
	/*	Enable PWM1H for PWM output */
	PWM1CON1bits.PEN1H = 1;

	/**	===[Set PWM Frequency]==============================
	 *	The following pin/register values set the PWM signal
	 *	to output at 100Hz required by the R/C truck driving
	 *	motor and steering servo.
	 *	====================================================
	 */
	/* 	PWM Time Base Input Clock Prescaler */
	P1TCONbits.PTCKPS = 0b11;

	/*	PWM Time Based period value */
	P1TPERbits.PTPER = 6249;

	
	/**	==[End Set PWM Frequency]=========================== */
}


/** ==========================================================================
 *	Function: motor_enable_pwm
 *	==========================================================================
 *
 *	History:
 *		2010-03-17 B. Ujiie function created.
 *
 *	Description:
 *		Enable PWM to drive the D/C motor.
 *
 *	Variable(s):
 *		@param void
 *		@return void
 */

void servo_enable_pwm ( void )
{
	/*	PWM time base timer enabled */
	P1TCONbits.PTEN = 1;
}


/** ==========================================================================
 *	Function: motor_disable_pwm
 *	==========================================================================
 *
 *	History:
 *		2010-03-17 B. Ujiie function created.
 *
 *	Description:
 *		Disable PWM to drive the D/C motor.
 *
 *	Variable(s):
 *		@param void
 *		@return void
 */

void servo_disable_pwm ( void )
{
	/*	PWM time base timer disabled */
	P1TCONbits.PTEN = 0;
}


/** ==========================================================================
 *	Function: motor_set_pwm
 *	==========================================================================
 *
 *	History:
 *		2010-03-17 B. Ujiie function created.
 *
 *	Description:
 *		Set PWM based on an input percentage (0% - 100%).
 *
 *	Variable(s):
 *		@param signed long duty
 *		@return void
 */

void servo_set_pwm ( unsigned int duty )
{
	P1DC1 = duty;
}


/** ==========================================================================
 *	Function: motor_set_speed
 *	==========================================================================
 *
 *	History:
 *		2010-03-17 B. Ujiie function created.
 *
 *	Description:
 *		Set desired speed of the motor. This function will set the motor
 *		PWM to achieve the desired speed. This function will invoke 
 *		motor_set_pwm.
 *
 *	Variable(s):
 *		@param float speed
 *		@return void
 */

void servo_set_angle ( float angle )
{
	unsigned int duty;
	float temp;
	float percent;
	float duty_cycle_percent;

	/*	Angle saturation check */
	if ( angle > SERVO_ANGLE_MAX_INDEX )
	{
		angle = SERVO_ANGLE_MAX_INDEX;
	}
	else if ( angle < SERVO_ANGLE_MIN_INDEX )
	{
		angle = SERVO_ANGLE_MIN_INDEX;
	}

	if ( angle >= 0 )
	{
		percent = angle / ( SERVO_ANGLE_MAX_INDEX - SERVO_ANGLE_MID_INDEX );
	}
	else if ( angle < 0 )
	{
		percent = angle / ( SERVO_ANGLE_MID_INDEX - SERVO_ANGLE_MIN_INDEX );
	}

	if ( percent >= 0 )
	{
		duty_cycle_percent = percent * ( SERVO_DUTY_CYCLE_MAX_PERCENT - SERVO_DUTY_CYCLE_MID_PERCENT ) + SERVO_DUTY_CYCLE_MID_PERCENT;
	}
	else if ( percent < 0 )
	{
		duty_cycle_percent = percent * ( SERVO_DUTY_CYCLE_MID_PERCENT - SERVO_DUTY_CYCLE_MIN_PERCENT ) + SERVO_DUTY_CYCLE_MID_PERCENT;
	}

	temp = ( ( duty_cycle_percent / 100.0 ) * ( SERVO_DUTY_CYCLE_MAX - SERVO_DUTY_CYCLE_MIN ) ) + SERVO_DUTY_CYCLE_MIN;

	duty = (unsigned int)temp;

	servo_set_pwm( duty );
}


/** ==========================================================================
 *	Function: motor_set_brake
 *	==========================================================================
 *
 *	History:
 *		2010-03-17 B. Ujiie function created.
 *
 *	Description:
 *		Set the desired braking "force" based on brake pedal input. Note: The
 *		maximum brake input is less than the speed input to induce a feeling
 *		of gradual braking.
 *
 *	Variable(s):
 *		@param float brake
 *		@return void
 */

void servo_set_zero ( void )
{

}
