/*
 * CarBehaviour.cpp
 *
 *  Created on: 13 feb. 2013
 *      Author: Fabian
 */

#include "CarBehaviour.h"
#include <SFML/Window.hpp>
#include <vector>

CarBehaviour::CarBehaviour(GameObject* c) : Behaviour(c) {
	car = (Car*) c;
}

CarBehaviour::~CarBehaviour() {
	// TODO Auto-generated destructor stub
}

void CarBehaviour::update(float step) {
	bool buttonPressed = false;
	float rotationSpeed = 0.0f;
	float* pSpeed = car->getSpeedPointer();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if (*pSpeed < 70) {
			*pSpeed = *pSpeed + 0.05f;
		}
		buttonPressed = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if (*pSpeed > -30) {
			*pSpeed = (*pSpeed - 0.05f);
		}
		buttonPressed = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (*pSpeed > 0) {
			rotationSpeed = -135.0f;
		} else if (*pSpeed < 0) {
			rotationSpeed = +135.0f;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (*pSpeed > 0) {
			rotationSpeed = +135.0f;
		} else if (*pSpeed < 0) {
			rotationSpeed = -135.0f;
		}
	}
	if (!buttonPressed) {
		if (*pSpeed > 0.0) {
			*pSpeed = *pSpeed - 0.02f;
		} else if (*pSpeed < 0.0) {
			*pSpeed = *pSpeed + 0.02f;
		}
		if ((*pSpeed < 0.02 && *pSpeed > 0.0) || (*pSpeed > -0.02 && *pSpeed < 0.0)) {
			*pSpeed = 0.0;
		}
	}
	parent->translate(glm::vec3(0.0f, 0.0f, *pSpeed * step));
	parent->rotate(rotationSpeed * step, glm::vec3(0.0f, 1.0f, 0.0f));
	vector<GameObject *>* children = car->getChildren();
	vector<GameObject *>::iterator i = children->begin();
	car->setSpeed(*pSpeed);
	i++;
	for (; i != children->end(); ++i) {
		((GameObject *) *i)->rotate((*pSpeed) / 10, glm::vec3(1.0f, 0.0f, 0.0f));
	}


}

