#define F_CPU 1000000L

#include <avr/io.h>
#include <util/delay.h>


#include "lab1.h"



void blink() {
	DDRD = 0x01;
	PORTD = 0x00;
	while (1)
	{
		PORTD = 0x01;
		_delay_ms(1000);
		PORTD = 0x00;
		_delay_ms(1000);
	}
}

void lab1_7() {
	DDRD = 0x01;
	PORTD = 0x00;
	while (1)
	{
		if(!(PIND & (1 << PD5))) {
			PORTD = 0x01;
		}
		else {
			PORTD = 0x00;
		}
	}
}