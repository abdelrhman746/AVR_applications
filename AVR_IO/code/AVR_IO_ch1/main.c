/*
 * main.c
 *
 *  Created on: Aug 24, 2023
 *      Author: Abdelrhman Fawzy
 */
#include"avr/io.h"
#include<util/delay.h>
/* Write Embedded C code using ATmega16 µC to
control a 7-segment using two push buttons.
 Requirements:
• Configure the µC control with internal 1Mhz Clock.
• The two switches are connected to pin 0 & 1 in PORTA.
• Connect both switches using Pull Down configuration.
• The 7-segment is connected to first 4-pins of PORTD.
• If the switch1 is pressed just increase the number appeared in
the 7 segment display, and if the number reach the maximum
number (9) do nothing.
• If the switch2 is pressed just decrease the number appeared in
the 7 segment display, and if the number reach the minimum
number (0) do nothing.*/
void main(void)
{
	char flag=0;
		int count=0;
		DDRA&=(~(1<<PA0|1<<PA1));// configure pin 0,1 of PORTA to be input pin
		DDRD=0x0f;// configure first 4 pins of PORTD to be output pin

		//initialize the 7 segment by 0
		PORTD=0x00;
		while(1)
		{
			if(PINA&(1<<PA0))
			{
				_delay_ms(30);
				if(count<9)
				{
					count++;
					switch(count){
					case 1:PORTD=0x01;break;
					case 2:PORTD=0x02;break;
					case 3:PORTD=0x03;break;
					case 4:PORTD=0x04;break;
					case 5:PORTD=0x05;break;
					case 6:PORTD=0x06;break;
					case 7:PORTD=0x07;break;
					case 8:PORTD=0x08;break;
					case 9:PORTD=0x09;break;
					}

				}
				else if(count==9)
				{

					PORTA=0x09;
				}
				while(PINA&(1<<PA0));
			}
			if(PINA&(1<<PA1))
			{

				_delay_ms(30);
				if(count>0)
				{
					count--;
					switch(count){
					case 0:PORTD=0x00;break;
					case 1:PORTD=0x01;break;
					case 2:PORTD=0x02;break;
					case 3:PORTD=0x03;break;
					case 4:PORTD=0x04;break;
					case 5:PORTD=0x05;break;
					case 6:PORTD=0x06;break;
					case 7:PORTD=0x07;break;
					case 8:PORTD=0x08;break;
					case 9:PORTD=0x09;break;
					}

				}
				else if(count==0)
				{
					PORTA=0x00;
				}
				while(PINA&(1<<PA1));
			}
		}
}

