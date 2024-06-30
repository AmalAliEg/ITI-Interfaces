/*
 * snake.c
 *
 *  Created on: Jan 7, 2024
 *      Author: DELL
 */

/*include the libraries */
#include <util/delay.h>
#include "../LIBRARY/BIT_MATH.h"
#include "../LIBRARY/STD_TYPES.h"


/*include the HAL layer*/

#include "../HAL/SSD_driver/HSSD_private.h"
#include "../HAL/SSD_driver/HSSD_config.h"
#include "../HAL/SSD_driver/HSSD_interface.h"


/*include the MCAL layer */
#include "../MCAL/DIO_driver/DIO_private.h"
#include "../MCAL/DIO_driver/DIO_config.h"
#include "../MCAL/DIO_driver/DIO_interface.h"

/*include same layer */
#include "switch.h"


void DIP_switch_lab1(void){
	MDIO_vSetPortDirection(PORTA,0xff);				//set the direction for the led
	MDIO_vSetPinDirection(PORTB,PIN0,DIO_INPUT);	//set the direction for the switch
	MDIO_vSetPinValue(PORTB,PIN0,DIO_HIGH);			//activate the pull-up resistor
	while (1){
		if (!MDIO_GetPinValue(PORTB,PIN0)){
			MDIO_vSetPortValue(PORTA,0xff);
			_delay_ms(500);
			MDIO_vSetPortValue(PORTA,0);
			_delay_ms(500);
		}
		else
		{
			MDIO_vSetPortValue(PORTA,0);
		}
	}
}
