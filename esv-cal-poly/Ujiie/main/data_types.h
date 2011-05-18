#ifndef	_DATA_TYPES_H
#define	_DATA_TYPES_H

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

IMU imu;

#endif
