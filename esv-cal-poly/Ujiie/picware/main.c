#include "main.h"
#include "definitions.h"

_FBS(RBS_NO_RAM & BSS_NO_BOOT_CODE & BWRP_WRPROTECT_OFF);
_FSS(RSS_NO_RAM & SSS_NO_FLASH);
_FGS(GSS_OFF & GCP_OFF);

_FOSCSEL(FNOSC_FRC & IESO_OFF);		

_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF & POSCMD_NONE);

_FWDT(FWDTEN_OFF & WINDIS_OFF); 

_FPOR(FPWRT_PWR128);

_FICD(JTAGEN_OFF & ICS_PGD1);


extern char Buf[80]; 			
extern char * Receiveddata;
extern char Buf2[80];
extern char * Receiveddata2;

extern unsigned int data_ready;
extern float tire_circumference;

unsigned int status_flag = 0;
unsigned int display_menu = 1;

float encoder_unit;

unsigned int qei1counter = 0;
unsigned int qei2counter = 0;

unsigned int encoder1counter = 0;
unsigned int encoder2counter = 0;

unsigned int qei1max = 60000;
unsigned int qei2max = 60000;

unsigned int encoder1max = 60000;
unsigned int encoder2max = 60000;

unsigned int update_encoder = 1;
unsigned int delay_count = 0;

extern IMU imu;
/*	Contains current raw ASCII character */
char control = 0;
char control2 = 0;

typedef struct {
	uint8_t new;
	uint8_t old;
	uint8_t del;
	float speed;
} Encoder;

typedef struct {
	uint8_t new;
	uint8_t old;
	uint8_t del;
	float speed;
} Qei;

IMU test;
Qei qei1 = {0, 0, 0, 0.0};
Qei qei2 = {0, 0, 0, 0.0}; 

Encoder encoder1 = {0, 0, 0, 0.0};
Encoder encoder2 = {0, 0, 0, 0.0};

float del_time = 0.0086 * 116.0 ; // seconds


