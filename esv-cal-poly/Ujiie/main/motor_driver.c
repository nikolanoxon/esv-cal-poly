/**	==========================================================================
 *	File: motor_driver.c
 *	==========================================================================
 *
 *	History:
 *		2011-03-11 B. Ujiie file created.
 *
 *	Description:
 *		Sets motor driver abilities for the DC driving motor connected to the
 *		R/C truck.
 */

#include "motor_driver.h"

volatile unsigned int motor_register_max = 0;
volatile unsigned int motor_duty_cycle = 0;


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

void motor_task ( void )
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
	
	P1DC2 = motor_duty_cycle;
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

void motor_setup ( void )
{
	motor_config_pwm();

	motor_enable_pwm();
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

void motor_config_pwm ( void )
{	
	/*	Enable PWM1H for PWM output */
	PWM1CON1bits.PEN2H = 1;

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

void motor_enable_pwm ( void )
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

void motor_disable_pwm ( void )
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

void motor_set_pwm ( unsigned int duty )
{
	P1DC2 = duty;
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

void motor_set_speed ( float speed )
{
	unsigned int duty;
	float temp;
	float percent;
	float duty_cycle_percent;

	if ( speed > MOTOR_INPUT_MAX )
	{
		speed = MOTOR_INPUT_MAX;
	}
	else if ( speed < MOTOR_INPUT_MIN )
	{
		speed = MOTOR_INPUT_MIN;
	}

	if ( speed >= 0 )
	{
		percent = speed / ( MOTOR_INPUT_MAX - MOTOR_INPUT_MID );
	}
	else if ( speed < 0 )
	{
		percent = speed / ( MOTOR_INPUT_MID - MOTOR_INPUT_MIN );
	}

	if ( percent >= 0 )
	{
		duty_cycle_percent = percent * ( MOTOR_DUTY_CYCLE_MAX_PERCENT - MOTOR_DUTY_CYCLE_MID_PERCENT ) + MOTOR_DUTY_CYCLE_MID_PERCENT;
	}
	else if ( percent < 0 )
	{
		duty_cycle_percent = percent * ( MOTOR_DUTY_CYCLE_MID_PERCENT - MOTOR_DUTY_CYCLE_MIN_PERCENT ) + MOTOR_DUTY_CYCLE_MID_PERCENT;
	}

	temp = ( ( duty_cycle_percent / 100.0 ) * ( MOTOR_DUTY_CYCLE_MAX - MOTOR_DUTY_CYCLE_MIN ) ) + MOTOR_DUTY_CYCLE_MIN;

	duty = (unsigned int)temp;

	motor_set_pwm( duty );
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

void motor_set_brake ( float brake )
{

}
