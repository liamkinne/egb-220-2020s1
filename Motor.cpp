#include "Motor.h"

Motor::Motor(bool side): side(side)
{
	TCCR0A |= (1<<COM0A1)|(1<<COM0B1)|(1<<WGM01)|(1<<WGM00);
	TCCR0B |= (1<<CS01);
}

void Motor::set(double velocity)
{
	if (side == 0) {
		OCR0A = (fabs(velocity) * 255);
	}
	else {
		OCR0B = (fabs(velocity) * 255);
	}
}