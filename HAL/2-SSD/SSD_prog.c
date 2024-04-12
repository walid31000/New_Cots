#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include"Err_Type.h"
#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_prv.h"


uint8 SSD_u8SetNumber(const SSD_Config_t* copy_SSD_Config,uint8 copy_u8Number)
{

	static 	uint8 SSD_ARR[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
	uint8 Local_u8ErrorState=OK;
	if(copy_SSD_Config!=NULL)
	{
	if(copy_SSD_Config->Type==ANODE)
	{
		DIO_u8SetPortValue(copy_SSD_Config->PORT,~SSD_ARR[copy_u8Number]);
	}
	else if(copy_SSD_Config->Type==CATHODE)
	{
		DIO_u8SetPortValue(copy_SSD_Config->PORT,SSD_ARR[copy_u8Number]);
	}
	}
	else
		return NULL_PTR;
	return Local_u8ErrorState;


}
/**********************************************************************/

/* This Function enable common pin*/
uint8 SSD_u8EnableSSD(const SSD_Config_t* copy_SSD_Config)
{
	uint8 Local_u8ErrorState=OK;
	/*Set port connected to Enable pin (commun) as output*/
	DIO_u8SetPortDirection(copy_SSD_Config->Enable_Port,0xff);

	/*Set port connected to SSD as output*/

	DIO_u8SetPortDirection(copy_SSD_Config->PORT,0xff);
	if(copy_SSD_Config!=NULL)
	{
		if(copy_SSD_Config->Type==ANODE)
		{
			DIO_u8SetPinValue(copy_SSD_Config->Enable_Port,copy_SSD_Config->Enable_PIN,DIO_PIN_HIGH);
		}
		else if(copy_SSD_Config->Type==CATHODE)
		{
			DIO_u8SetPinValue(copy_SSD_Config->Enable_Port,copy_SSD_Config->Enable_PIN,DIO_PIN_LOW);
		}

	}
	else
	{
		return NULL_PTR;
	}


	return Local_u8ErrorState;

}

/**********************************************************************/

uint8 SSD_u8DisableSSD(const SSD_Config_t* copy_SSD_Config)
{
	uint8 Local_u8ErrorState=OK;
	/*Set port connected to Enable pin (commun) as output*/
	DIO_u8SetPortDirection(copy_SSD_Config->Enable_Port,0xff);

	/*Set port connected to SSD as output*/

	DIO_u8SetPortDirection(copy_SSD_Config->PORT,0xff);
	if(copy_SSD_Config!=NULL)
	{
		if(copy_SSD_Config->Type==ANODE)
		{
			DIO_u8SetPinValue(copy_SSD_Config->Enable_Port,copy_SSD_Config->Enable_PIN,DIO_PIN_LOW);
		}
		else if(copy_SSD_Config->Type==CATHODE)
		{
			DIO_u8SetPinValue(copy_SSD_Config->Enable_Port,copy_SSD_Config->Enable_PIN,DIO_PIN_HIGH);
		}

	}
	else
	{
		return NULL_PTR;
	}


	return Local_u8ErrorState;






}
