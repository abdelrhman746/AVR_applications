/*
 * main.c
 *
 *  Created on: Aug 24, 2023
 *      Author: Abdelrhman Fawzy
 */

#include"avr/io.h"
#include<util/delay.h>
/* Write Embedded C code using ATmega16 µC to
control a led using a push button.
 Requirements:
• Configure the µC control with internal 1Mhz Clock.
• The switch is connected to pin 0 in PORTB.
• Connect the switch using Internal Pull Up configuration.
• The Led is connected to pin 0 in PORTC.
• Connect the Led using Negative Logic configuration.
• If the switch is pressed just toggle the led.*/
void main (void)
{
	char flag=0;

	DDRB&=(~(1<<PB0));// configure pin 0 of PORTB to be input pin
	PORTB|=(1<<PB0);// activate the internal pullup resistance

	DDRC|=(1<<PC0);// configure pin 0 of PORTC to be output pin

	//initialize led
	PORTC|=(1<<PC0);// led is off at the beginning (negative logic configuration)

	while(1)
	{
		if(!(PINB&(1<<PB0)))
		{
			_delay_ms(30);
			if(flag==0)
			{
				PORTC^=(1<<PC0);//Toggle the led
				flag=1;
			}
		}
		else
		{
			flag=0;
		}

	}
}

