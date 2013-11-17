/*
 * CameraFollowBehaviour.cpp
 *
 *  Created on: 26 feb. 2013
 *      Author: Fabian
 */

#include "CameraFollowBehaviour.h"
#include "iostream"

CameraFollowBehaviour::CameraFollowBehaviour(GameObject * followable, GameObject * gameObject) : Behaviour(gameObject) {
	this->followable = followable;
	this->gameObject = gameObject;
}

CameraFollowBehaviour::~CameraFollowBehaviour() {
	// TODO Auto-generated destructor stub
}

void CameraFollowBehaviour::update(float step) {
	parent->setTransform(followable->getTransForm());
	parent->translate(translate);
	parent->rotate(rotate.x, glm::vec3(1,0,0));
	parent->rotate(rotate.y, glm::vec3(0,1,0));
	parent->rotate(rotate.z, glm::vec3(0,0,1));

}

void CameraFollowBehaviour::setTrans(glm::vec3 t) {
	translate = t;
}
void CameraFollowBehaviour::setRot(glm::vec3 r ) {
	rotate = r;
}
