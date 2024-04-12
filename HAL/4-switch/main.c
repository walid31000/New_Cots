/*
 * main.c
 *
 *  Created on: 4 Apr 2024
 *      Author: walid
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "SW_interface.h"

void main(void)
{
	uint8 Local_u8PinRead;
	 SW_config_t SW={DIO_PORTD,DIO_PIN2,PULL_UP};

  /*activate internal pull up on D2*/
	DIO_u8SetPinDirection(DIO_PORTD,DIO_PIN2,DIO_PIN_INPUT);
	 DIO_u8SetPinValue(DIO_PORTD,DIO_PIN2,DIO_PIN_HIGH);
	/*set pin A0 as output*/
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_PIN_OUTPUT);

   while(1)
   {
	   SW_u8GetState(&SW,&Local_u8PinRead );


	   if(Local_u8PinRead==DIO_PIN_LOW)
	   {
		   DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
		   _delay_ms(250);
		   DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
		   _delay_ms(250);
	   }


   }

}
