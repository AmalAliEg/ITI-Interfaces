/*
 * BIT_MATH.h
 *
 *  Created on: Dec 6, 2023
 *      Author: Aml
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg, bit)      ( (reg) |=  (1 << (bit))           )

#define CLR_BIT(reg, bit)      (  (reg) &= ~(1 << (bit))          )

#define TOG_BIT(reg, bit)      (   (reg) ^=  (1 << (bit))         )

#define GET_BIT(reg, bit)      (     (    ((reg) >> (bit)) & 1)   )




#endif /* BIT_MATH_H_ */
