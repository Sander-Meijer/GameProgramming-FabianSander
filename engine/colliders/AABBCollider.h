/*
 * AABBCollider.h
 *
 *  Created on: 3 apr. 2013
 *      Author: Fabian
 */

#ifndef AABBCOLLIDER_H_
#define AABBCOLLIDER_H_

#include "../../Commonheader.h"
#include "../object/Mesh.hpp"
#include "Collider.hpp"
#include "../object/GameObject.hpp"

class AABBCollider : public Collider {
private:
	glm::vec3 maxValues;
public:

	AABBCollider(GameObject * aParent, float aRadius = 1.0f);
	virtual ~AABBCollider();
	glm::vec3 getCurrentMax();
	glm::vec3 getCurrentMin();
	bool AABBtoAABBCollision(AABBCollider*);
	bool axisCollide(float, float, float, float);
	string getName();

	bool collides( Collider * otherCollider );
	bool collides( AABBCollider * otherCollider );
	glm::vec3 getMaxValues();
};

#endif /* AABBCOLLIDER_H_ */
