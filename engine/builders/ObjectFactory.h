/*
 * ObjectFactory.h
 *
 *  Created on: 20 mrt. 2013
 *      Author: Fabian
 */

#ifndef ObjectFactory_H_
#define ObjectFactory_H_

#include <string.h>

#include "../object/GameObject.hpp"
#include "../object/Mesh.hpp"
#include "../object/Texture.hpp"
#include "../../game/GameObjects/Car.h"
#include "../../game/GameObjects/Player.h"
#include "../behaviours/Behaviour.hpp"
#include "../../Commonheader.h"
#include "../skybox/Skybox.h"
#include "../camera/Camera.hpp"
#include "../light/Light.hpp"

class ObjectFactory {

private:
	int currentID;
	ObjectFactory();
	static ObjectFactory* instance;
public:

	virtual ~ObjectFactory();

	static ObjectFactory* getInstance();

	Mesh* loadMesh(string);
	GameObject* loadObject( string, glm::vec3);
	Texture* loadTexture(string);
	Behaviour* loadBehaviour(const char*);

	GameObject* createWorld();
	Skybox* createSkybox(std::string skyboxFolder);
	Light* createLight();
	Camera* createCamera();

private:
	GameObject* createSkyboxSide(std::string, float, float, float);
};

#endif /* ObjectFactory_H_ */
