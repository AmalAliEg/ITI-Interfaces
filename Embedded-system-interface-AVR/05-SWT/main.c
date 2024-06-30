/*
 * main.c
 *
 *  Created on: Jan 8, 2024
 *      Author: DELL
 */


/*include the libraries */
#include <util/delay.h>
#include "LIBRARY/BIT_MATH.h"
#include "LIBRARY/STD_TYPES.h"

/*include APP layer */
#include "APP/switch.h"

/*include HAL layer */
#include "HAL/SSD_driver/HSSD_private.h"
#include "HAL/SSD_driver/HSSD_config.h"
#include "HAL/SSD_driver/HSSD_interface.h"


/*include the MCAL layer */
#include "MCAL/DIO_driver/DIO_private.h"
#include "MCAL/DIO_driver/DIO_config.h"
#include "MCAL/DIO_driver/DIO_interface.h"


int main(void){
DIP_switch_lab1();
}
