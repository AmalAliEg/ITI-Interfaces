/*
 * DIO_interface.h
 *
 *  Created on: Sep 11, 2022
 *      Author: Aml
 */

#ifndef SPI_SPI_INTERFACE_H_
#define SPI_SPI_INTERFACE_H_


#define DATA_ORDER_MSB 1
#define DATA_ORDER_LSB 2

#define MASTER_MODE 1
#define SLAVE_MODE 2

#define POLARITY_LeadingFall_TrailingRise 1
#define POLARITY_LeadingRise_TrailingFall 2

#define PHASE_SampleLead_SetupTrail 1
#define PHASE_SetupLead_SampleTrail 2

#define SCK_F2 1
#define SCK_F4 2
#define SCK_F8 3
#define SCK_F16 4
#define SCK_F32 5
#define SCK_F64 6
#define SCK_F128 7

#define INTERRUPT_DISABLE 0
#define INTERRUPT_ENABLE 1

#define SPI_DISABLE 0
#define SPI_ENABLE 1

#define IDLE 1
#define BUSY_IDLE 0

typedef enum {
	NOK,
	OK,
}ErrorStatus;

void SPI_vInit(void);


u8 SPI_SendReceive(u8 copy_u8SendData);	//if we work using polling








void SPI_PrintStr(char str[]);
void SPI_RecciveStr(char str[]);
void SPI_EnableInt(u8 source );    					//if we work using interrupt
void SPI_DisableInt(u8 source );    				//if we work using interrupt
void SPI_CallBack(void (*fptr)(void));  			//if we work using interrupt
u8 SPI_GetRX_Data(void);





#endif /* DIO_DIO_INTERFACE_H_ */
