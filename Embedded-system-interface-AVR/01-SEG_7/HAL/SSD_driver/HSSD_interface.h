/*
 * SSD_interface.h
 *
 *  Created on: Dec 31, 2023
 *      Author: Aml
 */

#ifndef HAL_SSD_DRIVER_HSSD_INTERFACE_H_
#define HAL_SSD_DRIVER_HSSD_INTERFACE_H_



/*define SSD types*/
#define COMMON_CATHOD_SSD 1
#define COMMON_ANODE_SSD 2



/*define SSD port*/
#define SSD_PORTA PORTA
#define SSD_PORTB PORTB
#define SSD_PORTC PORTC
#define SSD_PORTD PORTD


/*define ssd pins direction*/
#define SS_OUTPUT 0xff
#define SS_INPUT 0x00


/************************************************************************************************************/
/*	function name:		void HSSD_vInit(u8 copy_u8PortSSD,copy_u8SSDtype)
 * 	function inputs:	Port number, type(cathode or anode)
 * 	function outputs:	void
 */
/************************************************************************************************************/
void HSSD_vInit(u8 copy_u8PortSSD);


/************************************************************************************************************/
/*	function name:		void HSSD_vDisplayNumber(u8 copy_u8PortSSD, u8 copy_u8Number )
 * 	function inputs:	Port number, number
 * 	function outputs:	void
 */
/************************************************************************************************************/
void HSSD_vDisplayNumber(u8 copy_u8PortSSD, u8 copy_u8Number, u8 copy_u8SSDtype);




#endif /* HAL_SSD_DRIVER_HSSD_INTERFACE_H_ */



