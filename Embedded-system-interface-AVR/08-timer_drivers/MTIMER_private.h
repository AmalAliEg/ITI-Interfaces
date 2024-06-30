/*
 * INT_private.h
 *
 *  Created on: Dec 21, 2023
 *      Author: Aml
 */

#ifndef MTIMER_PRIVATE_H_
#define MTIMER_PRIVATE_H_
/*define modes of timer0*/
#define T0normal_M 				1
#define T0CTC_M 				2
#define T0PhasePWM_M			3
#define T0FastPWM_M 			4

#define CLR_OC0_ON_CMP			1
#define SET_OC0_ON_CMP			2




/*define modes of timer1*/

#define T1normal_M 		1
#define T1CTC_M 		2
#define T1PhasePWM_M	3
#define T1FastPWM_M 	4

/*cases of the top at CTC mode **/
#define Top_OCR1A				1
#define Top_ICR1A				2

/*cases of the top at FAST_PWM mode */
#define Top_fast_OCR1A			1
#define Top_fast_ICR1A			2
#define Top_fast_8Bit			3
#define Top_fast_9Bit			4
#define Top_fast_10Bit			5

/*cases of the top at PHASE_PWM mode */
#define Top_Phase_8Bit			1
#define Top_Phase_9Bit			2
#define Top_Phase_10Bit			3
#define Top_Phase_ICR1			4
#define Top_Phase_OCR1A			5


#define CLR_OCA_ON_CMP			1
#define SET_OCA_ON_CMP			2

#define CLR_OCB_ON_CMP			1
#define SET_OCB_ON_CMP			2

/*define modes of timer2*/

#define T2normal_M 				1
#define T2CTC_M 				2
#define T2PhasePWM_M			3
#define T2FastPWM_M 			4

#define CLR_OC2_ON_CMP			1
#define SET_OC2_ON_CMP			2

#define DIS_TNT 0
#define ENB_TNT 1
/**********************************************************/
/*                        timers registers               */
/**********************************************************/

#define TIMSK 	*((volatile u8*)(0x59))  			//Timer/Counter Interrupt Mask Register  --PIE of the timer
	#define TIMSK_TOIE0 	0
	#define TIMSK_OCIE0 	1
    #define TIMSK_TOIE1 	2
    #define TIMSK_OCIE1B 	3
    #define TIMSK_OCIE1A 	4
    #define TIMSK_TICIE1 	5
	#define TIMSK_TOIE2 	6
	#define TIMSK_OCIE2 	7

//---------------------------------------------------------------
#define TIFR 	*((volatile u8*)(0x58))  		//Timer/Counter Interrupt Flag Register  --PIF of the timer
		#define TIFR_TOV0 		0
		#define TIFR_OCF0 		1
		#define TIFR_TOIE1 		2
		#define TIFR_OCIE1B 	3
		#define TIFR_OCIE1A 	4
		#define TIFR_TICIE1 	5
		#define TIFR_TOIE2 		6
		#define TIFR_OCIE2 		7


/**********************************************************/
/*                     timers0 register                   */
/**********************************************************/


#define TCCR0 		*((volatile u8*)(0x53))  //Timer/Counter Register – control timer mode and prescaler. it is control register
	#define TCCR0_WGM00 6
	#define TCCR0_WGM01 3
	#define TCCR0_COM00 4
	#define TCCR0_COM01 5

	#define TCCR0_CS00 0
	#define TCCR0_CS01 1
	#define TCCR0_CS02 2
//---------------------------------------------------------------
#define TCNT0 		*((volatile u8*)(0x52))  ////Timer/Counter Register –counts needed to access required time of the app.  the register to used
#define OCR0 		*((volatile u8*)(0x5C))  //Output Compare Register


/**********************************************************/
/*                     timers1 register                   */
/**********************************************************/

#define  TCCR1A		*((volatile u8*)(0x4F))	 //Timer/Counter Register for A – 16-bit register. it is control register
#define  TCCR1B		*((volatile u8*)(0x4E)) 	//Timer/Counter Register for B –16-bit register.  the register to be controled
#define  TCCR1		*((volatile u16*)(0x4E)) 	//Timer/Counter Register for B –16-bit register.  the register to be controled
	#define TCCR1_WGM10 8
	#define TCCR1_WGM11 9
	#define TCCR1_WGM12 3
	#define TCCR1_WGM13 4
	#define TCCR1_COM10 12
	#define TCCR1_COM11 13
	#define TCCR1_COM12 14
	#define TCCR1_COM13 15

	#define TCCR1_CS10 0
	#define TCCR1_CS11 1
	#define TCCR1_CS12 2
//---------------------------------------------------------------

#define  TCNT1H  *((volatile u8*)(0x4D))                   //Timer/Counter1 – Counter Register High Byte 109
#define  TCNT1L  *((volatile u8*)(0x4C))         //Timer/Counter1 – Counter Register Low Byte 109
#define  TCNT1   *((volatile u16*)(0x4C))      //Timer/Counter1 – Counter
//---------------------------------------------------------------


#define  OCR1AH  *((volatile u8*)(0x4B))                 //Timer/Counter1 – Output Compare Register A High Byte 109
#define  OCR1AL  *((volatile u8*)(0x4A))                     //Timer/Counter1 – Output Compare Register A Low Byte 109
#define  OCR1A   *((volatile u16*)(0x4A))                     //Timer/Counter1 – Output Compare Register A Low Byte 109
//---------------------------------------------------------------


#define  OCR1BH  *((volatile u8*)(0x49)) 			//Timer/Counter1 – Output Compare Register B High Byte 109
#define  OCR1BL  *((volatile u8*)(0x48)) 			//Timer/Counter1 – Output Compare Register B Low Byte 109
#define  OCR1B   *((volatile u16*)(0x48)) 			//Timer/Counter1 – Output Compare Register B Low Byte 109
//---------------------------------------------------------------


#define  ICR1H   *((volatile u8*)(0x47))				//Timer/Counter1 – Input Capture Register High Byt
#define ICR1L    *((volatile u8*)(0x46))
#define ICR1     *((volatile u16*)(0x46))



/**********************************************************/
/*                     timers2 register                   */
/**********************************************************/

#define TCCR2  *((volatile u8*)(0x45))
	#define TCCR2_WGM20 6
	#define TCCR2_WGM21 3
	#define TCCR2_COM20 4
	#define TCCR2_COM21 5

	#define TCCR2_CS20 0
	#define TCCR2_CS21 1
	#define TCCR2_CS22 2
//---------------------------------------------------------------

#define  TCNT2 *((volatile u8*)(0x44))      //Timer/Counter2 (8 Bits) 125
//---------------------------------------------------------------

#define  OCR2  *((volatile u8*)(0x43))       //Timer/Counter2 Output Compare Register





/****************************************************************/
/*              define the prescaller                           */
/****************************************************************/
#define PR_1    0b001          	//1MHz
#define PR_8    0b010	        //8MHz
#define PR_64   0b011		    //64MHz
#define PR_256  0b100			//256MHz
#define PR_1024 0b101			//1024MHz

#endif /* MTIMER_PRIVATE_H_ */
