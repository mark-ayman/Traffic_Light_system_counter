/*

 * main.c
 *
 *  Created on: Aug 4, 2023
 *      Author: marka
 */


#include "Library/BIT_MATH.h"
#include "Library/STD_TYPES.h"
#include "HAL/LED_Driver/LED_Interface.h"
#include "HAL/SSD_Driver/SSD_Interface.h"
#include "MCAL/DIO_Driver/DIO_Interface.h"
//#include "HAL/Push_Button/PushButton_Interface.h"
#define 	F_CPU  8000000UL

#include <util/delay.h>



int main(void){


	LED led1_RED    ={DIO_PORTB , DIO_PIN0 , LED_Active_High};
	LED led2_YELLOW ={DIO_PORTB , DIO_PIN1 , LED_Active_High};
	LED led3_GREEN  ={DIO_PORTB , DIO_PIN2 , LED_Active_High};



	LED_voidInit( & led1_RED );
	LED_voidInit( & led2_YELLOW );
	LED_voidInit( & led3_GREEN );


	SSD SSD_1={ DIO_PORTC , SSD_COMMON_Anode } ;
	SSD SSD_2={ DIO_PORTA , SSD_COMMON_Anode } ;

	SSD_voidInit(& SSD_1 );
	SSD_voidInit(& SSD_2 );

	u8 counter =0;

	LED_voidOFF(&led3_GREEN);
	LED_voidOFF(&led2_YELLOW);
	LED_voidOFF(&led1_RED);
	while(counter!=70){
		for (u8 i=0;i<=9;i++){
			for(u8 k=0;k<=9;k++){
				if((counter>0&&counter<10)||(counter>23&&counter<33)||((counter>46&&counter<56))){
					LED_voidON(&led3_GREEN);
					LED_voidOFF(&led2_YELLOW);
					LED_voidOFF(&led1_RED);
				}
				else{
					LED_voidOFF(&led3_GREEN);
				}
				if((counter>13&&counter<23)||(counter>36&&counter<46)||(counter>59&&counter<70)){
					LED_voidON(&led1_RED);
					LED_voidOFF(&led3_GREEN);
					LED_voidOFF(&led2_YELLOW);
				}
				else{
					LED_voidOFF(&led1_RED);
				}
				if((counter>10&&counter<13)||(counter>33&&counter<36)||(counter>56&&counter<59)){
					LED_voidON(&led2_YELLOW);
					LED_voidOFF(&led1_RED);
					LED_voidOFF(&led3_GREEN);
				}
				else{
					LED_voidOFF(&led2_YELLOW);
				}
				SSD_voidEnable(& SSD_1 ,i);
				SSD_voidEnable(& SSD_2 ,k);
				_delay_ms(250);
				SSD_voidDisable(& SSD_1);
				SSD_voidDisable(& SSD_2);
				_delay_ms(50);
				counter++;
				if(counter==70){
					counter=0;
				}
			}
		}


	}
}
