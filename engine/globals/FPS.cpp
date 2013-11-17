#include <iostream>
#include <sstream>
#include "FPS.hpp"
#include "Time.hpp"

FPS* FPS::instance;
FPS::FPS() {

	startTime = 0.0f;
	count = 0;
	fps = 0;
	fpsString = new HudString("FPS: " + fI(fps),10,30);
}

FPS* FPS::getInstance() {
	if (instance == NULL) {
		instance = new FPS();
	}
	return instance;
}

void FPS::update() {
	float time = Time::getInstance()->now();
	count++;
	if (time - startTime >= 1.0f) {
		fps = count;
		fpsString->setString("FPS: " + fI(fps));
		count = 0;
		startTime = time;
	}
}

unsigned int FPS::getFPS() {
	return fps;
}
