/*
 * cShedule.h
 *
 *  Created on: 4 дек. 2017 г.
 *      Author: Oleksii Husak
 */

#ifndef CSHEDULE_H_
#define CSHEDULE_H_

#include "stdint.h"

class cShedule {
public:
	cShedule(uint8_t *ptrSheduleTable, uint8_t startStep,  uint8_t sheduleStepAmount,  uint8_t trafficLightAmount);

	uint8_t getTableCell(uint8_t row, uint8_t column);

	uint8_t getState(uint8_t stepNumber,uint8_t trafficLightNumber);

	uint32_t getTime(uint8_t stepNumber);

	uint8_t getNextStep(uint8_t stepNumber);

private:

	uint8_t *sheduleTable;

	uint8_t startStep;

	uint8_t sheduleStepAmount;

	uint8_t trafficLightAmount;
};

#endif /* CSHEDULE_H_ */









