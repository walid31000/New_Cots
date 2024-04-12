/*
 * main.c
 *
 *  Created on: 3 Apr 2024
 *      Author: walid
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "LED_interface.h"
#include "LED_prv.h"

void main()
{
	Led_config_t LED1={DIO_PORTA,DIO_PIN0,ACT_LOW};
	Led_config_t LED2={DIO_PORTA,DIO_PIN1,ACT_HIGH};
	Led_config_t LED3={DIO_PORTA,DIO_PIN2,ACT_HIGH};
	/*ACTIVATE  internal pull up for pin 0*/
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_PIN_OUTPUT);
	//DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);

	while(1)
	{
		uint8 counter=1;
		LED_u8SetON(&LED1);
        //_delay_ms(1000);
        //LED_u8SetOFF(&LED1);
          // _delay_ms(1000);
    /*  while(1)
      {
		if(counter%1==0)
		{
			LED_u8ToggleLed(&LED1 );
		}
		if(counter%2==0)
		{
			LED_u8ToggleLed(&LED2 );
		}
		if(counter%3==0)
		{
			LED_u8ToggleLed(&LED3 );
		}

		counter++;
		_delay_ms(1000);
      }*/

	}
}
