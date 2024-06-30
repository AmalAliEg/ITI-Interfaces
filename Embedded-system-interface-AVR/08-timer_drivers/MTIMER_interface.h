/*
 * INT_interface.h
 *
 *  Created on: Dec 18, 2023
 *      Author: Aml
 */

#ifndef MTIMER_INTERFACE_H_
#define MTIMER_INTERFACE_H_

typedef enum {
	T0_OVF,
	T0_CTC,
	T1_OVF,
	T1_CTCB,
	T1_CTCA,
	T1_ICT,
	T2_OVF,
	T2_CTC
}TIMER_t;


typedef enum
{
	NOK,
	OK
}ErrorStatus;


/************************************************************************************************************/
/*	function name:			void MTIMER_vTimerInit(void)
 * 	function inputs:		void
 * 	function outputs:		void
 * 	function Description	set the configuration for the 3 timers
 */
/************************************************************************************************************/
void MTIMER_vTimerInit(void);

/************************************************************************************************************/
/*	function name:			void MTIMER_vStartTimer(TIMER_t copy_enumTimerId,u16 copy_u16Delay)
 * 	function inputs:		timer id and time required as counted ticks
 * 	function outputs:		void
 * 	function Description	set the pre-scaller and fill the TCNT reg with the value of counts needed
 */
/************************************************************************************************************/
void MTIMER_vStartTimer(TIMER_t copy_enumTimerId,u16 copy_u16Delay);

/************************************************************************************************************/
/*	function name:			void MTIMER_vSetPreLoad(TIMER_t copy_enumTimerId,u16 copy_u16PreLoad)
 * 	function inputs:		timer id and preload
 * 	function outputs:		void
 * 	function Description	set the init value of TCNT reg with the value of counts needed to start from
 */
/************************************************************************************************************/
void MTIMER_vSetPreLoad(TIMER_t copy_enumu8TimerID, u16 copy_u16PreLoad);

/************************************************************************************************************/
/*	function name:			void MTIMER_vEndTimer(TIMER_t copy_enumTimerId)
 * 	function inputs:		timer id
 * 	function outputs:		void
 * 	function Description	set TCNT reg with 0
 */
/************************************************************************************************************/
void MTIMER_vEndTimer(TIMER_t copy_enumTimerId);

/************************************************************************************************************/
/*	function name:			void MTIMER_vEnableTimerPIE(TIMER_t copy_enumTimerId)
 * 	function inputs:		timer id
 * 	function outputs:		void
 * 	function Description	according to the timer id, it enables interrupt PIE
 */
/************************************************************************************************************/
void MTIMER_vEnableTimerPIE(TIMER_t copy_EnumTimerId);

/************************************************************************************************************/
/*	function name:			MTIMER_vDisableTimerPIE(TIMER_t copy_EnumTimerId)
 * 	function inputs:		timer id
 * 	function outputs:		void
 * 	function Description	according to the timer id, it disables interrupt PIE
 */
/************************************************************************************************************/
void MTIMER_vDisableTimerPIE(TIMER_t copy_EnumTimerId);

/************************************************************************************************************/
/*	function name:			void MTIMER_vSetOCR(TIMER_t copy_enumTimerId, u16 copy_u16ValueOCR)
 * 	function inputs:		timer id and time required as counted ticks
 * 	function outputs:		void
 * 	function Description	set the OCR reg with the value of counts needed in Compare mode
 */
/************************************************************************************************************/
void MTIMER_vSetOCR(TIMER_t copy_enumTimerId, u16 copy_u16ValueOCR);

/************************************************************************************************************/
/*	function name:			void MTIMER_vSetICR(u16 copy_u16ValueICR)
 * 	function inputs:		Value of ICR
 * 	function outputs:		void
 * 	function Description	set the ICR reg with the value of counts needed, it available only in T1.
 */
/************************************************************************************************************/
void MTIMER_vSetICR(u16 copy_u16ValueICR );

/************************************************************************************************************/
/*	function name:			void MTIMER_u16GetTimerCounterReg(TIMER_t copy_enumTimerId)
 * 	function inputs:		timer id
 * 	function outputs:		value of TCNTx reg
 * 	function Description	it returns the value of TCNT reg with the value of counts needed
 */
/************************************************************************************************************/
u16 MTIMER_u16GetTimerCounterReg(TIMER_t copy_EnumTimerId);

/************************************************************************************************************/
/*	function name:			u16 MTIMER_u16GetValueICR(void)
 * 	function inputs:		void
 * 	function outputs:		the value of ICR reg.
 * 	function Description	return the ICR reg with the value of counts needed, it available only in T1.
 */
/************************************************************************************************************/
u16 MTIMER_u16GetValueICR(void);

/************************************************************************************************************/
/*	function name:			void MTIMER_SetCallback(void (*fptr)(void),TIMER_t copy_enumInterrupt_Flag)
 * 	function inputs:		pointer to function , timer_flag id
 * 	function outputs:		void
 * 	function Description	points to the global pointer to function where the isr can have access to it
 */
/************************************************************************************************************/
void MTIMER_SetCallback(void (*fptr)(void),TIMER_t copy_enumInterrupt_Flag);

#endif /* MTIMER_INTERFACE_H_ */
