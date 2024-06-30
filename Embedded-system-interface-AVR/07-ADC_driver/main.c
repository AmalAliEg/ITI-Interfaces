/*
 * main.c
 *
 *  Created on: Dec 18, 2023
 *      Author: Aml
 */

#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MGIE_interface.h"
#include "MGIE_config.h"

#include "MADC_config.h"
#include "MADC_interface.h"
#include "MDIO_config.h"
#include "MDIO_interface.h"

#include "HLCD_config.h"
#include "HLCD_interface.h"



#define synch 0
#define asynch 1


#if synch
u8 MAP_u8Mappiny(u32 x_max,u32 x_min,u32 y_max,u32 y_min,u32 y);
int main()
{
MDIO_vSetPortDirection(PORTD,0xff);
MADC_vAdcInit();
u16 adc_value=0;
u16 mapped_value=0;
	while (1)
	{
		adc_value=MADC_u16ReadADC(ADC_CH1);
		mapped_value=MAP_u8Mappiny(255,0,1023,0,adc_value);
		MDIO_vSetPortValue(PORTD,mapped_value);
	}
}


//app to map the 1024 from ADC to 255
//in from 0 to 1024
//out from 0 to 255
u8 MAP_u8Mappiny(u32 x_max,u32 x_min,u32 y_max,u32 y_min,u32 y){

	u8 local_u8OutValue=0;

	local_u8OutValue= ( ((x_max-x_min)*(y-y_min)) /  ((y_max-y_min)+x_min));


	return local_u8OutValue;
}

#endif

#if asynch

volatile u16 digital_value=0;
volatile u8 ADC_flag=0;


void GetADCValue(void);
int main ()
 {
	AVR_GIEInit();
	HLCD_vInitLcd();

	u16 temprature = 0;


	MADC_vAdcInit();
	MADC_SetCallback(&GetADCValue);
	MADC_enumStartConversionADC(ADC_CH0);

	while (1) {
		if (ADC_flag == 1) {
			ADC_flag = 0;
			temprature = (5000 * digital_value) / 1024;
			HLCD_vSendCommand(Clear);
			HLCD_vWriteNumber(temprature);
		}
		_delay_ms(200);
	}

}
void GetADCValue(void)
{
	digital_value=MADC_u16ReadDataADC();
	ADC_flag =1;
	MADC_enumStartConversionADC(ADC_CH0);
}
#endif
