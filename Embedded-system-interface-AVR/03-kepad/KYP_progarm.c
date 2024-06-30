/*
 * KYP_progarm.c
 *
 *  Created on: Dec 12, 2023
 *      Author: Aml
 */

/* lib */
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"


/* lower layer */
#include "DIO_interface.h"

/* same layer */

#include "KYP_interface.h"
#include "KYP_config.h"
#include "KYP_private.h"



void HKYP_vInit(void){

	//set keypad pin configurations
	//col. as output
	//row as inputs
	MDIO_vSetPortDirection(KYP_PORT,0x0f);
	//active pull-up resistor
	//deactivate for all col.
	MDIO_vSetPortValue(KYP_PORT,0xff);

}

u8 HKYP_u8ReadButton(void)
 {
	u8 Local_u8PressedKey = NOT_PRESSED;
	u8 col_iterator;
	u8 row_iterator;
	u8 Local_u8Pressed;
	u16 flag = 0;
	//u16 counter=0; //to check the de bounce

	u8 KEYPAD_arr[Row_num][Col_num] = { { '7', '8', '9', '/' },
										{ '4', '5', '6', '*' },
										{ '1', '2', '3', '-' },
										{ '#', '0', '=', '+' } };

	u8 col_arr[Col_num] = { COL_PIN0, COL_PIN1, COL_PIN2, COL_PIN3 };
	u8 row_arr[Row_num] = { ROW_PIN0, ROW_PIN1, ROW_PIN2, ROW_PIN3 };

	for (col_iterator = 0; col_iterator < Col_num; col_iterator++)
	{
		/*activate current col.*/
		MDIO_vSetPinValue(KYP_PORT, col_arr[col_iterator], DIO_LOW);
		for (row_iterator = 0; row_iterator < Row_num; row_iterator++)
		{
			Local_u8Pressed = MDIO_GetPinValue(KYP_PORT, row_arr[row_iterator]);
			/*check all rows*/
			if (DIO_LOW == Local_u8Pressed)
			{
				Local_u8PressedKey = KEYPAD_arr[row_iterator][col_iterator];

				/*busy wait -> de bounce*/
				while (DIO_LOW == Local_u8Pressed /*|| counter<1000*/)
				{
					Local_u8Pressed = MDIO_GetPinValue(KYP_PORT,row_arr[row_iterator]);
				}
				//_delay_ms(20);
				flag = 1;
				break;
			}
			else
			{/*do nothing*/}
		}
		if (DIO_HIGH== flag)
		{
			break;
		}
		else {/*do nothing*/}

		/*deactivate the current col.*/
		MDIO_vSetPinValue( KYP_PORT, col_arr[col_iterator], DIO_HIGH);
	}
	return Local_u8PressedKey;

}
