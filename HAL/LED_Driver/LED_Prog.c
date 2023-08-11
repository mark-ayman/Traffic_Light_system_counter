/*
 * LED_Prog.c
 *
 *  Created on: Aug 4, 2023
 *      Author: marka
 */


#include "../../Library/BIT_MATH.h"
#include "../../Library/STD_TYPES.h"
#include "../../MCAL/DIO_Driver/DIO_Config.h"
#include "../../MCAL/DIO_Driver/DIO_Interface.h"
#include "../../MCAL/DIO_Driver/DIO_Private.h"
#include "LED_Interface.h"



//Initialization of Led pin as checking and put { port , pin , Determine Active_state of LED }

void LED_voidInit(LED * copy_localLEDPtr ){

	DIO_voidSetPinDirection ( copy_localLEDPtr->port , copy_localLEDPtr->Pin, DIO_OUTPUT);
	switch ( copy_localLEDPtr->Active_state ) {

		case LED_Active_High :

				DIO_voidSetPinValue(copy_localLEDPtr->port,copy_localLEDPtr->Pin,DIO_LOW);
				break;

		case LED_Active_LOW :

			DIO_voidSetPinValue(copy_localLEDPtr->port,copy_localLEDPtr->Pin,DIO_HIGH);
			break;

	}
}

void LED_voidON(LED * copy_localLEDPtr ){
	switch(copy_localLEDPtr->Active_state){
		case LED_Active_High :
			DIO_voidSetPinValue(copy_localLEDPtr->port,copy_localLEDPtr->Pin,DIO_HIGH);
			break;
		case LED_Active_LOW :
			DIO_voidSetPinValue(copy_localLEDPtr->port,copy_localLEDPtr->Pin,DIO_LOW);
			break;
	}
}


void LED_voidOFF(LED * copy_localLEDPtr ){
	switch(copy_localLEDPtr->Active_state){
		case LED_Active_High :
			DIO_voidSetPinValue(copy_localLEDPtr->port,copy_localLEDPtr->Pin,DIO_LOW);
			break;
		case LED_Active_LOW :
			DIO_voidSetPinValue(copy_localLEDPtr->port,copy_localLEDPtr->Pin,DIO_HIGH);
			break;
	}

}
