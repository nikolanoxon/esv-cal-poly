/* Customs functions file that might be useful
David, Kyle, Robert 
9-24-2010
Revision 1*/

#include "helper.h"

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


//Converts a character array to a float number//
//inputs: character buffer with stored user inputs, size of buffer//
//outputs: floating number//
//updated: 9-27-2010//
float char2float(char buf[], int size)
{	
	int int_count=0;		//counts the number of integers before the decimal place//
	int dec_count=0;		//counts the number of integers after the decimal place before the "enter"//
	int dec = 0;			//flag that is tripped when the decimal is reached//
	float tempI = 0;		//combines all integers before decimal place into a single number (tempI+tempD = returned float)//
	float tempD = 0; 		//combines all integers after the decimal place into the correct fraction (tempI+tempD = returned float)//
	int i=0; 				//initialize our index//
	float dec_array[size];	//array built to get only integers before the decimal place//
	float int_array[size];	//array built to get only integers after the decimal place//

	for (i=0; i<size; i++)	//run through entire buffer and separate the user input into the dec_array and int_array//
	{  
    	if (dec == 0 && buf[i] == 13)	//builds int_array then exits loop if user doesn't input a decimal number// 
		{
		 i=size;
		}
		else if (buf[i]!='.' && dec == 0)	//builds the int_array//
	    {
	     int_array[i]=buf[i]-48; //subtract 48 to switch from ascii to a number//
		 int_count++;	//determines the number of decimal places before the decimal place//
	    }
	    else if (buf[i]=='.')	//initiates flag when a decimal place is found in the user input//
	    {
	     dec = 1;	//flag if decimal place is found//
	    }
		else if (buf[i] != 13 && dec == 1)	//builds the dec_array//
	    {
	     dec_array[i-(int_count+1)]=buf[i]-48;	//subtract 48 to switch from ascii to a number and makes dec_array start at 0//
		 dec_count++;	//determines the number of decimal places after the decimal//
	    }
		else	//exits loop once both int_array and dec_array have been completely built//
		{
		 i=size;	//flag to exit loop//	
		}	
   	 }

	 for (i=0; i<int_count; i++)	//loops through int_array to build tempI//
	 {
	  tempI = tempI*10;
	  tempI = tempI + int_array[i];
 	 }

	 for (i=dec_count-1; i>=0; i--)		//loops through dec_array to build tempD//
	 {
		tempD = dec_array[i] + tempD;
		tempD = tempD/10;
	 }
	 tempI=tempI+tempD;	//tempI and tempD are combined to form the complete float number//
	 return(tempI);		//the complete float number is returned//
}


//Converts a character array to a integer number//
//inputs: character buffer with stored user inputs, size of buffer//
//outputs: integer number//
//updated: 9-27-2010//
int char2int(char buf[], int size)
{
	int tempI = 0;	//combines all ascii user inputs into a number//
	int i=0;		//initialize our index//
	
		for (i=0; i<size; i++) //loop to build the integer number//
		{  
    		if (buf[i]!= 13)
	    	{
	     	tempI = tempI*10;
		 	tempI = tempI + (int)buf[i] - 48;	//subtract 48 to switch from ascii to a number//
	    	}
	
			else if (buf[i] == 13)	//exits loop once number has been built//
	    	{
	     	i=size;		//flag to exit for loop//
	    	}	
   	 	}
 return(tempI); //returns integer number//
}

