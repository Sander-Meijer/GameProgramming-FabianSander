/*
 * SoundManager.cpp
 *
 *  Created on: 2 apr. 2013
 *      Author: Fabian
 */

#include "SoundManager.h"

SoundManager* SoundManager::instance;
SoundManager::SoundManager() {
	// TODO Auto-generated constructor stub

}

SoundManager::~SoundManager() {
	// TODO Auto-generated destructor stub
}

SoundManager* SoundManager::getInstance() {
	if (instance == NULL) {
		instance = new SoundManager();
	}
	return instance;
}

void SoundManager::playSound(string s) {
	sound.openFromFile("assets/sounds/" + s);
	sound.play();
}


