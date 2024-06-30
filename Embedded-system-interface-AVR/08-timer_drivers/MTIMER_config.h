/*
 * INT_config.h
 *
 *  Created on: Dec 18, 2023
 *      Author: Aml
 */

#ifndef MTIMER_CONFIG_H_
#define MTIMER_CONFIG_H_

/*
 * sense options:
 *	T0normal_M 		1				|	ENB_TNT means enable PIE of the TImer 0
	T0CTC_M 		2				|	DIS_TNT means disable PIE of the TImer 0
	T0PhasePWM_M	3				|
	T0FastPWM_M 	4				|
 */
/*timer 0 configuration */
#define Timer0_mode 				T0CTC_M
#define Timer0_prescaller 			PR_64
#define Timer0_Interrupt 			ENB_TNT
#define Timer0_CTC_PWM_mode			CLR_OC0
/*
 * sense options:
 *	T1normal_M 		1               |	ENB_TNT means enable PIE of the TImer 1
	T1CTC_M 		2               |	DIS_TNT means disable PIE of the TImer 1
	T1PhasePWM_M	3               |
	T1FastPWM_M 	4               |
 */

/*timer 1 configuration*/
#define Timer1_prescaller 			PR_64
#define Timer1_mode 				T1PhasePWM_M
#define Timer1_Interrupt 			ENB_TNT
#define Timer1_channelA_ctcMODE		CLR_OCA_ON_CMP
#define Timer1_channelB_ctcMODE		SET_OCB_ON_CMP

#define T1_CTCtop					Top_OCR1A
#define T1_FASTtop					Top_fast_OCR1A
#define T1_PHASEtop					Top_Phase_OCR1A


/*
 * sense options:
 *	T2normal_M 		1               |	ENB_TNT means enable PIE of the TImer 2
	T2CTC_M 		2               |	DIS_TNT means disable PIE of the TImer 2
	T2PhasePWM_M	3               |
	T2FastPWM_M 	4               |
 */
/*timer 2 configuration*/
#define Timer2_prescaller 			PR_64
#define Timer2_mode 				T2normal_M
#define Timer2_Interrupt 			ENB_TNT
#define Timer2_CTC_PWM_mode 		CLR_OC2


#endif /* MTIMER_CONFIG_H_ */
