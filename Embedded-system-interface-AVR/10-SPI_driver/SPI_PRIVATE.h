/*
 * DIO_private.h
 *
 *  Created on: Nov 28, 2023
 *      Author: Aml
 */

#ifndef SPI_SPI_PRIVATE_H_
#define SPI_SPI_PRIVATE_H_

//that file can't be edit by anyone
// define the PIN register on microcontroller as a hardware

/***********************************************************************/
/*define the bits for the SPCR reg*/
/***********************************************************************/

#define SPCR_SPIE 7 //interrupt enable
#define SPCR_SPE  6 //prepheral enable
#define SPCR_DORD 5 //data order
#define SPCR_MSTR 4 //master/slave select
#define SPCR_CPOL 3 //clock polarity
#define SPCR_CPHA 2 //clock phase
#define SPCR_SPR1 1 //SPI clk rate
#define SPCR_SPR0 0 //SPI clk rate

/***********************************************************************/
/*define the bits for the SPSR reg*/
/***********************************************************************/
#define SPSR_SPIF  7 //interrupt enable
#define SPSR_SPI2X 0 //Double SPI Speed Bit


#define SPDR   *( (volatile u8*) (0x2F)) //data regi
#define SPSR   *( (volatile u8*) (0x2E))
#define SPCR   *( (volatile u8*) (0x2D))




#endif /* DIO_DIO_PRIVATE_H_ */
