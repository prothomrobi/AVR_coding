/*
 * LCD_practice.c
 *
 * Created: 12/12/2017 9:24:36 PM
 * Author : Prothomrobi
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif
#define D4 eS_PORTB0
#define D5 eS_PORTB1
#define D6 eS_PORTB2
#define D7 eS_PORTB3
#define RS eS_PORTB5
#define EN eS_PORTB4

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h" //Can be download from the bottom of this article

int main(void)
{
	DDRB = 0xFF;
	DDRC = 0xFF;
	int i;
	Lcd4_Init();
	while(1)
	{
		Lcd4_Set_Cursor(1,1);
		Lcd4_Write_String("electroSome LCD Hello World");
		for(i=0;i<15;i++)
		{
			_delay_ms(500);
			Lcd4_Shift_Left();
		}
		for(i=0;i<15;i++)
		{
			_delay_ms(500);
			Lcd4_Shift_Right();
		}
		Lcd4_Clear();
		Lcd4_Set_Cursor(2,1);
		Lcd4_Write_Char('e');
		Lcd4_Write_Char('S');
		_delay_ms(2000);
	}
}