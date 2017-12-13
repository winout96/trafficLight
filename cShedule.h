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
	cShedule(uint8_t *ptrSheduleTable, uint8_t sheduleStepAmount);
	uint8_t getStep(uint8_t stepNumber, uint8_t trafficLightNumber);
	uint8_t getTime(uint8_t stepNumber);
private:

	uint8_t *sheduleTable;
};

#endif /* CSHEDULE_H_ */









