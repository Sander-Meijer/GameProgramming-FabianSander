/*
 * SkyboxBehaviour.cpp
 *
 *  Created on: 26 feb. 2013
 *      Author: Fabian
 */

#include "SkyboxBehaviour.h"
#include <SFML/Window.hpp>
#include "../object/GameObject.hpp"


SkyboxBehaviour::SkyboxBehaviour(GameObject * skybox, GameObject * gameObject) : Behaviour(skybox) {
	this->camera = gameObject;
}

SkyboxBehaviour::~SkyboxBehaviour() {
	// TODO Auto-generated destructor stub
}

void SkyboxBehaviour::update(float step) {
	parent->setTranslation(camera->getLocation());


}

