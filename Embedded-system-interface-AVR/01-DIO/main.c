/*
 * main.c
 *
 *  Created on: Jun 29, 2024
 *      Author: DELL
 */
#include <stdio.h>
#include <util/delay.h>
#include "DIO_interface.h"


int main()
{


	MDIO_vSetPinDirection(PORTC,PIN0,DIO_OUTPUT);

	for (int i=0 ;i<10;i++)
	{
		MDIO_vSetPinValue(PORTC,PIN0,DIO_HIGH);
		_delay_ms(100);
		MDIO_vSetPinValue(PORTC,PIN0,DIO_LOW);
	}
	return 0;
}

