/**	==========================================================================
 *	File: encoder_driver.c
 *	==========================================================================
 *
 *	History:
 *		2011-04-27 B. Ujiie file created.
 *
 *	Description:
 *		Sets up the quadrature encoder modules to monitor two of the four
 *		encoders on the R/C truck.
 */

#include "encoder_driver.h"

float tire_radius = 0.0;

volatile unsigned int old_ticks = 0;
volatile unsigned int new_ticks = 0;
volatile unsigned int del_ticks = 0;

volatile unsigned int enc_ISR_count = 0;

volatile float velocity = 0.0;

/** ==========================================================================
 *	Function: encoder_setup
 *	==========================================================================
 *
 *	History:
 *		2010-04-27 B. Ujiie function created.
 *
 *	Description:
 *		Sets up the quadrature encoder modules to read the encoder interrupts
 *		without disturbing the main program.
 *
 *	Variable(s):
 *		@param void
 *		@return void
 */

void encoder_setup ( void )
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



/** ==========================================================================
 *	Function: encoder_set_tire_radius
 *	==========================================================================
 *
 *	History:
 *		2010-04-27 B. Ujiie function created.
 *
 *	Description:
 *		Set the tire radius to be used in calculating the average velocity.
 *
 *	Variable(s):
 *		@param float _radius
 *		@return void
 */

void encoder_set_tire_radius ( float _radius )
{
	tire_radius = _radius;
}


/** ==========================================================================
 *	Function: encoder_read
 *	==========================================================================
 *
 *	History:
 *		2010-04-27 B. Ujiie function created.
 *
 *	Description:
 *		Read the QEI count register and grab the number of current ticks from
 *		the encoder. Note that this function will be called in the timer ISR
 *		as a means of reading the tick values at a specified period.
 *
 *	Variable(s):
 *		@param void
 *		@return void
 */

void encoder_read ( void )
{
	// count the number of times the encoder module was read
	enc_ISR_count++;
	
	// Read in the current encoder tick count
	new_ticks = POS1CNT;

	// Calculate the difference between the current encoder reading and the previous
	del_ticks = new_ticks - old_ticks;

	// Check sign of the difference in encoder ticks
	if( del_ticks < 0 )
	{
		del_ticks = del_ticks + MAX1CNT;
	}
	else 
	{
		float radians = ( 2 * 3.14159 ) / MAX1CNT;
		float arcLength = tire_radius * radians;
		velocity = arcLength / 0.20 ; // feet/sec
	}
}



