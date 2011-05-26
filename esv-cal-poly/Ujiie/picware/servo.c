#include "servo.h"


void initServo ( void )
{
	configServoPWM();
	enableServoPWM();
}

void configServoPWM( void )
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

void enableServoPWM( void )
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

void disableServoPWM( void )
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

void setServoPWM( unsigned int duty )
{
	P1DC1 = duty;
}

void floater( int angle ) {
	float percent;
	float fangle;
	float temp;
	unsigned int duty;
	fangle = (float)angle;
	percent = fangle/240.0;
	temp = percent*( 2100.0 - 1400.0) + 1400.0;
	duty = (unsigned int)temp;
}

void setServoAngleInt( unsigned int angle ) {
	float percent;
	float fangle;
	float temp;
	unsigned int duty;
	angle = angle + 120;
	fangle = (float)angle;
	percent = fangle/240.0;
	temp = 2100.0 - percent*( 2100.0 - 1400.0);
	duty = (unsigned int)temp;
	setServoPWM( duty );
}


void setServoAngleInt2( int angle ) {
	float fAngle = (float)angle;
	float setAngle = 0.0;
	float fPercent = 0.0;
	float angleSpan = 0.0;
	if( fAngle < 0.0 ) {
		fPercent = fAngle / ( SERVO_ANGLE_INT_MID_INDEX - SERVO_ANGLE_INT_MIN_INDEX );
		angleSpan = fPercent * ( SERVO_ANGLE_MID_INDEX - SERVO_ANGLE_MIN_INDEX );
		setAngle = SERVO_ANGLE_MID_INDEX + angleSpan;
	} else if( fAngle > 0.0 ) {
		fPercent = fAngle / ( SERVO_ANGLE_INT_MAX_INDEX - SERVO_ANGLE_INT_MID_INDEX );
		angleSpan = fPercent * ( SERVO_ANGLE_MAX_INDEX - SERVO_ANGLE_MID_INDEX );
		setAngle = SERVO_ANGLE_MID_INDEX + angleSpan;
	} else {
		setAngle = 0.0;
	}

	setServoAngle( setAngle );
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

void setServoAngle ( float angle )
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

	setServoPWM( duty );
}

void setServoZero( void )
{

}
