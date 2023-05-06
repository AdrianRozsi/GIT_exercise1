/*
 * pulsing.c
 *
 *  Created on: May 6, 2023
 *      Author: Adrian
 */

/*
 * pulsing.c
 *
 *  Created on: Apr 11, 2023
 *      Author: Adrian
 */
# include <avr/io.h>
# include <avr/interrupt.h>
# include <stdint.h>
#include "pin.h"
#include "timer0.h"
#include "utiles.h"
#include "pulsing.h"
// Makro za podesavanje visoke vrednosti signala na pinu
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


void pinPulsing( uint8_t port , uint8_t pin , uint32_t period ,uint8_t num_of_repetitions)
{
uint8_t i ;
// Implementacija num_of_repetitions perioda
for( i = 0; i < num_of_repetitions ; i ++)
pinPulse(port,pin,period);
}

void pinPulse( uint8_t port , uint8_t pin , uint32_t period)
{
// Poluperioda u kojoj pin ima visoku vrednost
pinSetValue( port , pin, HIGH);
timer0DelayMs(calculateHalfPeriod(period));
// Poluperioda u kojoj pin ima nisku vrednost
pinSetValue (port,pin,LOW);
timer0DelayMs(calculateHalfPeriod(period));
}

