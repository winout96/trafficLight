/*
 * cShedule.cpp
 *
 *  Created on: 4 дек. 2017 г.
 *      Author: Oleksii Husak
 */

#include "cShedule.h"
#include "Arduino.h"

cShedule::cShedule(uint8_t *ptrSheduleTable, uint8_t startStep, uint8_t sheduleStepAmount, uint8_t trafficLightAmount) {
	this->sheduleTable = ptrSheduleTable;
	this->startStep = startStep;
	this->sheduleStepAmount = sheduleStepAmount;
	this->trafficLightAmount = trafficLightAmount;
}

uint8_t cShedule::getTableCell(uint8_t row, uint8_t column) {

	return *(this->sheduleTable + ((trafficLightAmount + 1) * row + column));

}

uint32_t cShedule::getTime(uint8_t stepNumber) {

	return getTableCell(stepNumber, trafficLightAmount) * 1000;

}

uint8_t cShedule::getNextStep(uint8_t stepNumber) {

	uint8_t nextStep = stepNumber+1;

	if (nextStep < sheduleStepAmount) {
		return nextStep;
	} else {
		return startStep;
	}
}

uint8_t cShedule::getState(uint8_t stepNumber, uint8_t trafficLightNumber) {

	return getTableCell(stepNumber, trafficLightNumber);

}
