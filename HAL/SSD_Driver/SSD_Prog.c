/*
 * SSD_Prog.c
 *
 *  Created on: Aug 4, 2023
 *      Author: marka
 */



#include "../../Library/STD_TYPES.h"
#include "../../Library/BIT_MATH.h"
#include "../../MCAL/DIO_Driver/DIO_Config.h"
#include "../../MCAL/DIO_Driver/DIO_Interface.h"
#include "../../MCAL/DIO_Driver/DIO_Private.h"
#include "SSD_Interface.h"
#include"SSD_Private.h"
#include"SSD_Config.h"




void SSD_voidInit			(SSD * Copy_pstructSSD){
	DIO_voidSetPortDirection(Copy_pstructSSD->Port , DIO_OUTPUT);

		switch(Copy_pstructSSD->CommonState){
			case  SSD_COMMON_Anode :
				DIO_voidSetPortValue(Copy_pstructSSD->Port , 0xff );
				break;

			case SSD_COMMON_Cathode :
				DIO_voidSetPortValue( Copy_pstructSSD->Port , 0x00 );
				break ;
	}
}


void SSD_voidEnable	(SSD * Copy_pstructSSD ,u8 Copy_u8Number ){
		switch(Copy_pstructSSD->CommonState) {
			case  SSD_COMMON_Anode :

				DIO_voidSetPortValue(Copy_pstructSSD->Port,ArrayNumbers[ Copy_u8Number]);
				break;

			case SSD_COMMON_Cathode :

				DIO_voidSetPortValue(Copy_pstructSSD->Port,ArrayNumbers[ Copy_u8Number]);
				break ;
	}
}

void SSD_voidDisable		(SSD * Copy_pstructSSD){

	switch (Copy_pstructSSD->CommonState) {
		case  SSD_COMMON_Anode :
			DIO_voidSetPortValue(Copy_pstructSSD->Port, 0x00);
			break ;
		case SSD_COMMON_Cathode :
			DIO_voidSetPortValue(Copy_pstructSSD->Port, 0xff);
			break ;
	}
}
