/*
 * PlayerBehaviour.cpp
 *
 *  Created on: 2 apr. 2013
 *      Author: Fabian
 */

#include "PlayerBehaviour.h"
#include <SFML/Window.hpp>
#include "../../engine/globals/SoundManager.h"

PlayerBehaviour::PlayerBehaviour(GameObject * p) :
		Behaviour(p) {
	collided = false;
	speed = 0;
	//if this fails, you fail
	player = dynamic_cast<Player*>(p);
}

PlayerBehaviour::~PlayerBehaviour() {
	// TODO Auto-generated destructor stub
}

void PlayerBehaviour::update(float step) {
	float rotationSpeed = 0.0f;
	bool keyPressed = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		keyPressed = true;
		if (speed < 10) {
			speed += 0.05f;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		keyPressed = true;
		if (speed > -10) {
			speed += -0.05f;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		rotationSpeed = -135.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		rotationSpeed = +135.0f;
	} if (!keyPressed) {
		speed = 0;
	}
	if (!collided) {
		parent->translate(glm::vec3(0.0f, 0.0f, speed * step));
		parent->rotate(rotationSpeed * step, glm::vec3(0.0f, 1.0f, 0.0f));
	} else {
		parent->translate(glm::vec3(0.0f, 0.0f, -speed * step * 10));
		speed = 0;
	}
	hardCodedCollisions();
	collided = false;
}

void PlayerBehaviour::onCollision(GameObject* gameObject) {
	if (gameObject->getSolid()) {
		collided = true;
	} if (gameObject->canBePickedUp()) {
		player->setKey(player->getKeys() +1);

		SoundManager::getInstance()->playSound("pick_up.wav" );
				delete gameObject;
//		gameObject->translate(glm::vec3(0, -100, 0));
	} if (gameObject->requiresKey()) {
		if (player->getKeys() > 0) {
			gameObject->setSolid(false);
			gameObject->translate(glm::vec3(0, -100, 0));
			SoundManager::getInstance()->playSound("open_door.wav" );
			player->setKey(player->getKeys() - 1);

		}
	}

}

//because no time and cheap
void PlayerBehaviour::hardCodedCollisions() {
	glm::vec3 loc = parent->getLocation();
	if (parent->getLocation().z < -9.5f) {
		parent->setTranslation(glm::vec3(loc.x, loc.y, -9.5f));
		speed = 0;
	} if (parent->getLocation().z > 9.5f) {
		parent->setTranslation(glm::vec3(loc.x, loc.y, 9.5f));
		speed = 0;
	} if (parent->getLocation().x < -9.5f) {
		parent->setTranslation(glm::vec3(-9.5f, loc.y, loc.z));
		speed = 0;
	} if (parent->getLocation().x > 69) {
		parent->setTranslation(glm::vec3(69, loc.y, loc.z));
		speed = 0;
	}
}
