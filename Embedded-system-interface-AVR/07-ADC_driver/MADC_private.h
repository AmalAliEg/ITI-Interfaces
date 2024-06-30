/*
 * INT_private.h
 *
 *  Created on: Dec 18, 2023
 *      Author: Aml
 */

#ifndef MADC_PRIVATE_H_
#define MADC_PRIVATE_H_

//select the voltage reference for the ADC
#define ADMUX_REFS0 6  	//no. of bit 6 inside the ADMUX register
#define ADMUX_REFS1 7	//no. of bit 7 inside the ADMUX register

//Left Adjust Result by 0 or Right by 1
#define ADMUX_ADLAR 5	//no. of bit 5 inside the ADMUX register

//Analog Channel and Gain Selection Bits
#define ADMUX_MUX0 0	//no. of bit 0 inside the ADMUX register
#define ADMUX_MUX1 1	//no. of bit 1 inside the ADMUX register
#define ADMUX_MUX2 2	//no. of bit 2 inside the ADMUX register
#define ADMUX_MUX3 3	//no. of bit 3 inside the ADMUX register
#define ADMUX_MUX4 4	//no. of bit 4 inside the ADMUX register


//-----------------------------------------------------------------
//ADC Enable
#define ADCSRA_ADEN  7	//no. of bit 7 inside the ADCSRA register
//ADC Start Conversion
#define ADCSRA_ADSC  6	//no. of bit 6 inside the ADCSRA register
 //Auto Trigger
#define ADCSRA_ADATE 5	//no. of bit 5 inside the ADCSRA register
//C Interrupt Flag PIF
#define ADCSRA_ADIF  4	//no. of bit 4 inside the ADCSRA register
// ADC Interrupt Enable PIE
#define ADCSRA_ADIE  3	//no. of bit 3 inside the ADCSRA register

//: ADC Prescaler bits
#define ADCSRA_ADPS0 0	//no. of bit 0 inside the ADCSRA register
#define ADCSRA_ADPS1 1	//no. of bit 1 inside the ADCSRA register
#define ADCSRA_ADPS2 2	//no. of bit 2 inside the ADCSRA register

//-----------------------------------------------------------------






/*
 * define the register for all ports
 * it's not important to write volatile only for reg we read from
 */
#define ADMUX 	*(  (volatile u8*)  (0x27) )	//control reg and ctrl interrupt sense for IN0,IN1,IN2
#define ADCSRA 	*(  (volatile u8*)  (0x26) )	//control
//#define ADCH 	*(  (volatile u8*)  (0x25) )	//PIE of IN0,IN1,IN2
//#define ADCL 	*(  (volatile u8*)  (0x24) )	//PIF flag
#define ADC_DATA_REG 	*(  (volatile u16*)  (0x24) )	//PIF flag

#define SFIOR 	*(  (volatile u8*)  (0x50) )	//PIF flag


#define SREG  *((volatile u8*)(0x5F))         //Status Register__GIE

#endif /* MADC_PRIVATE_H_ */
