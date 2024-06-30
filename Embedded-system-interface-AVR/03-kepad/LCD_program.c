/*
 * LCD_program.c
 *
 *  Created on: Dec 10, 2023
 *      Author: Aml
 */

#include <util/delay.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"


//include lower layer if in hal then include mcal
#include "DIO_interface.h"

//include from same layer
#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"

copy_u8CustChar[]={
		{0x00,  0x1B,	0x1F,	0x1F,  0x1F,  0x1F,  0x0E,  0x04},	//heart
		{0x04,	0x00,	0x04,	0x0E,  0x0E,  0x0A,  0x15,  0x00}	};//bell

void HLCD_vInitLcd(void)
{
	/*set config of lcd pins*/
	MDIO_vSetPinDirection(CTR_PORT,	LCD_RS,	DIO_OUTPUT);
	MDIO_vSetPinDirection(CTR_PORT,	LCD_RW,	DIO_OUTPUT);
	MDIO_vSetPinDirection(CTR_PORT,	LCD_E,	DIO_OUTPUT);
	MDIO_vSetPortDirection(DATA_PORT,0xff);

	/*wait for more than 30ms*/
	_delay_ms(40);
	HLCD_vSendCommand(lcd_Home);
	_delay_ms(15);
	/*send function set command */
	HLCD_vSendCommand(Func_set);
	/*wait 39 us*/
	_delay_ms(1);
	/*send display on/off command*/
	HLCD_vSendCommand(Display_On_Off);
	/*wait 39 us*/
	_delay_ms(1);
	/*send clear command */
	HLCD_vSendCommand(Clear);
	_delay_ms(15);
	/*send entrymode command*/
	HLCD_vSendCommand(Entry_mode);
	_delay_ms(2);
}

static void HLCD_vSendCommand( u8 copy_u8command)
{
	/*set rs pin to 0 clr rs*/
	MDIO_vSetPinValue(CTR_PORT,LCD_RS,DIO_LOW);
	/*clr rw */
	MDIO_vSetPinValue(CTR_PORT,LCD_RW,DIO_LOW);

	/*set E pin*/
	MDIO_vSetPinValue(CTR_PORT,LCD_E,DIO_HIGH);

	/*send command */
	MDIO_vSetPortValue(DATA_PORT,copy_u8command);

	/*clr E*/
	MDIO_vSetPinValue(CTR_PORT,LCD_E,DIO_LOW);

	/*wait 5ms*/
	_delay_ms(5);
	/*set E pin*/
	MDIO_vSetPinValue(CTR_PORT,LCD_E,DIO_HIGH);

}


void HLCD_vSendChar( u8 copy_u8Char){
	/*set rs pin to 1 set rs*/
	MDIO_vSetPinValue(CTR_PORT, LCD_RS, DIO_HIGH);
	/*clr rw */
	MDIO_vSetPinValue(CTR_PORT, LCD_RW, DIO_LOW);

	/*set E pin*/
	MDIO_vSetPinValue(CTR_PORT, LCD_E, DIO_HIGH);

	/*send command */
	MDIO_vSetPortValue(DATA_PORT, copy_u8Char);

	/*clr E*/
	MDIO_vSetPinValue(CTR_PORT, LCD_E, DIO_LOW);

	/*wait 5ms*/
	_delay_ms(5);
	/*set E pin*/
	MDIO_vSetPinValue(CTR_PORT, LCD_E, DIO_HIGH);
}



void HLCD_vDisplayString( u8 *p_u8ptr){

	/*create infinite loop while()*/
	while ('\0'!= *p_u8ptr)
	{
		/*send char by char of the array */
		HLCD_vSendChar(*p_u8ptr);
		/*increment the iterator */
		p_u8ptr++;
	}
}

void HLCD_vWriteNumber(u16 Copy_u16Number)
{
	/*create arr to hold nums' digits*/
	u8 Local_u8arr[7]={0};

	/*turn number to char using itoa function */
	itoa(Copy_u16Number ,Local_u8arr,10);
	/*send the translated value to lcd */
	HLCD_vDisplayString(Local_u8arr);

}

void HLCD_vClrLcd(void){
	HLCD_vSendChar(Clear);

}


void HLCD_vGotoXY(u8 copy_u8PosX,u8 copy_u8PosY)
{
	u8 Local_Postion;		//the exact address to start write on lcd

	if (copy_u8PosX>=LCD_ROW_2 || copy_u8PosX <=LCD_ROW_2 ||copy_u8PosY>16 || copy_u8PosY<0)
	{
		Local_Postion=F_ADS1;
	}
	/*switch on the lines of lcd */
	switch(copy_u8PosX)
	{
	case LCD_ROW_1:
		Local_Postion=lcd_SetCursor+(copy_u8PosY-1);
		break;
	case LCD_ROW_2:
		Local_Postion=F_ADS1+(copy_u8PosY-1);
		break;
	}
	HLCD_vSendCommand(Local_Postion);
	_delay_ms(1);
	
}


void HLCD_vStrPosition(u8 copy_u8PosX,u8 copy_u8PosY,u8 *p_u8str)
{

	HLCD_vGotoXY(copy_u8PosX,copy_u8PosY);
	HLCD_vDisplayString(p_u8str);

}

void HLCD_vSaveCustomChar(u8 copy_u8location,u8 *p_u8pattern)
{
	/*create iterator */
	u8 iterator;
	/*AC points to CGRAM*/
	HLCD_vSendCommand(F_ADS_CG);
	/*draw char*/
	for (iterator=0; iterator<sizeof(copy_u8CustChar)/sizeof(copy_u8CustChar[0]); iterator++)
	{
		/*send char to CGRAM */
		HLCD_vSendChar(copy_u8CustChar[iterator]);
	}
	/*return AC to DDRAM*/
	HLCD_vGotoXY(0,0);
	/*send char to lcd*/
	for (iterator=0;iterator<8;iterator++)
	{
		HLCD_vSendChar(iterator);
	}

}

