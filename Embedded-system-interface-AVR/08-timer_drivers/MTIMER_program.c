/*
 * INT_program.c
 *
 *  Created on: Dec 18, 2023
 *      Author: Aml
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"


#include "MTIMER_private.h"
#include "MTIMER_config.h"
#include "MTIMER_interface.h"
/*global pointers to function for timer */
static void (*TM0_OVF0_CALLBACK)(void);  		//timer0 overflow
static void (*TM0_CTC0_CALLBACK)(void);  		//timer0 ctc mode

static void (*TM1_OVF1_CALLBACK)(void);	 		//timer1 overflow
static void (*TM1_CTC1B_CALLBACK)(void);	 	//timer1 compare mode for channel b
static void (*TM1_CTC1A_CALLBACK)(void);	 	//timer1 compare mode for channel a
static void (*TM1_ICT1_CALLBACK)(void);	 		//timer1 input capture mode

static void (*TM2_OVF2_CALLBACK)(void);  		//timer2 overflow
static void (*TM2_CTC2_CALLBACK)(void);  		//timer2 ctc mode
/*--------------------------------------------------------------------------------------*/
/*
 * function implementations
 */
void MTIMER_vTimerInit() {
	/*choose the mode for timer0*/

#if Timer0_mode==T0normal_M
	CLR_BIT(TCCR0, TCCR0_WGM00);      		    //WGM00 ->pin 6
	CLR_BIT(TCCR0, TCCR0_WGM01);      		    //WGM01 ->pin 3


#elif Timer0_mode==T0PhasePWM_M
	SET_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);
		/*the action done on OC0 pin*/
		#if Timer0_CTC_PWM_mode == CLR_OC0_ON_CMP
		CLR_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);
		#elif Timer0_CTC_PWM_mode==SET_OC0_ON_CMP
		SET_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);
		#endif

#elif Timer0_mode==T0CTC_M
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
		/*the action done on OC0 pin*/
		#if Timer0_CTC_PWM_mode == CLR_OC0_ON_CMP
		CLR_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);
		#elif Timer0_CTC_PWM_mode==SET_OC0_ON_CMP
		SET_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);
		#endif

#elif Timer0_mode==T0FastPWM_M
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
		/*the action done on OC0 pin*/
		#if Timer0_CTC_PWM_mode == CLR_OC0_ON_CMP
		CLR_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);
		#elif Timer0_CTC_PWM_mode==SET_OC0_ON_CMP
		SET_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);
		#endif
#endif

#if Timer2_mode==T2normal_M                      //WGM20 ->pin 6
	CLR_BIT(TCCR2, TCCR2_WGM20);                 //WGM21 ->pin 3
	CLR_BIT(TCCR2, TCCR2_WGM21);

#elif Timer2_mode==T0PhasePWM_M
	SET_BIT(TCCR2,TCCR2_WGM20);
	CLR_BIT(TCCR2,TCCR2_WGM21);
		/*the action done on OC2 pin*/
		#if Timer2_CTC_PWM_mode == CLR_OC2_ON_CMP
		CLR_BIT(TCCR2,TCCR2_COM20);
		SET_BIT(TCCR2,TCCR2_COM21);
		#elif Timer2_CTC_PWM_mode==SET_OC2_ON_CMP
		SET_BIT(TCCR2,TCCR2_COM20);
		SET_BIT(TCCR2,TCCR2_COM21);
		#endif
#elif Timer2_mode==T2CTC_M
	CLR_BIT(TCCR2,TCCR2_WGM20);
	SET_BIT(TCCR2,TCCR2_WGM21);
		/*the action done on OC2 pin*/
		#if Timer2_CTC_PWM_mode == CLR_OC2_ON_CMP
		CLR_BIT(TCCR2,TCCR2_COM20);
		SET_BIT(TCCR2,TCCR2_COM21);
		#elif Timer2_CTC_PWM_mode==SET_OC2_ON_CMP
		SET_BIT(TCCR2,TCCR2_COM20);
		SET_BIT(TCCR2,TCCR2_COM21);
		#endif
