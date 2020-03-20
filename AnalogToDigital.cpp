#include "AnalogToDigital.h"

AnalogToDigital::AnalogToDigital(uint8_t channel): channel(channel)
{
	//*ddr_for_channel[channel] &= ~(1<<pin_for_channel[channel]); // set mode
}

void AnalogToDigital::init()
{
	// Use external voltage reference, Left adjust result.
	ADMUX = (1<<REFS0)|(1<<ADLAR);
	// Enable ADC, Prescale with a division factor of 4.
	ADCSRA = (1<<ADEN)|(1<<ADPS1)|(1<<ADPS0);
}

double AnalogToDigital::read()
{
	ADMUX &= 0b11100000; // Clear channel
	ADMUX |= channel & 0b11111; // Set channel

	ADCSRA |= (1<<ADSC); // Start Conversion

	while(ADCSRA & (1<<ADSC)); // Wait for conversion to finish

	// todo: convert from two's complement form binary to voltage
	uint16_t result = ADCH;

	double voltage = (3.3 * result) / 255;

	return voltage;
}

