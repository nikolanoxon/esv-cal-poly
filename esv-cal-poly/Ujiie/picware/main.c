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

unsigned int encoder1del = 0;
unsigned int encoder2del = 0;
unsigned int encoder3del = 0;
unsigned int encoder4del = 0;

int value = -120;
int fwd = 0;
int cnt = 0;

int main ( void )
{
		

	initPPL();
	setup();
    initTimer();
	setEncoderWheelRadius( 2.25 / 12.0 );
	initEncoder();
//	initUART1(115200UL);
	initUART2(115200UL);

	initUART1(9600UL);
//	initUART2(9600UL);

	

	/*	Begin motor setup */
	initMotor();

	/*	Begin servo setup */
	initServo();

	setMotorPWM(1885);
	setServoPWM( 1775 );
//	unsigned int motorPWM = 1885;
//	unsigned int servoPWM = 1775;
	unsigned int imuFlag = 1;
	unsigned int dataSendCounter = 0;
while(1)
{
	control = *( Receiveddata - 1 );
	control2 = *( Receiveddata2 - 1 );

	if( imuFlag ) {
		sendUART2('#');
		imuFlag = 0;
	}

//	switch( control ) {
//		case 'w':
//			putsUART1("W was pressed\n\r");
//			motorPWM++;
//			setMotorPWM(motorPWM);
//			Receiveddata = clearBuffer(Buf, &Buf[0], 80);
//			break;
//		case 's':
//			putsUART1("S was pressed\n\r");
//			motorPWM--;
//			setMotorPWM(motorPWM);
//			Receiveddata = clearBuffer(Buf, &Buf[0], 80);
//			break;
//		case 'a':
//			putsUART1("A was pressed\n\r");
//			servoPWM++;
//			setServoPWM(servoPWM);
//			Receiveddata = clearBuffer(Buf, &Buf[0], 80);
//			break;
//		case 'd':
//			putsUART1("D was pressed\n\r");
//			servoPWM--;
//			setServoPWM(servoPWM);
//			Receiveddata = clearBuffer(Buf, &Buf[0], 80);
//			break;
//		default:
//			break;
//	}



//if( updateEncoderFlag ) {
//	sendUART1(50);
//	sendUART1(51);
//	sendUART1(52);
//	sendUART1(53);
//	sendUART1(54);
//	sendUART1(55);
//	sendUART1(56);
//	sendUART1(57);
//	sendUART1(65);
//	sendUART1(66);
//	sendUART1(67);
//	sendUART1(68);
//	sendUART1(69);
//	sendUART1(70);
//	sendUART1(71);
//	sendUART1('\r');
//	updateEncoderFlag = 0;
//}

if( updateEncoderFlag ) {
	
	if( dataReady ) {
		sendUART1(imu.accelX.msb);
		sendUART1(imu.accelX.lsb);
		sendUART1(imu.accelY.msb);
		sendUART1(imu.accelY.lsb);
		sendUART1(imu.accelZ.msb);
		sendUART1(imu.accelZ.lsb);
		sendUART1(imu.roll.msb);
		sendUART1(imu.roll.lsb);
		sendUART1(imu.pitch.msb);
		sendUART1(imu.pitch.lsb);
		sendUART1(imu.yaw.msb);
		sendUART1(imu.yaw.lsb);
		sendUART1( '\r' );
		dataReady = 0;
		dataSendCounter = 0;
	}
	updateEncoderFlag = 0;
}



//if( updateEncoderFlag ) {
//	if( dataReady ) {
//		switch( dataSendCounter ) {
//			case 0:
//				sendUART1( imu.accelX.msb );
//				sendUART1( imu.accelX.lsb );
//				sendUART1( imu.accelY.msb );
//				sendUART1( imu.accelY.lsb );
//				sendUART1( imu.accelZ.msb );
//				sendUART1( imu.accelZ.lsb );
//				sendUART1( imu.pitch.msb );
//				sendUART1( imu.pitch.lsb );
//				sendUART1( '\r' );
//				dataReady = 0;
//				dataSendCounter = 0;
//				//dataSendCounter++;
//				break;
//	//		case 2:
//	//			sendUART1( imu.roll.msb );
//	//			sendUART1( imu.roll.lsb );
//	//			sendUART1( imu.yaw.msb );
//	//			sendUART1( imu.yaw.lsb );
//	//			dataSendCounter++;
//	//			break;
//	//		case 3:	
//	//			sendUART1( '\r' );
//	//			dataSendCounter = 0;
//	//			dataReady = 0;
//	//			break;
//			default:
//				break;
//		}
//	}
//	updateEncoderFlag = 0;
//}




//if( updateEncoderFlag ) {
//	updateEncoder(1);
//	updateEncoder(2);
//	updateEncoder(3);
//	updateEncoder(4);
//
//	encoder1del = getEncoderDel(1);
//	encoder2del = getEncoderDel(2);
//	encoder3del = getEncoderDel(3);
//	encoder4del = getEncoderDel(4);
//
//	sendUART1( encoder1del );
//	sendUART1( encoder2del );
//	sendUART1( encoder3del );
//	sendUART1( encoder4del );
//	sendUART1( '\r' );
//	updateEncoderFlag = 0;
//}

//if( commandReady ) {
//	
////	setServoAngleInt( command.steer );
////	setMotorSpeedInt( command.throttle );
//	//sendUART1( command.steer );
//	//sendUART1( command.throttle );
//	commandReady = 0;
//}

//	putsUART1("HI THERE\n\r");
//
//if( commandReady ) {
//
//	if( updateEncoderFlag ) {
//		updateEncoder(1);
//		updateEncoder(2);
//		updateEncoder(3);
//		updateEncoder(4);
//
//		encoder1del = getEncoderDel(1);
//		encoder2del = getEncoderDel(2);
//		encoder3del = getEncoderDel(3);
//		encoder4del = getEncoderDel(4);
//
//		sendUART1( encoder1del );
//		sendUART1( encoder2del );
//		sendUART1( encoder3del );
//		sendUART1( encoder4del );
//		sendUART1( "\r" ); 
//
//		updateEncoderFlag = 0;
//	}
//
//	if( dataReady ) {
//		sendUART1(imu.accelX.msb);
//		sendUART1(imu.accelX.lsb);
//		sendUART1(imu.accelY.msb);
//		sendUART1(imu.accelY.lsb);
//		sendUART1(imu.accelZ.msb);
//		sendUART1(imu.accelZ.lsb);
//		sendUART1(imu.pitch.msb);
//		sendUART1(imu.pitch.lsb);
//		sendUART1(imu.roll.msb);
//		sendUART1(imu.roll.lsb);
//		sendUART1(imu.yaw.msb);
//		sendUART1(imu.yaw.lsb);
//		sendUART1("\r");
//		dataReady = 0;		
//	}
//	
//	setServoAngleInt( command.steer );
//	setMotorSpeedInt( command.throttle );
//	sendUART1( command.steer );
//	sendUART1( command.throttle );
//	sendUART1( '\r' );
//
//	commandReady = 0;
//}
//
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
	_QEB1R = 8;	// connect encoder to pin 8, not 7

	_QEA2R = 13;		// working!
	_QEB2R = 9;		

	_INT1R = 5;			
	_INT2R = 15;		

	PPSLock;
	__delay_ms(10);
}