#elif Timer2_mode==T2FastPWM_M
	SET_BIT(TCCR2,TCCR2_WGM20);
	SET_BIT(TCCR2,TCCR2_WGM21);
		/*the action done on OC2 pin*/
		#if Timer2_CTC_PWM_mode == CLR_OC2_ON_CMP
		CLR_BIT(TCCR2,TCCR2_COM20);
		SET_BIT(TCCR2,TCCR2_COM21);
		#elif Timer2_CTC_PWM_mode==SET_OC2_ON_CMP
		SET_BIT(TCCR2,TCCR2_COM20);
		SET_BIT(TCCR2,TCCR2_COM21);
		#endif
#endif

#if Timer1_mode==T1normal_M
	CLR_BIT(TCCR1, TCCR1_WGM12);
	CLR_BIT(TCCR1, TCCR1_WGM13);
	CLR_BIT(TCCR1, TCCR1_WGM10);
	CLR_BIT(TCCR1, TCCR1_WGM11);


#elif Timer1_mode==T1PhasePWM_M
	/*check the 47 on datasheet */
	#if T1_PHASEtop==Top_Phase_OCR1A
	OCR1A=MTIMER_vSetOCR()
	CLR_BIT(TCCR1, TCCR1_WGM12);
	SET_BIT(TCCR1, TCCR1_WGM13);
	SET_BIT(TCCR1, TCCR1_WGM10);
	SET_BIT(TCCR1, TCCR1_WGM11);
		/*case channel A*/
		/*output signal on OC1A pin*/
		#if Timer1_channelA_ctcMODE == CLR_OCA_ON_CMP
		CLR_BIT(TCCR1,TCCR1_COM12);
		SET_BIT(TCCR1,TCCR1_COM13);
		#elif Timer1_channelA_ctcMODE==SET_OCA_ON_CMP
		SET_BIT(TCCR1,TCCR1_COM12);
		SET_BIT(TCCR1,TCCR1_COM13);
		#endif
		/*case channel B*/
		#if Timer1_channelB_ctcMODE == CLR_OCB_ON_CMP
		CLR_BIT(TCCR1,TCCR1_COM10);
		SET_BIT(TCCR1,TCCR1_COM11);
		#elif Timer1_channelB_ctcMODE==SET_OCB_ON_CMP
		SET_BIT(TCCR1,TCCR1_COM10);
		SET_BIT(TCCR1,TCCR1_COM11);
		#endif
	#elif T1_PHASEtop==Top_Phase_ICR1
	CLR_BIT(TCCR1, TCCR1_WGM12);
	SET_BIT(TCCR1, TCCR1_WGM13);
	CLR_BIT(TCCR1, TCCR1_WGM10);
	SET_BIT(TCCR1, TCCR1_WGM11);
		/*case channel A*/
		#if Timer1_channelA_ctcMODE == CLR_OCA_ON_CMP
		CLR_BIT(TCCR1,TCCR1_COM12);
		SET_BIT(TCCR1,TCCR1_COM13);
		#elif Timer1_channelA_ctcMODE==SET_OCA_ON_CMP
		SET_BIT(TCCR1,TCCR1_COM12);
		SET_BIT(TCCR1,TCCR1_COM13);
		#endif
		/*case channel B*/
		#if Timer1_channelB_ctcMODE == CLR_OCB_ON_CMP
		CLR_BIT(TCCR1,TCCR1_COM10);
		SET_BIT(TCCR1,TCCR1_COM11);
		#elif Timer1_channelB_ctcMODE==SET_OCB_ON_CMP
		SET_BIT(TCCR1,TCCR1_COM10);
		SET_BIT(TCCR1,TCCR1_COM11);
		#endif
	#elif T1_PHASEtop==Top_Phase_8Bit
	CLR_BIT(TCCR1, TCCR1_WGM12);
	CLR_BIT(TCCR1, TCCR1_WGM13);
	SET_BIT(TCCR1, TCCR1_WGM10);
	CLR_BIT(TCCR1, TCCR1_WGM11);
		/*case channel A*/
		#if Timer1_channelA_ctcMODE == CLR_OCA_ON_CMP
		CLR_BIT(TCCR1,TCCR1_COM12);
		SET_BIT(TCCR1,TCCR1_COM13);
		#elif Timer1_channelA_ctcMODE==SET_OCA_ON_CMP
		SET_BIT(TCCR1,TCCR1_COM12);
		SET_BIT(TCCR1,TCCR1_COM13);
		#endif
		/*case channel B*/
		#if Timer1_channelB_ctcMODE == CLR_OCB_ON_CMP
		CLR_BIT(TCCR1,TCCR1_COM10);
		SET_BIT(TCCR1,TCCR1_COM11);
		#elif Timer1_channelB_ctcMODE==SET_OCB_ON_CMP
		SET_BIT(TCCR1,TCCR1_COM10);
		SET_BIT(TCCR1,TCCR1_COM11);
		#endif
	#elif T1_PHASEtop==Top_Phase_9Bit
	CLR_BIT(TCCR1, TCCR1_WGM12);
	CLR_BIT(TCCR1, TCCR1_WGM13);
	CLR_BIT(TCCR1, TCCR1_WGM10);
	SET_BIT(TCCR1, TCCR1_WGM11);
		/*case channel A*/
		#if Timer1_channelA_ctcMODE == CLR_OCA_ON_CMP
		CLR_BIT(TCCR1,TCCR1_COM12);
		SET_BIT(TCCR1,TCCR1_COM13);
		#elif Timer1_channelA_ctcMODE==SET_OCA_ON_CMP
		SET_BIT(TCCR1,TCCR1_COM12);
		SET_BIT(TCCR1,TCCR1_COM13);
		#endif
		/*case channel B*/
		#if Timer1_channelB_ctcMODE == CLR_OCB_ON_CMP
		CLR_BIT(TCCR1,TCCR1_COM10);
		SET_BIT(TCCR1,TCCR1_COM11);
		#elif Timer1_channelB_ctcMODE==SET_OCB_ON_CMP
		SET_BIT(TCCR1,TCCR1_COM10);
		SET_BIT(TCCR1,TCCR1_COM11);
		#endif
	#elif T1_PHASEtop==Top_Phase_10Bit
	CLR_BIT(TCCR1, TCCR1_WGM12);
	CLR_BIT(TCCR1, TCCR1_WGM13);
	SET_BIT(TCCR1, TCCR1_WGM10);
	SET_BIT(TCCR1, TCCR1_WGM11);
		/*case channel A*/
		#if Timer1_channelA_ctcMODE == CLR_OCA_ON_CMP
		CLR_BIT(TCCR1,TCCR1_COM12);
		SET_BIT(TCCR1,TCCR1_COM13);
		#elif Timer1_channelA_ctcMODE==SET_OCA_ON_CMP
		SET_BIT(TCCR1,TCCR1_COM12);
		SET_BIT(TCCR1,TCCR1_COM13);
		#endif
		/*case channel B*/
		#if Timer1_channelB_ctcMODE == CLR_OCB_ON_CMP
		CLR_BIT(TCCR1,TCCR1_COM10);
		SET_BIT(TCCR1,TCCR1_COM11);
		#elif Timer1_channelB_ctcMODE==SET_OCB_ON_CMP
		SET_BIT(TCCR1,TCCR1_COM10);
		SET_BIT(TCCR1,TCCR1_COM11);
		#endif
	#endif


