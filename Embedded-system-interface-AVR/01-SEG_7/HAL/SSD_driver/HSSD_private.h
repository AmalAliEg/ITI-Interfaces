/*
 * HSSD_private.h
 *
 *  Created on: Dec 31, 2023
 *      Author: Aml
 */

#ifndef HAL_SSD_DRIVER_HSSD_PRIVATE_H_
#define HAL_SSD_DRIVER_HSSD_PRIVATE_H_
/*
//gfed cba
			0b01110111,
			0b01100110,
			0b11010111,
			0b11010111,
			0b01100110,
			0b10110110,
			0b10111110,
			0b11100000,
			0b11111110,
			0b11110110	};

*/
/*define common cathod array*/
#define ARRAY_OF_CATHODE_NUM {	0b01110111 ,\
								0b01100110 ,\
								0b11010111 ,\
								0b11010111 ,\
								0b01100110 ,\
								0b10110110 ,\
								0b10111110 ,\
								0b11100000 ,\
								0b11111110 ,\
								0b11110110	\
								}\

#define ARRAY_OF_ANODE_NUM {	0b11000000 ,\
								0b11111001 ,\
								0b10100100 ,\
								0b10110000 ,\
								0b10011001 ,\
								0b10010010 ,\
								0b10000010 ,\
								0b11111000 ,\
								0b10000000 ,\
								0b10010000	\
								}\


 u8 u8Mask (u8 copy_Number);
#endif /* HAL_SSD_DRIVER_HSSD_PRIVATE_H_ */
