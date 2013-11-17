/*
 * LapTimer.cpp
 *
 *  Created on: 2 apr. 2013
 *      Author: Fabian
 */

#include "LapTimer.h"
#include <sstream>

LapTimer* LapTimer::instance;

LapTimer::LapTimer() {
	Time::getInstance()->addObserver(this);
	lapStartTime = Time::getInstance()->now();
	currentLapTime = 0;
	timeString = new HudString("LapTime: " + fI(currentLapTime), 10, 90);
}

LapTimer::~LapTimer() {
	// TODO Auto-generated destructor stub
}

LapTimer* LapTimer::getInstance() {
	if (instance == NULL) {
		instance = new LapTimer();
	}
	return instance;
}

float LapTimer::getLapTime() {
	return Time::getInstance()->now() - lapStartTime;
}

void LapTimer::newLap() {
	lapStartTime = Time::getInstance()->now();
}

void LapTimer::update(Observable* calling) {
	currentLapTime = Time::getInstance()->now() - lapStartTime;
	timeString->setString("LapTime: " + fI(currentLapTime));
}


