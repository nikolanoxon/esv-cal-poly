#include "motor.h"

void initMotor( void ) {
	configMotorPWM();
	enableMotorPWM();
}

void configMotorPWM( void ) {	
	PWM1CON1bits.PEN2H = 1;
	P1TCONbits.PTCKPS = 0b11;
	P1TPERbits.PTPER = 6249;
}

void enableMotorPWM( void ) {
	P1TCONbits.PTEN = 1;
}

void disableMotorPWM( void ) {
	P1TCONbits.PTEN = 0;
}

void setMotorPWM( unsigned int duty ) {
	P1DC2 = duty;
}

void setMotorSpeedInt( unsigned int angle ) {
	float percent;
	float fangle;
	float temp;
	unsigned int duty;
	fangle = (float)angle;
	percent = fangle/240.0;
	temp = 2100.0 - percent*( 2100.0 - 1400.0);
	duty = (unsigned int)temp;
	setMotorPWM( duty );
}

void setMotorSpeedInt2( int speed ) {
	float fThrottle = (float)speed;
	float setThrottle = 0.0;
	float fPercent = 0.0;
	float throttleSpan = 0.0;
	if( fThrottle < 0.0 ) {
		fPercent = fThrottle / ( MOTOR_THROTTLE_INT_MID_INDEX - MOTOR_THROTTLE_INT_MIN_INDEX );
		throttleSpan = fPercent * ( MOTOR_INPUT_MID - MOTOR_INPUT_MIN );
		setThrottle = MOTOR_INPUT_MID + throttleSpan;
	} else if( fThrottle > 0.0 ) {
		fPercent = fThrottle / ( MOTOR_THROTTLE_INT_MAX_INDEX - MOTOR_THROTTLE_INT_MID_INDEX );
		throttleSpan = fPercent * ( MOTOR_INPUT_MAX - MOTOR_INPUT_MID );
		setThrottle = MOTOR_INPUT_MID + throttleSpan;
	} else {
		setThrottle = 0.0;
	}

	setMotorSpeed( setThrottle );
}


void setMotorSpeed ( float speed ) {
	unsigned int duty;
	float temp;
	float percent;
	float dutyCyclePercent;

	if ( speed > MOTOR_INPUT_MAX ) {
		speed = MOTOR_INPUT_MAX;
	} else if ( speed < MOTOR_INPUT_MIN ) {
		speed = MOTOR_INPUT_MIN;
	}

	if ( speed >= 0 ) {
		percent = speed / ( MOTOR_INPUT_MAX - MOTOR_INPUT_MID );
	} else if ( speed < 0 ) {
		percent = speed / ( MOTOR_INPUT_MID - MOTOR_INPUT_MIN );
	}

	if ( percent >= 0 ) {
		dutyCyclePercent = percent * ( MOTOR_DUTY_CYCLE_MAX_PERCENT - MOTOR_DUTY_CYCLE_MID_PERCENT ) + MOTOR_DUTY_CYCLE_MID_PERCENT;
	} else if ( percent < 0 ) {
		dutyCyclePercent = percent * ( MOTOR_DUTY_CYCLE_MID_PERCENT - MOTOR_DUTY_CYCLE_MIN_PERCENT ) + MOTOR_DUTY_CYCLE_MID_PERCENT;
	}

	temp = ( ( dutyCyclePercent / 100.0 ) * ( MOTOR_DUTY_CYCLE_MAX - MOTOR_DUTY_CYCLE_MIN ) ) + MOTOR_DUTY_CYCLE_MIN;

	duty = (unsigned int)temp;

	setMotorPWM( duty );
}

void setMotorBrake( float brake ) {

}
