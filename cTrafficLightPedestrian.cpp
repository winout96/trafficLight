/*
 * cTrafficLightPedestrians.cpp
 *
 *  Created on: 25 ����. 2017 �.
 *      Author: ���
 */

#include "cTrafficLightPedestrian.h"

cTrafficLightPedestrian::cTrafficLightPedestrian(cLamp *ptrLampGreen, cLamp *ptrLampRed) {
	this->lampGreen = ptrLampGreen;
	this->lampRed = ptrLampRed;
}

void cTrafficLightPedestrian::Run(void){
	lampGreen->Run();
	lampRed->Run();
}

void cTrafficLightPedestrian::SetMode(TrafficLightModes_t newMode){
	lampGreen->SetMode((LampModes_t)modesTable[newMode][0]);
	lampRed->SetMode((LampModes_t)modesTable[newMode][1]);
}

