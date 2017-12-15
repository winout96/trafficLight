/*
 * cCrossroad.cpp
 *
 *  Created on: 4 дек. 2017 г.
 *      Author: Oleksii Husak
 */
#include "Arduino.h"
#include "cCrossroad.h"
#include "stdint.h"

cCrossroad::cCrossroad(cTrafficLight **ptrTrafficLightsList, uint8_t trafficLightAmount,  cShedule *ptrShedule )
{
	this->trafficLightsList = ptrTrafficLightsList;
	this->trafficLightAmount = trafficLightAmount;
	this->shedule = ptrShedule;

	this->currentStep = 0;

	this->startTime = millis();


	this->currentTime = millis();

	this->stepTime = shedule->getTime(currentStep);

	for (uint8_t i = 0; i < trafficLightAmount; ++i) {
		trafficLightsList[i]->SetMode((TrafficLightModes_t) shedule->getState(currentStep, i));
	}




}

void cCrossroad::Run(void)
{
	currentTime = millis();

	for (uint8_t i = 0; i < trafficLightAmount; ++i) {
		trafficLightsList[i] -> Run();
	}

	if (currentTime - startTime > stepTime) {
		currentStep = shedule->getNextStep(currentStep);
		stepTime = shedule->getTime(currentStep);

		for (uint8_t i = 0; i < trafficLightAmount; ++i) {
			trafficLightsList[i]->SetMode((TrafficLightModes_t) shedule->getState(currentStep, i));
		}

		startTime = millis();
	}
}
