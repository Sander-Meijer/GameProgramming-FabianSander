/*
 * LevelBuilder.cpp
 *
 *  Created on: 20 mrt. 2013
 *      Author: Fabian
 */

#include "LevelBuilder.h"
#include <utility>
#include "../../game/GameObjects/Car.h"
#include "../../game/behaviours/CameraFollowBehaviour.h"
#include <algorithm>
using namespace std;

LevelBuilder* LevelBuilder::instance = new LevelBuilder();

LevelBuilder::LevelBuilder() {
	followables = new map<std::string, GameObject*>();
	deb = true;
}

LevelBuilder::~LevelBuilder() {
	// TODO Auto-generated destructor stub
}

LevelBuilder* LevelBuilder::getInstance() {
	return instance;
}

GameObject* LevelBuilder::loadFile(const char* s) {
	GameObject* world = ObjectFactory::getInstance()->createWorld();
	string line = "";
	ifstream myfile;
	myfile.open(s);
	if (myfile.is_open()) {
		while (!myfile.eof()) {
			getline(myfile, line);
			world->add(parent(line, myfile, world));
		}
		myfile.close();
	} else {
		cout << "Unable to open file";
	}
	return world;
}

GameObject* LevelBuilder::buildGameObject(string s) {
	debug("building gameObject " + s);
	GameObject* gameObject = ObjectFactory::getInstance()->loadObject(s, glm::vec3());
	debug("building Mesh " + s);
	gameObject->setMesh(ObjectFactory::getInstance()->loadMesh(s));
	debug("building Text " + s);
	gameObject->setColorMap(ObjectFactory::getInstance()->loadTexture(s));
	return gameObject;
}

GameObject* LevelBuilder::parent(string s, ifstream& myfile, GameObject* gameObject) {
	GameObject* g = loadObject(s, true);
	string line = "";
	if (myfile.is_open()) {
		while (!myfile.eof()) {
			getline(myfile, line);
			if (std::string::npos == line.find("//")) {
				if (std::string::npos != line.find("#")) {
					debug("specials");
					specials(line, gameObject);
					debug("finished special");
				} else if (std::string::npos != line.find("</")) {
					return g;
				} else if (std::string::npos != line.find("<")) {
					g->add(parent(line, myfile, g));
				} else {
					g->add(loadObject(line, false));
				}
			}
		}
	}
	debug(" problem here?");
	if (g != NULL) {
		debug(" problem there?");
		gameObject->add(g);
		debug(" problem here!");
	}
	return gameObject;
}

GameObject* LevelBuilder::loadObject(string line, bool parent) {
	debug("loadObject " + line);
	glm::vec3 position;
	glm::vec3 rotation;
	float angle = 0.0f;
	char name[25]; // c-type string to store cmd
	char extras[26];
	char behaviour[26];
	char collision[26];
	name[0] = 0;
	line.erase(remove(line.begin(), line.end(), '<'), line.end());
	sscanf(line.c_str(), " %25s ; %f %f %f ; %f %f %f %f ; %25s ; %25s ; %25s  ", name, &position.x, &position.y, &position.z, &angle, &rotation.x, &rotation.y, &rotation.z, extras, behaviour, collision);
	string s = name;
	debug("loadObject " + s);
	GameObject* g;
	if (parent) {
		g = ObjectFactory::getInstance()->loadObject(s, glm::vec3());
	} else {
		g = buildGameObject(s);
	}
	g->setTranslation(position);
	if (angle != 0.0f) {
		g->rotate(angle, rotation);
	}
	string ex = extras;
	if (ex != "") {
		debug("handling extras for: " + s);
		handleExtras(g, ex);
	}
	string behaviours = behaviour;
	if (behaviours != "") {
		setBehaviour(g, behaviours);
	}
	string collisions = collision;
	debug("COLLIIIIIIIII" + collisions);
	setCollider(g, collisions);
	debug("done loading" + s);
	return g;
}

void LevelBuilder::specials(std::string s, GameObject* world) {
	debug("special is: " + s);
	assert(world != NULL);
	if (std::string::npos != s.find("#skybox")) {
		Skybox* sb = ObjectFactory::getInstance()->createSkybox("default_outside");
		map<std::string, GameObject*>::iterator iter = followables->begin();
		if (iter != followables->end()) {
			GameObject* car = iter->second;
			sb->setBehaviour(new SkyboxBehaviour(sb, car));
		}
		world->add(sb);
	} else if (std::string::npos != s.find("#camera")) {
		Camera* c = ObjectFactory::getInstance()->createCamera();
		map<std::string, GameObject*>::iterator iter = followables->begin();
		if (iter != followables->end()) {
			GameObject* followable = iter->second;
			char name[25];
			glm::vec3 position;
			glm::vec3 rotation;
			sscanf(s.c_str(), " %25s ; %f %f %f ; %f %f %f ", name, &position.x, &position.y, &position.z, &rotation.x, &rotation.y, &rotation.z);
			CameraFollowBehaviour* cfb = new CameraFollowBehaviour(followable, c);
			cfb->setTrans(position);
			cfb->setRot(rotation);
			c->setBehaviour(cfb);

		}
		world->add(c);
	} else if (std::string::npos != s.find("#light")) {
		world->add(ObjectFactory::getInstance()->createLight());
	}
}

void LevelBuilder::handleExtras(GameObject* gameObject, string s) {
	if (std::string::npos != s.find("f")) {
		followables->insert(pair<string, GameObject*>(gameObject->getName(), gameObject));
	}
	if (std::string::npos != s.find("s")) {
		debug(" making " + gameObject->getName() + " solid");
		gameObject->setSolid(true);
	}
	if (std::string::npos != s.find("p")) {
		debug(" making " + gameObject->getName() + " pick up able");
		gameObject->setCanBePickedUp(true);
	}
	if (std::string::npos != s.find("k")) {
		debug(" making " + gameObject->getName() + " requires key");
		gameObject->setReqKey(true);
	}
}

void LevelBuilder::setBehaviour(GameObject* gameObject, string s) {
	if (string::npos != s.find("behaviour") || string::npos != s.find("Behaviour")) {
		Behaviour* b = BehaviourRegistry::getBehaviour(gameObject, s);
		if (b != NULL) {
			debug("setting behaviour " + s);
			gameObject->setBehaviour(b);
		}
	}
}

void LevelBuilder::setCollider(GameObject* gameObject, string s) {
	debug(" COLLIDER MUP MUP" + s);
	if (string::npos != s.find("AABBcollider")) {
		debug("setting AABBcollider for: " + gameObject->getName());
		AABBCollider* collider = new AABBCollider(gameObject, 1.0f);
		gameObject->setCollider(collider);
	} else if (string::npos != s.find("collider")) {
		debug("setting collider for: " + gameObject->getName());
		SphereCollider* collider = new SphereCollider(gameObject, 1.0f);
		gameObject->setCollider(collider);
	}
}
