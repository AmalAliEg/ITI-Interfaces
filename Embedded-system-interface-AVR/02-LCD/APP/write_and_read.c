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


/*include HAL layer */
#include "../HAL/LCD_driver/LCD_private.h"
#include "../HAL/LCD_driver/LCD_config.h"
#include "../HAL/LCD_driver/LCD_interface.h"


/*include the MCAL layer */
#include "../MCAL/DIO_driver/DIO_private.h"
#include "../MCAL/DIO_driver/DIO_config.h"
#include "../MCAL/DIO_driver/DIO_interface.h"

/*include same layer */
#include "write_and_read.h"


	u8 copy_u8heartChr[]=	{	0x00,  	0x1B,	0x1F,	0x1F,  0x1F,  0x1F,  0x0E,  0x04};				//heart
	u8 copy_u8bellChr[]= 	{	0x04,	0x00,	0x04,	0x0E,  0x0E,  0x0A,  0x15,  0x00};				//bell
	u8 copy_u8FlowerChr[]= 	{	0x04, 	0x0E,  	0x1B,  	0x15,  0x1B,  0x0E,  0x04,  0x00};				//flower

void ShowCustomChar(void){
	HLCD_vInitLcd();
	//HLCD_vDisplayString("hello");
	HLCD_vSaveCustomChar(1,copy_u8heartChr);
	HLCD_vSaveCustomChar(2,copy_u8bellChr);
	HLCD_vSaveCustomChar(3,copy_u8FlowerChr);

	HLCD_vDisplayCustomChar(1);
	HLCD_vDisplayCustomChar(2);
	HLCD_vDisplayCustomChar(3);


	while (1);
}

void Print_name_use_char(void){
	HLCD_vInitLcd();
	HLCD_vSendChar('M');
	HLCD_vSendChar('O');
	HLCD_vSendChar('L');
	HLCD_vSendChar('L');
	HLCD_vSendChar('Y');


	while (1);
}

void Print_full_string(void){
	HLCD_vInitLcd();
	HLCD_vDisplayString("ILoveMMEou");
	//HLCD_vSendCommand(lcd_Home);
	HLCD_vSendCommand(Shift_Dis_right);

	HLCD_vSendCommand(Shift_Cur_Right);

	HLCD_vSendChar('a');

	while(1);
}

void Move_name(void){

	HLCD_vInitLcd();

	//HLCD_vGotoXY(0, 1);
	HLCD_vSendCommand(Clear);
	u8 name[] = "AMAL";
	u8 len = strlen(name);

	while (1) {
	        for (u8 i = 0; i < len + 8; i++) {
	        	HLCD_vSendCommand(Clear);
	            HLCD_vSendCommand(lcd_SetCursor + i);  // Set cursor position
	            HLCD_vDisplayString(name);
	            _delay_ms(1000);
	        }

	        for (u8 i = len + 9; i >= 0; i--) {
	        	HLCD_vSendCommand(Clear);
	        	HLCD_vSendCommand(lcd_SetCursor + i);
	        	HLCD_vDisplayString(name);
	            _delay_ms(1000);
	        }
	    }
}

void PrintNum(void)
{
	HLCD_vInitLcd();
	HLCD_vSendCommand(Clear);
	u16 arr[3]={10,55,62};
	for (u8 i=0;i<3;i++){
		HLCD_vWriteNumber(arr[i]);
		HLCD_vSendCommand(Shift_Cur_Right);
	}

	while (1){}
}
