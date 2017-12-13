/*
 * cCrossroad.cpp
 *
 *  Created on: 4 дек. 2017 г.
 *      Author: Oleksii Husak
 */

#include "cCrossroad.h"
#include "stdint.h"

cCrossroad::cCrossroad(cTrafficLight **ptrTrafficLightsList, uint8_t trafficLightAmount,  cShedule *shedule )
{
	this->trafficLightsList = ptrTrafficLightsList;
	this->trafficLightAmount = trafficLightAmount;
}

void cCrossroad::Run(void)
{
	for (uint8_t i = 0; i < trafficLightAmount; ++i) {
		trafficLightsList[i] -> Run();
	}

	//TODO setmode hahaha


}
