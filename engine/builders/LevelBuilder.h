/*
 * LevelBuilder.h
 *
 *  Created on: 20 mrt. 2013
 *      Author: Fabian
 */

#ifndef LEVELBUILDER_H_
#define LEVELBUILDER_H_

#include "../object/GameObject.hpp"
#include "../camera/Camera.hpp"
#include "ObjectFactory.h"
#include "fstream"
#include "sstream"
#include "../../Commonheader.h"
#include <cstring>
#include "../skybox/Skybox.h"
#include "../light/Light.hpp"
#include <map>
#include "../behaviours/BehaviourRegistry.h"
#include "../behaviours/SkyboxBehaviour.h"
#include "../colliders/SphereCollider.hpp"
#include "../colliders/AABBCollider.h"

class LevelBuilder {
private:
	static LevelBuilder* instance;
	map<string, GameObject*>* followables;

	bool deb;
public:

	virtual ~LevelBuilder();
	GameObject* loadFile(const char*);
	GameObject* loadObject(string, bool);
	static LevelBuilder* getInstance();
	GameObject* buildGameObject(string);
	GameObject* parent(string, ifstream&, GameObject*);
	GameObject* readNode(string);
	void handleExtras(GameObject*, string);
	void specials(string, GameObject*);
	void setBehaviour(GameObject*, string);
	void setCollider(GameObject*, string);

private:
	LevelBuilder();
	glm::vec3 getPosition(string);
	glm::vec4 getRotation(string);
//	void debug(string);
};

#endif /* LEVELBUILDER_H_ */
