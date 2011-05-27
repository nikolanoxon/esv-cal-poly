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

extern unsigned int updateEncoderFlag;

extern unsigned int dataReady;
extern float wheelCircumference;

unsigned int status_flag = 0;
unsigned int display_menu = 1;

extern int testflag;

extern IMU imu;
extern CONTROL command;

extern unsigned int commandReady;
/*	Contains current raw ASCII character */
char control = 0;
char control2 = 0;

float encoder1speed = 0.0;
float encoder2speed = 0.0;
float encoder3speed = 0.0;
float encoder4speed = 0.0;

int value = -120;
int fwd = 0;
int cnt = 0;

int main ( void )
{
		

	initPPL();
	setup();
    initTimer();
	setEncoderWheelRadius( 2.25/12.0 );
	initEncoder();
	initUART1(115200UL);
	initUART2(115200UL);

	

	/*	Begin motor setup */
	initMotor();

	/*	Begin servo setup */
	initServo();

	/*	Initialize motor to a speed of 0 */
	setMotorSpeedInt(120);
	
	/*	Initialize servo steering angle to 0 */
	setServoAngleInt(120);
	
	/*	Contains integer value of signal from buffer. Used to check
	 *	for start bit set at 125.
	 */
	int signal = 0;



	float motor_speed = 0.0;
	float servo_angle = 0.0;
	int start_imu = 0;
	float tempspeed;

	int controller = 0;

	// start IMU
	//printf("#\n");

	unsigned int qei_count = 0;
	//putsUART1("Program Started again\r\n");
	putsUART2("#");
status_flag = 1;
	putsUART1("Menu\r\n");


while(1)
{
	control = *( Receiveddata - 1 );
	control2 = *( Receiveddata2 - 1 );

//	if( dataReady ) {
//		putsUART1(imu.accelX.msb);
//		putsUART1(imu.accelX.lsb);
//		putsUART1(imu.accelY.msb);
//		putsUART1(imu.accelY.lsb);
//		putsUART1(imu.accelZ.msb);
//		putsUART1(imu.accelZ.lsb);
//		putsUART1(imu.pitch.msb);
//		putsUART1(imu.pitch.lsb);
//		putsUART1(imu.roll.msb);
//		putsUART1(imu.roll.lsb);
//		putsUART1(imu.yaw.msb);
//		putsUART1(imu.yaw.lsb);
//		putsUART1("\r");
//		dataReady = 0;		
//	}
//
	if( status_flag ) {
		if( updateEncoderFlag ) {
			updateEncoder(1);
			updateEncoder(2);
			updateEncoder(3);
			updateEncoder(4);
			
			encoder1speed = getEncoderSpeed(1);
			encoder2speed = getEncoderSpeed(2);
			encoder3speed = getEncoderSpeed(3);
			encoder4speed = getEncoderSpeed(4);

		//	putfUART1(encoder1speed);
		//	putfUART1(encoder2speed);
		//	putfUART1(encoder3speed);
		//	putfUART1(encoder4speed);
		
		//printf("%d\t%d\t%d\t%.2f\n", getEncoderNew(2), getEncoderOld(2), getEncoderOld(2), encoder2speed);

			updateEncoderFlag = 0;
			// get encoder speeds here getEncoderSpeed()
		}
	}
//
//	if( commandReady ) {
//		setServoAngle( command.steer );
//		setMotorSpeed( command.throttle );
//	}

	/**	===[Terminal controls]============================ */
	
//	switch ( control )
//	{
//		case 'w':
//			motor_speed = motor_speed + 0.5;
//			printf("Motor Speed: %f\n", motor_speed);
//			Receiveddata = clearBuffer(Buf, &Buf[0], 80);
//			break;
//		case 's':
//			motor_speed = motor_speed - 0.5;
//			printf("Motor Speed: %f\n", motor_speed);
//			Receiveddata = clearBuffer(Buf, &Buf[0], 80);
//			break;
//		case 'a':
//			servo_angle = servo_angle - 5.0;
//			printf("Servo Angle %f\n", servo_angle);
//			Receiveddata = clearBuffer(Buf, &Buf[0], 80);
//			break;
//		case 'd':
//			servo_angle = servo_angle + 5.0;
//			printf("Servo Angle %f\n", servo_angle);
//			Receiveddata = clearBuffer(Buf, &Buf[0], 80);
//			break;
//		default:
//			// Do nothing
//			break;			
//	}

if( commandReady ) {
	
	setServoAngleInt( command.steer );
	setMotorSpeedInt( command.steer );
	sendUART1( command.steer );
	sendUART1( command.throttle );
	sendUART1( '\r' );

	commandReady = 0;
}
Receiveddata = clearBuffer(Buf, &Buf[0], 80);

//setMotorSpeedInt( controller );
	//setMotorSpeed( motor_speed );
//	setServoAngle( servo_angle );
	/**	===[End Terminal Controls]======================== */
}
	CloseQEI1();
	CloseQEI2();
	return 1;
}
void setup( void ) {	
    INTCON2 = 0x0000;       

    IFS1bits.INT1IF = 0;  
    IEC1bits.INT1IE = 1;  

    IFS1bits.INT2IF = 0;   
    IEC1bits.INT2IE = 1; 

	TRISB = 0;				
	TRISBbits.TRISB2 = 0;	
						
	TRISBbits.TRISB3 = 1;	

	TRISBbits.TRISB0 = 0;
	TRISBbits.TRISB1 = 1;

	TRISBbits.TRISB7 = 1;  
    TRISBbits.TRISB13 = 1; 
	TRISBbits.TRISB9 = 1;
	TRISBbits.TRISB8 = 1;

    TRISBbits.TRISB5 = 1;   
    TRISBbits.TRISB15 = 1; 

	TRISBbits.TRISB9 = 1;
	TRISBbits.TRISB8 = 1;
	
	AD1PCFGLbits.PCFG4 = 1;	
	AD1PCFGLbits.PCFG5 = 1;	

	AD1PCFGLbits.PCFG2 = 1;	
	AD1PCFGLbits.PCFG3 = 1;	

    PPSUnLock;

	_U1RXR = 3;
	_RP2R = 0b00011;

	_U2RXR = 1;	
	_RP0R = 0b00101;

	_QEA1R = 7;			
	_QEB1R = 8;

	_QEA2R = 13;		// working!
	_QEB2R = 9;

	_INT1R = 5;			
	_INT2R = 15;		

	PPSLock;
	__delay_ms(10);
}






