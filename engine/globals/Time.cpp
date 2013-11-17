#include "Time.hpp"
#include <sstream>

#include "../../Commonheader.h"
using namespace std;

sf::Clock Clock;
Time* Time::instance;

Time::Time() {
	currentTime = clock.getElapsedTime().asSeconds();
	deltaTime = 0.0f;
}

Time* Time::getInstance() {
	if (instance == NULL) {
		instance = new Time();
	}
	return instance;
}

void Time::update() {
	float newTime = clock.getElapsedTime().asSeconds();
	deltaTime = newTime - currentTime;
	currentTime = newTime;
	for (vector<Observer*>::iterator i = observers->begin(); i != observers->end(); ++i) {
		((Observer *)* i)->update(this);
	}
}

float Time::now() {
	return currentTime;
}

float Time::step() {
	return deltaTime;
}