#elif Timer1_mode==T1CTC_M
	#if T1_CTCtop==Top_OCR1A
	SET_BIT(TCCR1, TCCR1_WGM12);
	CLR_BIT(TCCR1, TCCR1_WGM13);
	CLR_BIT(TCCR1, TCCR1_WGM10);
	CLR_BIT(TCCR1, TCCR1_WGM11);
		/*case channel A*/
		#if Timer1_channelA_ctcMODE == CLR_OCA_ON_CMP
		CLR_BIT(TCCR1,TCCR1_COM12);
		SET_BIT(TCCR1,TCCR1_COM13);
		#elif Timer1_channelA_ctcMODE==SET_OCA_ON_CMP
		SET_BIT(TCCR1,TCCR1_COM12);
		SET_BIT(TCCR1,TCCR1_COM13);
		#endif
		/*case channel B*/
		#if Timer1_channelB_ctcMODE == CLR_OCB_ON_CMP
		CLR_BIT(TCCR1,TCCR1_COM10);
		SET_BIT(TCCR1,TCCR1_COM11);
		#elif Timer1_channelB_ctcMODE==SET_OCB_ON_CMP
		SET_BIT(TCCR1,TCCR1_COM10);
		SET_BIT(TCCR1,TCCR1_COM11);
		#endif
	#elif T1_CTCtop==Top_ICR1A
	SET_BIT(TCCR1, TCCR1_WGM12);
	SET_BIT(TCCR1, TCCR1_WGM13);
	CLR_BIT(TCCR1, TCCR1_WGM10);
	CLR_BIT(TCCR1, TCCR1_WGM11);
		/*case channel A*/
		#if Timer1_channelA_ctcMODE == CLR_OCA_ON_CMP
		CLR_BIT(TCCR1,TCCR1_COM12);
		SET_BIT(TCCR1,TCCR1_COM13);
		#elif Timer1_channelA_ctcMODE==SET_OCA_ON_CMP
		SET_BIT(TCCR1,TCCR1_COM12);
		SET_BIT(TCCR1,TCCR1_COM13);
		#endif
		/*case channel B*/
		#if Timer1_channelB_ctcMODE == CLR_OCB_ON_CMP
		CLR_BIT(TCCR1,TCCR1_COM10);
		SET_BIT(TCCR1,TCCR1_COM11);
		#elif Timer1_channelB_ctcMODE==SET_OCB_ON_CMP
		SET_BIT(TCCR1,TCCR1_COM10);
		SET_BIT(TCCR1,TCCR1_COM11);
		#endif
	#endif
