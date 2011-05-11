/**	==========================================================================
 *	File: main.c
 *	==========================================================================
 *
 *	History:
 *		2010-08-13 T. Cooke file created.
 *		2011-03-11 B. Ujiie oscillator configuration modified for PPL.
 *
 *	Description:
 *		Main program file.
 */

/* All other includes should be defined in the main header file */
#include "main.h"


/*	These macro's set up the configuration registers using scripts 
 *	included with C30. See p33FJ64MC202.h for definitions.
 */
_FBS(RBS_NO_RAM & BSS_NO_BOOT_CODE & BWRP_WRPROTECT_OFF);
_FSS(RSS_NO_RAM & SSS_NO_FLASH);
_FGS(GSS_OFF & GCP_OFF);

/*	Sets the boot OSC to the internal fastRC OSC */
_FOSCSEL(FNOSC_FRC & IESO_OFF);		

/*	This allows for PLL to be set after boot. FCKSM_CSECMD allows 
 *	clocks to be switched. Use fast clock for quick start up then
 *	change to the selected clock (e.g. primary, xt, etc.) This program 
 *	uses FRC clock always.
 */
_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF & POSCMD_NONE);

/*	Disable Watch Dog Timer (WDT) and Windowed WDT */
_FWDT(FWDTEN_OFF & WINDIS_OFF); 

/*	Set power on reset to 128ms */
_FPOR(FPWRT_PWR128);

/*	Turn off JTAG debugging to free up pins */
_FICD(JTAGEN_OFF & ICS_PGD1);

extern char Buf[112]; 				// 80 character buffer
extern char * Receiveddata;

extern char Buf2[112];
extern char * Receiveddata2;





/** ==========================================================================
 *	Function: main
 *	==========================================================================
 *
 *	History:
 *		2010-08-13 T. Cooke function created.
 *
 *	Description:
 *		Main program function. This function runs all the necessary elements
 *		to control the R/C truck and communicate with the steering wheel via
 *		serial transmission.
 *
 *	Variable(s):
 *		@param void
 *		@return int
 */

int main ( void )
{
	unsigned int match_value;	

	/*	Setup PPL to achieve 80Mhz internal clock speed */
	ppl_setup();

	/*	Setup Input/Ouput pins and serial Tx/Rx pins */
	setup_IO();

	/** Note: the timer is used to regularly pole the value
	 *		  from the quadrature encoder module. The quadrature
     *		  encoder module will not send any value to the
	 *		  program. Instead, the program will regularly
	 *		  pull the current encoder tick count from the module.
	 */

	/* Enable Timer1 Interrupt and Priority to "1" */
    ConfigIntTimer2(T2_INT_PRIOR_2 & T2_INT_ON);

    WriteTimer2(0);

    match_value = 4999;
	/* Turn on Timer2 with desired settings */
	/* EXPLAIN EACH.... */
    OpenTimer2(	T2_ON & 
				T2_GATE_OFF & 
				T2_IDLE_STOP &
                T2_PS_1_8 &
                T2_SOURCE_INT, match_value);

	/*	Start UART1 with the specified baudrate */
	start_uart1(115200UL);
	start_uart2(115200UL);


	/*	Contains current raw ASCII character */
	char control = 0;
	char control2 = 0;

	// Get IMU menu by sending a space ascii character
//	print_uart2(" ");
//	print_uart2("9");
//	print_uart2("#");
	print_uart1("Hello, welcome!.\r\n");

while(1)
{
		
	control = *( Receiveddata - 1 );

	control2 = *( Receiveddata2 - 1 );

//switch( control ) {
//	case 'w':
//		print_uart1("hi\r\n");
//		break;
//	default:
//		break;
//}

//	if( flag ) {
//		print_uart1("key pressed\r\n");
//		flag = 0;
//	}	

	switch( control ) {
		case 'w':
			print_uart1("Up\r\n");
			Receiveddata = clear_buf(Buf, &Buf[0], 112);
			break;
		case 's':
			print_uart1("Down\r\n");
			Receiveddata = clear_buf(Buf, &Buf[0], 112);
			break;
		case 'a':
			print_uart1("Left\r\n");
			Receiveddata = clear_buf(Buf, &Buf[0], 112);
			break;
		case 'd':
			print_uart1("Right\r\n");
			Receiveddata = clear_buf(Buf, &Buf[0], 112);
			break;
		default:
			break;
}


//	switch( control2 ) {
//		case 'w':
//			print_uart2("Up\r\n");
//			Receiveddata2 = clear_buf(Buf2, &Buf2[0], 80);
//			break;
//		case 's':
//			print_uart2("Down\r\n");
//			Receiveddata2 = clear_buf(Buf2, &Buf2[0], 80);
//			break;
//		case 'a':
//			print_uart2("Left\r\n");
//			Receiveddata2 = clear_buf(Buf2, &Buf2[0], 80);
//			break;
//		case 'd':
//			print_uart2("Right\r\n");
//			Receiveddata2 = clear_buf(Buf2, &Buf2[0], 80);
//			break;
//		default:
//			break;
//	}


//	// Check if data string is at the end and if so, stop storing data
//	if( control2 == 'Z' ) {
//		print_uart1("Z\r\n");
//		start_flag = FALSE;
//		end_flag = TRUE;
//		Receiveddata2 = clear_buf(Buf2, &Buf2[0], 80);
//	}
//
//	// Store data if string has not ended yet
//	if( start_flag ) {
//		if( !msb_done ) {
//			//printf("%d", control2);
//			msb = control2;
//			Receiveddata2 = clear_buf(Buf2, &Buf2[0], 80);
//			msb_done = TRUE;
//		} else {
//			lsb = control2;
//			Receiveddata2 = clear_buf(Buf2, &Buf2[0], 80);
//			imu[imu_count] = (msb << 8) | lsb;
//			imu_count++;
//			msb_done = FALSE;
//		}
//	}
//
//	// Check if data string is at the start and if so, start storing data
//	if( control2 == 'A' ) {
//		print_uart1("A\r\n");
//		start_flag = TRUE;
//		Receiveddata2 = clear_buf(Buf2, &Buf2[0], 80);
//	}
//
//	if( end_flag ) {
//		//print_uart1(imu[0]);
//		end_flag = FALSE;
//	}
	
}
	return 1;
}


