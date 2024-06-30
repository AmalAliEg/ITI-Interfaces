/*

 * main.c
 *
 *  Created on: Dec 9, 2023
 *      Author: Aml
 */

/*include the libraries */
#include <util/delay.h>
#include "LIBRARY/BIT_MATH.h"
#include "LIBRARY/STD_TYPES.h"



/*include APP layer */
#include "APP/segment.h"

/*include the HAL layer*/

#include "HAL/SSD_driver/HSSD_private.h"
#include "HAL/SSD_driver/HSSD_config.h"
#include "HAL/SSD_driver/HSSD_interface.h"


/*include the MCAL layer */
#include "MCAL/DIO_driver/DIO_private.h"
#include "MCAL/DIO_driver/DIO_config.h"
#include "MCAL/DIO_driver/DIO_interface.h"

int main() {
	Show_Num_on7Seg();					//animate the seg that show from 0 to 9

}
