/*
 * DIO_program.c
 *
 *  Created on: Dec 9, 2023
 *      Author: Aml
 */

#include "../STD_TYPES.h"
#include "../BIT_MATH.h"

//include lower layer if in hal then include mcal

//include from same layer


#include "DIO_interface.h"


/************************************************************************************************************/
/*	function name:		MDIO_vSetPortDirection( u8 copy_u8port,u8 copy_u8PortDirection)
 * 	function inputs:	Port number , value to be input  or output
 * 	function outputs:	void
 */
/************************************************************************************************************/
void MDIO_vSetPortDirection( u8 copy_u8port,u8 copy_u8PortDirection){

	switch (copy_u8port)
	{
	case PORTA:
		DDRA_reg=copy_u8PortDirection;
		break;
	case PORTB:
		DDRB_reg=copy_u8PortDirection;
		break;
	case PORTC:
		DDRC_reg=copy_u8PortDirection;
		break;
	case PORTD:
		DDRD_reg=copy_u8PortDirection;
		break;
	}
}


/************************************************************************************************************/
/*	function name:		void MDIO_vSetPortValue( u8 copy_u8port,u8 copy_u8PortValue)
 * 	function inputs:	Port number , value to be high or low
 * 	function outputs:	void
 */
/************************************************************************************************************/
void MDIO_vSetPortValue( u8 copy_u8port,u8 copy_u8PortValue){

	switch (copy_u8port) {
	case PORTA:
		PORTA_reg = copy_u8PortValue;
		break;
	case PORTB:
		PORTB_reg = copy_u8PortValue;
		break;
	case PORTC:
		PORTC_reg = copy_u8PortValue;
		break;
	case PORTD:
		PORTD_reg = copy_u8PortValue;
		break;
	}
}


/************************************************************************************************************/
/*	function name:		u8 MDIO_GetPortValue( u8 copy_u8port)
 * 	function inputs:	Port number
 * 	function outputs:	value is is high or low
 */
/************************************************************************************************************/
u8 MDIO_GetPortValue( u8 copy_u8port){

	u8 value=0;
	switch (copy_u8port) {
	case PORTA:
		value = PINA_reg;
		break;
	case PORTB:
		value=PINB_reg;
		break;
	case PORTC:
		value=PINC_reg;
		break;
	case PORTD:
		value=PIND_reg;
		break;
	}
	return value;

}






/************************************************************************************************************/
/*	function name:		void MDIO_vSetPinDirection( u8 copy_u8port,u8 copy_u8pin, u8 copy_u8PinDirection)
 * 	function inputs:	Port number , pin number ,value to be input  or output
 * 	function outputs:	void
 */
/************************************************************************************************************/
void MDIO_vSetPinDirection( u8 copy_u8port,u8 copy_u8pin, u8 copy_u8PinDirection)
{

	if (copy_u8PinDirection == DIO_OUTPUT) 
	{
		switch (copy_u8port) 
		{
		case PORTA:
			SET_BIT(DDRA_reg, copy_u8pin);
			break;
		case PORTB:
			SET_BIT(DDRB_reg, copy_u8pin);
			break;
		case PORTC:
			SET_BIT(DDRC_reg, copy_u8pin);
			break;
		case PORTD:
			SET_BIT(DDRD_reg, copy_u8pin);
			break;
		}
	}
	else if (copy_u8PinDirection == DIO_INPUT) 
	{
		switch (copy_u8port) 
		{
		case PORTA:
			CLR_BIT(DDRA_reg, copy_u8pin);
			break;
		case PORTB:
			CLR_BIT(DDRB_reg, copy_u8pin);
			break;
		case PORTC:
			CLR_BIT(DDRC_reg, copy_u8pin);
			break;
		case PORTD:
			CLR_BIT(DDRD_reg, copy_u8pin);
			break;
		}
	}
}


/************************************************************************************************************/
/*	function name:		void SET_PIN_VALUE( u8 PORT_ID,u8 PIN_ID,u8 PORT_value
 * 	function inputs:	Port number , pin number, value to be high or low
 * 	function outputs:	void
 */
/************************************************************************************************************/
void MDIO_vSetPinValue( u8 copy_u8port,u8 copy_u8pin, u8 copy_u8PinValue)
{

	if (copy_u8PinValue == DIO_HIGH) 
	{
		switch (copy_u8port) 
		{
		case PORTA:
			SET_BIT(PORTA_reg, copy_u8pin);
			break;
		case PORTB:
			SET_BIT(PORTB_reg, copy_u8pin);
			break;
		case PORTC:
			SET_BIT(PORTC_reg, copy_u8pin);
			break;
		case PORTD:
			SET_BIT(PORTD_reg, copy_u8pin);
			break;
		}
	}
	else if (copy_u8PinValue == DIO_LOW) 
	{
		switch (copy_u8port) 
		{
		case PORTA:
			CLR_BIT(PORTA_reg, copy_u8pin);
			break;
		case PORTB:
			CLR_BIT(PORTB_reg, copy_u8pin);
			break;
		case PORTC:
			CLR_BIT(PORTC_reg, copy_u8pin);
			break;
		case PORTD:
			CLR_BIT(PORTD_reg, copy_u8pin);
			break;
		}
	}
}



/************************************************************************************************************/
/*	function name:		void GET_PIN_VALUE( u8 PORT,u8 PIN_ID)
 * 	function inputs:	Port number, Pin number
 * 	function outputs:	value is is high or low
 */
/************************************************************************************************************/
u8 MDIO_GetPinValue( u8 copy_u8port,u8 copy_u8pin){
	u8 value=0;
	switch (copy_u8port) {
	case PORTA:
		value = GET_BIT(PINA_reg,copy_u8pin);
		break;
	case PORTB:
		value = GET_BIT(PINB_reg,copy_u8pin);
		break;
	case PORTC:
		value = GET_BIT(PINC_reg,copy_u8pin);
		break;
	case PORTD:
		value = GET_BIT(PIND_reg,copy_u8pin);
		break;
	}
	return value;

}
