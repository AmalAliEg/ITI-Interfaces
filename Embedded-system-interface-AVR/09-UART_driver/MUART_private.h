/*
 * MUART_private.h
 *
 *  Created on: Dec 28, 2023
 *      Author: Aml
 */

#ifndef MUART_PRIVATE_H_
#define MUART_PRIVATE_H_

//that file can't be edit by anyone
// define the PIN register on microcontroller as a hardware

/*equation to find the Value of UBRR reg to config the baud rate */
#define FreQ 				User_FREQ
#define BAUD_RATE_VALUE		BAUD_RATE_RQUIERED
#define UBRR_value 			( (FreQ/(16UL*BAUD_RATE_VALUE))-1)

#define UBRRH *( (volatile u8*) (0x40))
#define UBRRL *( (volatile u16*) (0x29))


#define UDR   *( (volatile u8*) (0x2C))		///data reg.
#define UCSRA *( (volatile u8*) (0x2B))
	#define UCSRA_RXC 	7
	#define UCSRA_TXC 	6
	#define UCSRA_UDRE	5
	#define UCSRA_FE 	4
	#define UCSRA_DOR 	3
	#define UCSRA_PE 	2
	#define UCSRA_U2X 	1
	#define UCSRA_MPCM 	0

#define UCSRB *( (volatile u8*) (0x2A))
	#define UCSRB_RXCIE 7			        //PIE for receiver
	#define UCSRB_TXCIE 6			        //PIE for transmitter
	#define UCSRB_UDRIE 5			        //PIE for empty UDR reg
	#define UCSRB_RXEN 	4			        //enable the circut HW for receiver
	#define UCSRB_TXEN	3			        //enable the circut HW for tranmitter
	#define UCSRB_UCSZ2 2			        //configuration for char. size 7 bit, 8 bit
	#define UCSRB_RXB8 	1			        //configuration for char. is 9 bit
	#define UCSRB_TXB8 	0			        //configuration for char. is 9 bit

#define UCSRC *( (volatile u8*) (0x40))
	#define UCSRC_URSEL 7			        //selection reg UCSRC OR UCSRH
	#define UCSRC_UMSEL 6			        //select clk.... synch or asynch mode
	#define UCSRC_UPM1 	5			        //select parity mode -- no parity, even odd
	#define UCSRC_UPM0 	4			        //select parity mode -- no parity, even odd
	#define UCSRC_USBS 	3			        //select nu. of stop bit ib bit or 2 bits
	#define UCSRC_UCSZ1 2			        //configuration for char. size 7 bit, 8 bit with UCSRB_UCSZ2
	#define UCSRC_UCSZ0 1			        //configuration for char. size 7 bit, 8 bit with UCSRB_UCSZ2
	#define UCSRC_UCPOL 0			        // select Clk polarity for synch mode only -at rising or falling edge


#endif /* MUART_PRIVATE_H_ */
