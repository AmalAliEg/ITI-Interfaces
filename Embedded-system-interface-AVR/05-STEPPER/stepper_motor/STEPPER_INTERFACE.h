/*
 * DIO_interface.h
 *
 *  Created on: Sep 11, 2022
 *      Author: Aml
 */

#ifndef STEPPER_MOTOR_STEPPER_INTERFACE_H_
#define STEPPER_MOTOR_STEPPER_INTERFACE_H_


#include <util/delay.h>


#define ClockWise 1
#define Anti_ClockWise 2

#define Full_step 1
#define half_step 2

#define Coil_Blue     0
#define Coil_Pink     1
#define Coil_Yellow   2
#define Coil_Orange   3

#define stride_angle 5.625
#define gear_angle 64                       //find in data sheet-> 28byj48 module ->stride angle =5.625/64
#define full_rotation  (360/stride_angle)                      //from data sheet ->360/5.625=64
#define Full_haptic_angle        (gear_angle*full_rotation)              //angle felt from the motor

#define HW_PORT PORTD


void HStepper_init(u8 copy_u8StepperDir);
void HStepper_DIR_MODE(u8 DIRECTION,u8 steps_mode);





#endif /* DIO_DIO_INTERFACE_H_ */
