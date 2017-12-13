/*
 * cShedule.cpp
 *
 *  Created on: 4 дек. 2017 г.
 *      Author: Oleksii Husak
 */

#include "cShedule.h"
#include "Arduino.h"

cShedule::cShedule(uint8_t *ptrSheduleTable,  uint8_t sheduleStepAmount) {
	this->sheduleTable = ptrSheduleTable;
}

uint8_t cShedule::getStep(uint8_t stepNumber, uint8_t trafficLightNumber) {
	Serial.begin(9600);
	uint8_t m = 5;

	for (uint8_t i = 0; i < 9; i++) {
		for (uint8_t j = 0; j < 5; j++) {
			Serial.print(*(this->sheduleTable + i * m + j), DEC);
			Serial.write(", ");
		}
		Serial.write("\n");
	}

	Serial.write("\n\n\n\n\n");

}
