/*
 * cCrossroad.h
 *
 *  Created on: 4 ���. 2017 �.
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
};

#endif /* CCROSSROAD_H_ */
