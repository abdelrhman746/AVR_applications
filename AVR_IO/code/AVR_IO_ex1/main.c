/*
 * main.c
 *
 *  Created on: Aug 17, 2023
 *      Author: Abdelrhman Fawzy
 */

#include"avr/io.h"
#include<util/delay.h>
/*
 *  Write Embedded C code using ATmega16 µC to
control a led.
 Requirements:
• Configure the µC control with internal 8Mhz Clock.
• The led is connected to pin 6 in PORTD.
• Connect the Led using Negative Logic configuration.
• Flash the led every 1 second.
 * */
void ex1(void)
{
	DDRD=DDRD|(1<<PD6);//direction OUTPUT PORTD PIN 6
	while(1)
	{
		PORTD= PORTD |(1<<PD6);//SET PIN 6 in PORTD
		_delay_ms(1000);
		PORTD= PORTD &(~(1<<PD6));//CLR PIN 6 in PORTD
		_delay_ms(1000);

	}
}

void main(void)
{
	ex1();
}
