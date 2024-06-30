
/*					driver Card
 *
 *	project name:			LCD_config.h
 *	project description:	set the configuration by the user of the functions for the driver
 *  start date:				Dec 10, 2023
 *  Author: 				Eng. Amal Aly
 *  version:				V0.0
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*configuration of the pins */
#define DATA_PORT 			PORTD
/*
 * OPTIONS:
 *
 * 	PORTA_reg
	PORTB_reg
	PORTC_reg
	PORTD_reg
 */
#define DATA_PORT_REG		PORTD_reg



#define CTR_PORT  			PORTC
#define LCD_RS 				PIN0
#define LCD_RW 				PIN1		//in bit 4 mode it connected to GND
#define LCD_E  				PIN2


/*address of the last char in the first line --equalavent to 39 in decimal*/
#define L_ADS0 				0x27
/*address of the first char in the second line --equalavent to 64 in decimal*/
#define F_ADS1 				0x40
/*address of the last char in the second line --equalavent to 103 in decim*/
#define L_ADS1 				0x67
/*address of the first location in the CGRAM*/
#define F_ADS_CG 			0x40

#define LCD_ROW_1 			0
#define LCD_ROW_2 			1

/*OPTIONS:
 * BIT_4
 * BIT_8
 */
#define LCD_mode			BIT_4



/*define commands*/
#define Defualt_DDRAM 				0x20			//default value inside the CGROM " "

#define Func_set					0x38			// 8-bit data, 2-line display, 5 x 7 font
#define lcd_FunctionSet4bit 		0x28          // 4-bit data, 2-line display, 5 x 7 font
#define Display_On_Off     			0x0f
#define lcd_DisplayOn       		0x0C          // display on, cursor off, don't blink character
#define Clear						0x01
#define Entry_mode					0x06
#define lcd_SetCursor     			0x80          // set cursor at first position in lcd
#define lcd_Home            		0x02
#define Shift_Cur_left				0x04
#define Shift_Dis_right				0x05
#define Shift_Dis_left				0x07
#define Shift_Cur_Right				0x06
#endif /* LCD_CONFIG_H_ */





