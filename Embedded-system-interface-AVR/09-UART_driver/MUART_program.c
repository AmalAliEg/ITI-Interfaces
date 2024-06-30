/*
 * MUART_program.c
 *
 *  Created on: Dec 28, 2023
 *      Author: Aml
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

//include the drivers
#include "MUART_private.h"
#include "MUART_config.h"
#include "MUART_interface.h"


static void (*transmit_CallBack)(void);
static void (*receive_CallBack)(void);
static void (*UDRE_CallBack)(void);
/*------------------------------------------------------------*/
/*             functions implementations                      */
/*------------------------------------------------------------*/


void UART_vInit(void)
{
	/*instead of UCSRC itself as i can't set options directly to UCSRC	 */
	u8 UCSRC_register = 0;

	/* set buad rate*/
	UBRRL = UBRR_value;    //9600 bps
	/*selects between accessing the UCSRC or the UBRRH Register*/
#if REG_SELECT==UCSRC_reg_select
	SET_BIT(UCSRC_register,UCSRC_URSEL);
#elif  REG_SELECT==UCSRH_reg_select
	CLR_BIT(UCSRC_register,UCSRC_URSEL);
#endif

	/*payload size--5bits -->size of how many bits for the data */
#if PAYLOAD_SIZE==Bits_5
	CLR_BIT(UCSRB,UCSRB_UCSZ2);              	//UCSZ2
	CLR_BIT(UCSRC_register,UCSRC_UCSZ0);     	//UCSZ0
	CLR_BIT(UCSRC_register,UCSRC_UCSZ0);     	//UCSZ1
#elif PAYLOAD_SIZE==Bits_6
	CLR_BIT(UCSRB,UCSRB_UCSZ2);              	//UCSZ2
	SET_BIT(UCSRC_register,UCSRC_UCSZ0);     	//UCSZ0
	CLR_BIT(UCSRC_register,UCSRC_UCSZ0);     	//UCSZ1
#elif PAYLOAD_SIZE==Bits_7
	CLR_BIT(UCSRB,UCSRB_UCSZ2);              	//UCSZ2
	CLR_BIT(UCSRC_register,UCSRC_UCSZ0);     	//UCSZ0
	SET_BIT(UCSRC_register,UCSRC_UCSZ0);     	//UCSZ1
#elif PAYLOAD_SIZE==Bits_8
	CLR_BIT(UCSRB,UCSRB_UCSZ2);              	//UCSZ2
	SET_BIT(UCSRC_register,UCSRC_UCSZ0);     	//UCSZ0
	SET_BIT(UCSRC_register,UCSRC_UCSZ0);     	//UCSZ1
#elif PAYLOAD_SIZE==Bits_9
	SET_BIT(UCSRB,UCSRB_UCSZ2);              	//UCSZ2
	SET_BIT(UCSRC_register,UCSRC_UCSZ0);     	//UCSZ0
	SET_BIT(UCSRC_register,UCSRC_UCSZ0);     	//UCSZ1
	SET_BIT(UCSRB,UCSRB_TXB8);					// Transmit Data Bit 8
	SET_BIT(UCSRB,UCSRB_RXB8);					// Receive Data Bit  8
#endif

	/*enables the USART Receiver and transmitter. HW circuts --> in UCSRB register --RXEN,TXEN  */
	SET_BIT(UCSRB,UCSRB_RXEN);					//RXEN
	SET_BIT(UCSRB,UCSRB_TXEN); 					//TXEN

	/*number of stop bits */
#if STOP_BIT==Stop_bits_1
	CLR_BIT(UCSRC_register,UCSRC_USBS);
#elif STOP_BIT==Stop_bits_2
	SET_BIT(UCSRC_register,UCSRC_USBS);
#endif
	/* parity check control*/
#if PARITY_MODE==P_NO
	CLR_BIT(UCSRC_register, UCSRC_UPM0);
	CLR_BIT(UCSRC_register, UCSRC_UPM1);
#elif PARITY_MODE==P_ODD
	SET_BIT(UCSRC_register, UCSRC_UPM0);
	SET_BIT(UCSRC_register, UCSRC_UPM1);
#elif PARITY_MODE==P_EVEN
	CLR_BIT(UCSRC_register, UCSRC_UPM0);
	SET_BIT(UCSRC_register, UCSRC_UPM1);
#endif

	/*mode of operation.*/
#if USART_Mode==UART_ASYNCH
	CLR_BIT(UCSRC_register, UCSRC_UMSEL);
#elif USART_Mode==UART_SYNC
	SET_BIT(UCSRC_register,UCSRC_UMSEL);
#endif


	/*clock polarity if it synch.*/
#if CLK_POLARITY==TRANSMITE_RISING_RECEIVE_FALLING
	CLR_BIT(UCSRC_register, UCSRC_UCPOL);
#elif clock_polarity==TRANSMITE_FALLING_RECEIVE_RISING
	SET_BIT(UCSRC_register,UCSRC_UCPOL);
#endif

	UCSRC = UCSRC_register;

}

