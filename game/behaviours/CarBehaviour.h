/*
 * CarBehaviour.h
 *
 *  Created on: 13 feb. 2013
 *      Author: Fabian
 */

#ifndef CARBEHAVIOUR_H_
#define CARBEHAVIOUR_H_

#include "../../engine/behaviours/Behaviour.hpp"
#include "../GameObjects/Car.h"
#include "../../engine/object/GameObject.hpp"
#include "../../Commonheader.h"
class CarBehaviour : public Behaviour{
private:
	Car* car;

public:
	CarBehaviour(GameObject *);
	virtual ~CarBehaviour();
	virtual void update( float step );
};

#endif /* CARBEHAVIOUR_H_ */
