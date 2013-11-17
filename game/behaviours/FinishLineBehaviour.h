/*
 * FinishLineBehaviour.h
 *
 *  Created on: 2 apr. 2013
 *      Author: Fabian
 */

#ifndef FINISHLINEBEHAVIOUR_H_
#define FINISHLINEBEHAVIOUR_H_

#include "../../engine/behaviours/Behaviour.hpp"
#include "../../Commonheader.h"
#include "../../engine/object/GameObject.hpp"
#include "../../engine/globals/SoundManager.h"

class FinishLineBehaviour : public Behaviour{
private:
	GameObject* finishLine;
public:
	FinishLineBehaviour(GameObject*);
	virtual ~FinishLineBehaviour();
	void onCollision(GameObject* );
};

#endif /* FINISHLINEBEHAVIOUR_H_ */
