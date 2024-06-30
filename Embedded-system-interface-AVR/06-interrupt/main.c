/*
 * main.c
 *
 *  Created on: Dec 18, 2023
 *      Author: Aml
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include  <util/delay.h>
#include "DIO_private.h"
#include "DIO_config.h"
#include "DIO_interface.h"

#include "MGIE_private.h"
#include "MGIE_config.h"
#include "MGIE_interface.h"

#include "MEXIT_private.h"
#include "MEXIT_config.h"
#include "MEXIT_interface.h"

void toggle_int0(void)

{
	MDIO_vTogglePinValue(PORTC,PIN1);	//led      in2
	MDIO_vTogglePinValue(PORTC,PIN3);	//led      in2
}

void toggle_int1(void)

{
MDIO_vTogglePinValue(PORTD,PIN3);
}

void toggle_int2(void)

{
MDIO_vTogglePinValue(PORTB,PIN2);
}


int main()


{
	MDIO_vSetPinDirection(PORTD,PIN2,DIO_INPUT);  	//switch   in0
	MDIO_vSetPinValue(PORTD,PIN2,DIO_HIGH);			//pull-up

	//MDIO_vSetPinDirection(PORTD,PIN3,DIO_INPUT);	//switch1  in1
	MDIO_vSetPinDirection(PORTC,PIN5,DIO_OUTPUT);	//led      in2

	MDIO_vSetPinDirection(PORTC,PIN1,DIO_OUTPUT);	//led
	MDIO_vSetPinDirection(PORTC,PIN3,DIO_OUTPUT);	//led



	MEXIT_vIntInit();
	MEXIT_enumEnableIterrupt(IN0);
	MEXIT_enumCallBack(toggle_int0,IN0);
	MGIE_Init();

	while(1)
	{
		MDIO_vSetPinValue(PORTC,PIN5,DIO_HIGH);	//led      in2
		_delay_ms(500);
		MDIO_vSetPinValue(PORTC,PIN5,DIO_LOW);	//led      in2
		_delay_ms(500);

	}
}
