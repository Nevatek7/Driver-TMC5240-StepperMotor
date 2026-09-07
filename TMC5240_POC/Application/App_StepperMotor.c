/*
 * App_StepperMotor.c
 *
 *  Created on: Aug 28, 2026
 *      Author: Nevatek
 */


#include "App_StepperMotor.h"
#include "HI_SPI_1.h"
#include "hal_data.h"


#include "tmc5240.h"

int32_t g_n32TargetPos ;/*TODO Afil : move to structure*/
int32_t g_n32CurrentPos ;/*TODO Afil : move to structure*/
/*Afil also add functions to get status of motor like motor busy , motor idle etc to wtite state machines in app layer*/
 struct tmc5240_dev tmc5240_dev[TMC5240_MAX_DEVICES] = {0};

 struct tmc5240_init_param tmc5240_ip = {

	/*
	 * Simple motion profile
	 */

	/* Start velocity */
	.vstart = 1,

	/* Use the same acceleration for all phases */
	.a1 = 100,
	.a2 = 100,
	.amax = 65536,

	/* Velocity thresholds */
	.v1 = 100000,
	.v2 = 200000,

	/* Maximum velocity */
	.vmax = 500000,

	/* Use the same deceleration for all phases */
	.d1 = 100,
	.d2 = 100,
	.dmax = 65536,

	/* Stop velocity */
	.vstop = 10,

	/*
	 * TMC5240 clock
	 */
	.clock = 12500000,

	/*
	 * 1.8 degree stepper:
	 *
	 * 1.8 degrees = 1800 millidegrees
	 */
	.step_angle_millidegrees = 1800,

	/*
	 * 0 = 256 microsteps
	 */
	.microsteps_res = 8,

	/*
	 * Current configuration
	 */
	.current_run = 8,
	.current_hold = 8,

	.irundelay = 4,
	.iholddelay = 4,

	.global_scaler = 0xFB,

	/*
	 * Chopper configuration
	 */
	.toff = 3,
	.tbl = 2,

	.slope_control = 0,
	.current_range = 3,
};
uint8_t device0 = 0;

void App_StepperMotor_init()
{

	R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_02_PIN_00, BSP_IO_LEVEL_LOW);

	tmc5240_initSPI();

	volatile int ret;
	ret = tmc5240_init(&(tmc5240_dev[device0]), &tmc5240_ip);

		/* Normal shaft direction */
	ret = tmc5240_set_shaft_dir(&(tmc5240_dev[device0]), 0);

	ret = tmc5240_get_current_pos(&(tmc5240_dev[device0]) , &g_n32CurrentPos);
	ret = tmc5240_set_current_pos(&(tmc5240_dev[device0]), 0);
	g_n32TargetPos = 50 * 200;/*51200 = 360 degree in 256 micro stesp*/
	tmc5240_set_target_pos(&(tmc5240_dev[device0]) , g_n32TargetPos);
	(void)ret;
}

void App_StepperMotor_Exe()
{

//	g_n32TargetPos += 1000;
//	tmc5240_set_target_vel(&(tmc5240_dev[device0]), 5000);
//	/*
//	 * Rotate in positive direction.
//	 */
//	tmc5240_set_target_vel(&(tmc5240_dev[device0]), 5000);
//
//
	R_BSP_SoftwareDelay(5, BSP_DELAY_UNITS_SECONDS);
//
//	/*
//	 * Stop using configured deceleration.
//	 */
//	tmc5240_stop(&(tmc5240_dev[device0]));
//
//	R_BSP_SoftwareDelay(5, BSP_DELAY_UNITS_SECONDS);
//
//	tmc5240_set_target_vel(&(tmc5240_dev[device0]), -5000);
//
//	R_BSP_SoftwareDelay(5, BSP_DELAY_UNITS_SECONDS);
//
//	/*
//	 * Stop using configured deceleration.
//	 */
//	tmc5240_stop(tmc5240_dev);


}
