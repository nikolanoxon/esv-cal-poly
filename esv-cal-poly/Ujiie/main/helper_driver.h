/* Customs functions file that might be useful
Robert, David, Kyle 
9-24-2010
Revision 1*/

#ifndef 	_HELPER_DRIVER_H
#define 	_HELPER_DRIVER_H

#include "main.h"
//Clears a character array//
char * clear_buf(char [], char *, int);

float char_to_float ( char buf[], int size );

int char_to_int ( char buf[], int size );

//Converts a character buffer to a floating point number
float char2float(char [], int);

//Converts a character buffer to an integer
int char2int(char [], int);



#endif
