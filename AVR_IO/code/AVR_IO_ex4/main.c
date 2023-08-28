/*
 * main.c
 *
 *  Created on: Aug 24, 2023
 *      Author: Abdelrhman Fawzy
 */

#include"avr/io.h"
#include<util/delay.h>
/* Write Embedded C code using ATmega16 µC to
control a 7-segment using a push button.
 Requirements:
• Configure the µC control with internal 1Mhz Clock.
• The switch is connected to pin 4 in PORTD.
• Connect the switches using Pull Down configuration.
• The 7-segment is connected to first 4-pins of PORTC.
• If the switch is pressed just increase the number appeared in the
7 segment display, and if we reach the maximum number (9)
overflow occurs.*/

void main(void)
{
	char flag=0;
	int count=1;
	DDRD&=(~(1<<PD4));// configure pin 4 of PORTD to be input pin
	DDRC=0x0f;// configure first 4 pins of PORTC to be output pin

	//initialize the 7 segment by 0
	PORTC=0x00;
	while(1)
	{
		if(PIND&(1<<PD4))
		{
			_delay_ms(30);
			if(count<10)
			{
				switch(count){
				case 1:PORTC=0x01;break;
				case 2:PORTC=0x02;break;
				case 3:PORTC=0x03;break;
				case 4:PORTC=0x04;break;
				case 5:PORTC=0x05;break;
				case 6:PORTC=0x06;break;
				case 7:PORTC=0x07;break;
				case 8:PORTC=0x08;break;
				case 9:PORTC=0x09;break;
				}
				count++;
			}
			else
			{
				count=1;
				PORTC=0x00;
			}
			while(PIND&(1<<PD4));
		}



	}
}
