/*
 * DIO_program.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Aml
 */


#include "BIT_MATH.h"
#include "STD_TYPES.h"

//include the drivers
#include "SPI_PRIVATE.h"
#include "SPI_CONFIG.h"
#include "SPI_INTERFACE.h"

static void (*SPI_CALLBACK)(void);




void SPI_Init(void)

{

#if (SPI_DATA_ORDER==DATA_ORDER_MSB)
	CLR_BIT(SPCR,SPCR_DORD);
#elif (SPI_DATA_ORDER==DATA_ORDER_LSB)
	SET_BIT(SPCR,SPCR_DORD);
#endif

#if (SPI_MASTER_SLAVE_SELECT==MASTER_MODE)
	SET_BIT(SPCR,SPCR_MSTR);
#elif (SPI_MASTER_SLAVE_SELECT==SLAVE_MODE)
	CLR_BIT(SPCR,SPCR_MSTR);
#endif

#if(SPI_CLK_POLARITY==POLARITY_LeadingFall_TrailingRise)
	SET_BIT(SPCR,SPCR_CPOL);
#elif (SPI_CLK_POLARITY==POLARITY_LeadingRise_TrailingFall)
	CLR_BIT(SPCR,SPCR_CPOL);
#endif

#if (SPI_CLK_PHASE==PHASE_SampleLead_SetupTrail)
	CLR_BIT(SPCR,SPCR_CPHA);
#elif (SPI_CLK_PHASE==PHASE_SetupLead_SampleTrail)
	SET_BIT(SPCR,SPCR_CPHA;)
#endif

#if (SPI_CLK_RATE==SCK_F2)
	CLR_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPSR,SPSR_SPI2X);

#elif (SPI_CLK_RATE==SCK_F4)
	CLR_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);

#elif (SPI_CLK_RATE==SCK_F8)
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPSR,SPSR_SPI2X);

#elif (SPI_CLK_RATE==SCK_F16)
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);

#elif (SPI_CLK_RATE==SCK_F32)
	CLR_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPSR,SPSR_SPI2X);

#elif (SPI_CLK_RATE==SCK_F64)

	CLR_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);

#elif (SPI_CLK_RATE==SCK_F128)
	SET_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);

#endif

#if (SPI_INTERRUPT_ENABLE==INTERRUPT_DISABLE)
	CLR_BIT(SPCR,SPCR_SPE);

#elif (SPI_INTERRUPT_ENABLE==INTERRUPT_ENABLE)
	SET_BIT(SPCR,SPCR_SPE);
#endif


}

u8 SPI_SendReceive(u8 copy_u8SendData)
{
	/* Start transmission */
	SPDR = copy_u8SendData;
	/* Wait for transmission complete */
	while (!GET_BIT(SPSR, SPSR_SPIF));
	return SPDR;
}

ErrorStatus SetCallBack(void (*fptr)(void)){
/**/
	if (fptr==NULL)
	{
		SPI_CALLBACK=fptr;
	}
}
/****************************************************************************/
/*                                 ISR                                     	*/
/****************************************************************************/

void __vector_12(void) __attribute__((signal));

void __vector_12(void) {
	if (SPI_CALLBACK != NULL) {
		SPI_CALLBACK();
	}
}
