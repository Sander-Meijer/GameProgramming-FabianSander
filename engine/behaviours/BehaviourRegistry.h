/*
 * BehaviourRegistry.h
 *
 *  Created on: 28 mrt. 2013
 *      Author: Fabian
 */

#ifndef BEHAVIOURREGISTRY_H_
#define BEHAVIOURREGISTRY_H_

#include "Behaviour.hpp"
#include "../../Commonheader.h"
#include "../../game/behaviours/CarBehaviour.h"
#include "../../game/behaviours/FinishLineBehaviour.h"
#include "../../game/behaviours/PlayerBehaviour.h"


class BehaviourRegistry {
public:
	BehaviourRegistry();
	virtual ~BehaviourRegistry();
	static Behaviour* getBehaviour(GameObject*, string s);
};

#endif /* BEHAVIOURREGISTRY_H_ */
