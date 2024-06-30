/*
 * INT_config.h
 *
 *  Created on: Dec 18, 2023
 *      Author: Aml
 */

#ifndef MEXIT_CONFIG_H_
#define MEXIT_CONFIG_H_

#define Int0_mode En_INT
#define Int1_mode En_INT
#define Int2_mode En_INT

/*
 * sense options:
 * 				1- SFALL_EDG 1
				2- SRIS_EDG 2
				3- SON_CHG 3
				4- SLOW 4
 */
#define IN0_Sense_ctrl  SON_CHG
#define IN1_Sense_ctrl  SFALL_EDG

/*
 * sense options:
 * 				1- SFALL_EDG 1
				2- SRIS_EDG 2

 */
#define IN2_Sense_ctrl  SFALL_EDG




#endif /* MEXIT_CONFIG_H_ */