#elif Timer1_mode==T1FastPWM_M

	#if T1_FASTtop==Top_fast_OCR1A
	SET_BIT(TCCR1, TCCR1_WGM12);
	SET_BIT(TCCR1, TCCR1_WGM13);
	SET_BIT(TCCR1, TCCR1_WGM10);
	SET_BIT(TCCR1, TCCR1_WGM11);
		/*case channel A*/
		#if Timer1_channelA_ctcMODE == CLR_OCA_ON_CMP
		CLR_BIT(TCCR1,TCCR1_COM12);
		SET_BIT(TCCR1,TCCR1_COM13);
		#elif Timer1_channelA_ctcMODE==SET_OCA_ON_CMP
		SET_BIT(TCCR1,TCCR1_COM12);
		SET_BIT(TCCR1,TCCR1_COM13);
		#endif
		/*case channel B*/
		#if Timer1_channelB_ctcMODE == CLR_OCB_ON_CMP
		CLR_BIT(TCCR1,TCCR1_COM10);
		SET_BIT(TCCR1,TCCR1_COM11);
		#elif Timer1_channelB_ctcMODE==SET_OCB_ON_CMP
		SET_BIT(TCCR1,TCCR1_COM10);
		SET_BIT(TCCR1,TCCR1_COM11);
		#endif
	#elif T1_FASTtop==Top_fast_ICR1A
	SET_BIT(TCCR1, TCCR1_WGM12);
	SET_BIT(TCCR1, TCCR1_WGM13);
	CLR_BIT(TCCR1, TCCR1_WGM10);
	SET_BIT(TCCR1, TCCR1_WGM11);
		/*case channel A*/
		#if Timer1_channelA_ctcMODE == CLR_OCA_ON_CMP
		CLR_BIT(TCCR1,TCCR1_COM12);
		SET_BIT(TCCR1,TCCR1_COM13);
		#elif Timer1_channelA_ctcMODE==SET_OCA_ON_CMP
		SET_BIT(TCCR1,TCCR1_COM12);
		SET_BIT(TCCR1,TCCR1_COM13);
		#endif
		/*case channel B*/
		#if Timer1_channelB_ctcMODE == CLR_OCB_ON_CMP
		CLR_BIT(TCCR1,TCCR1_COM10);
		SET_BIT(TCCR1,TCCR1_COM11);
		#elif Timer1_channelB_ctcMODE==SET_OCB_ON_CMP
		SET_BIT(TCCR1,TCCR1_COM10);
		SET_BIT(TCCR1,TCCR1_COM11);
		#endif
	#elif T1_FASTtop==Top_fast_8Bit
	SET_BIT(TCCR1, TCCR1_WGM12);
	CLR_BIT(TCCR1, TCCR1_WGM13);
	SET_BIT(TCCR1, TCCR1_WGM10);
	CLR_BIT(TCCR1, TCCR1_WGM11);
		/*case channel A*/
		#if Timer1_channelA_ctcMODE == CLR_OCA_ON_CMP
		CLR_BIT(TCCR1,TCCR1_COM12);
		SET_BIT(TCCR1,TCCR1_COM13);
		#elif Timer1_channelA_ctcMODE==SET_OCA_ON_CMP
		SET_BIT(TCCR1,TCCR1_COM12);
		SET_BIT(TCCR1,TCCR1_COM13);
		#endif
		/*case channel B*/
		#if Timer1_channelB_ctcMODE == CLR_OCB_ON_CMP
		CLR_BIT(TCCR1,TCCR1_COM10);
		SET_BIT(TCCR1,TCCR1_COM11);
		#elif Timer1_channelB_ctcMODE==SET_OCB_ON_CMP
		SET_BIT(TCCR1,TCCR1_COM10);
		SET_BIT(TCCR1,TCCR1_COM11);
		#endif
	#elif T1_FASTtop==Top_fast_9Bit
	SET_BIT(TCCR1, TCCR1_WGM12);
	CLR_BIT(TCCR1, TCCR1_WGM13);
	CLR_BIT(TCCR1, TCCR1_WGM10);
	SET_BIT(TCCR1, TCCR1_WGM11);
		/*case channel A*/
		#if Timer1_channelA_ctcMODE == CLR_OCA_ON_CMP
		CLR_BIT(TCCR1,TCCR1_COM12);
		SET_BIT(TCCR1,TCCR1_COM13);
		#elif Timer1_channelA_ctcMODE==SET_OCA_ON_CMP
		SET_BIT(TCCR1,TCCR1_COM12);
		SET_BIT(TCCR1,TCCR1_COM13);
		#endif
		/*case channel B*/
		#if Timer1_channelB_ctcMODE == CLR_OCB_ON_CMP
		CLR_BIT(TCCR1,TCCR1_COM10);
		SET_BIT(TCCR1,TCCR1_COM11);
		#elif Timer1_channelB_ctcMODE==SET_OCB_ON_CMP
		SET_BIT(TCCR1,TCCR1_COM10);
		SET_BIT(TCCR1,TCCR1_COM11);
		#endif
	#elif T1_FASTtop==Top_fast_10Bit
	SET_BIT(TCCR1, TCCR1_WGM12);
	SET_BIT(TCCR1, TCCR1_WGM13);
	CLR_BIT(TCCR1, TCCR1_WGM10);
	SET_BIT(TCCR1, TCCR1_WGM11);
	/*case channel A*/
		#if Timer1_channelA_ctcMODE == CLR_OCA_ON_CMP
		CLR_BIT(TCCR1,TCCR1_COM12);
		SET_BIT(TCCR1,TCCR1_COM13);
		#elif Timer1_channelA_ctcMODE==SET_OCA_ON_CMP
		SET_BIT(TCCR1,TCCR1_COM12);
		SET_BIT(TCCR1,TCCR1_COM13);
		#endif
		/*case channel B*/
		#if Timer1_channelB_ctcMODE == CLR_OCB_ON_CMP
		CLR_BIT(TCCR1,TCCR1_COM10);
		SET_BIT(TCCR1,TCCR1_COM11);
		#elif Timer1_channelB_ctcMODE==SET_OCB_ON_CMP
		SET_BIT(TCCR1,TCCR1_COM10);
		SET_BIT(TCCR1,TCCR1_COM11);
		#endif
	#endif
