/*
 * Updater.cpp
 *
 *  Created on: 14 mrt. 2013
 *      Author: Sander
 */

#include "../behaviours/Behaviour.hpp"

#include "Updater.h"
#include "Time.hpp"
#include "iostream"
#include "../../game/GameObjects/Car.h"
Updater* Updater::instance = new Updater();

Updater::~Updater() {
	// TODO Auto-generated destructor stub
}

Updater* Updater::getInstance(){
	return instance;
}

void Updater::visit(GameObject* object) {
	Behaviour* b = object->getBehaviour();
	if (b) {
		b->update(Time::getInstance()->step());
	}
	std::vector<GameObject *>* children = object->getChildren();

	for (std::vector<GameObject *>::iterator i = children->begin(); i != children->end(); ++i) {
		((GameObject *) *i)->accept(this);
	}
}

void Updater::visit(Mesh* mesh) {
//	std::cerr << "Mesh is not supported by updater";
//	throw "Mesh is not supported by updater";
}

void Updater::visit(Camera* camera) {

	Behaviour* b = camera->getBehaviour();
	if (b) {
		b->update(Time::getInstance()->step());
	}
}

void Updater::visit(Light* light) {
//	std::cerr << "Light is not supported by updater";
//	throw "Light is not supported by updater";
}

