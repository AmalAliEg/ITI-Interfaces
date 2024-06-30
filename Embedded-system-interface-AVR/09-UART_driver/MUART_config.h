/*
 * MUART_config.h
 *
 *  Created on: Dec 28, 2023
 *      Author: Aml
 */

#ifndef MUART_CONFIG_H_
#define MUART_CONFIG_H_

#define User_FREQ			8000000
#define BAUD_RATE_RQUIERED	9600

#define USART_Mode 			UART_ASYNCH  // selects between Asynchronous and Synchronous mode of operation.

#define REG_SELECT			UCSRC_reg_select

#define PAYLOAD_SIZE 		Bits_8
#define STOP_BIT	 		Stop_bits_1
#define PARITY_MODE 		P_NO


#define CLK_POLARITY TRANSMITE_RISING_RECEIVE_FALLING


#endif /* MUART_CONFIG_H_ */
