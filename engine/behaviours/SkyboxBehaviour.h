/*
 * SkyboxBehaviour.h
 *
 *  Created on: 26 feb. 2013
 *      Author: Fabian
 */

#ifndef SKYBOXBEHAVIOUR_H_
#define SKYBOXBEHAVIOUR_H_

#include "../../engine/behaviours/Behaviour.hpp"

class SkyboxBehaviour : public Behaviour {

private:
	GameObject * camera;

public:
	SkyboxBehaviour(GameObject *,GameObject *);
	virtual ~SkyboxBehaviour();
	virtual void update( float step );

};

#endif /* SKYBOXBEHAVIOUR_H_ */
