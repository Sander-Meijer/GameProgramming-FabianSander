/*
 * AABBCollider.cpp
 *
 *  Created on: 3 apr. 2013
 *      Author: Fabian
 */

#include "AABBCollider.h"

// since the origin of the box is at the center of the mesh, we can invert the maxValues to get the minValues.

AABBCollider::AABBCollider(GameObject * aParent, float aRadius) : Collider(aParent) {
	if (parent->getMesh() != NULL) {
		maxValues = parent->getMesh()->getHightestValues(parent);
	} else {
//		maxValues = glm::vec3(20);
	}

}

AABBCollider::~AABBCollider() {
	// TODO Auto-generated destructor stub
}



glm::vec3 AABBCollider::getCurrentMax() {
	return parent->getAbsoluteLocation() + maxValues;
}

glm::vec3 AABBCollider::getCurrentMin() {
	return parent->getAbsoluteLocation() - maxValues;
}

bool AABBCollider::collides(Collider* otherCollider) {
	return false;
}

bool AABBCollider::collides(AABBCollider* other) {
	if (axisCollide(getCurrentMin().x, getCurrentMax().x, other->getCurrentMin().x, other->getCurrentMax().x) && axisCollide(getCurrentMin().y, getCurrentMax().y, other->getCurrentMin().y, other->getCurrentMax().y) && axisCollide(getCurrentMin().z, getCurrentMax().z, other->getCurrentMin().z, other->getCurrentMax().z)) {
		return true;
	}
	return false;
}

bool AABBCollider::axisCollide(float boxAStart, float boxAEnd, float boxBStart, float boxBEnd) {
	if (boxAEnd < boxBStart) {
		return false;
	}

	if (boxAStart > boxBEnd) {
		return false;
	}

	return true;
}

string AABBCollider::getName() {
	return "AABBCOLLI";
}

glm::vec3 AABBCollider::getMaxValues() {
	return maxValues;
}
