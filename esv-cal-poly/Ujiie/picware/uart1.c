
#include "uart1.h"
#include "definitions.h"

char Buf[80]; 				
char * Receiveddata = Buf;

unsigned int commandReady = 0;
unsigned int commandCount = 2;

unsigned int counter = 0;

unsigned int receivedValue;


CONTROL command = {0, 0};

void __attribute__( ( interrupt, no_auto_psv ) ) _U1TXInterrupt( void )
{  
	/*	IMPORTANT: Reset UART Receive interrupt flag. Note: if interrupt 
		flag is not cleared a new interrupt will not occur.
	 */
	IFS0bits.U1TXIF = 0;
} 


void __attribute__( ( interrupt, no_auto_psv ) ) _U1RXInterrupt( void )
{
	/*	Checks the framing error for UART transmission & 
	 *	if transmit shift register is empty
	 */
	if( U1STAbits.FERR == 1 && U1STAbits.TRMT ==  1);

	/*	Checks parity error for UART transmission &
	 *	if transmit shift register is empty	
	 */
	if( U1STAbits.PERR == 1 && U1STAbits.TRMT == 1 );

	/*	Checks overrun error for UART transmission & 
	 *	if transmit shift register is empty		
	 */
	if( U1STAbits.OERR == 1 && U1STAbits.TRMT == 1 );


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
	 *	 when the last transmission has completed successfully. URXDA is set to 1
	 *	 when data is available to read from the register.
	 */
	if(	U1STAbits.URXDA == 1 && U1STAbits.TRMT == 1 );
	{
//		if( U1RXREG == 121 ) {
//			commandCount = 0;
//		}
//		if( commandCount == 2 ) { // 2 stores only steering, 3 stores both
//			commandReady = 1;
//			commandCount = 0;
//		}
//
//		if( !commandReady ) {
//			switch( commandCount ) {
//				case 0:
//					// Idle
//					break;
//				case 1:
//					command.steer = U1RXREG;
//					break;
//				case 2:	
//					command.throttle = U1RXREG;
//					break;
//				default:
//					break;
//			}
//		}
//		
//		commandCount++;


		/* Notice Reciveddata pointer is post incremented */
		//( *( Receiveddata )++ ) = U1RXREG;
		receivedValue = U1RXREG;

	if( !commandReady ) {
		if( receivedValue == 250 ) {
			commandCount = 0;
		}else {
			switch( commandCount ) {
				case 0:
					command.steer = receivedValue;
					commandCount++;
					break;
				case 1:
					command.throttle = receivedValue;
					commandReady = 1;
					commandCount++;
					break;
				default:
					break;
			}
		}
	}		
			
	
		/*	In order to echo the right character we have to send the char
		 *	at (pointer-1)
		 */
		//U1TXREG = *( Receiveddata - 1 );
		
	}

    
	/*	IMPORTANT: Reset UART Receive interrupt flag. Note: if interrupt 
		flag is not cleared a new interrupt will not occur.
	 */
    IFS0bits.U1RXIF = 0;  
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

void initUART1( unsigned long baudrate )
{
	/*	Holds the value of baud register */
	unsigned int baudvalue;   

	/*	Holds the value of uart config reg */
	unsigned int U1MODEvalue;

	/*	Holds the information regarding uart
	 *	Tx and Rx interrupt modes
	 */  
	unsigned int U1STAvalue; 

	/*	Turn off UART1module */
    CloseUART1();

	    /** Clear UART1 Receive Interrupt Flag
	 *	Note: If flag is not cleared, the program will continue to
	 *		  think an interrupt has occured and remain within the
	 *		  the user defined interrupt routine.
	 */
	IFS0bits.U1RXIF = 0;  
	IFS0bits.U1TXIF = 0;
	
	/** Configure UART1 Receive and Transmit Interrupts */
    ConfigIntUART1( UART_RX_INT_EN & 	// Enable UART1 Receive Interrupts
					UART_RX_INT_PR3 & 	// Set UART1 Receive interrupts to priority 3
                    UART_TX_INT_DIS & 	// Disable UART1 Transmit interrupts	
					UART_TX_INT_PR3 );	// Set UART1 Transmit interrupts to priority 3

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
	    U1MODEvalue = UART_EN & 			// Enable UART1
					  UART_IDLE_CON & 		// Work in idle mode
					  UART_IrDA_DISABLE &	// Disable IrDA encoder and decoder
                  	  UART_MODE_FLOW & 		// UART1 pin in flow control mode
					  UART_UEN_00 & 		// U1TX and U1RX used, U1TCS, U1RTS, and BCLK controlled by latch for flow control
					  UART_DIS_WAKE &		// Disable wakeup on start
                 	  UART_DIS_LOOPBACK & 	// Disable loopback mode
					  UART_DIS_ABAUD & 		// Baudrate me asurment disabled
					  UART_UXRX_IDLE_ONE &	// U1Rx Idle state is 1 (not 0)
        			  UART_BRGH_SIXTEEN & 	// Baud Rate Generator generates 16 clocks per bit second (16x baudrate)
					  UART_NO_PAR_8BIT & 	// Do not use a parity bit
					  UART_1STOPBIT;		// Use 1 stop bit
	}
	/*	High speed settings */
	else
	{
    	baudvalue = ( unsigned int )( ( FCY / ( 4 * baudrate ) ) - 1 );
    	U1MODEvalue = UART_EN & 			
					  UART_IDLE_CON & 
					  UART_IrDA_DISABLE &
                  	  UART_MODE_FLOW & 
					  UART_UEN_00 & 
					  UART_DIS_WAKE &
                  	  UART_DIS_LOOPBACK & 
					  UART_DIS_ABAUD & 
					  UART_UXRX_IDLE_ONE &
                  	  UART_BRGH_FOUR & 		// Baud Rate Generator generates 4 clocks per bit second (4x baudrate) high speed
					  UART_NO_PAR_8BIT & 
					  UART_1STOPBIT;
 	}
    
    /*	Status register settings */
    U1STAvalue  = UART_INT_TX & 				// Interrupt on transfer of every character to Trap Service Routine
				  UART_TX_ENABLE & 				// Enable UART1 transmit
    			  UART_IrDA_POL_INV_ZERO & 		// IrDA encoded, idle state is 0 (not 1)
				  UART_SYNC_BREAK_DISABLED  & 	// Sync break transmission disabled
    			  UART_INT_RX_CHAR & 			// Trigger an interrupt on every character received
				  UART_ADR_DETECT_DIS & 		// Disable address detection
    			  UART_TX_BUF_FUL & 			// Transmit buffer is full
				  UART_RX_OVERRUN_CLEAR;		// Rx buffer over run bit clear
	
	/* Open UART1 connection
	 *
	 * This function is defined in uart.h the builtin library fuctions
	 * provided with the compiler. See uart.h or the C30 library users
	 * guide for more infromation
	 */
	
	OpenUART1( U1MODEvalue, U1STAvalue, baudvalue );
	
	__delay_ms(10);

	/*	Prints a welcome banner alerting user serial communication port
	 *	has been opened.
	 */

	//putsUART1("UART1 started!\r\n");
}

void sendUART1( unsigned int _command ) {
	U1TXREG = _command;	
}