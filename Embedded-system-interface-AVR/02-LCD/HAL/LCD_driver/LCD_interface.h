/*					driver Card
 *
 *	project name:			LCD_interface.h
 *	project description:	set the implementation of the functions for the driver
 *  start date:				Dec 9, 2023
 *  Author: 				Eng. Amal Aly
 *  version:				V0.4
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_





/************************************************************************************************************/
/*	function name:		void HLCD_vSendCommend( u8 copy_u8commed);
 * 	function inputs:	copy_u8commend to talk to lcd
 * 	function outputs:	void
 */
/************************************************************************************************************/
 void HLCD_vSendCommand( u8 copy_u8command);

/************************************************************************************************************/
/*	function name:		void HLCD_vInitLcd( void);
 * 	function inputs:	void
 * 	function outputs:	void
 */
/************************************************************************************************************/
void HLCD_vInitLcd(void);


/************************************************************************************************************/
/*	function name:			void HLCD_vSendChar( u8 copy_u8Char);
 * 	function inputs:		copy_u8Char  to display on lcd
 * 	function outputs:		void
 *	function description: 	to display on lcd
 */
/************************************************************************************************************/
void HLCD_vSendChar( u8 copy_u8Char);


/************************************************************************************************************/
/*	function name:			void HLCD_vDisplayString( u8 *copy_u8ptr);
 * 	function inputs:		p_u8ptr
 * 	function outputs:		void
 *	function description: 	is a pointer to pass the array of characters
 */
/************************************************************************************************************/
void HLCD_vDisplayString( u8 *p_u8ptr);


/************************************************************************************************************/
/*	function name:		void HLCD_vWriteNumber(u16 Copy_u16Number);
 * 	function inputs:	Copy_u16Number 
 * 	function outputs:	void
 */
/************************************************************************************************************/
void HLCD_vWriteNumber(u16 Copy_u16Number);


/************************************************************************************************************/
/*	function name:		void HLCD_vClrLcd(void);
 * 	function inputs:	void
 * 	function outputs:	void
 */
/************************************************************************************************************/
void HLCD_vClrLcd(void);


/************************************************************************************************************/
/*	function name:			void HLCD_vGotoXY(u8 copy_u8PosX,u8 copy_u8PosY)
 * 	function inputs:		copy_u8PosX, copy_u8PosY
 * 	function outputs:		void
 *	function description: 	position of the curser in which row and which column
 */
/************************************************************************************************************/
void HLCD_vGotoXY(u8 copy_u8PosX,u8 copy_u8PosY);



/************************************************************************************************************/
/*	function name:			void HLCD_vStrPosition(u8 copy_u8PosX,u8 copy_u8PosY,p_u8str)
 * 	function inputs:		copy_u8PosX, copy_u8PosY, p_u8str
 * 	function outputs:		void
 *	function description: 	control the position of the string
 */
/************************************************************************************************************/

void HLCD_vStrPosition(u8 copy_u8PosX,u8 copy_u8PosY,u8 *p_u8str);



/************************************************************************************************************/
/*	function name:			void HLCD_vSaveCustomChar(u8 copy_u8address,u8 *ptr_u8array)
 * 	function inputs:		copy_u8location, p_u8pattern
 * 	function outputs:		void
 *	function description: 	store the generated char in CGRAM
 */
/************************************************************************************************************/

void HLCD_vSaveCustomChar(u8 copy_u8address,u8 *ptr_u8array);

/************************************************************************************************************/
/*	function name:			void HLCD_vDisplayCustomChar(u8 copy_u8address)
 * 	function inputs:	 	p_u8pattern
 * 	function outputs:		void
 *	function description: 	display on lcd the custom char
 */
/************************************************************************************************************/

void HLCD_vDisplayCustomChar(u8 copy_u8address);


#endif /* LCD_INTERFACE_H_ */
