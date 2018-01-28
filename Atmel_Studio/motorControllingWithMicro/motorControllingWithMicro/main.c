/*
 * motorControllingWithMicro.c
 *
 * Created: 11/16/2017 3:44:56 PM
 * Author : Prothomrobi
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	DDRB=0xff;
    while (1) 
    {
		PORTB=0b00000001;
		_delay_ms(180);
		PORTB=0x00;
		_delay_ms(160);
    }
}

