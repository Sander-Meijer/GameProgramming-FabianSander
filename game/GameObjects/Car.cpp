/*
 * Car.cpp
 *
 *  Created on: 13 feb. 2013
 *      Author: Fabian
 */

#include "Car.h"
#include "../globals/LapTimer.h"

using namespace std;
Car::Car(int id, std::string aName, glm::vec3 aPosition) :
		GameObject(id, aName, aPosition) {
	speed = 0;
	LapTimer::getInstance();
	speedString = new HudString("Speed: " + cI(speed),10,120);
}

Car::~Car() {
	// TODO Auto-generated destructor stub
}

float* Car::getSpeedPointer() {
	return &speed;
}

vector<GameObject *>* Car::getChildren() {
	return children;
}

void Car::setSpeed(float s) {
	speed = s;
	speedString->setString("Speed: " + fI(speed));
}