int main ( void )
{
	unsigned int match_value;	

	ppl_setup();

	setup();

    ConfigIntTimer2(T2_INT_PRIOR_2 & T2_INT_ON);
	PR1 = 5375;
    WriteTimer2(0);

    match_value = 4999;

    OpenTimer2(	T2_ON & 
				T2_GATE_OFF & 
				T2_IDLE_STOP &
                T2_PS_1_64 &
                T2_SOURCE_INT, match_value);

	encoder_set_tire_radius( 0.5 );
	encoder_setup();

	start_uart1(115200UL);
	start_uart2(115200UL);

	

	/*	Begin motor setup */
	motor_setup();
	motor_task();

	/*	Begin servo setup */
	servo_setup();
	servo_task();

	/*	Initialize motor to a speed of 0 */
	motor_set_speed(0.0);
	
	/*	Initialize servo steering angle to 0 */
	servo_set_angle(0.0);
	
	/*	Contains integer value of signal from buffer. Used to check
	 *	for start bit set at 125.
	 */
	int signal = 0;



	float motor_speed = 0.0;
	float servo_angle = 0.0;
	int start_imu = 0;
	encoder_unit = encoder_get_stepsize();

	// start IMU
	//printf("#\n");

	unsigned int qei_count = 0;
	//putsUART1("Program Started again\r\n");
	putsUART2(")#");


while(1)
{
	control = *( Receiveddata - 1 );
	control2 = *( Receiveddata2 - 1 );

	if( data_ready ) {
		putsUART1(imu.accelY.lsb);
		//putsUART1("\r\n");
		data_ready = 0;
	}

	if( status_flag ) {
		if( update_encoder ) {
			qei1.new = qei1counter;
			qei1.speed = (qei1.new - qei1.old) * encoder_unit * (1.0 / 5280.0) * (1.0 / del_time) * 3600.0;
			qei1.old = qei1.new;	
		
			qei2.new = qei2counter;
			qei2.speed = (qei2.new - qei2.old) * encoder_unit * (1.0 / 5280.0) * (1.0 / del_time) * 3600.0;
			qei2.old = qei2.new;
	
			encoder1.new = encoder1counter;
			encoder1.speed = (encoder1.new - encoder1.old) * encoder_unit * (1.0 /5280.0) * (1.0 / del_time) * 3600.0;
			encoder1.old = encoder1.new;
	
			encoder2.new = encoder2counter;
			encoder2.speed = (encoder2.new - encoder2.old) * encoder_unit * (1.0 /5280.0) * (1.0 / del_time) * 3600.0;
			encoder2.old = encoder2.new;
			
			update_encoder = 0;
		}

//printf("Encoder Stepsize: %.2f\tQEI1 New ticks: %d\tQEI1 Old ticks: %d\t QEI1 Speed: %.2f\tQEI2 New ticks: %d\tQEI2 Old ticks: %d\tQEI2 Speed: %.2f\n", encoder_unit, qei1.new, qei1.old, qei1.speed, qei2.new, qei2.old, qei2.speed); 
//		printf("Encoder Stepsize: %.2f\tEnc1 New ticks: %d\tEnc1 Old ticks: %d\t Enc1 Speed: %.2f\tEnc2 New ticks: %d\tEnc2 Old ticks: %d\tEnc2 Speed: %.2f\n", encoder_unit, encoder1.new, encoder1.old, encoder1.speed, encoder2.new, encoder2.old, encoder2.speed); 
	}


	/**	===[Terminal controls]============================ */
	
//	switch ( control )
//	{
//		case 'w':
//			motor_speed = motor_speed + 0.5;
//			printf("Motor Speed: %f\n", motor_speed);
//			Receiveddata = clear_buf(Buf, &Buf[0], 80);
//			break;
//		case 's':
//			motor_speed = motor_speed - 0.5;
//			printf("Motor Speed: %f\n", motor_speed);
//			Receiveddata = clear_buf(Buf, &Buf[0], 80);
//			break;
//		case 'a':
//			servo_angle = servo_angle - 5.0;
//			printf("Servo Angle %f\n", servo_angle);
//			Receiveddata = clear_buf(Buf, &Buf[0], 80);
//			break;
//		case 'd':
//			servo_angle = servo_angle + 5.0;
//			printf("Servo Angle %f\n", servo_angle);
//			Receiveddata = clear_buf(Buf, &Buf[0], 80);
//			break;
//		default:
//			// Do nothing
//			break;			
//	}

	
	motor_set_speed( motor_speed );
	servo_set_angle ( servo_angle );
	/**	===[End Terminal Controls]======================== */
}
	CloseQEI1();
	CloseQEI2();
	return 1;
}
void setup ( void )
{	
    INTCON2 = 0x0000;       /* Setup all INT on rising edge triggering */

    IFS1bits.INT1IF = 0;    /*Reset INT0 interrupt flag */
    IEC1bits.INT1IE = 1;    /*Enable INT0 Interrupt Service Routine */

    IFS1bits.INT2IF = 0;    /*Reset INT1 interrupt flag */
    IEC1bits.INT2IE = 1;    /*Enable INT1 Interrupt Service Routine */

	/**	====[Input/Output Pin Configuration]=================================== 
	 *	This section sets up the pins to be used as either input or output. 
	 *	=======================================================================
	 */
	TRISB = 0;				// Set the whole port to output mode
	TRISBbits.TRISB2 = 0;	// Set the pins as appropriate I/O
							// This sets PB2 to an output
	TRISBbits.TRISB3 = 1;	// Auto-set by UART1 anyways!

	TRISBbits.TRISB0 = 0;
	TRISBbits.TRISB1 = 1;

	TRISBbits.TRISB7 = 1;  // Set pin 22 to input pin
    TRISBbits.TRISB13 = 1;  // Set pin 21 to input pin

    TRISBbits.TRISB5 = 1;   // Set pin 14 to input pin
    TRISBbits.TRISB15 = 1;  // set pin 26 to input pin
	
	/* Look out for analog pins. By defualt as an input the pin is tied to the 
	A2D Converter*/
	AD1PCFGLbits.PCFG4 = 1;	// IMPORTANT. RB2 is muxxed with AN4 by default
	AD1PCFGLbits.PCFG5 = 1;	// IMPORTANT. RB3 is muxxed with AN5 by default

	AD1PCFGLbits.PCFG2 = 1;	// IMPORTANT. RP0 is muxxed with AN2 by default
	AD1PCFGLbits.PCFG3 = 1;	// IMPORTANT. RP1 is muxxed with AN3 by default

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

	_U2RXR = 1;	
	_RP0R = 0b00101;

	//Map QEI pins to RP13 and RP4
	_QEA1R = 7;			// mapping to pin 18
	_QEA2R = 13;			// mapping to pin 17

	_INT1R = 5;				// mapping to pin 14
	_INT2R = 15;			// mapping to pin 26

	//Both QEIs, an additional interrupt pin, an
	/* Lock the PPS pins */
	PPSLock;
	__delay_ms(10);
}

void __attribute__((interrupt, no_auto_psv)) _INT1Interrupt(void)
{
	if( encoder1counter == ENC1MAX ) {
		encoder1counter = 0;
	} else {
   		encoder1counter++;
	}
    IFS1bits.INT1IF = 0;
}

void __attribute__((interrupt, no_auto_psv)) _INT2Interrupt(void)
{
 	if( encoder2counter == ENC2MAX ) {
		encoder2counter = 0;
	 } else {
		encoder2counter++;
	}
    IFS1bits.INT2IF = 0;
}

void __attribute__((__interrupt__)) _T2Interrupt(void)
{
	if( delay_count == 116 && !update_encoder ) {
		update_encoder = 1;
		delay_count = 0;	
	} else if( !update_encoder ){
		delay_count++;
	}
	
	IFS0bits.T2IF = 0;    /* Clear Timer interrupt flag */
}  

void __attribute__((__interrupt__)) _QEI1Interrupt(void) 
{
	if( qei1counter == QEI2MAX ) {
		qei1counter = 0;
	} else {
   		qei1counter++;
	}
   _QEI1IF = 0;
} 

void __attribute__((__interrupt__)) _QEI2Interrupt(void) {
	if( qei2counter == QEI2MAX ) {
		qei2counter = 0;
	} else {
		qei2counter++;
	}
	_QEI2IF = 0;
}
