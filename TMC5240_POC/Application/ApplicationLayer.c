/*
 * ApplicationLayer.c
 *
 *  Created on: Aug 20, 2026
 *      Author: Nevatek
 */


#include "ApplicationLayer.h"
//#include "App_TMC5240.h"
#include "App_StepperMotor.h"


void ApplicationLayer_Init(void);
void ApplicationLayer_Exe(void);

/******************************.FUNCTION_HEADER.******************************
.Purpose : This function serve as one time call function of application layer
.Returns :
.Note : use this function for all major initilization
******************************************************************************/
void ApplicationLayer_Init(void)
{
//	App_TMC5240_init();
	App_StepperMotor_init();

}
/******************************.FUNCTION_HEADER.******************************
.Purpose : This function serve as one time call function of application layer
.Returns :
.Note : use this function for all major initilization
******************************************************************************/
void ApplicationLayer_Exe(void)
{
//	App_TMC5240_Exe();
	App_StepperMotor_Exe();

}

/******************************.FUNCTION_HEADER.******************************
.Purpose : This function serve as one time call function of application layer
.Returns :
.Note : use this function for all major initilization
******************************************************************************/
void ApplicationLayer(void)
{
	ApplicationLayer_Init();

	while(1)
	{
		ApplicationLayer_Exe();
	}
}
