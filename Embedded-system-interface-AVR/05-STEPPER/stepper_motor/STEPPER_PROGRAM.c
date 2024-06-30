/*
 * DIO_program.c
 *
 *  Created on: Sep 11, 2022
 *      Author: Aml
 */


#include "../BIT_MATH.h"
#include "../STD_TYPES.h"
//include the drivers
#include "../AVR_DIO/DIO_interface.h"

#include "STEPPER_CONFIG.h"
#include "STEPPER_INTERFACE.h"




/*------------------------------------------------------------*/
/*             functions implementations                      */
/*------------------------------------------------------------*/


void HStepper_init(u8 copy_u8StepperDir) {
	MDIO_vSetPortDirection(STEPPER_PORT, copy_u8StepperDir);

}

void HStepper_DIR_MODE(u8 DIRECTION,u8 steps_mode)

{
	if (steps_mode==Full_step)
	{



	switch (DIRECTION) {
	case ClockWise:

		MDIO_vSetPinValue(HW_PORT,Coil_Blue,DIO_HIGH);
		MDIO_vSetPinValue(HW_PORT,Coil_Pink,DIO_LOW);
		MDIO_vSetPinValue(HW_PORT,Coil_Yellow,DIO_LOW);
		MDIO_vSetPinValue(HW_PORT,Coil_Orange,DIO_LOW);


/*		HW_PORT=HW_PORT |(1<<Coil_Blue) & ~(1<<Coil_Pink) & ~(1<<Coil_Yellow) & ~(1<<Coil_Orange);*/

		_delay_ms(Stepper_speed);

		MDIO_vSetPinValue(HW_PORT,Coil_Blue,DIO_LOW);
		MDIO_vSetPinValue(HW_PORT,Coil_Pink,DIO_HIGH);
		MDIO_vSetPinValue(HW_PORT,Coil_Yellow,DIO_LOW);
		MDIO_vSetPinValue(HW_PORT,Coil_Orange,DIO_LOW);

/*		HW_PORT=HW_PORT &~(1<<Coil_Blue) |(1<<Coil_Pink) & ~(1<<Coil_Yellow) & ~(1<<Coil_Orange);*/

		_delay_ms(Stepper_speed);

		MDIO_vSetPinValue(HW_PORT,Coil_Blue,DIO_LOW);
		MDIO_vSetPinValue(HW_PORT,Coil_Pink,DIO_LOW);
		MDIO_vSetPinValue(HW_PORT,Coil_Yellow,DIO_HIGH);
		MDIO_vSetPinValue(HW_PORT,Coil_Orange,DIO_LOW);

/*		HW_PORT=HW_PORT &~(1<<Coil_Blue) &~(1<<Coil_Pink) | (1<<Coil_Yellow) & ~(1<<Coil_Orange);*/

		_delay_ms(Stepper_speed);
		MDIO_vSetPinValue(HW_PORT,Coil_Blue,DIO_LOW);
		MDIO_vSetPinValue(HW_PORT,Coil_Pink,DIO_LOW);
		MDIO_vSetPinValue(HW_PORT,Coil_Yellow,DIO_LOW);
		MDIO_vSetPinValue(HW_PORT,Coil_Orange,DIO_HIGH);


/*		HW_PORT=HW_PORT &~(1<<Coil_Blue) &~(1<<Coil_Pink) & ~(1<<Coil_Yellow) |(1<<Coil_Orange);*/

		_delay_ms(Stepper_speed);
		break;
	case Anti_ClockWise:
		MDIO_vSetPinValue(HW_PORT,Coil_Blue,DIO_LOW);
		MDIO_vSetPinValue(HW_PORT,Coil_Pink,DIO_LOW);
		MDIO_vSetPinValue(HW_PORT,Coil_Yellow,DIO_LOW);
		MDIO_vSetPinValue(HW_PORT,Coil_Orange,DIO_HIGH);


		_delay_ms(Stepper_speed);
		MDIO_vSetPinValue(HW_PORT,Coil_Blue,DIO_LOW);
		MDIO_vSetPinValue(HW_PORT,Coil_Pink,DIO_LOW);
		MDIO_vSetPinValue(HW_PORT,Coil_Yellow,DIO_HIGH);
		MDIO_vSetPinValue(HW_PORT,Coil_Orange,DIO_LOW);


		_delay_ms(Stepper_speed);
		MDIO_vSetPinValue(HW_PORT,Coil_Blue,DIO_LOW);
		MDIO_vSetPinValue(HW_PORT,Coil_Pink,DIO_HIGH);
		MDIO_vSetPinValue(HW_PORT,Coil_Yellow,DIO_LOW);
		MDIO_vSetPinValue(HW_PORT,Coil_Orange,DIO_LOW);

		_delay_ms(Stepper_speed);
		MDIO_vSetPinValue(HW_PORT,Coil_Blue,DIO_HIGH);
		MDIO_vSetPinValue(HW_PORT,Coil_Pink,DIO_LOW);
		MDIO_vSetPinValue(HW_PORT,Coil_Yellow,DIO_LOW);
		MDIO_vSetPinValue(HW_PORT,Coil_Orange,DIO_LOW);


		_delay_ms(Stepper_speed);
		break;

	}
	}
	else if (steps_mode==half_step)
	{
		switch (DIRECTION) {
		case ClockWise:
			MDIO_vSetPinValue(HW_PORT,Coil_Blue,DIO_HIGH);
			MDIO_vSetPinValue(HW_PORT,Coil_Pink,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Yellow,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Orange,DIO_HIGH);


			_delay_ms(Stepper_speed);
			MDIO_vSetPinValue(HW_PORT,Coil_Blue,DIO_HIGH);
			MDIO_vSetPinValue(HW_PORT,Coil_Pink,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Yellow,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Orange,DIO_LOW);


			_delay_ms(Stepper_speed);
			MDIO_vSetPinValue(HW_PORT,Coil_Blue,DIO_HIGH);
			MDIO_vSetPinValue(HW_PORT,Coil_Pink,DIO_HIGH);
			MDIO_vSetPinValue(HW_PORT,Coil_Yellow,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Orange,DIO_LOW);

			_delay_ms(Stepper_speed);
			MDIO_vSetPinValue(HW_PORT,Coil_Blue,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Pink,DIO_HIGH);
			MDIO_vSetPinValue(HW_PORT,Coil_Yellow,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Orange,DIO_LOW);

			_delay_ms(Stepper_speed);
			MDIO_vSetPinValue(HW_PORT,Coil_Blue,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Pink,DIO_HIGH);
			MDIO_vSetPinValue(HW_PORT,Coil_Yellow,DIO_HIGH);
			MDIO_vSetPinValue(HW_PORT,Coil_Orange,DIO_LOW);


			_delay_ms(Stepper_speed);
			MDIO_vSetPinValue(HW_PORT,Coil_Blue,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Pink,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Yellow,DIO_HIGH);
			MDIO_vSetPinValue(HW_PORT,Coil_Orange,DIO_LOW);

			_delay_ms(Stepper_speed);

			MDIO_vSetPinValue(HW_PORT,Coil_Blue,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Pink,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Yellow,DIO_HIGH);
			MDIO_vSetPinValue(HW_PORT,Coil_Orange,DIO_HIGH);


			_delay_ms(Stepper_speed);
			MDIO_vSetPinValue(HW_PORT,Coil_Blue,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Pink,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Yellow,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Orange,DIO_HIGH);


			_delay_ms(Stepper_speed);
			break;


		case Anti_ClockWise:
			MDIO_vSetPinValue(HW_PORT,Coil_Blue,DIO_HIGH);
			MDIO_vSetPinValue(HW_PORT,Coil_Pink,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Yellow,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Orange,DIO_HIGH);


			_delay_ms(Stepper_speed);
			MDIO_vSetPinValue(HW_PORT,Coil_Blue,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Pink,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Yellow,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Orange,DIO_HIGH);


			_delay_ms(Stepper_speed);
			MDIO_vSetPinValue(HW_PORT,Coil_Blue,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Pink,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Yellow,DIO_HIGH);
			MDIO_vSetPinValue(HW_PORT,Coil_Orange,DIO_HIGH);


			_delay_ms(Stepper_speed);
			MDIO_vSetPinValue(HW_PORT,Coil_Blue,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Pink,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Yellow,DIO_HIGH);
			MDIO_vSetPinValue(HW_PORT,Coil_Orange,DIO_LOW);


			_delay_ms(Stepper_speed);

			MDIO_vSetPinValue(HW_PORT,Coil_Blue,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Pink,DIO_HIGH);
			MDIO_vSetPinValue(HW_PORT,Coil_Yellow,DIO_HIGH);
			MDIO_vSetPinValue(HW_PORT,Coil_Orange,DIO_LOW);

			_delay_ms(Stepper_speed);

			MDIO_vSetPinValue(HW_PORT,Coil_Blue,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Pink,DIO_HIGH);
			MDIO_vSetPinValue(HW_PORT,Coil_Yellow,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Orange,DIO_LOW);

			_delay_ms(Stepper_speed);
			MDIO_vSetPinValue(HW_PORT,Coil_Blue,DIO_HIGH);
			MDIO_vSetPinValue(HW_PORT,Coil_Pink,DIO_HIGH);
			MDIO_vSetPinValue(HW_PORT,Coil_Yellow,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Orange,DIO_LOW);


			_delay_ms(Stepper_speed);
			MDIO_vSetPinValue(HW_PORT,Coil_Blue,DIO_HIGH);
			MDIO_vSetPinValue(HW_PORT,Coil_Pink,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Yellow,DIO_LOW);
			MDIO_vSetPinValue(HW_PORT,Coil_Orange,DIO_HIGH);


			_delay_ms(Stepper_speed);


			break;

		}
	}
}




