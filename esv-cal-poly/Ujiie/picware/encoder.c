#include "encoder.h"

float wheelRadius = 0.0;
float wheelCircumference = 0.0;
float encoderStepsize;

float totalTicks = 8.0; // number of ticks on encoder wheel

unsigned int encoder1counter = 0;
unsigned int encoder2counter = 0;

unsigned int encoder1max = 250;
unsigned int encoder2max = 250;

unsigned int qei1max = 250;
unsigned int qei2max = 250;

unsigned int qei1counter = 0;
unsigned int qei2counter = 0;

float encoderUnit;
float delTime = 0.0086 * 116.0;

typedef struct {
	uint8_t new;
	uint8_t old;
	uint8_t del;
	float speed;
} QEI;

typedef struct {
	uint8_t new;
	uint8_t old;
	uint8_t del;
	float speed;
} Encoder;

Encoder encoder1 = {0, 0, 0, 0.0};
Encoder encoder2 = {0, 0, 0, 0.0};

QEI qei1 = {0, 0, 0, 0.0};
QEI qei2 = {0, 0, 0, 0.0}; 

void initEncoder ( void )
{
	/*	Enable QEI interrupts */
	ConfigIntQEI1(QEI_INT_PRI_1 & QEI_INT_DISABLE);

	POS1CNT = 0;         //reset POS1CNT register
	MAX1CNT = 360;	     //Set point to reset POS1CNT counter

	/*	Open QEI connection */
	OpenQEI1(QEI_INT_CLK & QEI_INDEX_RESET_DISABLE & 

            QEI_CLK_PRESCALE_256 & 

            QEI_GATED_ACC_DISABLE & QEI_INPUTS_NOSWAP &

            QEI_MODE_x4_MATCH & QEI_DIR_SEL_CNTRL &  

            QEI_IDLE_CON, 0);

	//This QEI config bit needs separate line because it's not
	//included in OpenQEI1 function. Need to explain...
    QEI1CONbits.UPDN = 1;



	/*	Enable QEI interrupts */
	ConfigIntQEI2(QEI_INT_PRI_1 & QEI_INT_DISABLE);

	POS2CNT = 0;         //reset POS1CNT register
	MAX2CNT = 360;	     //Set point to reset POS1CNT counter

	/*	Open QEI connection */
	OpenQEI2(QEI_INT_CLK & QEI_INDEX_RESET_DISABLE & 

            QEI_CLK_PRESCALE_256 & 

            QEI_GATED_ACC_DISABLE & QEI_INPUTS_NOSWAP &

            QEI_MODE_x4_MATCH & QEI_DIR_SEL_CNTRL &  

            QEI_IDLE_CON, 0);

	//This QEI config bit needs separate line because it's not
	//included in OpenQEI1 function. Need to explain...
    QEI2CONbits.UPDN = 1;
}



void setEncoderWheelRadius ( float _radius )
{
	wheelRadius = _radius;
	wheelCircumference = (2.0 * 3.14159 * wheelRadius);
}

float getEncoderStepsize ( void ) {
	encoderStepsize = ( wheelCircumference / totalTicks ); // ft/ticks
	return encoderStepsize;
}

