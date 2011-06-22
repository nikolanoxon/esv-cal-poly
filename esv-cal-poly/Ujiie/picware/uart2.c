/**	==========================================================================
 *	File: uart1.c
 *	==========================================================================
 *
 *	History:
 *		2010-08-13 T. Cooke file created.
 *
 *	Description:
 *		Sets up dsPIC33F to use UART1 on which ever pins
 *		were mapped in setup_IO() in main.c.
 */

#include "uart2.h"
#include "definitions.h"


/*	Recieved data will be stored in an 80 character array named Buf */
char Buf2[80]; 				

/*	Pointer to the most recent character in Buf */
char * Receiveddata2 = Buf2;

unsigned int dataReady = 0;
unsigned int dataCount = 0;

unsigned int receivedValue2;
unsigned int aFound = 0;

IMU imu = {0, 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0};

/** ==========================================================================
 *	Function: _U1TXInterrupt
 *	==========================================================================
 *
 *	History:
 *		2010-08-13 T. Cooke function created.
 *
 *	Description:
 *		This is the UART1 transmit ISR. Note that the Tx interrupt
 *		has not been enabled yet.
 *
 *	Variable(s):
 *		@param void
 *		@return void
 */

void __attribute__( ( interrupt, no_auto_psv ) ) _U2TXInterrupt( void )
{  
	/*	IMPORTANT: Reset UART Receive interrupt flag. Note: if interrupt 
		flag is not cleared a new interrupt will not occur.
	 */
	IFS1bits.U2TXIF = 0;
} 


/** ==========================================================================
 *	Function: _U1RXInterrupt
 *	==========================================================================
 *
 *	History:
 *		2010-08-13 T. Cooke function created.
 *
 *	Description:
 *		This is the UART1 receiving ISR.
 *
 *	Variable(s):
 *		@param void
 *		@return void
 */

void __attribute__( ( interrupt, no_auto_psv ) ) _U2RXInterrupt( void )
{
	/*	Checks the framing error for UART transmission & 
	 *	if transmit shift register is empty
	 */
	if( U2STAbits.FERR == 1 && U2STAbits.TRMT ==  1);

	/*	Checks parity error for UART transmission &
	 *	if transmit shift register is empty	
	 */
	if( U2STAbits.PERR == 1 && U2STAbits.TRMT == 1 );

	/*	Checks overrun error for UART transmission & 
	 *	if transmit shift register is empty		
	 */
	if( U2STAbits.OERR == 1 && U2STAbits.TRMT == 1 );


	/*	If we have recieved data and the transmit buffer is empty place it in 
	 *	the recieve buffer increment the pointer, and echo the character back to 
	 *	the terminal.
	 *	
	 *	-U1STA refers to UART1 Status Register
	 *
	 *	-URXDA refers to the Receive Buffer Data bit that is set to 1 when 
	 *	 data is available to read.
	 *
	 *	-TRMT refers to Transmit Shift Register is Empty. This bit is set to 1
	 *	 when the last transmission has completed successfully.
	 */
	if(	U2STAbits.URXDA == 1 && U2STAbits.TRMT == 1 );
	{

		receivedValue2 = U2RXREG;

		if( !dataReady ) {
			if( receivedValue2 == 'A' && !aFound ) {
				aFound = 1;
				dataCount = 1;
			}else {
				switch( dataCount ) {
					case 1:		// Counter
						dataCount++;
						break;
					case 2:
						dataCount++;
						break;
					case 3:		// X
						imu.accelX.msb = receivedValue2;
						dataCount++;
						break;
					case 4:	
						imu.accelX.lsb = receivedValue2;
						//imu.accelX.lsb = 49;
						dataCount++;
						break;
					case 5:		// 
						imu.accelY.msb = receivedValue2;
						dataCount++;
						break;
					case 6:
						imu.accelY.lsb = receivedValue2;
						dataCount++;
						break;
					case 7:		// Roll?
						imu.accelZ.msb = receivedValue2;
						dataCount++;
						break;
					case 8:	
						imu.accelZ.lsb = receivedValue2;
						dataCount++;
						break;
					case 9:		//
						imu.roll.msb = receivedValue2;
						dataCount++;
						break;
					case 10:
						imu.roll.lsb = receivedValue2;
						dataCount++;
						break;
					case 11:	//
						imu.pitch.msb = receivedValue2;
						dataCount++;
						break;
					case 12:	
						imu.pitch.lsb = receivedValue2;
						dataCount++;
						break;
					case 13:	//
						imu.yaw.msb = receivedValue2;
						dataCount++;
						break;
					case 14:
						imu.yaw.lsb = receivedValue2;
						dataReady = 1;
						aFound = 0;
						dataCount++;
						break;
					default:
						break;
				}
			}
		}

		/* Notice Reciveddata pointer is post incremented */
	//	( *( Receiveddata2 )++ ) = U2RXREG;

		/*	In order to echo the right character we have to send the char
		 *	at (pointer-1)
		 */
	//	U2TXREG = *( Receiveddata2 - 1 );
	}

    
	/*	IMPORTANT: Reset UART Receive interrupt flag. Note: if interrupt 
		flag is not cleared a new interrupt will not occur.
	 */
    IFS1bits.U2RXIF = 0;  
}


