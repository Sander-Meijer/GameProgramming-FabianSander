/*
 * Skybox.h
 *
 *  Created on: 26 feb. 2013
 *      Author: Fabian
 */

#ifndef SKYBOX_H_
#define SKYBOX_H_

#include "../../engine/object/GameObject.hpp"

class Skybox : public GameObject {
public:
	Skybox(int);
	virtual ~Skybox();
//	GameObject* createSide(std::string, float, float, float);
	void setSkyboxBehaviour(GameObject*);
};

#endif /* SKYBOX_H_ */
