/*
 * DIO_private.h
 *
 *  Created on: Dec 9, 2023
 *      Author: Aml
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_


/*
 * define the DDR register for all ports
 * it's not important to write volatile
 */
#define DDRA_reg 	*(  (volatile u8*)  (0x3A) )
#define DDRB_reg 	*(  (volatile u8*)  (0x37) )
#define DDRC_reg 	*(  (volatile u8*)  (0x34) )
#define DDRD_reg 	*(  (volatile u8*)  (0x31) )


/*
 * define the PORT register for all ports
 */
#define PORTA_reg 	*(  (volatile u8*)  (0x3B) )
#define PORTB_reg 	*(  (volatile u8*)  (0x38) )
#define PORTC_reg 	*(  (volatile u8*)  (0x35) )
#define PORTD_reg 	*(  (volatile u8*)  (0x32) )

/*
 * define the PIN register for all ports
 * volatile required in pin as the value changed by the hardware
 */
#define PINA_reg 	*(  (volatile u8*)  (0x39) )
#define PINB_reg 	*(  (volatile u8*)  (0x36) )
#define PINC_reg 	*(  (volatile u8*)  (0x33) )
#define PIND_reg 	*(  (volatile u8*)  (0x30) )

#endif /* DIO_PRIVATE_H_ */
