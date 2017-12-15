#include "TraficLightTeacher.h"

#include "cLamp.h"
#include "cTrafficLightPedestrian.h"
#include "cTrafficLightCars.h"

#include "cCrossroad.h"
#include "cShedule.h"

cLamp HeartbeatLed					(13, HIGH, LOW,  300);


cLamp pedMainLampGreenPin2			(2,  LOW,  HIGH, 500);
cLamp pedMainLampRedPin3			(3,  LOW,  HIGH, 500);

cLamp carMainLampGreenPin4 			(4,  LOW,  HIGH, 500);
cLamp carMainLampYellowPin5			(5,  LOW,  HIGH, 500);
cLamp carMainLampRedPin6			(6,  LOW,  HIGH, 500);

cLamp pedSecondaryLampGreenPin7		(7,  LOW,  HIGH, 500);
cLamp pedSecondaryLampRedPin8		(8,  LOW,  HIGH, 500);

cLamp carSecondaryLampGreenPin9		(9,  LOW,  HIGH, 500);
cLamp carSecondaryLampYellowPin10	(10, LOW,  HIGH, 500);
cLamp carSecondaryLampRedPin11		(11, LOW,  HIGH, 500);



cTrafficLightCars		trafficLightCarsMain (&carMainLampGreenPin4, &carMainLampYellowPin5, &carMainLampRedPin6);
cTrafficLightCars		trafficLightCarsSecond (&carSecondaryLampGreenPin9, &carSecondaryLampYellowPin10, &carSecondaryLampRedPin11);

cTrafficLightPedestrian pedestrianMain (&pedMainLampGreenPin2, &pedMainLampRedPin3);
cTrafficLightPedestrian pedestrianSecondary (&pedSecondaryLampGreenPin7, &pedSecondaryLampRedPin8);





cTrafficLight *trafficLightsList[] = {
		&trafficLightCarsMain,
		&trafficLightCarsSecond,

		&pedestrianMain,
		&pedestrianSecondary

};

uint8_t trafficLightAmount = sizeof(trafficLightsList)/sizeof(trafficLightsList[0]);



static uint8_t trafficLightScheduler[][5] = {
/*		Main Cars			Second Cars			Main Ped			Second Ped			Duration (sec)	*/
/*0*/	{modeService,		modeService,		modeService,		modeService,			10},
/*1*/	{modeGreen,			modeRed,			modeRed,			modeGreen,				5},
/*2*/	{modeGreenBlink, 	modeRed,			modeRed,			modeGreenBlink,			3},
/*3*/	{modeYellow,		modeRed,			modeRed,			modeRed,				2},
/*4*/	{modeRed, 			modeRedYellow,		modeGreen,			modeRed,				2},
/*5*/	{modeRed,			modeGreen,			modeGreen, 			modeRed,				5},
/*6*/	{modeRed,			modeGreenBlink,		modeGreenBlink,		modeRed,				3},
/*7*/	{modeRed,			modeRedYellow,		modeRed,			modeRed,				5},
/*8*/	{modeRedYellow,		modeRed,			modeRed,			modeRed,				5}

};

uint8_t sheduleStepAmount = sizeof(trafficLightScheduler)/sizeof(trafficLightScheduler[0]);

cShedule shedule(*trafficLightScheduler, 1, sheduleStepAmount, trafficLightAmount);

cCrossroad  crossroad(trafficLightsList, trafficLightAmount, &shedule);

void setup() {
	HeartbeatLed.SetMode(lampBlink);

}

// The loop function is called in an endless loop
void loop() {
	crossroad.Run();
	HeartbeatLed.Run();
}
