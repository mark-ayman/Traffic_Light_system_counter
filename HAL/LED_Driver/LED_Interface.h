/*
 * LED_Interface.h
 *
 *  Created on: Aug 4, 2023
 *      Author: marka
 */

#ifndef HAL_LED_DRIVER_LED_INTERFACE_H_
#define HAL_LED_DRIVER_LED_INTERFACE_H_

#include "../../Library/BIT_MATH.h"
#include "../../Library/STD_TYPES.h"
#include "../../MCAL/DIO_Driver/DIO_Config.h"
#include "../../MCAL/DIO_Driver/DIO_Interface.h"
#include "../../MCAL/DIO_Driver/DIO_Private.h"



#define LED_Active_High 1

#define LED_Active_LOW 0

typedef struct {
	u8 port ;
	u8 Pin;
	u8 Active_state;
}LED;



void LED_voidInit(LED * copy_localLEDPtr );
void LED_voidON(LED * copy_localLEDPtr );
void LED_voidOFF(LED * copy_localLEDPtr );


#endif /* HAL_LED_DRIVER_LED_INTERFACE_H_ */
