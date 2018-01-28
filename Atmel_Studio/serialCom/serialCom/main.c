/*
 * serialCom.c
 *
 * Created: 11/15/2017 10:07:10 PM
 * Author : Lenovo
 */ 

/*
 * USART_comMcu2.c
 *
 * Created: 11/9/2017 3:03:30 PM
 * Author : Lenovo
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BAUD 19200
#define MYUBRR    F_CPU/16/BAUD-1

void init_uart(unsigned short uValue  ){
	// setting the baud rate
	UBRR0H =(unsigned char)  ( uValue>> 8);  // 0x00
	UBRR0L =(unsigned char) uValue;  // 0x0C
	// enabling TX & RX
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	//UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0);
	UCSR0A = (1<<UDRE0);
	UCSR0C =  (1 << UCSZ01) | (1 << UCSZ00);    // Set frame: 8data, 1 stop

}

void uart_transmit(unsigned char data){
	while(!(UCSR0A & (1<<UDRE0))){};
	UDR0 = data;
}

unsigned uart_receive(void){
	while(!(UCSR0A) & (1<<RXEN0)){};
	PORTC = UDR0;
}


int main ()
{
	init_uart(MYUBRR);
	int value = uart_receive();
	char buffer [20];
	itoa (value,buffer,10);

	for (int j=0; j<20;j++)
	{
		//printf(buffer);
		PORTD ^= (1<< PD7);
		UDR0 = buffer[j];
		_delay_ms(5);
	}
	//uart_transmit(value);
}



