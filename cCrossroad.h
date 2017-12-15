/*
 * cCrossroad.h
 *
 *  Created on: 4 дек. 2017 г.
 *      Author: Oleksii Husak
 */

#ifndef CCROSSROAD_H_
#define CCROSSROAD_H_

#include "stdint.h"
#include "cTrafficLight.h"

#include "cShedule.h"
#include "Arduino.h"


class cCrossroad {
public:
	cCrossroad(cTrafficLight **ptrTrafficLightsList, uint8_t trafficLightAmount, cShedule *shedule);

	void Run();
private:
	cTrafficLight **trafficLightsList;

	uint8_t trafficLightAmount;

	cShedule *shedule;

	uint8_t currentStep;

	uint32_t startTime;

	uint32_t currentTime;

	uint32_t stepTime;
};

#endif /* CCROSSROAD_H_ */
