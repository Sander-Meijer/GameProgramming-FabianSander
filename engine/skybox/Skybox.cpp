/*
 * Skybox.cpp
 *
 *  Created on: 26 feb. 2013
 *      Author: Fabian
 */

#include "Skybox.h"
#include "../object/Texture.hpp"
#include "../object/Mesh.hpp"
#include "string.h"
#include "../behaviours/SkyboxBehaviour.h"

Skybox::Skybox(int id) : GameObject(id, "skyBox",  glm::vec3(1) ) {
//	add(createSide(skyboxFolder + "/north",-400,-350,-400));
//
//	GameObject * s = createSide(skyboxFolder + "/west",-400,-350,400);
//	s->rotate(90.0,glm::vec3(0,1,0));
//	add(s);
//
//	GameObject * s2 = createSide(skyboxFolder + "/east",400,-350,-400);
//	s2->rotate(270.0,glm::vec3(0,1,0));
//	add(s2);
//
//	GameObject * s3 = createSide(skyboxFolder + "/south",400,-350,400);
//	s3->rotate(180.0,glm::vec3(0,1,0));
//	add(s3);

}

void Skybox::setSkyboxBehaviour(GameObject* gameObject) {
	setBehaviour(new SkyboxBehaviour(this, gameObject));
}

//GameObject* Skybox::createSide(std::string s, float x, float y,	float z) {
//	GameObject* side = new GameObject(id, s, glm::vec3(x,y,z));
//	Mesh * skyboxMesh = Mesh::load("assets/models/skyBoxPlane.obj");
//	side->setMesh(skyboxMesh);
//	std::string s2 = "assets/skyboxes/" + s + ".jpg";
//	side->setColorMap(Texture::load(s2.c_str()));
//	return side;
//}

Skybox::~Skybox() {
	// TODO Auto-generated destructor stub
}

