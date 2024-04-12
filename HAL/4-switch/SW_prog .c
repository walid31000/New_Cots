#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include "DIO_interface.h"
#include "SW_interface.h"








uint8 SW_u8GetState(const SW_config_t* copySWObject,uint8* copy_SWState  )
{
	uint8 Local_u8ErroreState=OK;
	uint8 Local_u8State;
	if(copySWObject!=NULL)
	{
		if(copy_SWState!=NULL)
		{
			if(copySWObject->pulling==PULL_UP)
			{
				DIO_u8GetPinValue(copySWObject->PORT,copySWObject->PIN,& Local_u8State);
				if((Local_u8State)==DIO_PIN_LOW)
				{
					*copy_SWState= pressed;
				}
				else
				{
					*copy_SWState= realeased;
				}
			}

			if(copySWObject->pulling==PULL_DOWN)
			{

				DIO_u8GetPinValue(copySWObject->PORT,copySWObject->PIN,& Local_u8State);
				if(Local_u8State==DIO_PIN_HIGH)
				{
					*copy_SWState= pressed;
				}
				else
				{
					*copy_SWState=realeased;
				}
			}

		}
		else
		{
			return NULL_PTR;
		}

	}

	else
	{
		Local_u8ErroreState=NULL_PTR;
	}


	return Local_u8ErroreState;




}
