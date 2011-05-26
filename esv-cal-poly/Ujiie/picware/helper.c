#include "helper.h"

char * clearBuffer( char buf[], char * buf_pointer, int size ) {
	unsigned int x = 0;

	for( x = 0; x < size; x++ ) {		
		*( buf_pointer+x ) = 0;
	}
	return buf_pointer;	
}

float char2float ( char buf[], int size )
{
	unsigned int count = 0;

	unsigned int ncount = 0;

	unsigned int i = 0;

	unsigned int digits[size];

	unsigned int number = 0;

	while( buf[count] != '\0' ) {
		if( ( buf[count] > 47 ) && ( buf[count] < 58 ) ) {
			digits[count] = buf[count] - 48;
		} else {
			ncount++;
		}		
		count++;
	}

	for( i = 0; i < ( count - ncount ); i++ ) {
		number = ( number * 10 ) + digits[i];
	}

	return (float)number;
}


int char2int ( char buf[], int size )
{
	unsigned int count = 0;

	unsigned int ncount = 0;

	unsigned int i = 0;

	unsigned int digits[size];

	unsigned int number = 0;

	while ( buf[count] != '\0' )	{
		if (  ( buf[count] > 47 ) && ( buf[count] < 58 ) ) {
			digits[count] = buf[count] - 48;
		} else {
			ncount++;
		}		
		count++;
	}

	for ( i = 0; i < ( count - ncount ); i++ ) {
		number = ( number * 10 ) + digits[i];
	}

	return number;
}

