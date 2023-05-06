/*
 * utiles.c
 *
 *  Created on: May 6, 2023
 *      Author: Adrian
 */


# include <avr/io.h>
# include <avr/interrupt.h>
# include <stdint.h>
#include "utiles.h"

uint32_t calculateHalfPeriod( uint32_t period )
{
return ( period /2) ;
}
