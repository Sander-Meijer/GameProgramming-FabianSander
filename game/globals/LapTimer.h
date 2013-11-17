/*
 * LapTimer.h
 *
 *  Created on: 2 apr. 2013
 *      Author: Fabian
 */

#ifndef LAPTIMER_H_
#define LAPTIMER_H_

#include "../../Commonheader.h"
#include "../../engine/globals/Time.hpp"
#include "../../engine/interfaces/Observer.h"
#include "../../engine/Hud/HudString.h"

class LapTimer : public Observer{
private:
	static LapTimer* instance;
	float lapStartTime;
	float currentLapTime;
	HudString* timeString;
	LapTimer();
public:
	static LapTimer* getInstance();
	float getLapTime();
	void newLap();
	void update(Observable*);
	string getTimeString();
	virtual ~LapTimer();
};

#endif /* LAPTIMER_H_ */
