#include "AnalogToDigital.h"
#include "Motor.h"

AnalogToDigital thumbwheelLeft(0);
AnalogToDigital thumbwheelRight(1);
AnalogToDigital sensor1(4);
AnalogToDigital sensor2(5);
AnalogToDigital sensor3(6);
AnalogToDigital sensor4(7);
AnalogToDigital sensor5(11);
AnalogToDigital sensor6(10);
AnalogToDigital sensor7(9);
AnalogToDigital sensor8(8);

Motor motorLeft(0);
Motor motorRight(1);


int main()
{
	DDRD |= (1 << 5)|(1<<0);
	DDRF = 0;

	DDRB |= (1<<7);

	AnalogToDigital::init();

	while (1)
	{
		double turning_val = (sensor5.read() - sensor4.read()) / 255;
		motorLeft.set(0.5 + turning_val);
		motorRight.set(0.5 - turning_val);
	}
}
