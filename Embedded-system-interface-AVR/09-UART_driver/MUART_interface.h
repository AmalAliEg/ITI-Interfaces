/*
 * MUART_interface.h
 *
 *  Created on: Dec 28, 2023
 *      Author: Aml
 */

#ifndef MUART_INTERFACE_H_
#define MUART_INTERFACE_H_


#include "BIT_MATH.h"
#include "STD_TYPES.h"

/*define the mode of protocole Asynchronanse - syncronanse **/
#define UART_ASYNCH		1
#define UART_SYNC 		2

#define Stop_bits_1 	1
#define Stop_bits_2 	2

/*define clock polarity */
#define TRANSMITE_RISING_RECEIVE_FALLING	1
#define TRANSMITE_FALLING_RECEIVE_RISING	2


/*define parity mode*/
#define P_EVEN		1
#define	P_ODD 		2
#define	P_NO 		3

/*define interrupt state */
#define EN_INT		1
#define DIS_INT		2


#define UART_TX 	1
#define UART_RX 	2

/*select which reg to use UCSRC or USCRH*/
#define UCSRC_reg_select 1
#define UCSRH_reg_select 2

/*define the payload*/
#define Bits_5	1
#define Bits_6	2
#define Bits_7	3
#define Bits_8	4
#define Bits_9	5


/************************************************************************************************************/
/*	function name:		void UART_init(void)
 * 	function inputs:	void
 * 	function outputs:	void
 * 	description:		configure the USART protocol
 */
/************************************************************************************************************/
void UART_vInit(void);

/************************************************************************************************************/
/*	function name:		void UART_Send(u8 data_send)
 * 	function inputs:	data to send send
 * 	function outputs:	void
 * 	description:		send char by char (8 bits at time )
 */
/************************************************************************************************************/
void UART_vSend(u8 data_send);

/************************************************************************************************************/
/*	function name:		u8 UART_Receive(void)
 * 	function inputs:	void
 * 	function outputs:	data to be receive
 * 	description:		receive  char by char (8 bits at time )
 */
/************************************************************************************************************/
u8 UART_u8Receive(void);

/************************************************************************************************************/
/*	function name:		void UART_PrintStr(char str[]);
 * 	function inputs:	address of first element in the string
 * 	function outputs:	void
 * 	description:		send a string
 */
/************************************************************************************************************/
void UART_vSendStr(char str[]);

/************************************************************************************************************/
/*	function name:		void UART_RecciveStr(char str[],u16 size);
 * 	function inputs:	address of first element in the string and it's size
 * 	function outputs:	void
 * 	description:		recieve a string
 */
/************************************************************************************************************/
void UART_vRecciveStr(char str[],u16 size);

/************************************************************************************************************/
/*	function name:		void UART_EnableInt(void)
 * 	function inputs:	void
 * 	function outputs:	void
 * 	description:		enable the interrupt
 */
/************************************************************************************************************/
void UART_EnableInt(void );

/************************************************************************************************************/
/*	function name:		void UART_DisableInt(void)
 * 	function inputs:	void
 * 	function outputs:	void
 * 	description:		disable the interrupt
 */
/************************************************************************************************************/
void UART_DisableInt(void );

/************************************************************************************************************/
/*	function name:		void UART_CallBack(u8 source, void (*fptr)(void))
 * 	function inputs:	void
 * 	function outputs:	void
 * 	description:		configure the USART protocol
 */
/************************************************************************************************************/
void UART_CallBack(u8 source, void (*fptr)(void));

/************************************************************************************************************/
/*	function name:		void UART_init(void)
 * 	function inputs:	void
 * 	function outputs:	void
 * 	description:		configure the USART protocol
 */
/************************************************************************************************************/


/************************************************************************************************************/
/*	function name:		void UART_init(void)
 * 	function inputs:	void
 * 	function outputs:	void
 * 	description:		configure the USART protocol
 */
/************************************************************************************************************/
void UART_vSetBuadRate(u16 buad);


/************************************************************************************************************/
/*	function name:		void UART_init(void)
 * 	function inputs:	void
 * 	function outputs:	void
 * 	description:		configure the USART protocol
 */
/************************************************************************************************************/
u8 UART_u8GetRX_Data(void);




#endif /* MUART_INTERFACE_H_ */