/** ==========================================================================
 *	Function: setup_IO
 *	==========================================================================
 *
 *	History:
 *		2010-08-13 T. Cooke function created.
 *
 *	Description:
 *		Setup Input/Ouput pins for necessary ports. In addition, map Tx and Rx
 *		pins for serial transfer between computer and dsPIC.
 *
 *	Variable(s):
 *		@param void
 *		@return void
 */

void setup_IO ( void )
{
	/**	====[Input/Output Pin Configuration]=================================== 
	 *	This section sets up the pins to be used as either input or output. 
	 *	=======================================================================
	 */
	TRISB = 0;				// Set the whole port to output mode
	TRISBbits.TRISB2 = 0;	// Set the pins as appropriate I/O
							// This sets PB2 to an output
	TRISBbits.TRISB3 = 1;	// Auto-set by UART1 anyways!

	TRISBbits.TRISB8 = 0;
	TRISBbits.TRISB9 = 1;
	
	/* Look out for analog pins. By defualt as an input the pin is tied to the 
	A2D Converter*/
	AD1PCFGLbits.PCFG4 = 1;	// IMPORTANT. RB2 is muxxed with AN4 by default
	AD1PCFGLbits.PCFG5 = 1;	// IMPORTANT. RB3 is muxxed with AN5 by default

	/**	====[Remapable pin section]============================================ 
	 *	This section sets up specific perifrials to output pins. This is a great
	 *	feture of this chip because overall board complexity can be decreased.
	 *	Note: remapping peripheral pins uses the pps.h header.
	 *	=======================================================================
	 */
	 
	/* Unlock the PPS pins to configure peripherals */
    PPSUnLock;

	/**	Map Rx and Tx pins to RP3 and RP2 */

	/*	UART1 Receive on RP3 pin. Note: _U1RXR equivalent to 
	 *	RPINR18bits.U1RXR 
	 */
	_U1RXR = 3;
	

	/*	UART1 Transmit on RP2 pin. Note: there is no _UTXR definition for
	 *	the transmitting line. Use RPOR1bits.RP2R equivalent to _RP2R.
	 */
	_RP2R = 0b00011;

	_U2RXR = 9;	
	_RP8R = 0b00101;

	//Both QEIs, an additional interrupt pin, an
	/* Lock the PPS pins */
	PPSLock;
	__delay_ms(10);
}


/** ==========================================================================
 *	Function: _T2Interrupt
 *	==========================================================================
 *
 *	History:
 *		2011-04-26 B. Ujiie function created.
 *
 *	Description:
 *		Function called when a timer interrupts the program.
 *
 *	Variable(s):
 *		@param void
 *		@return void
 */

void __attribute__((__interrupt__)) _T2Interrupt(void)
{
	IFS0bits.T2IF = 0;    /* Clear Timer interrupt flag */
}  
