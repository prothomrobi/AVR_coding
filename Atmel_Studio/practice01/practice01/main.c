/*
 * practice01.c
 *
 * Created: 11/20/2017 8:24:54 AM
 * Author : Prothomrobi
 */ 
#define F_CPU 16000000UL;
#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
	//MCUSCR |=(1<<JTD);
	DDRB=0x00;
	DDRC=0xFF;
	unsigned char i;
    while (1) 
    {
		i=PINB;
		PORTC=i;
    }
}

