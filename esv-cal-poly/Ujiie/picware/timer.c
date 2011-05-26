#include "timer.h"

unsigned int updateEncoderFlag;
unsigned int delayCounter;
unsigned int matchValue;

void initTimer( void ) {
 ConfigIntTimer2(T2_INT_PRIOR_2 & T2_INT_ON);
	PR1 = 5375;
    WriteTimer2(0);

    matchValue = 4999;

    OpenTimer2(	T2_ON & 
				T2_GATE_OFF & 
				T2_IDLE_STOP &
                T2_PS_1_64 &
                T2_SOURCE_INT, matchValue);
}

void __attribute__((__interrupt__)) _T2Interrupt( void )
{
	if( delayCounter == 116 && !updateEncoderFlag ) {
		updateEncoderFlag = 1;
		delayCounter = 0;	
	} else if( !updateEncoderFlag ){
		delayCounter++;
	}
	
	IFS0bits.T2IF = 0;    /* Clear Timer interrupt flag */
}  
