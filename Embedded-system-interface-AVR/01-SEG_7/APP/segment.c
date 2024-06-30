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
#include "segment.h"


 u8 u8Mask (u8 copy_Number)
{
	 u8 Local_u8value=0;					//the number in binary
	switch (copy_Number)
	{
	case 0 :  Local_u8value= 0b00111111;	  break;
	case 1 :  Local_u8value= 0b00000110;	  break;
	case 2 :  Local_u8value= 0b01011011;	  break;
	case 3 :  Local_u8value= 0b01001111;	  break;
	case 4 :  Local_u8value= 0b01100110;	  break;
	case 5 :  Local_u8value= 0b01101101;	  break;
	case 6 :  Local_u8value= 0b01111101;	  break;
	case 7 :  Local_u8value= 0b00000111;	  break;
	case 8 :  Local_u8value= 0b01111111;	  break;
	case 9 :  Local_u8value= 0b01101111;	  break;
	}
	return Local_u8value;
}

void Show_Num_on7Seg(void) {

	HSSD_vInit(SS_PORT);

	while (1) {

		for (int i = 0; i < 10; i++) {
			MDIO_vSetPortValue(SS_PORT, u8Mask(i));
			_delay_ms(500);

		}
	}
}

void seg_lab1(void) {
	{

		HSSD_vInit(SSD_PORTA);

		while (1) {
			for (int i = 0; i < 10; i++) {
				HSSD_vDisplayNumber(SSD_PORTA, i, COMMON_CATHOD_SSD);
				_delay_ms(200);

			}
		}

	}
}



/****************************************************************************************/
/*
void Test_seg7(void){
	u8 arr_led={
			//gfedcba
			0b0111111,
			0b0000110,
			0b1011011,
			0b1001111,
			0b1100110,
			0b1101101,
			0b1111101,
			0b0000111,
			0b1111111,
			0b1101111	};

	u8 *ptr;
	ptr=&arr_led;

	MDIO_vSetPortDirection(PORTA, 0xFF);

	for (int i=0;i<10;i++)
	{
		MDIO_vSetPortValue(PORTA,ptr[i]);
		_delay_ms(500);

	}

	while (1) {

	}
}

*/
