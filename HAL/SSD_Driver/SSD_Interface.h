/*
 * SSD_Interface.h
 *
 *  Created on: Aug 4, 2023
 *      Author: marka
 */

#ifndef HAL_SSD_DRIVER_SSD_INTERFACE_H_
#define HAL_SSD_DRIVER_SSD_INTERFACE_H_

#include "../../Library/BIT_MATH.h"
#include "../../Library/STD_TYPES.h"

#define SSD_COMMON_Anode 1
#define SSD_COMMON_Cathode 0


#define ZERO 	0b00111111
#define ONE		0b00000110
#define TWO		0b01011011
#define THREE	0b01001111
#define FOUR	0b01100110
#define FIVE	0b01101101
#define SIX		0b01111101
#define SEVEN	0b00000111
#define EIGHT	0b01111111
#define NINE 	0b01101111

typedef struct {
	u8 Port;
	u8 CommonState;
}SSD;

const static u8 ArrayNumbers[10] = { ZERO , ONE , TWO , THREE , FOUR , FIVE , SIX , SEVEN , EIGHT , NINE};


void SSD_voidInit			(SSD * Copy_pstructSSD);

void SSD_voidEnable			(SSD * Copy_pstructSSD ,u8 Copy_u8Number );

void SSD_voidDisable		(SSD * Copy_pstructSSD);


#endif /* HAL_SSD_DRIVER_SSD_INTERFACE_H_ */
