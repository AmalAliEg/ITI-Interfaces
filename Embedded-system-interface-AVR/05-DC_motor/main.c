/*
 * main.c
 *
 *  Created on: Dec 13, 2023
 *      Author: Aml
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "util/delay.h"

#define a 0
#define b 1

int main ()
{


#if a

	AVR_DIO_SetPinDirection(DIO_PORTB,DIO_PIN0,DIO_OUTPUT);   //DDR reg is output
		while (1)
		{
			AVR_DIO_SetPinValue(DIO_PORTB,DIO_PIN0,DIO_HIGH);  		// PORT reg is high
			_delay_ms(100);
			AVR_DIO_SetPinValue(DIO_PORTB,DIO_PIN0,DIO_LOW);  		// PORT reg is low
			_delay_ms(100);

		}

#endif

#if b

		/*for motor*/
	MDIO_vSetPinDirection(PORTD,PIN0,DIO_OUTPUT);
	MDIO_vSetPinDirection(PORTD,PIN1,DIO_OUTPUT);

		/*for switch*/
	MDIO_vSetPinDirection(PORTC,PIN0,DIO_INPUT);
	MDIO_vSetPinDirection(PORTC,PIN1,DIO_INPUT);
		/*for pull-up*/
	MDIO_vSetPinValue(PORTC,PIN0,DIO_HIGH);
	MDIO_vSetPinValue(PORTC,PIN1,DIO_HIGH);

	u8 ClW;
	u8 Anti_Clw;

	while (1)
	{

		ClW =MDIO_GetPinValue(PORTC,PIN0);
		if (0==ClW)
		{
			MDIO_vSetPinValue(PORTD,PIN0,DIO_HIGH);
			MDIO_vSetPinValue(PORTD,PIN1,DIO_LOW);

		}
		else if (1==ClW)
		{
			MDIO_vSetPinValue(PORTD,PIN0,DIO_LOW);
			MDIO_vSetPinValue(PORTD,PIN1,DIO_LOW);
		}
		else {}

		Anti_Clw=MDIO_GetPinValue(PORTC,PIN1);
		if (0==Anti_Clw)
		{
			MDIO_vSetPinValue(PORTD,PIN0,DIO_LOW);
			MDIO_vSetPinValue(PORTD,PIN1,DIO_HIGH);
		}
		else if (1==Anti_Clw)
		{
			MDIO_vSetPinValue(PORTD,PIN0,DIO_LOW);
			MDIO_vSetPinValue(PORTD,PIN1,DIO_LOW);
		}
		else{/*do  nothing */}

	}

#endif


}
