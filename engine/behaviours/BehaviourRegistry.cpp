/*
 * BehaviourRegistry.cpp
 *
 *  Created on: 28 mrt. 2013
 *      Author: Fabian
 */

#include "BehaviourRegistry.h"

BehaviourRegistry::BehaviourRegistry() {
	// TODO Auto-generated constructor stub

}

BehaviourRegistry::~BehaviourRegistry() {
	// TODO Auto-generated destructor stub
}

Behaviour* BehaviourRegistry::getBehaviour(GameObject* gameObject, string s) {
	if (s == "carBehaviour") {
		return new CarBehaviour(gameObject);
	} else if (s == "finishLineBehaviour") {
		return new FinishLineBehaviour(gameObject);
	} else if (s == "playerBehaviour") {
		return new PlayerBehaviour(gameObject);
	}
	return NULL;
}


