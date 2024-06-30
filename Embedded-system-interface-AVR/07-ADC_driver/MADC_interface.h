/*
 * INT_interface.h
 *
 *  Created on: Dec 18, 2023
 *      Author: Aml
 */

#ifndef MADC_INTERFACE_H_
#define MADC_INTERFACE_H_

typedef enum CH_ADC
{
	ADC_CH0=0,
	ADC_CH1,
	ADC_CH2,
	ADC_CH3,
	ADC_CH4,
	ADC_CH5,
	ADC_CH6,
	ADC_CH7
}ADC_channel_t;

typedef enum
{
	NOK,
	OK,
}ErrorStatus;

void MADC_vAdcInit(void);
u16 MADC_u16ReadADC(ADC_channel_t copy_enuChannelADC);


ErrorStatus MADC_enumSelectADCChannel(ADC_channel_t copy_enuChannelADC);
ErrorStatus MADC_enumStartConversionADC(ADC_channel_t copy_enuChannelADC);
u16 MADC_u16ReadDataADC(void);

ErrorStatus MADC_SetCallback(void(*fptr)(void));
#endif /* MADC_INTERFACE_H_ */
