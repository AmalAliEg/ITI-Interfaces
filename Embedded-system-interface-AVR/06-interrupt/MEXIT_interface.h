/*
 * INT_interface.h
 *
 *  Created on: Dec 18, 2023
 *      Author: Aml
 */

#ifndef MEXIT_INTERFACE_H_
#define MEXIT_INTERFACE_H_

typedef enum
{
	NOK,
	OK
}ErrorStatus;


typedef enum {
	IN0,
	IN1,
	IN2,
}EXTI_channel_t;


#define Dis_INT		0
#define En_INT 		1


#define SFALL_EDG 	1
#define SRIS_EDG 	2
#define SON_CHG 	3
#define SLOW 		4


/************************************************************************************************************/
/*	function name:		void MEXIT_vIntInit( EXTI_channel_t copyEnumChannelNum)
 * 	function inputs:	copyEnumChannelNum
 * 	function outputs:	void
 */
/************************************************************************************************************/
void MEXIT_vIntInit(void);	//pre-build configration

/************************************************************************************************************/
/*	function name:		ErrorStatus MEXIT_enumEnableIterrupt(u8 copy_u8InterruptID)
 * 	function inputs:	copy_u8InterruptID
 * 	function outputs:	ErrorStatus
 * 	description:		enable PIE of external interrupt
 */
/************************************************************************************************************/
ErrorStatus MEXIT_enumEnableIterrupt(u8 copy_u8InterruptID);

/************************************************************************************************************/
/*	function name:		ErrorStatus MEXIT_enumDisableIterrupt(u8 copy_u8InterruptID)
 * 	function inputs:	copy_u8InterruptID
 * 	function outputs:	ErrorStatus
 * 	description:		disable PIE of external interrupt
 */
/************************************************************************************************************/

ErrorStatus MEXIT_enumDisableIterrupt(u8 copy_u8InterruptID);
/************************************************************************************************************/
/*	function name:		ErrorStatus MEXIT_enumClrInterruptFlag(u8 copy_u8InterruptID)
 * 	function inputs:	copy_u8InterruptID
 * 	function outputs:	ErrorStatus
 * 	description:		clear the flag by set it with logic one
 */
/************************************************************************************************************/
ErrorStatus MEXIT_enumClrInterruptFlag(u8 copy_u8InterruptID);


/************************************************************************************************************/
/*	function name:		ErrorStatus MEXIT_enumCallBack(u8 copy_u8InterruptID)
 * 	function inputs:	p_voidfuncCallBack
 * 	function outputs:	ErrorStatus
 * 	description:		take address of a function in the main to add it in ISR
 */
/************************************************************************************************************/

ErrorStatus MEXIT_enumCallBack(void (*p_voidfuncCallBack)(void),u8 copy_u8InterruptID);

#endif /* MEXIT_INTERFACE_H_ */

