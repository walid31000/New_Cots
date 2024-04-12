/*
 * CLCD_app1.c
 *description:application that send string to LCD
 *  Created on: 19 Mar 2024
 *      Author: walid
 */

#include "STD_TYPES.h"
#include "Err_Type.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "DIO_interface.h"
#include "CLCD_interface.h"


void main(void)
{
	//uint8 Local_u8MyPattern[8]={0,0b00010001,0b00010001,0b00011111,0b00011111,0,0b00000100,0};
	/*SET LCD pins at output*/
		DIO_u8SetPortDirection(DIO_PORTA,0xff);
		DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN0,DIO_PIN_OUTPUT);
		DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
		DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
		CLCD_voidInit();

//CLCD_u8WriteSpecialCharacter(1, Local_u8MyPattern,5u,0u);
//CLCD_voidGoToXY(0u,1u);
//CLCD_voidSendNumber(987123);
 //CLCD_u8SendString("walid");
		CLCD_voidSendData('A');
while(1)
{

}

}
