/*
 * PushButton_Interface.h
 *
 *  Created on: Aug 4, 2023
 *      Author: marka
 */

#ifndef HAL_PUSH_BUTTON_PUSHBUTTON_INTERFACE_H_
#define HAL_PUSH_BUTTON_PUSHBUTTON_INTERFACE_H_


#define PB_Pull_UP 1
#define PB_Pull_DOWN 0


typedef struct {
	u8 Port;
	u8 Pin ;
	u8 PB_Pull_State;
}PB;


void PB_voidInit (PB * copy_localPB);







#endif /* HAL_PUSH_BUTTON_PUSHBUTTON_INTERFACE_H_ */
