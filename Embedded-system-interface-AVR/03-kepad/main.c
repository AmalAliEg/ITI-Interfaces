/*
 * main.c
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
#include "LCD_interface.h"
#include "LCD_config.h"
#include "KYP_interface.h"
#include "KYP_config.h"


#define show_char_on_lcd 1

#define calculator 0

int main()
{
#if show_char_on_lcd
	u8 Data;
	HKYP_vInit();
	HLCD_vInitLcd();
	HLCD_vSendChar('a');


	while(1)
	{
		Data=HKYP_u8ReadButton();
		if (Data!=NOT_PRESSED)
		{
			HLCD_vSendChar(Data);

		}
/*		if (Data == '#') {
			HLCD_vClrLcd();
		}*/

	}
#endif

#if calculator
	HKYP_vInit();
	HLCD_vInitLcd();
	HLCD_vDisplayString("aml");
	HLCD_vWriteNumber(2521);
	HLCD_vGotoXY(1,6);
	HLCD_vSendChar('a');

	while(1){

	}

#endif
}
