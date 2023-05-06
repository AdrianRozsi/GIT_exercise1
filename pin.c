/**
 * @file pin.c
 * @brief Datoteka koja definise funkcije za rad sa pinovima
 * @author Ime Prezime
 * @date dd-mm-yyyy
 * @version 1.0
 */
/*
 * pin.c
 *
 *  Created on: Apr 11, 2023
 *      Author: Adrian
 */

# include <avr/io.h>
# include <avr/interrupt.h>
# include <stdint.h>
#include "pin.h"
# define HIGH 1
// Makro za podesavanje niske vrednosti signala na pinu
# define LOW 0
// Makro za podesavanje izlaznog smera pina
# define OUTPUT 1
// Makro za podesavanje ulaznog smera pina
# define INPUT 0
// Makro za selektovanje porta B
# define PORT_B 0
// Makro za selektovanje porta C
# define PORT_C 1
// Makro za selektovanje porta D
# define PORT_D 2
// Makro za selektovanje pina na koji je povezana dioda
# define DIODE_PIN 5
// Makro za podesavanje periode u brzom rezimu treptanja
# define FAST 200
// Makro za podesavanje periode u sporom rezimu treptanja
# define SLOW 1000
// Makro za podesavanje broja brzih treptaja
# define FAST_REPS 15
// Makro za podesavanje broja sporih treptaja
# define SLOW_REPS 3

// Promenljiva koja skladisti broj milisekundi proteklih od pokretanja aplikacije


void pinSetValue(uint8_t port, uint8_t pin, uint8_t value)
{
	// Postavljanje vrednosti pina
	switch (port)
	{
		case PORT_B:
			if (value == HIGH)
				PORTB |= 1 << pin;
			else
				PORTB &= ~(1 << pin);
			break;

		case PORT_C:
			if (value == HIGH)
				PORTC |= 1 << pin;
			else
				PORTC &= ~(1 << pin);
			break;

		case PORT_D:
			if (value == HIGH)
				PORTD |= 1 << pin;
			else
				PORTD &= ~(1 << pin);
			break;

		default:
			break;
	}
}

/***********************************************************/

void pinInit(uint8_t port, uint8_t pin, uint8_t direction)
{
	// Inicijalizacija smera pina
	switch (port)
	{
		case PORT_B:
			if (direction == OUTPUT)
				DDRB |= 1 << pin;
			else
				DDRB &= ~(1 << pin);
			break;

		case PORT_C:
			if (direction == OUTPUT)
				DDRC |= 1 << pin;
			else
				DDRC &= ~(1 << pin);
			break;

		case PORT_D:
			if (direction == OUTPUT)
				DDRD |= 1 << pin;
			else
				DDRD &= ~(1 << pin);
			break;

		default:
			break;
	}
}
