#ifndef TIME_H
#define TIME_H

#include <SFML/System.hpp>
#include "string"
#include "../interfaces/Observable.h"

class Time : public Observable {
private:
	// data members
	static Time* instance;
	sf::Clock clock;
	float currentTime;
	float deltaTime;

private:
	// disable creation of time object
	Time();

public:
	// functons
	static Time* getInstance();
	void update();
	float now();
	float step();
	void newLap();
	std::string getTimeString();
};

#endif // TIME_H
