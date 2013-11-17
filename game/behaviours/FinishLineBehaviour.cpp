/*
 * FinishLineBehaviour.cpp
 *
 *  Created on: 2 apr. 2013
 *      Author: Fabian
 */

#include "FinishLineBehaviour.h"
#include "../GameObjects/Car.h"
#include "../globals/LapTimer.h"

FinishLineBehaviour::FinishLineBehaviour(GameObject * finishLine) : Behaviour(finishLine) {
	this->finishLine = finishLine;

}

FinishLineBehaviour::~FinishLineBehaviour() {
	// TODO Auto-generated destructor stub
}

void FinishLineBehaviour::onCollision(GameObject* otherObject) {
	Car * c = dynamic_cast<Car*>(otherObject);
	if (c != NULL) {
		if (LapTimer::getInstance()->getLapTime() > 10.0f) {
			LapTimer::getInstance()->newLap();
			SoundManager::getInstance()->playSound("Finish.wav");
		}
	}
}
