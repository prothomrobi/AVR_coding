/*
 * timer1.c
 *
 * Created: 11/27/2017 8:27:47 PM
 * Author : Prothomrobi
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void timer0_init()
{
	// set up timer with no prescaling
	TCCR0 |= (1 << CS00);
	
	// initialize counter
	TCNT0 = 0;
}

int main(void)
{
	// connect led to pin PC0
	DDRC = 0xff;
	
	// initialize timer
	timer0_init();
	
	// loop forever
	while(1)
	{
		// check if the timer count reaches 191
		if (TCNT0 >= 191)
		{
			
			PORTC ^= (1 << 0);
			
			//PORTC |= (1 << PC0);    // toggles the led
			//_delay_ms(1000);
			//PORTC &= (1 << PC0);    // toggles the led
			//_delay_ms(1000);
			TCNT0 = 0;            // reset counter
		}
	}
}

