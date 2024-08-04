/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    LM35_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Walid Megherbi
 *  Layer  : HAL
 *  SWC    : LM35
 *
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
//#include "ADC_cfg.h"

#include "ADC_interface.h"
#include "ADC_prv.h"
#include "ADC_cfg.h"
#include "LM35_interface.h"
#include "LM35_cfg.h"
#include "Map.h"


    	// Define ADC resolution constants
    	#define ADC_RES_EIGHT_BITS 256UL
    	#define ADC_RES_TEN_BITS 1024UL
uint8 LM35_u8GetTemp(LM35_config_t *copy_LM35_Obj,uint8 *Temp_Reading)
{

    uint16 Local_u16Digital;
    uint16 Local_u16Analog;
    uint32 ADC_u8RES;
    uint8 Local_u8Errorstate=OK;
    if(copy_LM35_Obj!=NULL)
    {
        // Determine the ADC resolution value based on the config file
        #if ADC_u8RESOLUTION == EIGHT_BITS
            ADC_u8RES = ADC_RES_EIGHT_BITS;
        #elif ADC_u8RESOLUTION == TEN_BITS
            ADC_u8RES = ADC_RES_TEN_BITS;
        #else
            // Handle invalid resolution case
#error   " ERROR configuration"
        #endif

        Local_u16Digital = ADC_u16GetChannelReading(copy_LM35_Obj->LM_35_CH);

/*save the result in Temp_Reading variable using derefrencing */

        *Temp_Reading = (uint8)(((uint32)Local_u16Digital * 500UL) / ADC_u8RES);


    }
    else
    {
    	return NULL_PTR;
    }
    return Local_u8Errorstate;
}