void UART_vSend(u8 data_send){
/*wait the data to be shifted from Tx shift register ,(UDR reg is empty)*/
	while (!GET_BIT(UCSRA,UCSRA_UDRE));    //do nothing }
		UDR=data_send;
}

u8 UART_u8Receive(void){
	/*wait the data to be shifted from Tx shift register ,(UDR reg is empty)*/
	while (GET_BIT(UCSRA,UCSRA_RXC)==0);

	return UDR;
}


u8 UART_u8GetRX_Data(void){
	return UDR;
}


void UART_vSendStr(char str[]) {

	while (*str != '\0') {
		UART_vSend(*str);
		str++;
	}
}

void UART_vRecciveStr(char *str , u16 size) {
	u8 flag=0;// flag to indicate that the user end the string
	for (u16 i=0;i<size-1;i++)
	{
		if (str[i]=='\n')
		{
			str[i]='\0';
			flag=1;
			break;
		}
		str[i]=UART_u8Receive();
	}
	if (flag==0)
	{
		str[size-1]='\0';
	}
}

void UART_EnableInt(void) {

	/*enable interrupts
	 * 1-RX complete
	 * 2-TX complete
	 * 3-UDR register empty
	 */
	SET_BIT(UCSRB,UCSRB_RXCIE);  		//PIE of RX
	SET_BIT(UCSRB,UCSRB_TXCIE);			//PIE of TX
	SET_BIT(UCSRB,UCSRB_UDRIE);			//PIE of udr empty flag

}

void UART_DisableInt(void) {
	/*disable interrupts
	 * 1-RX complete
	 * 2-TX complete
	 * 3-UDR register empty
	 */
	CLR_BIT(UCSRB,UCSRB_RXCIE);  		//PIE of RX
	CLR_BIT(UCSRB,UCSRB_TXCIE);			//PIE of TX
	CLR_BIT(UCSRB,UCSRB_UDRIE);			//PIE of udr empty flag

}

void UART_vSetBuadRate(u16 buad) {
	u16 Baud_value=( (FreQ/(16*buad))-1);
	UBRRL=(u8)Baud_value;
	UBRRH=(u8)Baud_value>>8;
}

void UART_CallBack(u8 source, void (*fptr)(void)) {
	switch(source)
	{

	case UART_TX:
	transmit_CallBack=fptr;
		break;
	case UART_RX:
	receive_CallBack=fptr;
		break;
	}

}

/**************************************************************************************************/
/*                                         ISR implementation                                     */
/**************************************************************************************************/


void __vector_13 (void) __attribute__((signal));
void __vector_13(void)
{
	if( receive_CallBack !=NULL)

	{receive_CallBack();

	}

}

void __vector_14 (void) __attribute__((signal));

void __vector_14(void)
{
	if (transmit_CallBack!=NULL)
	{UDRE_CallBack();

	}

}

void __vector_15 (void) __attribute__((signal));

void __vector_15(void)
{
	if (transmit_CallBack!=NULL)
	{transmit_CallBack();

	}

}

