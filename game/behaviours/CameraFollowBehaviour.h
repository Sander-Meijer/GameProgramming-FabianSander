/*
 * CameraFollowBehaviour.h
 *
 *  Created on: 26 feb. 2013
 *      Author: Fabian
 */

#ifndef CAMERAFOLLOWBEHAVIOUR_H_
#define CAMERAFOLLOWBEHAVIOUR_H_

#include "../../engine/behaviours/Behaviour.hpp"
#include "../../engine/camera/Camera.hpp"
#include "../../engine/object/GameObject.hpp"

class CameraFollowBehaviour : public Behaviour {

private:
	GameObject* followable;
	GameObject* gameObject;
	glm::vec3 translate;
	glm::vec3 rotate;
public:
	CameraFollowBehaviour(GameObject *, GameObject *);
	virtual ~CameraFollowBehaviour();
	virtual void update( float step );

	void setTrans(glm::vec3);
	void setRot(glm::vec3);
};

#endif /* CAMERAFOLLOWBEHAVIOUR_H_ */
