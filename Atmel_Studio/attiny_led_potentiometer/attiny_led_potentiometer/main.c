/*
* ADC_attiny13a.c
*
* Created: 12/6/2017 1:09:00 PM
* Author : Nu
*/

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


void adc_setup (void)
{
	ADMUX |= (1 << MUX0); // Set the ADC input to PB2/ADC1
	ADMUX |= (1 << ADLAR);
	ADCSRA |= (1 << ADPS1) | (1 << ADPS0) | (1 << ADEN); // Set the prescalar to clock/128 & enable ADC
}
int adc_read (void)
{
	ADCSRA |= (1 << ADSC); // Start the conversion
	while (ADCSRA & (1 << ADSC)); // Wait for it to finish - blocking
	return ADCH;
}
int main(void)
{
	DDRB |= (1 << PB0);  // Output Red LED
	DDRB |= (1 << PB1);  // Output Green LED
	while (1) {
		adc_setup();
		uint16_t adc_val = adc_read();
		if( adc_val >= 128){
			PORTB |= (1 << PB0);
			PORTB &= ~(1<<PB1);
		}
		else{
			//PORTB &= ~(1<<PB0);
			PORTB |= (1 << PB1);
		}
	}
}