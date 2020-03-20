#ifndef MOTOR_H
#define MOTOR_H

#include <avr/io.h>
#include <math.h>

class Motor
{
public:
	Motor(bool side);

	void set(double veloctiy);
	
private:
	bool side;
};

#endif