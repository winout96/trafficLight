/*
 * cCrossroad.cpp
 *
 *  Created on: 4 дек. 2017 г.
 *      Author: Oleksii Husak
 */

#include "cCrossroad.h"
#include "stdint.h"

cCrossroad::cCrossroad(cTrafficLight **ptrTrafficLightsList, uint8_t trafficLightAmount,  cShedule *ptrShedule )
{
	this->trafficLightsList = ptrTrafficLightsList;
	this->trafficLightAmount = trafficLightAmount;
	this->shedule = ptrShedule;
}

void cCrossroad::Run(void)
{
	for (uint8_t i = 0; i < trafficLightAmount; ++i) {
		trafficLightsList[i] -> Run();
	}

	//TODO setmode hahaha




//	delay(5000);
//	shedule->getState(8, 5);
//
//	Serial.print(trafficLightAmount);
//	Serial.write("\n\n\n\n\n");
//
//	Serial.print(sheduleStepAmount);
//	Serial.write("\n\n\n\n\n");





}