void updateEncoder( int _encoder ) {

	encoderUnit = getEncoderStepsize();
	float del = 0.0;

	if( _encoder == 1 ) {
		encoder1.new = encoder1counter;
		encoder1.del = encoder1.new - encoder1.old;
		del = (float)encoder1.del;
		encoder1.speed = (del * encoderUnit * (1.0 /5280.0) * (1.0 / delTime) * 3600.0);

	//	printf("New: %d\tOld: %d\tDel: %d\tUnit: %.2f\tTime: %.2f\tSpeed: %.2f\n",encoder1.new,encoder1.old,encoder1.del,encoderUnit,delTime,encoder1.speed); 
		encoder1.old = encoder1.new;
	}else if( _encoder == 2 ) {
		encoder2.new = encoder2counter;
		encoder2.del = encoder2.new - encoder2.old;
		del = (float)encoder2.del;
		encoder2.speed = (del * encoderUnit * (1.0 /5280.0) * (1.0 / delTime) * 3600.0);

	//	printf("New: %d\tOld: %d\tDel: %d\tUnit: %.2f\tTime: %.2f\tSpeed: %.2f\n",encoder2.new,encoder2.old,encoder2.del,encoderUnit,delTime,encoder2.speed); 
		encoder2.old = encoder2.new;
	}else if( _encoder == 3 ) {
		qei1.new = qei1counter;
		qei1.del = qei1.new - qei1.old;
		del = (float)qei1.del;
		qei1.speed = (del * encoderUnit * (1.0 / 5280.0) * (1.0 / delTime) * 3600.0);

	//	printf("New: %d\tOld: %d\tDel: %d\tUnit: %.2f\tTime: %.2f\tSpeed: %.2f\n",qei1.new,qei1.old,qei1.del,encoderUnit,delTime, qei1.speed); 
		qei1.old = qei1.new;
	}else if( _encoder == 4 ) {
		qei2.new = qei2counter;
		qei2.del = qei2.new - qei2.old;
		del = (float)qei2.del;
		qei2.speed = (del * encoderUnit * (1.0 / 5280.0) * (1.0 / delTime) * 3600.0);
	// 	printf("New: %d\tOld: %d\tDel: %d\tUnit: %.2f\tTime: %.2f\tSpeed: %.2f\n",qei2.new,qei2.old, qei2.del,encoderUnit,delTime,qei2.speed); 
		qei2.old = qei2.new;
	}else{
		// Do nothing
	}
}

unsigned int getEncoderDel( int _encoder ) {
	
	unsigned int temp = 0;

	if( _encoder == 1 ) {
		temp = encoder1.del;
	}else if( _encoder == 2 ) {
		temp = encoder2.del;
	}else if( _encoder == 3 ) {
		temp = qei1.del;
	}else if( _encoder == 4 ) {
		temp = qei2.del;
	}else{
		// Do nothing
	}
	return temp;
}

unsigned int getEncoderNew( int _encoder ) {

	unsigned int temp = 0;

	if( _encoder == 1 ) {
		temp = encoder1.new;
	}else if( _encoder == 2 ) {
		temp = encoder2.new;
	}else if( _encoder == 3 ) {
		temp = qei1.new;
	}else if( _encoder == 4 ) {
		temp = qei2.new;
	}else{
		// Do nothing
	}
	return temp;
}

unsigned int getEncoderOld( int _encoder ) {

	unsigned int temp = 0;

	if( _encoder == 1 ) {
		temp = encoder1.old;
	}else if( _encoder == 2 ) {
		temp = encoder2.old;
	}else if( _encoder == 3 ) {
		temp = qei1.old;
	}else if( _encoder == 4 ) {
		temp = qei2.old;
	}else{
		// Do nothing
	}
	return temp;
}

float getEncoderSpeed( int _encoder ) {

	float temp = 0;

	if( _encoder == 1 ) {
		temp = encoder1.speed;
	}else if( _encoder == 2 ) {
		temp = encoder2.speed;
	}else if( _encoder == 3 ) {
		temp = qei1.speed;
	}else if( _encoder == 4 ) {
		temp = qei2.speed;
	}else {
		// Do nothing
	}
	return temp;
}

void __attribute__((interrupt, no_auto_psv)) _INT1Interrupt(void)
{
	if( encoder1counter == encoder1max ) {
		encoder1counter = 0;
	} else {
   		encoder1counter++;
	}
    IFS1bits.INT1IF = 0;
}

void __attribute__((interrupt, no_auto_psv)) _INT2Interrupt(void)
{
 	if( encoder2counter == encoder2max ) {
		encoder2counter = 0;
	 } else {
		encoder2counter++;
	}
    IFS1bits.INT2IF = 0;
}

void __attribute__((__interrupt__)) _QEI1Interrupt(void) 
{
	if( qei1counter == qei1max ) {
		qei1counter = 0;
	} else {
   		qei1counter++;
	}
   _QEI1IF = 0;
} 

void __attribute__((__interrupt__)) _QEI2Interrupt(void) {
	if( qei2counter == qei2max ) {
		qei2counter = 0;
	} else {
		qei2counter++;
	}
	_QEI2IF = 0;
}




