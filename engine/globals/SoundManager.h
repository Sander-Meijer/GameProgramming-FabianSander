/*
 * SoundManager.h
 *
 *  Created on: 2 apr. 2013
 *      Author: Fabian
 */

#ifndef SOUNDMANAGER_H_
#define SOUNDMANAGER_H_

#include "../../Commonheader.h"
#include <SFML/Audio.hpp>

class SoundManager {
private:
	static SoundManager* instance;
	SoundManager();
	sf::Music sound;
public:
	static SoundManager* getInstance();
	virtual ~SoundManager();
	void playSound(string);
};

#endif /* SOUNDMANAGER_H_ */
