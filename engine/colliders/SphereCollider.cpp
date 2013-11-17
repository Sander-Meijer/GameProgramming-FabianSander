#include <cassert>
#include <iostream>
#include "SphereCollider.hpp"
#include "../object/GameObject.hpp"
#include "AABBCollider.h"

SphereCollider::SphereCollider(GameObject * aParent, float aRadius) :
		Collider(aParent), radius(aRadius) {
	//ctor
}

SphereCollider::~SphereCollider() {
	//dtor
}

bool SphereCollider::collides(Collider * otherCollider) {
	AABBCollider* aabb = dynamic_cast<AABBCollider*>(otherCollider);
	if (aabb != NULL) {
		return collides(aabb);
	}
	SphereCollider* sc = dynamic_cast<SphereCollider*>(otherCollider);
	if (sc != NULL) {
		return collides(sc);
	} else {
		return false;
	}
	return otherCollider->collides(this);
}

bool SphereCollider::collides(SphereCollider * otherCollider) {
	glm::vec3 location = parent->getAbsoluteLocation();
	glm::vec3 otherLocation = otherCollider->parent->getAbsoluteLocation();
	float distance = glm::distance(location, otherLocation);
	if (distance < radius + otherCollider->radius) {
		return true;
	};
	return false;
}

// This is actually AABB AABB collision, because lack of time, but it works well enough for now... and should unless spheres get reallllyy big
bool SphereCollider::collides(AABBCollider * aabbCollider) {
	glm::vec3 sphLoc = parent->getAbsoluteLocation();
	glm::vec3 AABBLoc = aabbCollider->getParent()->getAbsoluteLocation();
	if ((sphLoc.x - radius < AABBLoc.x + aabbCollider->getMaxValues().x) && (sphLoc.x + radius > AABBLoc.x - aabbCollider->getMaxValues().x) &&
	(sphLoc.y - radius < AABBLoc.y + aabbCollider->getMaxValues().y) && (sphLoc.y + radius > AABBLoc.y - aabbCollider->getMaxValues().y) &&
	(sphLoc.z - radius < AABBLoc.z + aabbCollider->getMaxValues().z) && (sphLoc.z + radius > AABBLoc.z - aabbCollider->getMaxValues().z)) {
		debug(aabbCollider->getParent()->getName());
		return true;
	}
	return false;
}

string SphereCollider::getName() {
	return "SphereColli";
}