#endif

}

void MTIMER_vSetPreLoad(TIMER_t copy_enumu8TimerID, u16 copy_u16PreLoad) {
	switch (copy_enumu8TimerID) {
	case T0_OVF ... T0_CTC:	TCNT0 = copy_u16PreLoad;	break;
	case T1_OVF ... T1_ICT:	TCNT1 = copy_u16PreLoad;	break;
	case T2_OVF ... T2_CTC:	TCNT2 = copy_u16PreLoad;	break;
	}

}

void MTIMER_vStartTimer(TIMER_t copy_enumTimerId, u16 copy_u16Delay) {

	switch (copy_enumTimerId)
	{
	case T0_OVF ... T0_CTC:
		/*mask the TCCR reg*/
		TCCR0 &= 0xF8;        //0b11111000
		/*set prescaller */
		TCCR0 |= Timer0_prescaller;
		/*set value of the counter reg TCNT0*/
		TCNT0 = copy_u16Delay;
		break;

	case T1_OVF ...T1_ICT:
		//  enable the prescaller
		/*mask the TCCR reg*/
		TCCR1 &= 0xFFF8;        //0b11111000
		TCCR1 |= Timer1_prescaller;
		/*set value of the counter reg TCNT1*/
		TCNT1 = copy_u16Delay;
		break;

	case T2_OVF ... T2_CTC:
		/*mask the TCCR reg*/
		TCCR2 &= 0xF8;        //0b11111000
		/*set value of the counter reg TCNT2*/
		TCCR2 |= Timer2_prescaller;
		TCNT2 = copy_u16Delay;
		break;
	}

}
void MTIMER_vEndTimer(TIMER_t copy_enumTimerId) {

	switch (copy_enumTimerId) {

				case T0_OVF ... T0_CTC:	TCNT0=0x00;		break;
				case T1_OVF ...T1_ICT:	TCNT1=0x00;		break;
				case T2_OVF ... T2_CTC:	TCNT2=0x00; 	break;
			}
}


