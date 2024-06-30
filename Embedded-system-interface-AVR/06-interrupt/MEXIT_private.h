/*
 * INT_private.h
 *
 *  Created on: Dec 18, 2023
 *      Author: Aml
 */

#ifndef MEXIT_PRIVATE_H_
#define MEXIT_PRIVATE_H_

/*configure bit of MCUCR reg.*/
#define MCUCR_ISC00 0  //bit no.0 inside MCURC register ctrl sense for INT0
#define MCUCR_ISC01 1	//bit no.1 inside MCURC register ctrl sense for INT0
#define MCUCR_ISC10 2	//bit no.2 inside MCURC register ctrl sense for INT1
#define MCUCR_ISC11 3	//bit no.3 inside MCURC register ctrl sense for INT1

/*configure bit of MCUCR reg.*/
#define MCUCSR_ISC2 6  //bit no.6 inside MCUCSR register ctrl sense for INT2

/*configure bit of GICR reg.*/
#define GICR_INT0 6 //bit no. 6 i reg. GICR
#define GICR_INT1 7 //bit no. 7 i reg. GICR
#define GICR_INT2 5 //bit no. 5 i reg. GICR

/*configure bit of GIFR reg.*/
#define GIFR_INT0 6 //bit no. 6 i reg. GIFR
#define GIFR_INT1 7 //bit no. 7 i reg. GIFR
#define GIFR_INT2 5 //bit no. 5 i reg. GIFR
/*
 * define the register for all ports
 * it's not important to write volatile
 */
#define MCUCR_reg 	*(  (volatile u8*)  (0x55) )	//control reg and ctrl interrupt sense for IN0,IN1
#define MCUCSR_reg 	*(  (volatile u8*)  (0x54) )	//control reg and ctrl interrupt sense for IN2
#define GICR_reg 	*(  (volatile u8*)  (0x5B) )	//PIE of IN0,IN1,IN2
#define GIFR_reg	*(  (volatile u8*)  (0x5A) )	//PIF flag



#endif /* MEXIT_PRIVATE_H_ */
