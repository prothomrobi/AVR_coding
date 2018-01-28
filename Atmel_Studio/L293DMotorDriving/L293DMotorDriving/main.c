
#define F_CPU 8000000UL // 16MHz clock speed
#define soft_reset()
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC = 0x0F;  
	DDRB = 0x00;            // initialize port C
	// motors connected across PC0...Pc3
	while(1)
	{
		
		if(PINB &= (1<<PB0)){
			// clockwise rotation
			PORTC = 0b00000101;     // PC0 = High = Vcc
			// PC1 = Low = 0
			// PC2 = High = Vcc
			// PC3 = Low = 0
			
			//_delay_ms(5000);         // wait 0.5s
			//PORTC = 0b00001010;     // PC0 = Low = 0
		}
		
		else if(PINB &= (1<<PB1)){
			
			//counter-clockwise rotation
			PORTC = 0b00001010;     // PC0 = Low = 0
			// PC1 = High = Vcc
			// PC2 = Low = 0
			// PC3 = High = Vcc
			
			//_delay_ms(5000);   
			//PORTC = 0b00000101;      // wait 0.5s
		}
		
	}
}