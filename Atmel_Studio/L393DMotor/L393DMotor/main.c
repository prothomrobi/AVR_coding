/*
 * L393DMotor.c
 *
 * Created: 11/19/2017 11:56:21 AM
 * Author : Prothomrobi
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC = 0xff;
	while (1)
	{
		PORTC = (1<<PC0) | (1<<PC2);
		_delay_ms(1000);
		PORTC = (1<<PC1) | (1<<PC2);
		_delay_ms(1000);
	}
}


