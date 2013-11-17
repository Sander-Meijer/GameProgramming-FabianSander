#include <iostream>
#include "Collider.hpp"
#include "../object/GameObject.hpp"

Collider::Collider(GameObject * aParent, float aRadius) :
		parent(aParent), radius(aRadius) {
	deb = false;
}

Collider::~Collider() {
	//dtor
	parent->setCollider(NULL);
}

bool Collider::collides(Collider * otherCollider) {
	glm::vec3 location = parent->getAbsoluteLocation();
	glm::vec3 otherLocation = otherCollider->parent->getAbsoluteLocation();
	float distance = glm::distance(location, otherLocation);
	if (distance < radius + otherCollider->radius) {
		return true;
	};
	return false;
}

string Collider::getName() {
	return " Collider";
}

GameObject* Collider::getParent() {
	return parent;
}
