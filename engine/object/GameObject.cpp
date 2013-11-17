#include <cassert>
#include <iostream>

#include "GameObject.hpp"
#include "../colliders/Collider.hpp"
#include "../behaviours/Behaviour.hpp"
#include "../interfaces/VistitorInterface.hpp"
#include "Mesh.hpp"
#include "Texture.hpp"

GameObject::GameObject(int id, std::string aName, glm::vec3 aPosition) :
		name(aName), transform(glm::translate(aPosition)), collider(NULL), behaviour(NULL), mesh(NULL), colorMap(NULL) {
	uniqueID = id;
	parent = NULL;
	solid = false;
	pickUpable = false;
	reqKey = false;
	children = new vector<GameObject*>();
}

GameObject::~GameObject() {
	//dtor

	parent->removeChild(getUniqueID());

	delete mesh;
	debug("deleted mesh");
	delete behaviour;
	debug("deleted behaviour");
	delete collider;
	debug("deleted collider");
	delete colorMap;
	debug("deleted colorMap");
	for (vector<GameObject*>::iterator iter = children->begin(); iter != children->end(); ++iter) {
		removeChild(((GameObject*)* iter)->getUniqueID());
	}
	delete children;
	debug("deleted children");
	setParent(NULL);
	debug("no more parents");

}

void GameObject::removeChild(int id){
	for (vector<GameObject*>::iterator iter = children->begin(); iter != children->end(); ++iter) {
		if(((GameObject*)* iter)->getUniqueID() == id){
			children->erase(iter);
		}
	}
}

glm::mat4 GameObject::getTransForm() {
	return transform;
}

void GameObject::translate(glm::vec3 translation) {
	transform = glm::translate(transform, translation);
}

void GameObject::rotate(float angle, glm::vec3 axis) {
	transform = glm::rotate(transform, angle, axis);
}

const string GameObject::getName() {
	return name;
}

glm::vec3 GameObject::getLocation() {
	return glm::vec3(transform[3][0], transform[3][1], transform[3][2]);
}

bool GameObject::hasCollider() {
	return collider != NULL;
}

void GameObject::setBehaviour(Behaviour * aBehaviour) {
	behaviour = aBehaviour;
}

void GameObject::setCollider(Collider * aCollider) {
	collider = aCollider;
}

void GameObject::setMesh(Mesh* aMesh) {
	mesh = aMesh;
}

void GameObject::setColorMap(Texture * aColorMap) {
	colorMap = aColorMap;
}

Mesh* GameObject::getMesh() {
	return mesh;
}

bool GameObject::collides(GameObject * otherGameObject) {
	Collider* c = getCollider();
	assert( otherGameObject != NULL);
	Collider* oc = otherGameObject->getCollider();
	assert( c != NULL);
	assert( oc != NULL);
	return c->collides(oc);
}

void GameObject::setTranslation(glm::vec3 translation) {
	transform[3][0] = translation[0];
	transform[3][1] = translation[1];
	transform[3][2] = translation[2];

}
void GameObject::onCollision(GameObject * otherGameObject) {
	if (behaviour) {
		behaviour->onCollision(otherGameObject);
	}
}

void GameObject::add(GameObject * child) {
	assert( child != NULL);
	cout << child->getName() << endl;
	children->push_back(child);
	child->setParent(this);
}

void GameObject::setParent(GameObject* parent) {
	this->parent = parent;
}

void GameObject::accept(VisitorInterface* visitor) {
	visitor->visit(this);
}

glm::mat4 GameObject::getTransform() {
	return transform;
}

Texture* GameObject::getColorMap() {
	return colorMap;
}

vector<GameObject *>* GameObject::getChildren() {
	return children;
}

Behaviour* GameObject::getBehaviour() {
	return behaviour;
}

void GameObject::setTransform(glm::mat4 transformation) {
	this->transform = transformation;
}

glm::mat4 GameObject::getParentTransform() {
	if (parent != NULL) {
		return parent->getParentTransform() * transform;
	}
	return glm::mat4(1);
}
// private functions

Collider* GameObject::getCollider() {
	return collider;
}

void GameObject::setSolid(bool isSolid) {
	solid = isSolid;
}

bool GameObject::getSolid() {
	return solid;
}

void GameObject::setCanBePickedUp(bool canbe) {
	pickUpable = canbe;
}

bool GameObject::canBePickedUp() {
	return pickUpable;
}

vector<GameObject *>* GameObject::getAllChildren() {
	vector<GameObject *>* allChildren = new vector<GameObject *>();
	for (vector<GameObject*>::iterator iter = children->begin(); iter != children->end(); ++iter) {
		allChildren->push_back(((GameObject*) *iter));
		vector<GameObject *>* childs = ((GameObject*) *iter)->getAllChildren();
		for (vector<GameObject*>::iterator i = childs->begin(); i != childs->end(); ++i) {
			allChildren->push_back(((GameObject*) *i));
		}
	}
	return allChildren;
}

bool GameObject::requiresKey() {
	return reqKey;
}

void GameObject::setReqKey(bool b) {
	reqKey = b;
}

glm::vec3 GameObject::getAbsoluteLocation( ) {
	if (parent != NULL) {
		return parent->getAbsoluteLocation() + getLocation();
	}
	return getLocation();
}

int GameObject::getUniqueID(){
	return uniqueID;
}
