/*
 * main.c
 *
 *  Created on: Aug 25, 2023
 *      Author: Abdelrhman Fawzy
 */
#include"avr/io.h"
#include<util/delay.h>
/* Write Embedded C code using ATmega16 µC to
control a DC-Motor using three push buttons.
 Requirements:
• Configure the µC control with internal 1Mhz Clock.
• The three switches are connected to pin 0 & 1 & 2 in
PORTA.
• Connect switches using Pull Down configuration.
• IN1 & IN2 of the L293D chip are connected to first two
pins in PORTC.
• If the first switch is pressed motor should rotate clock
wise.
• If the second switch is pressed motor should rotate
anti- clock wise.
• If the third switch is pressed motor should stop.*/
void main(void)
{
	// configure the pin 0,1,2 of PORTA as input
	DDRA &= ~(1<<PA0);
	DDRA &= ~(1<<PA1);
	DDRA &= ~(1<<PA2);


	//configure pin 0,1 of PORTC as output
	DDRC |= (1<<PC0);
	DDRC |= (1<<PC1);

	//Initialize the motor  off
	PORTC&=(~(1<<PC0));
	PORTC&=(~(1<<PC1));

	while(1)
	{
		if(PINA&(1<<PA0))
		{
			PORTC&=(~(1<<PC0));
			PORTC|=(1<<PC1);
		}
		else if(PINA&(1<<PA1))
		{
			PORTC|=(1<<PC0);
			PORTC&=(~(1<<PC1));
		}
		else if(PINA&(1<<PA2))
		{
			PORTC&=(~(1<<PC0));
			PORTC&=(~(1<<PC1));
		}


	}
}
