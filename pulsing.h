/*
 * pulsing.h
 *
 *  Created on: May 6, 2023
 *      Author: Adrian
 */

/*
 * pulsing.h
 *
 *  Created on: Apr 11, 2023
 *      Author: Adrian
 */
# include <avr/io.h>
# include <avr/interrupt.h>
# include <stdint.h>
#ifndef PULSING_H_
#define PULSING_H_

/*
* pinPulsing - Funkcija koja implementira num_of_repetitions
perioda podizanja i spustanja vrednosti na pinu
odgovarajucom brzinom
*/
void pinPulsing( uint8_t port , uint8_t pin , uint32_t period , uint8_t num_of_repetitions);
/*
* pinPulse - Funkcija koja implementiran podizanje i spustanje
vrednosti na pinu odgovarajucom brzinom
*/
void pinPulse(uint8_t port , uint8_t pin , uint32_t period);



#endif /* PULSING_H_ */
