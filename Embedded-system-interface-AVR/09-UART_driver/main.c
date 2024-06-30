/*
 * main.c
 *
 *  Created on: May 20, 2023
 *      Author: Aml
 */
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include  "DIO_private.h"
#include "DIO_config.h"
#include "DIO_interface.h"

#include "MUART_private.h"
#include "MUART_config.h"
#include "MUART_interface.h"

#define test_UART 1
#define test_UART_INTERRUPT 0
#define test 0



#if test



int main (){

	u8 x;
	MDIO_vSetPortDirection(PORTC,DIO_OUTPUT);

//	MDIO_vSetPinValue(PORTD,PIN3,DIO_LOW);
	UART_vInit();
//	UART_vSendStr("helloAVR");
	UART_vSend('1');
			MDIO_vSetPinDirection(PORTD,PIN5,DIO_HIGH);
			_delay_ms(50);
			MDIO_vSetPinDirection(PORTD,PIN5,DIO_LOW);
			UART_vSend('8');
			MDIO_vSetPinDirection(PORTD,PIN6,DIO_HIGH);
			_delay_ms(50);
			MDIO_vSetPinDirection(PORTD,PIN6,DIO_LOW);
			UART_vSend('6');
			MDIO_vSetPinDirection(PORTD,PIN7,DIO_HIGH);
			_delay_ms(50);
			MDIO_vSetPinDirection(PORTD,PIN7,DIO_LOW);

			_delay_ms(50);

	while (1){


		x=UART_u8Receive();
		if (x=='1')
		{
			MDIO_vTogglePinValue(PORTD,PIN2);

		}
		if (x=='3')
		{
			MDIO_vTogglePinValue(PORTD,PIN3);

		}
	}
}
#endif


#if test_UART_INTERRUPT

volatile u8 rx_buffer[20];
u8 rx_flag=0;

void uart_rx_callback(void) {
	static u16 counter = 0;
	char RX_data=0;
	RX_data=UART_GetRX_Data();
	if (rx_buffer[counter] == '\0') {
		counter = 0;
		rx_flag = 1;
		UART_DisableInt(UART_RX);

	} else {
		rx_buffer[counter] = RX_data;

		counter++;
	}


}
int main ()
{
	UART_CallBack(UART_RX,uart_rx_callback);
	UART_init();

	while (1) {
		if (rx_flag == 1) {
			UART_PrintStr("aml");
			rx_flag=0;
		}

	}
}
#endif



#if test_UART
int main()

{
	u8 receive =0;

	UART_vInit();

	while (1) {
	receive=UART_u8Receive();
	UART_vSend(receive);
	}


}
#endif
