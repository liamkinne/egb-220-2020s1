#include "Motor.h"

Motor::Motor(bool side): side(side)
{
	TCCR0A |= (1<<COM0A1)|(1<<COM0B1)|(1<<WGM01)|(1<<WGM00);
	TCCR0B |= (1<<CS01);

	if (side == 0) {
		DDRB |= (1<<7)|(1<<0);
	}
	else {
		DDRE |= (1<<6);
		DDRD |= (1<<0);
	}
}

void Motor::set(double velocity)
{
	if (side == 0) {
		OCR0A = (fabs(velocity) * 255);
		if (velocity < 0) {
			PORTB |= (1<<0);
		}
		else {
			PORTB &= ~(1<<0);
		}
	}
	else {
		OCR0B = (fabs(velocity) * 255);
		if (velocity < 0) {
			PORTE |= (1<<6);
		}
		else {
			PORTE &= ~(1<<6);
		}
	}
}