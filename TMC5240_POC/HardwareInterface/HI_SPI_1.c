/*
 * HI_SPI_1.c
 *
 *  Created on: Aug 20, 2026
 *      Author: Nevatek
 */


#include "HI_SPI_1.h"

/* generic headers */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hal_data.h"

/* Event flags for master and slave */
static volatile spi_event_t g_master_event_flag;    // Master Transfer Event completion flag


void tmc5240_initSPI()
{
	fsp_err_t err = FSP_SUCCESS;     // Error status

	/* Open/Initialize SPI Master module */
	err = R_SPI_B_Open (&g_spi0_ctrl, &g_spi0_cfg);
	/* handle error */
	if (FSP_SUCCESS != err)
	{
		/* Close SPI master */
		R_SPI_B_Close(&g_spi0_ctrl);
	}
}

void tmc5240_readWriteSPI(uint16_t icID, uint8_t *data, size_t dataLength)
{
    uint8_t rxData[5] = {0};
    uint8_t txData[5] = {0};
    memcpy(txData, data, dataLength);

    fsp_err_t err;

    (void)icID;

    g_master_event_flag = SPI_EVENT_TRANSFER_ABORTED;

    err = R_SPI_B_WriteRead(&g_spi0_ctrl,
    						txData,       /* TX */
                            rxData,     /* RX */
                            dataLength,
                            SPI_BIT_WIDTH_8_BITS);

    if (err != FSP_SUCCESS)
    {
        return;
    }

    while (g_master_event_flag != SPI_EVENT_TRANSFER_COMPLETE)
    {
    }

    /* Copy received data back to caller's buffer */
    memcpy(data, rxData, dataLength);

    g_master_event_flag = SPI_EVENT_TRANSFER_ABORTED;
}
bool tmc5240_readWriteUART(uint16_t icID, uint8_t *data, size_t writeLength, size_t readLength)
{
    (void)icID;
    (void)data;
    (void)writeLength;
    (void)readLength;

	return false;
}

TMC5240BusType tmc5240_getBusType(uint16_t icID)
{
	if(0 == icID)
		return IC_BUS_SPI;
	else
		return IC_BUS_SPI;
}

uint8_t tmc5240_getNodeAddress(uint16_t icID)
{
    (void)icID;

	return 0;
}

void spi_callback(spi_callback_args_t *p_args)
{
	g_master_event_flag = p_args->event;
}
