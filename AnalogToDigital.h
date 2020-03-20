#ifndef ANALOG_TO_DIGITAL_H
#define ANALOG_TO_DIGITAL_H

#include <avr/io.h>

class AnalogToDigital
{
public:
	AnalogToDigital(uint8_t channel);

	static void init();

	double read();

private:
	uint8_t channel;

	const uint8_t ddr_for_channel = {

	};
	const uint8_t pin_for_channel = {

	};
	
};

#endif