/*
 * HSSD_program.c
 *
 *  Created on: Dec 31, 2023
 *      Author: Aml
 */

/*include libraries*/
#include "../../LIBRARY/BIT_MATH.h"
#include "../../LIBRARY/STD_TYPES.h"

/*include lower layer HALL*/
#include "HSSD_private.h"
#include "HSSD_config.h"
#include "HSSD_interface.h"

/*include lower layer MCAL*/
#include "../../MCAL/DIO_driver/DIO_private.h"
#include "../../MCAL/DIO_driver/DIO_config.h"
#include "../../MCAL/DIO_driver/DIO_interface.h"


/*create array of the SSD cotain bainary representation of each number*/
static u8 SSD_CathodeDisplayNum[10]= ARRAY_OF_CATHODE_NUM;
static u8 SSD_AnodeDisplayNum[10]= ARRAY_OF_ANODE_NUM;


void HSSD_vInit(u8 copy_u8PortSSD)
{
	switch (copy_u8PortSSD)
	{
		case SSD_PORTA: MDIO_vSetPortDirection(PORTA,SS_PORT_dir);	break;
		case SSD_PORTB: MDIO_vSetPortDirection(PORTB,SS_PORT_dir);	break;
		case SSD_PORTC: MDIO_vSetPortDirection(PORTC,SS_PORT_dir);	break;
		case SSD_PORTD: MDIO_vSetPortDirection(PORTD,SS_PORT_dir);	break;
	}
}

void HSSD_vDisplayNumber(u8 copy_u8PortSSD, u8 copy_u8Number, u8 copy_u8SSDtype) {

	int i;
	switch (copy_u8PortSSD) {
	case SSD_PORTA:
		if (copy_u8SSDtype == COMMON_CATHOD_SSD) {

			{
				if (copy_u8Number == SSD_CathodeDisplayNum[i])
					MDIO_vSetPortValue(PORTA, SSD_CathodeDisplayNum[i]);
			}

		} else if (copy_u8SSDtype == COMMON_ANODE_SSD) {
			if (copy_u8Number == SSD_AnodeDisplayNum[i]) {
				MDIO_vSetPortValue(PORTA, SSD_AnodeDisplayNum[i]);
			}

		} else {
		}

		break;
	case SSD_PORTB:
		if (copy_u8SSDtype == COMMON_CATHOD_SSD) {
			if (copy_u8Number == SSD_CathodeDisplayNum[i])
				MDIO_vSetPortValue(PORTB, SSD_CathodeDisplayNum[i]);

		} else if (copy_u8SSDtype == COMMON_ANODE_SSD) {
			if (copy_u8Number == SSD_AnodeDisplayNum[i])
				MDIO_vSetPortValue(PORTB, SSD_CathodeDisplayNum[i]);
		} else {
		}

		break;
	case SSD_PORTC:
		if (copy_u8SSDtype == COMMON_CATHOD_SSD) {
			if (copy_u8Number == SSD_CathodeDisplayNum[i])
				MDIO_vSetPortValue(PORTC, SSD_CathodeDisplayNum[i]);

		} else if (copy_u8SSDtype == COMMON_ANODE_SSD) {
			if (copy_u8Number == SSD_AnodeDisplayNum[i])
				MDIO_vSetPortValue(PORTC, SSD_AnodeDisplayNum[i]);

		} else {
		}

		break;

	case SSD_PORTD:
		if (copy_u8SSDtype == COMMON_CATHOD_SSD) {
			if (copy_u8Number == SSD_CathodeDisplayNum[i])
				MDIO_vSetPortValue(PORTD, SSD_CathodeDisplayNum[i]);

		} else if (copy_u8SSDtype == COMMON_ANODE_SSD) {
			if (copy_u8Number == SSD_AnodeDisplayNum[i])
				MDIO_vSetPortValue(PORTD, SSD_AnodeDisplayNum[i]);

		} else {
		}

		break;
	}
}