/** ==========================================================================
 *	Function: start_uart1
 *	==========================================================================
 *
 *	History:
 *		2010-08-13 T. Cooke function created.
 *
 *	Description:
 *		Starts UART1 with the specified baudrate.
 *
 *	Variable(s):
 *		@param unsigned long baudrate
 *		@return void
 */

void initUART2( unsigned long baudrate )
{
	/*	Holds the value of baud register */
	unsigned int baudvalue;   

	/*	Holds the value of uart config reg */
	unsigned int U2MODEvalue;

	/*	Holds the information regarding uart
	 *	Tx and Rx interrupt modes
	 */  
	unsigned int U2STAvalue; 

	/*	Turn off UART1module */
    CloseUART2();

    /*	Clear interupts */
	IFS1bits.U2RXIF = 0;  
	IFS1bits.U2RXIF = 0;

	/* 	Configure uart1 receive and transmit interrupt */
    ConfigIntUART2( UART_RX_INT_EN & UART_RX_INT_PR3 & 
                    UART_TX_INT_DIS & UART_TX_INT_PR3 );

	/* Configure UART1 module to transmit 8 bit data with one stopbit. 
	 *  
	 * Load a value into Baud Rate Generator.  Example is for 38400.
	 * See section 19.3.1 of datasheet.
	 *  	baudvalue = (Fcy/(16*BaudRate))-1
	 *  	baudvalue = (40M/(16*38400))-1
	 *  	baudvalue = 65
	 */

	/*	Slow speed settings */
    if(baudrate <= 57600UL)
    {
	    baudvalue = ( unsigned int )( ( FCY / ( 16 * baudrate ) ) - 1 );
	    U2MODEvalue = UART_EN & UART_IDLE_CON & UART_IrDA_DISABLE &
                  	  UART_MODE_FLOW & UART_UEN_00 & UART_DIS_WAKE &
                 	  UART_DIS_LOOPBACK & UART_DIS_ABAUD & UART_UXRX_IDLE_ONE &
        			  UART_BRGH_SIXTEEN & UART_NO_PAR_8BIT & UART_1STOPBIT;
	}
	/*	High speed settings */
	else
	{
    	baudvalue = ( unsigned int )( ( FCY / ( 4 * baudrate ) ) - 1 );
    	U2MODEvalue = UART_EN & UART_IDLE_CON & UART_IrDA_DISABLE &
                  	  UART_MODE_FLOW & UART_UEN_00 & UART_DIS_WAKE &
                  	  UART_DIS_LOOPBACK & UART_DIS_ABAUD & UART_UXRX_IDLE_ONE &
                  	  UART_BRGH_FOUR & UART_NO_PAR_8BIT & UART_1STOPBIT;
 	}
    
    /*	Status register settings */
    U2STAvalue  = UART_INT_TX & UART_TX_ENABLE & 
    			  UART_IrDA_POL_INV_ZERO & UART_SYNC_BREAK_DISABLED  & 
    			  UART_INT_RX_CHAR & UART_ADR_DETECT_DIS & 
    			  UART_TX_BUF_FUL & UART_RX_OVERRUN_CLEAR;
	
	/* Open UART1 connection
	 *
	 * This function is defined in uart.h the builtin library fuctions
	 * provided with the compiler. See uart.h or the C30 library users
	 * guide for more infromation
	 */
	
	OpenUART2( U2MODEvalue, U2STAvalue, baudvalue );
	
	__delay_ms(10);

	/*	Prints a welcome banner alerting user serial communication port
	 *	has been opened.
	 */
}

void sendUART2( unsigned int _command ) {
	U2TXREG = _command;
}