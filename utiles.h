/*
 * utiles.h
 *
 *  Created on: May 6, 2023
 *      Author: Adrian
 */

/*
 * utiles.h
 *
 *  Created on: Apr 11, 2023
 *      Author: Adrian
 */
# include <avr/io.h>
# include <avr/interrupt.h>
# include <stdint.h>
#ifndef UTILES_H_
#define UTILES_H_

/*
* c a lc u l a te H alfPeriod - Funkcija koja izracunava polovinu
prosledjene periode
*/
uint32_t calculateHalfPeriod(uint32_t period);

#endif /* UTILES_H_ */
