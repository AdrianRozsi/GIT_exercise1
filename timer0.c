/*
 * timer0.c
 *
 *  Created on: Apr 11, 2023
 *      Author: Adrian
 */

# include <avr/io.h>
# include <avr/interrupt.h>
# include <stdint.h>
#include "timer0.h"

volatile uint32_t ms = 0;

void timer0DelayMs ( uint32_t delay_length )
{
// trenutak pocevsi od kog se racuna pauza
uint32_t t0 = timer0Millis() ;
// implementacija pauze
while ( timer0Millis() - t0 < delay_length );
}

uint32_t timer0Millis()
{
uint32_t tmp ;
cli () ; // Zabrana prekida
tmp = ms ; // Ocitavanje vremena
sei () ; // Dozvola prekida
return tmp;
}



void timer0Init()
{
// tajmer / brojac modul 0: CTC mod
TCCR0A = 0x02 ;
// Provera frekvencije takta prilikom kompilacije


uint32_t n = F_CPU / 1000;
uint8_t clksel = 1;
// Odredjivanje vrednosti preskalera i periode tajmer /

while ( n > 255)
{
n /= 8;
clksel ++;
}
// tajmer / brojac modul 0: Podesavanje preskalera
TCCR0B = clksel;
// tajmer / brojac modul 0: Podesavanje periode
OCR0A = ( uint8_t ) ( n & 0xff ) - 1;
// tajmer / brojac modul 0: Dozvola prekida
TIMSK0 = 0x02 ;
// Globalna dozvola prekida
sei();
}

ISR(TIMER0_COMPA_vect)
{
// Inkrementovanje broja milisekundi koje su prosle od

ms++;
}
