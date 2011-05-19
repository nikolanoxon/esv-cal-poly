#ifndef	_DEFINITIONS_H
#define	_DEFINITIONS_H

typedef struct {
	unsigned int msb;
	unsigned int lsb;
} WORD;

typedef struct {
	WORD accelX;
	WORD accelY;
	WORD accelZ;
	WORD pitch;
	WORD roll;
	WORD yaw;
} IMU;

#endif
