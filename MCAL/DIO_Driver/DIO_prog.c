/*
 * DIO_prog.c
 *
 *  Created on: Aug 3, 2023
 *      Author: marka
 */

#include "../../Library/BIT_MATH.h"
#include "../../Library/STD_TYPES.h"

#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"





void DIO_voidSetPinDirection    (u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8Direction ){
	switch(Copy_u8Direction){
	case DIO_OUTPUT :
		switch (Copy_u8PortId){
		case DIO_PORTA :
				SET_BIT(DDRA_REG,Copy_u8PinId);
			break;
		case DIO_PORTB :
				SET_BIT(DDRB_REG,Copy_u8PinId);
			break;
		case DIO_PORTC :
			    SET_BIT(DDRC_REG,Copy_u8PinId);
			break;
		case DIO_PORTD  :
				SET_BIT(DDRD_REG,Copy_u8PinId);
			break;
		}
		break;

	case DIO_INPUT :
		switch (Copy_u8PortId){
		case DIO_PORTA :
				CLEAR_BIT(DDRA_REG,Copy_u8PinId);
			break;
		case DIO_PORTB :
				CLEAR_BIT(DDRB_REG,Copy_u8PinId);
			break;
		case DIO_PORTC :
				CLEAR_BIT(DDRC_REG,Copy_u8PinId);
			break;
		case DIO_PORTD  :
				CLEAR_BIT(DDRD_REG,Copy_u8PinId);
			break;
		}
		break ;
	}
}

void DIO_voidSetPinValue    (u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8Value ){
	switch(Copy_u8Value){
	case DIO_HIGH :
		switch (Copy_u8PortId){
		case DIO_PORTA :
				SET_BIT(PORTA_REG,Copy_u8PinId);
			break;
		case DIO_PORTB :
				SET_BIT(PORTB_REG,Copy_u8PinId);
			break;
		case DIO_PORTC :
			    SET_BIT(PORTC_REG,Copy_u8PinId);
			break;
		case DIO_PORTD  :
				SET_BIT(PORTD_REG,Copy_u8PinId);
			break;
		}
		break;

	case DIO_LOW :
		switch (Copy_u8PortId){
		case DIO_PORTA :
				CLEAR_BIT(PORTA_REG,Copy_u8PinId);
			break;
		case DIO_PORTB :
				CLEAR_BIT(PORTB_REG,Copy_u8PinId);
			break;
		case DIO_PORTC :
				CLEAR_BIT(PORTC_REG,Copy_u8PinId);
			break;
		case DIO_PORTD  :
				CLEAR_BIT(PORTD_REG,Copy_u8PinId);
			break;
		}
		break ;
	}
}

u8 DIO_u8GetPinValue        (u8 Copy_u8PortId , u8 Copy_u8PinId ){
	u8 Local_u8ReturnedValue = 255 ;
	switch (Copy_u8PortId){
		case DIO_PORTA :
			Local_u8ReturnedValue=GIT_BIT(PINA_REG,Copy_u8PinId);
			break;
		case DIO_PORTB :
			Local_u8ReturnedValue=GIT_BIT(PINB_REG,Copy_u8PinId);
			break;
		case DIO_PORTC :
			Local_u8ReturnedValue=GIT_BIT(PINC_REG,Copy_u8PinId);
			break;
		case DIO_PORTD  :
			Local_u8ReturnedValue=GIT_BIT(PIND_REG,Copy_u8PinId);
			break;
		}
	return Local_u8ReturnedValue;
}

void DIO_voidSetPortDirection    (u8 Copy_u8PortId , u8 Copy_u8Direction ){
	switch(Copy_u8Direction){
		case DIO_OUTPUT :
				switch(Copy_u8PortId){
					case DIO_PORTA :
							DDRA_REG=255;//0xFF//0b 1111 1111
						break;
					case DIO_PORTB :
						DDRB_REG=255;//0xFF//0b 1111 1111
						break;
					case DIO_PORTC :
						DDRC_REG=255;//0xFF//0b 1111 1111
						break;
					case DIO_PORTD :
						DDRD_REG=255;//0xFF//0b 1111 1111
						break;
				}
			break;
		case DIO_INPUT  :
			switch(Copy_u8PortId){
				case DIO_PORTA :
					DDRA_REG=0;//0x00//0b 0000 0000
					break;
				case DIO_PORTB :
					DDRB_REG=0;//0x00//0b 0000 0000
					break;
				case DIO_PORTC :
					DDRC_REG=0;//0x00//0b 0000 0000
					break;
				case DIO_PORTD :
					DDRD_REG=0;//0x00//0b 0000 0000
					break;
			}
			break;
	}
}

void DIO_voidSetPortValue    (u8 Copy_u8PortId , u8 Copy_u8Value ){
		switch(Copy_u8PortId){
			case DIO_PORTA :
				PORTA_REG=Copy_u8Value;
				break;
			case DIO_PORTB :
				PORTB_REG=Copy_u8Value;
				break;
			case DIO_PORTC :
				PORTC_REG=Copy_u8Value;
				break ;
			case DIO_PORTD :
				PORTD_REG=Copy_u8Value;
				break;
		}
}

u8 DIO_u8GetPortValue  (u8 Copy_u8PortId  ){
	u8 Local_u8ReturnedValue = 255 ;

	switch(Copy_u8PortId){
		case DIO_PORTA :
				Local_u8ReturnedValue=PINA_REG;
				break;
		case DIO_PORTB :
				Local_u8ReturnedValue=PINB_REG;
				break;
		case DIO_PORTC :
				Local_u8ReturnedValue=PINC_REG;
			break;
		case DIO_PORTD :
				Local_u8ReturnedValue=PIND_REG;
				break;
	}
	return Local_u8ReturnedValue;
}








