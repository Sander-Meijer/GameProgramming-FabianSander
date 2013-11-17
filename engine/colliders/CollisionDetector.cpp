/*
 * CollisionDetector.cpp
 *
 *  Created on: 18 mrt. 2013
 *      Author: Sander
 */

#include "CollisionDetector.h"



CollisionDetector* CollisionDetector::instance;
CollisionDetector::CollisionDetector() {
	// TODO Auto-generated constructor stub

}

CollisionDetector::~CollisionDetector() {
	// TODO Auto-generated destructor stub
}

CollisionDetector* CollisionDetector::getInstance() {
	if(instance == NULL){
		instance = new CollisionDetector();
	}
	return instance;
}

void CollisionDetector::checkCollisions(GameObject* root) {
	vector<GameObject *>* children = root->getAllChildren();
	for (vector<GameObject *>::iterator collider = children->begin(); collider != children->end(); ++collider) {
		GameObject* firstGameObject = ((GameObject *) *collider);
		if (firstGameObject->hasCollider()) {
			for (std::vector<GameObject *>::iterator collidee = collider + 1; collidee != children->end(); ++collidee) {
				GameObject* secondGameObject = ((GameObject *) *collidee);
				if (secondGameObject->hasCollider()) {
//					secondGameObject->accept(this);
					if (firstGameObject->collides(secondGameObject)) {
						firstGameObject->onCollision(secondGameObject);
					}
				}
			}
		}
	}
}

void CollisionDetector::visit(GameObject* object) {
//	result = result || ((GameObject *) *collider)->collides((GameObject *) *collidee);
}

void CollisionDetector::visit(Mesh* mesh) {
//	std::cerr << "Mesh is not supported by CollisionDetector";
//	throw "Mesh is not supported by CollisionDetector";
}

void CollisionDetector::visit(Camera* camera) {
//	std::cerr << "Camera is not supported by CollisionDetector";
//	throw "Camera is not supported by CollisionDetector";
}

void CollisionDetector::visit(Light* light) {
//	std::cerr << "Light is not supported by CollisionDetector";
//	throw "Light is not supported by CollisionDetector";
}
