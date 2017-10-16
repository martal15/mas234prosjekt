#define F_CPU 1000000L

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "lab1.h"

bool lastPD5 = false;

int main(void)
{
	DDRD = 0x01;
	PORTD = 0x00;
	
	PCMSK2 |= (1 << PCINT21);
	PCICR |= (1 << PCIE2);
	EICRA |= ISC00;
	
	sei();
	
	while(1) {
		
	}
}

ISR (PCINT2_vect)
{
	if(!(PIND & (1 << PD5)) && !lastPD5) {
		PORTD = (PORTD ^ 0x01);
		lastPD5 = true;
		_delay_ms(50);
	}
	else {
		lastPD5 = false;
	}
}
