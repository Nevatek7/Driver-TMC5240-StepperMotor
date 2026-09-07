/*
 * HI_SPI_1.h
 *
 *  Created on: Aug 20, 2026
 *      Author: Nevatek
 */

#ifndef HI_SPI_1_H_
#define HI_SPI_1_H_

#include <stdint.h>
#include "Drv_TMC5240.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define RESET_VALUE             (0x00)

/* Macro for miscellaneous */
#define DELAY_ONE_SEC   (1)

/* Max wait count for time-out operation */
#define MAX_COUNT (0xFFFFFF)

/* Min wait count for time-out operation */
#define MIN_COUNT (0)

/* MACRO for checking if two buffers are equal */
#define BUFF_EQUAL (0)

void tmc5240_initSPI();
// => TMC-API wrapper
 void tmc5240_readWriteSPI(uint16_t icID, uint8_t *data, size_t dataLength);
 bool tmc5240_readWriteUART(uint16_t icID, uint8_t *data, size_t writeLength, size_t readLength);
 TMC5240BusType tmc5240_getBusType(uint16_t icID);
 uint8_t tmc5240_getNodeAddress(uint16_t icID);
// => TMC-API wrapper

#endif /* HI_SPI_1_H_ */
