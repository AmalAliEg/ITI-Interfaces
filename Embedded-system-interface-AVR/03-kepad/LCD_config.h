/*
 * LCD_config.h
 *
 *  Created on: Dec 10, 2023
 *      Author: Aml
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define DATA_PORT PORTB
#define CTR_PORT  PORTA

#define L_ADS0 0x27			//address of the last char in the first line --equalavent to 39 in decimal
#define F_ADS1 0x40			//address of the first char in the second line --equalavent to 64 in decimal
#define L_ADS1 0x67			//address of the last char in the second line --equalavent to 103 in decim
#define F_ADS_CG 0x40			//address of the first location in the CGRAM

#define LCD_ROW_1 0
#define LCD_ROW_2 1

#define LCD_RS PIN0
#define LCD_RW PIN1
#define LCD_E  PIN2


/*define commands*/

#define Defualt_DDRAM 		0x20			//default value inside the CGROM " "

#define Func_set			0x38
#define Display_On_Off     	0x0f
#define Clear				0x01
#define Entry_mode			0x06
#define lcd_SetCursor       0x80          // set cursor at first position in lcd
#define lcd_Home            0x02
#endif /* LCD_CONFIG_H_ */
