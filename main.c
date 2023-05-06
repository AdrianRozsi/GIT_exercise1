/*
 * main.c
 *
 *  Created on: May 5, 2023
 *      Author: Adrian
 */
//MASINA STANJA


#include <stdint.h>
#include <stdlib.h>
#include "usart.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdio.h>
#include "timer0.h"
#include "pin.h"
#include "pulsing.h"
#include "utiles.h"



int8_t checkDigit(int8_t c)
{
	while(!usartAvailable() == 0);

	if(usartGetChar() == c)
		return 1;
	else
		return 0;

}

int main()
{
	pinInit(PORT_B, 5, OUTPUT);
	//timer0InteruptInit();
	usartInit(115200);

	enum state_t{LOCKED, NUM1, NUM2, UNLOCKED, BROKEN};
	enum state_t state = LOCKED;

	pinSetValue(PORT_B, 5, LOW);

	while(1)
	{
		switch(state)
		{
			case LOCKED:
				if(checkDigit('1'))
				{
					pinPulsing(PORT_B, 5, 2000, 1);
					state = NUM1;
				}
				else{
					pinSetValue(PORT_B,5, HIGH);
					state = BROKEN;
				}
				break;
			case NUM1:
				if(checkDigit('2'))
				{
					pinPulsing(PORT_B, 5, 2000, 1);
					state = NUM2;
				}
				else
				{
					pinSetValue(PORT_B, 5, HIGH);
					state = BROKEN;
				}
				break;
			case NUM2:
				if(checkDigit('3'))
				{
					pinPulsing(PORT_B, 5, 2000, 3);
					state = UNLOCKED;
				}
				else
				{
					pinSetValue(PORT_B, 5, HIGH);
					state = BROKEN;
				}
				break;
			case UNLOCKED:
				break;
			case BROKEN:
				break;
		}
	}


	return 0;
}


