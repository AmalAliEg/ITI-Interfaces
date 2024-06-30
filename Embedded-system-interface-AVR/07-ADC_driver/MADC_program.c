/*
 * INT_program.c
 *
 *  Created on: Dec 18, 2023
 *      Author: Aml
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MADC_config.h"
#include "MADC_interface.h"
#include "MADC_private.h"


static void (*MADC_CALLBACK)(void);


void MADC_vAdcInit(){

	/*select volt ref. AVCC REF.*/
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
	/*select the adjust Right adjust*/
	CLR_BIT(ADMUX,ADMUX_ADLAR);

	/*enable ADC it regard the circute itself */
	SET_BIT(ADCSRA,ADCSRA_ADEN);
	/*auto trigger*/
	CLR_BIT(ADCSRA,ADCSRA_ADATE);
	/*enable/disable adc interrupt */
	SET_BIT(ADCSRA,ADCSRA_ADIE);

	/*set the pre-scaller --64*/
	CLR_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
}

//adc Synchronans function
u16 MADC_u16ReadADC(ADC_channel_t copy_enuChannelADC){
	/*mask the bits for channel before overwrite*/
	ADMUX &=0xE0; //or binary 0b11100000
	/*select channel */
	ADMUX |=copy_enuChannelADC;
	/*start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	/*busy wait for ADC flag*/
	while(!GET_BIT(ADCSRA,ADCSRA_ADIF)){}
	/*clr flag*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);
	return ADC_DATA_REG;
}
/*use an asynchro.*/


ErrorStatus MADC_enumSelectADCChannel(ADC_channel_t copy_enuChannelADC){
	/*create local var from ERRORStatus*/
	ErrorStatus Local_u8Errorstate = OK;

	if ((copy_enuChannelADC >= ADC_CH0) && (copy_enuChannelADC <= ADC_CH7)) {
		/*mask the bits for channel before overwrite*/
		ADMUX &= 0xE0; //or binary 0b11100000
		/*select channel */
		ADMUX |= copy_enuChannelADC;
	} else {
		Local_u8Errorstate = NOK;
	}
	return Local_u8Errorstate;
}

ErrorStatus MADC_enumStartConversionADC(ADC_channel_t copy_enuChannelADC){
	/*create local var from ERRORStatus*/
	ErrorStatus Local_u8Errorstate = OK;
	if ((copy_enuChannelADC >= ADC_CH0) && (copy_enuChannelADC <= ADC_CH7)) {

		/*start conversion*/
		SET_BIT(ADCSRA, ADCSRA_ADSC);
	} else {
		Local_u8Errorstate = NOK;
	}
	return Local_u8Errorstate;
}
u16 MADC_u16ReadDataADC(void){
	return ADC_DATA_REG;

}

ErrorStatus MADC_SetCallback(void(*fptr)(void)){
	/*create local var from ERRORStatus*/
	ErrorStatus Local_u8ErrorState = OK;
	if (fptr != NULL) {
		MADC_CALLBACK = fptr;
	} else {
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;

}

ErrorStatus __vector_16(void) __attribute__((signal));
ErrorStatus __vector_16(void)
 {
	/*create local var from ERRORStatus*/
	ErrorStatus Local_u8ErrorState = OK;
	if (MADC_CALLBACK != NULL) {
		MADC_CALLBACK();
		// clear ADC interrupt flag
		SET_BIT(ADCSRA, ADCSRA_ADIF);
	} else {
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}

