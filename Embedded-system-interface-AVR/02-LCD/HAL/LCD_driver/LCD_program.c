/*					driver Card
 *
 *	project name:			LCD_program.c
 *	project description:	set the implementation of the functions for the driver
 *  start date:				Dec 10, 2023
 *  Author: 				Eng. Amal Aly
 *  version:				V0.4
 */

#include <util/delay.h>


#include "../../LIBRARY/STD_TYPES.h"
#include "../../LIBRARY/BIT_MATH.h"


//include lower layer
#include "../../MCAL/DIO_driver/DIO_interface.h"

//include from same layer
#include "LCD_config.h"
#include "LCD_private.h"
#include "LCD_interface.h"



 void HLCD_vSendCommand( u8 copy_u8command)
{

#if LCD_mode==BIT_8
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
#elif LCD_mode==BIT_4
		/* 1-set RS pin to LOW '0'*/
		MDIO_vSetPinValue(CTR_PORT,LCD_RS,DIO_LOW);
		/*clr rw */
		MDIO_vSetPinValue(CTR_PORT,LCD_RW,DIO_LOW);

		/* 3-set D0 to D7 pins as output to write the command*/
		DATA_PORT_REG = (DATA_PORT_REG & 0x0F) | (copy_u8command & 0xF0);
		/* 4- set E pin pulse*/
		MDIO_vSetPinValue(CTR_PORT,LCD_E, DIO_HIGH);
		_delay_ms(1);
		MDIO_vSetPinValue(CTR_PORT,LCD_E, DIO_LOW);
		_delay_ms(1);


		/* set D0 to D7 pins as output to write the command*/
		DATA_PORT_REG = (DATA_PORT_REG & 0x0F) | (copy_u8command <<4 );
		/* 4- set E pin pulse*/
		MDIO_vSetPinValue(CTR_PORT,LCD_E, DIO_HIGH);
		_delay_ms(1);
		MDIO_vSetPinValue(CTR_PORT,LCD_E, DIO_LOW);
		_delay_ms(1);
#endif

}


void HLCD_vSendChar( u8 copy_u8Char){

#if LCD_mode==BIT_8
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
#elif LCD_mode==BIT_4
	/* 1-set RS pin to HIGH '1'*/
	MDIO_vSetPinValue(CTR_PORT,LCD_RS, DIO_HIGH);
	/*clr rw */
	MDIO_vSetPinValue(CTR_PORT, LCD_RW, DIO_LOW);

	/* 3-set D0 to D7 pins as output to write the command*/
	DATA_PORT_REG = (DATA_PORT_REG & 0x0F) | (copy_u8Char & 0xF0);

	/* 4- set E pin pulse*/
	MDIO_vSetPinValue(CTR_PORT,LCD_E, DIO_HIGH);
	_delay_ms(1);
	MDIO_vSetPinValue(CTR_PORT,LCD_E, DIO_LOW);
	_delay_ms(1);

	DATA_PORT_REG = (DATA_PORT_REG & 0x0F) | (copy_u8Char <<4);

	/* 4- set E pin pulse*/
	MDIO_vSetPinValue(CTR_PORT,LCD_E, DIO_HIGH);
	_delay_ms(1);
	MDIO_vSetPinValue(CTR_PORT,LCD_E, DIO_LOW);
	_delay_ms(1);
#endif
}




void HLCD_vInitLcd(void)
{
	/*set config of lcd pins*/
	MDIO_vSetPinDirection(CTR_PORT,	LCD_RS,	DIO_OUTPUT);
	MDIO_vSetPinDirection(CTR_PORT,	LCD_RW,	DIO_OUTPUT);
	MDIO_vSetPinDirection(CTR_PORT,	LCD_E,	DIO_OUTPUT);
	MDIO_vSetPortDirection(DATA_PORT,0xff);
#if LCD_mode==BIT_8
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
#elif LCD_mode==BIT_4
	_delay_ms(40);
	HLCD_vSendCommand(lcd_Home);
	_delay_ms(15);
	HLCD_vSendCommand(lcd_FunctionSet4bit);
	_delay_ms(1);
	HLCD_vSendCommand(lcd_DisplayOn);
	_delay_ms(1);
	HLCD_vSendCommand(Clear);
	_delay_ms(15);
	HLCD_vSendCommand(Entry_mode);
	_delay_ms(2);
#endif

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
	u8 digits[11] = {0} ;

	/* extract each digit in the array (reversed) */
	u8 i=0;
	while(Copy_u16Number > 0)
	{
		digits[i] = Copy_u16Number%10 ; // extract units digit
		Copy_u16Number /= 10 ; // shift the number to the right by one decimal place
		i++ ;
	}

	for(s8 j=i-1; j>=0; j--)
	{
		HLCD_vSendChar(digits[j] + '0'); // convert digit to ASCII representation
	}


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
	}
	HLCD_vSendCommand(Local_Postion);
	_delay_ms(1);
	
}


void HLCD_vStrPosition(u8 copy_u8PosX,u8 copy_u8PosY,u8 *p_u8str)
{

	HLCD_vGotoXY(copy_u8PosX,copy_u8PosY);
	HLCD_vDisplayString(p_u8str);

}

void HLCD_vDisplayCustomChar(u8 copy_u8address)
{
	if (copy_u8address<8)
	{
		HLCD_vSendChar(copy_u8address);
	}
}

void HLCD_vSaveCustomChar(u8 copy_u8address,u8 *ptr_u8array)
{
	if (copy_u8address<8)
	{
		HLCD_vSendCommand(0b01000000+(copy_u8address*8));   //here we access CGRAM
		for (u8 i =0 ; i<8;i++)
		{
			HLCD_vSendChar(ptr_u8array[i]);  //array of the 0's and 1's to form the custom character within 5*7 size
		}
		HLCD_vSendCommand(0b10000000);

	}


}
/*

void HLCD_vSaveCustomChar(u8 copy_u8location,u8 *p_u8pattern)
{
	//create iterator
	u8 iterator;
	//AC points to CGRAM
	HLCD_vSendCommand(F_ADS_CG);
	//draw char
	for (iterator=0; iterator<sizeof(copy_u8CustChar)/sizeof(copy_u8CustChar[0]); iterator++)
	{
		//send char to CGRAM
		HLCD_vSendChar(copy_u8CustChar[iterator]);
	}
	//return AC to DDRAM
	HLCD_vGotoXY(0,0);
	//send char to lcd
	for (iterator=0;iterator<8;iterator++)
	{
		HLCD_vSendChar(iterator);
	}

}
*/

