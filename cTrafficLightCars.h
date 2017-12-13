/*
 * cTrafficLightCars.h
 *
 *  Created on: Dec 1, 2017
 *      Author: SAK
 */

#ifndef CTRAFFICLIGHTCARS_H_
#define CTRAFFICLIGHTCARS_H_

#include "cTrafficLight.h"
#include "cLamp.h"

class cTrafficLightCars: public cTrafficLight {
public:
	cTrafficLightCars(cLamp *ptrLampGreen, cLamp *ptrLampYellow, cLamp *ptrLampRed);

	void Run(void);

	void SetMode(TrafficLightModes_t newMode);

private:
	cLamp *lampRed;
	cLamp *lampYellow;
	cLamp *lampGreen;

	const LampModes_t modesTable[6][3] = {
								//Green		Yellow		Red
		/* modeGreen */			{lampOn, 	lampOff,	lampOff	},
		/* modeGreenBlink */	{lampBlink,	lampOff,	lampOff	},
		/* modeRed */			{lampOff,	lampOff,    lampOn	},
		/* modeYellow */		{lampOff,	lampOn,		lampOff	},
		/* modeRedYellow */		{lampOff,	lampOn,		lampOn	},
		/* modeService */		{lampOff,	lampBlink,	lampOff }
	};

};

#endif /* CTRAFFICLIGHTCARS_H_ */