void MTIMER_vEnableTimerPIE(TIMER_t copy_EnumTimerId) {
	switch (copy_EnumTimerId) {
	case T0_OVF:	SET_BIT(TIMSK, TIMSK_TOIE0);	break;
	case T0_CTC:	SET_BIT(TIMSK,TIMSK_OCIE0);		break;
	case T1_OVF:	SET_BIT(TIMSK, TIMSK_TOIE1);	break;
	case T1_CTCB:	SET_BIT(TIMSK,TIMSK_OCIE1B);	break;
	case T1_CTCA:	SET_BIT(TIMSK,TIMSK_OCIE1A);	break;
	case T1_ICT:	SET_BIT(TIMSK,TIMSK_TICIE1);	break;
	case T2_OVF:	SET_BIT(TIMSK, TIMSK_TOIE2);	break;
	case T2_CTC:	SET_BIT(TIMSK,TIMSK_OCIE2);		break;


	}
}

void MTIMER_vDisableTimerPIE(TIMER_t copy_EnumTimerId) {
	switch (copy_EnumTimerId) {

		case T0_OVF:	CLR_BIT(TIMSK, TIMSK_TOIE0);	break;
		case T0_CTC:	CLR_BIT(TIMSK,TIMSK_OCIE0);		break;
		case T1_OVF:	CLR_BIT(TIMSK, TIMSK_TOIE1);	break;
		case T1_CTCB:	CLR_BIT(TIMSK,TIMSK_OCIE1B);	break;
		case T1_CTCA:	CLR_BIT(TIMSK,TIMSK_OCIE1A);	break;
		case T1_ICT:	CLR_BIT(TIMSK,TIMSK_TICIE1);	break;
		case T2_OVF:	CLR_BIT(TIMSK, TIMSK_TOIE2);	break;
		case T2_CTC:	CLR_BIT(TIMSK,TIMSK_OCIE2);		break;
	}
}

void MTIMER_vSetOCR(TIMER_t copy_enumTimerId, u16 copy_u16ValueOCR){

	switch (copy_enumTimerId) {

			case T0_CTC:	OCR0= copy_u16ValueOCR;		break;
			case T1_CTCB:	OCR1B= copy_u16ValueOCR;	break;
			case T1_CTCA:	OCR1A= copy_u16ValueOCR;	break;
			case T2_CTC:	OCR2= copy_u16ValueOCR; 	break;
		}

}
void MTIMER_vSetICR(u16 copy_u16ValueICR ){

				ICR1= copy_u16ValueICR;

}

