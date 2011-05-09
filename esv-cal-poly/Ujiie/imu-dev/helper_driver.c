/* Customs functions file that might be useful
David, Kyle, Robert 
9-24-2010
Revision 1*/

#include "helper_driver.h"

//Clears a character array//
//inputs: character buffer that will be cleared, first address of buffer, size of buffer//
//outputs: character pointer to first address of cleared buffer//
//updated: 9-27-2010//
char * clear_buf(char buf[], char * buf_pointer, int size)
{
	int x=0;	// initialize our index

	for(x=0 ; x<size ;x++){		// run through entire buffer and set to 0
		*(buf_pointer+x)= 0;
	}
return(buf_pointer);			// return top of buffer to reset indexing pointer
}

/** ==========================================================================
 *	Function: char_to_float
 *	==========================================================================
 *
 *	History:
 *		2010-09-27 K. Valiton function created.
 *		2011-03-29 B. Ujiie simplified and removed decimal detection.
 *	Description:
 *		Converts input command from serial ascii characters to usable floating
 *		point numbers to adjust the PWM signal to the steering servo and motor.
 *
 *	Variable(s):
 *		@param char buf[]
 *		@param int size
 *		@return float
 */

float char_to_float ( char buf[], int size )
{
	/*	Initialize a counter to loop through buffer */
	int count = 0;

	/*	Initialize non integer counter */
	int ncount = 0;
	
	/*	Initialize a second counter to piece int back together */
	int i = 0;

	/*	Initialize an array to store each digit of the number */
	int digits[size];

	/*	Integer value of the ASCII value from buffer */
	int number = 0;

	while ( buf[count] != '\0')
	{
		/*	Convert ASCII character to a number
		 *	by subtracting 48 from each value in
		 *	buffer. 
		 */
		if (  ( buf[count] > 47 ) && ( buf[count] < 58 ) )
		{
			digits[count] = buf[count] - 48;
		}
		else
		{
			ncount++;
		}		
		count++;

	}

	for ( i = 0; i < ( count - ncount ); i++ )
	{
		number = ( number * 10 ) + digits[i];
	}

	return (float)number;
}


/** ==========================================================================
 *	Function: char_to_int
 *	==========================================================================
 *
 *	History:
 *		2010-09-27 K. Valiton function created.
 *		2011-03-29 B. Ujiie simplified.
 *	Description:
 *		Converts input command from serial ascii characters to usable integer
 *		numbers to adjust the PWM signal to the steering servo and motor.
 *
 *	Variable(s):
 *		@param char buf[]
 *		@param int size
 *		@return int
 */

int char_to_int ( char buf[], int size )
{
	/*	Initialize a counter to loop through buffer */
	int count = 0;

	/*	Initialize non integer counter */
	int ncount = 0;
	
	/*	Initialize a second counter to piece int back together */
	int i = 0;

	/*	Initialize an array to store each digit of the number */
	int digits[size];

	/*	Integer value of the ASCII value from buffer */
	int number = 0;

	while ( buf[count] != '\0')
	{
		/*	Convert ASCII character to a number
		 *	by subtracting 48 from each value in
		 *	buffer. 
		 */
		if (  ( buf[count] > 47 ) && ( buf[count] < 58 ) )
		{
			digits[count] = buf[count] - 48;
		}
		else
		{
			ncount++;
		}		
		count++;

	}

	for ( i = 0; i < ( count - ncount ); i++ )
	{
		number = ( number * 10 ) + digits[i];
	}

	return number;
}

