/*
 * INT_program.c
 *
 *  Created on: Dec 18, 2023
 *      Author: Aml
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"


#include "MEXIT_config.h"
#include "MEXIT_interface.h"
#include "MEXIT_private.h"

/*create global pointer to function that hold address of the ISR for function in main*/
void (*EXIT0_CallBack)(void)=NULL; //avoid wild pointer
void (*EXIT1_CallBack)(void)=NULL; //avoid wild pointer
void (*EXIT2_CallBack)(void)=NULL; //avoid wild pointer


void MEXIT_vIntInit()
{

#if Int0_mode==En_INT
	#if (IN0_Sense_ctrl==SLOW)
			CLR_BIT(MCUCR_reg, MCUCR_ISC00);
			CLR_BIT(MCUCR_reg, MCUCR_ISC01);

	#elif (IN0_Sense_ctrl==SFALL_EDG)
			CLR_BIT(MCUCR_reg, MCUCR_ISC00);
			SET_BIT(MCUCR_reg, MCUCR_ISC01);
	#elif (IN0_Sense_ctrl==SON_CHG)
			SET_BIT(MCUCR_reg, MCUCR_ISC00);
			CLR_BIT(MCUCR_reg, MCUCR_ISC01);
	#elif (IN0_Sense_ctrl==SRIS_EDG)
			SET_BIT(MCUCR_reg, MCUCR_ISC00);
			SET_BIT(MCUCR_reg, MCUCR_ISC01);
	#else
	#error "no sense signal"
	#endif
#endif

#if En_INT==Int1_mode
	#if (IN1_Sense_ctrl==SLOW)
			CLR_BIT(MCUCR_reg, MCUCR_ISC10);
			CLR_BIT(MCUCR_reg, MCUCR_ISC11);

	#elif (IN1_Sense_ctrl==SFALL_EDG)
			CLR_BIT(MCUCR_reg, MCUCR_ISC10);
			SET_BIT(MCUCR_reg, MCUCR_ISC11);
	#elif (IN1_Sense_ctrl==SON_CHG)
			SET_BIT(MCUCR_reg, MCUCR_ISC10);
			CLR_BIT(MCUCR_reg, MCUCR_ISC11);
	#elif (IN1_Sense_ctrl==SRIS_EDG)
			SET_BIT(MCUCR_reg, MCUCR_ISC10);
			SET_BIT(MCUCR_reg, MCUCR_ISC11);
	#else
	#error "no sense signal"
	#endif
#endif

#if En_INT==Int2_mode
	#if (IN2_Sense_ctrl==SFALL_EDG)
			CLR_BIT(MCUCSR_reg, MCUCSR_ISC2);
	#elif (IN2_Sense_ctrl==SRIS_EDG)
			SET_BIT(MCUCSR_reg, MCUCSR_ISC2);
	#else
	#error "no sense signal"
	#endif
#endif
}


ErrorStatus MEXIT_enumEnableIterrupt(u8 copy_u8InterruptID)
{
	/*create local variale from Error status type*/
	ErrorStatus Local_u8ErrorState=OK;
	/*check the validation range IN0 ,IN1,IN2*/
	if ((copy_u8InterruptID>=IN0) && (copy_u8InterruptID<=IN2))
	{
		/*check which interrupt pin chosen */
		switch (copy_u8InterruptID) {
			case IN0:SET_BIT(GICR_reg,GICR_INT0);	break;
			case IN1:SET_BIT(GICR_reg,GICR_INT1);	break;
			case IN2:SET_BIT(GICR_reg,GICR_INT2);	break;
		}
	}
	else
	{
		Local_u8ErrorState=NOK;
	}

	return Local_u8ErrorState;
}



ErrorStatus MEXIT_enumDisableIterrupt(u8 copy_u8InterruptID)
{
	/*create local variale from Error status type*/
	ErrorStatus Local_u8ErrorState=OK;
	/*check the validation range IN0 ,IN1,IN2*/
	if ((copy_u8InterruptID>=IN0) && (copy_u8InterruptID<=IN2))
	{
		/*check which interrupt pin chosen */
		switch (copy_u8InterruptID) {
			case IN0:CLR_BIT(GICR_reg,GICR_INT0);	break;
			case IN1:CLR_BIT(GICR_reg,GICR_INT1);	break;
			case IN2:CLR_BIT(GICR_reg,GICR_INT2);	break;
		}
	}
	else
	{
		Local_u8ErrorState=NOK;
	}

	return Local_u8ErrorState;
}

ErrorStatus MEXIT_enumClrInterruptFlag(u8 copy_u8InterruptID){
	/*create local variale from Error status type*/
	ErrorStatus Local_u8ErrorState=OK;
	/*check the validation range IN0 ,IN1,IN2*/
	if ((copy_u8InterruptID>=IN0) && (copy_u8InterruptID<=IN2))
	{
		/*check which interrupt pin chosen */
		switch (copy_u8InterruptID) {
			case IN0:SET_BIT(GIFR_reg,GIFR_INT0);	break;
			case IN1:SET_BIT(GIFR_reg,GIFR_INT1);	break;
			case IN2:SET_BIT(GIFR_reg,GIFR_INT2);	break;
		}
	}
	else
	{
		Local_u8ErrorState=NOK;
	}

	return Local_u8ErrorState;
}

ErrorStatus MEXIT_enumCallBack(void (*p_voidfuncCallBack)(void),u8 copy_u8InterruptID )
 {
	/*create local variale from Error status type*/
	ErrorStatus Local_u8ErrorState = OK;
	/*check the pointer value is NULL or not*/
	if (p_voidfuncCallBack!=NULL) {
		switch(copy_u8InterruptID)
		{
		case IN0:	EXIT0_CallBack = p_voidfuncCallBack; break;
		case IN1:	EXIT1_CallBack = p_voidfuncCallBack; break;
		case IN2:	EXIT2_CallBack = p_voidfuncCallBack; break;
		}
	}
		else {
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}


/*ISR implementation*/
ErrorStatus __vector_1(void) __attribute__((signal));
ErrorStatus __vector_1(void)
 {
	/*create local var from Error status*/

	ErrorStatus Local_enumErrorstate = OK;
	if (EXIT0_CallBack!=NULL) {
		/*call the function*/
		EXIT0_CallBack();
		/*clear the flag*/
		SET_BIT(GIFR_reg,GIFR_INT0);
	} else {
		Local_enumErrorstate = NOK;
	}
	return Local_enumErrorstate;

}


ErrorStatus __vector_2(void) __attribute__((signal));
ErrorStatus __vector_2(void)
 {
	/*create local var from Error status*/

	ErrorStatus Local_enumErrorstate = OK;
	if (EXIT1_CallBack!=NULL) {
		/*call the function*/
		EXIT1_CallBack();
		/*clear the flag*/
		SET_BIT(GIFR_reg,GIFR_INT1);
	} else {
		Local_enumErrorstate = NOK;
	}
	return Local_enumErrorstate;

}

ErrorStatus __vector_3(void) __attribute__((signal));
ErrorStatus __vector_3(void)
 {
	/*create local var from Error status*/

	ErrorStatus Local_enumErrorstate = OK;
	if (EXIT2_CallBack!=NULL) {
		/*call the function*/
		EXIT2_CallBack();
		/*clear the flag*/
		SET_BIT(GIFR_reg,GIFR_INT2);
	} else {
		Local_enumErrorstate = NOK;
	}
	return Local_enumErrorstate;

}


