/*
 * main.c
 *
 *  Created on: May 20, 2023
 *      Author: Aml
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AVR_DIO/DIO_interface.h"

#include "stepper_motor/STEPPER_INTERFACE.h"
#include "stepper_motor/STEPPER_CONFIG.h"

#define dc 0
#define d 0
int main()
{

#if dc

		MDIO_vSetPortDirection(PORTA, 0xff);
		/*for motor*/
		MDIO_vSetPinDirection(PORTA,PIN0,DIO_OUTPUT);
		MDIO_vSetPinDirection(PORTA,PIN1,DIO_OUTPUT);

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
				MDIO_vSetPinValue(PORTA,PIN0,DIO_HIGH);
				MDIO_vSetPinValue(PORTA,PIN1,DIO_LOW);

			}
			else if (1==ClW)
			{
				MDIO_vSetPinValue(PORTA,PIN0,DIO_LOW);
				MDIO_vSetPinValue(PORTA,PIN1,DIO_LOW);
			}
			else {}

			Anti_Clw=MDIO_GetPinValue(PORTC,PIN1);
			if (0==Anti_Clw)
			{
				MDIO_vSetPinValue(PORTA,PIN0,DIO_LOW);
				MDIO_vSetPinValue(PORTA,PIN1,DIO_HIGH);
			}
			else if (1==Anti_Clw)
			{
				MDIO_vSetPinValue(PORTA,PIN0,DIO_LOW);
				MDIO_vSetPinValue(PORTA,PIN1,DIO_LOW);
			}
			else{/*do  nothing */}

		}


}

#endif

HStepper_init(0xff);
	u16 i;


	while (1)
	{

		/* Rotate anti clock wise for 5 seconds */
		for (i= 0;  i<Full_haptic_angle;  i++)
		{
			HStepper_DIR_MODE(Anti_ClockWise,Full_step);
		}
	}

#if d
	while (1)
	{
		
		/* Rotate clock wise for 5 seconds */
		for (i=0;i<250;i++)
		{
			STEPPER_DIR_MODE(ClockWise,Full_step);
		}

		/* Rotate anti clock wise for 5 seconds */
		for (i=0;i<250;i++)
		{
			STEPPER_DIR_MODE(Anti_ClockWise,Full_step);
		}

	}
#endif

}

