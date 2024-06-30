/*
 * DIO_interface.h
 *
 *  Created on: Dec 9, 2023
 *      Author: Aml
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_private.h"

/************************************************************************************************************
*Error status
*/

/************************************************************************************************************/
typedef enum
{
	DIO_NOK,
	DIO_Ok
}DIO_ErrorStatus;


#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define DIO_OUTPUT 1
#define DIO_INPUT 0

#define DIO_HIGH 1
#define DIO_LOW 0


/************************************************************************************************************/
/*	function name:		DIO_ErrorStatus MDIO_vSetPortDirection( u8 copy_u8port,u8 copy_u8PortDirection)
 * 	function inputs:	Port number , value to be input  or output
 * 	function outputs:	DIO_ErrorStatus
 */
/************************************************************************************************************/
DIO_ErrorStatus MDIO_vSetPortDirection( u8 copy_u8port,u8 copy_u8PortDirection);


/************************************************************************************************************/
/*	function name:		DIO_ErrorStatus MDIO_vSetPortValue( u8 copy_u8port,u8 copy_u8PortValue)
 * 	function inputs:	Port number , value to be high or low
 * 	function outputs:	DIO_ErrorStatus
 */
/************************************************************************************************************/
DIO_ErrorStatus MDIO_vSetPortValue( u8 copy_u8port,u8 copy_u8PortValue);


/************************************************************************************************************/
/*	function name:		u8 MDIO_GetPortValue( u8 copy_u8port)
 * 	function inputs:	Port number
 * 	function outputs:	value is is high or low
 */
/************************************************************************************************************/
u8 MDIO_GetPortValue( u8 copy_u8port);






/************************************************************************************************************/
/*	function name:		DIO_ErrorStatus MDIO_vSetPinDirection( u8 copy_u8port,u8 copy_u8pin, u8 copy_u8PinDirection)
 * 	function inputs:	Port number , pin number ,value to be input  or output
 * 	function outputs:	DIO_ErrorStatus
 */
/************************************************************************************************************/
DIO_ErrorStatus MDIO_vSetPinDirection( u8 copy_u8port,u8 copy_u8pin, u8 copy_u8PinDirection);


/************************************************************************************************************/
/*	function name:		DIO_ErrorStatus MDIO_vSetPinValue( u8 copy_u8port,u8 copy_u8pin, u8 copy_u8PinDirection)
 * 	function inputs:	Port number , pin number, value to be high or low
 * 	function outputs:	DIO_ErrorStatus
 */
/************************************************************************************************************/
DIO_ErrorStatus MDIO_vSetPinValue( u8 copy_u8port,u8 copy_u8pin, u8 copy_u8PinValue);


/************************************************************************************************************/
/*	function name:		void MDIO_GetPinValue( u8 copy_u8port,u8 copy_u8pin)
 * 	function inputs:	Port number, Pin number
 * 	function outputs:	value is is high or low
 */
/************************************************************************************************************/
u8 MDIO_GetPinValue( u8 copy_u8port,u8 copy_u8pin);


/************************************************************************************************************/
/*	function name:		DIO_ErrorStatus MDIO_vTogglePinValue( u8 copy_u8port,u8 copy_u8pin, u8 copy_u8PinDirection)
 * 	function inputs:	Port number , pin number, value to be high or low
 * 	function outputs:	DIO_ErrorStatus
 */
/************************************************************************************************************/
DIO_ErrorStatus MDIO_vTogglePinValue( u8 copy_u8port,u8 copy_u8pin);
#endif /* DIO_INTERFACE_H_ */