u16 MTIMER_u16GetTimerCounterReg(TIMER_t copy_EnumTimerId){
	u16 Local_u16Return;

	switch (copy_EnumTimerId) {

				case T0_OVF ... T0_CTC:	Local_u16Return=TCNT0;		break;
				case T1_OVF ...T1_ICT:	Local_u16Return= TCNT1;		break;
				case T2_OVF ... T2_CTC:	Local_u16Return= TCNT2; 	break;
			}
	return Local_u16Return;
}
u16 MTIMER_u16GetValueICR(void)
{
	return ICR1;
}

void MTIMER_SetCallback(void (*fptr)(void),TIMER_t copy_enumInterrupt_Flag) {
	if (fptr != NULL)
	switch(copy_enumInterrupt_Flag){
	case T0_OVF:	TM0_OVF0_CALLBACK = fptr;	break;
	case T0_CTC:	TM0_CTC0_CALLBACK=fptr;		break;
	case T1_OVF:	TM1_OVF1_CALLBACK=fptr;		break;
	case T1_CTCB:	TM1_CTC1B_CALLBACK=fptr;	break;
	case T1_CTCA:	TM1_CTC1A_CALLBACK=fptr;	break;
	case T1_ICT:	TM1_ICT1_CALLBACK=fptr;		break;
	case T2_OVF:	TM2_OVF2_CALLBACK=fptr;		break;
	case T2_CTC:	TM2_CTC2_CALLBACK=fptr;		break;
	}

}
/*****************************************************************************************/
/*           ISR's for the timer                                                         */
/*****************************************************************************************/

void __vector_11(void) __attribute__((signal));
void __vector_11(void) {
	if (TM0_OVF0_CALLBACK != NULL)

	{
		TM0_OVF0_CALLBACK();
	}
	// clear ADC interrupt flag
	SET_BIT(TIFR, TIFR_TOV0);
}
//-----------------------------------------------------------
void __vector_10(void) __attribute__((signal));
void __vector_10(void) {
	if (TM0_CTC0_CALLBACK != NULL)

	{
		TM0_CTC0_CALLBACK();
	}
	// clear ADC interrupt flag
	SET_BIT(TIFR, TIFR_OCF0);
}
//--------------------------------------------------------
void __vector_9(void) __attribute__((signal));
void __vector_9(void) {
	if (TM1_OVF1_CALLBACK != NULL)

	{
		TM1_OVF1_CALLBACK();
	}
	// clear ADC interrupt flag
	SET_BIT(TIFR, TIFR_TOIE1);
}
//----------------------------------------------------------

void __vector_8(void) __attribute__((signal));
void __vector_8(void) {
	if (TM1_CTC1B_CALLBACK != NULL)

	{

		TM1_CTC1B_CALLBACK();
	}
	// clear ADC interrupt flag
	SET_BIT(TIFR, TIFR_OCIE1B);
}
//----------------------------------------------------------

void __vector_7(void) __attribute__((signal));
void __vector_7(void) {
	if (TM1_CTC1A_CALLBACK != NULL)

	{

		TM1_CTC1A_CALLBACK();
	}
	// clear ADC interrupt flag
	SET_BIT(TIFR, TIFR_OCIE1A);
}
//----------------------------------------------------------

void __vector_6(void) __attribute__((signal));
void __vector_6(void) {
	if (TM1_ICT1_CALLBACK != NULL)

	{

		TM1_ICT1_CALLBACK();
	}
	// clear ADC interrupt flag
	SET_BIT(TIFR, TIFR_TICIE1);
}
//----------------------------------------------------------

void __vector_5(void) __attribute__((signal));
void __vector_5(void) {
	if (TM2_OVF2_CALLBACK != NULL)

	{

		TM2_OVF2_CALLBACK();
	}
	// clear ADC interrupt flag
	SET_BIT(TIFR, TIFR_TOIE2);
}
//----------------------------------------------------------

void __vector_4(void) __attribute__((signal));
void __vector_4(void) {
	if (TM2_CTC2_CALLBACK != NULL)

	{

		TM2_CTC2_CALLBACK();
	}
	// clear ADC interrupt flag
	SET_BIT(TIFR, TIFR_OCIE2);
}
//----------------------------------------------------------
