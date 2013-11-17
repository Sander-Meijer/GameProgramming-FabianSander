/*
 * ObjectFactory.cpp
 *
 *  Created on: 20 mrt. 2013
 *      Author: Fabian
 */

#include "ObjectFactory.h"

ObjectFactory* ObjectFactory::instance;

ObjectFactory::ObjectFactory() {
	currentID = 0;
	// TODO Auto-generated constructor stub

}

ObjectFactory::~ObjectFactory() {
	// TODO Auto-generated destructor stub
}

ObjectFactory* ObjectFactory::getInstance() {
	if (!instance) {
		instance = new ObjectFactory();
	}
	return instance;
}
Mesh* ObjectFactory::loadMesh(string s){
	string derp = "assets/models/" + s + ".obj";
	Mesh* mesh = Mesh::load(derp.c_str());
	return mesh;
}

GameObject* ObjectFactory::loadObject( string s, glm::vec3 position){
	if (s == "car") {
		return new Car(currentID++, s, position);
	} if ( s == "player") {
		return new Player(currentID++, s, position);
	}
	return new GameObject(currentID++, s, position);
}

Texture* ObjectFactory::loadTexture(string s){
	string derp = "assets/models/" + s + ".png";
	Texture* texture = Texture::load(derp.c_str());
	return texture;

}

Behaviour* ObjectFactory::loadBehaviour(const char*) {
	return NULL; // because wut
}

Skybox* ObjectFactory::createSkybox(std::string skyboxFolder){
	Skybox* box = new Skybox(currentID++);

	box->add(createSkyboxSide(skyboxFolder + "/north",-400,-350,-400));

	GameObject * s = createSkyboxSide(skyboxFolder + "/west",-400,-350,400);
	s->rotate(90.0,glm::vec3(0,1,0));
	box->add(s);

	GameObject * s2 = createSkyboxSide(skyboxFolder + "/east",400,-350,-400);
	s2->rotate(270.0,glm::vec3(0,1,0));
	box->add(s2);

	GameObject * s3 = createSkyboxSide(skyboxFolder + "/south",400,-350,400);
	s3->rotate(180.0,glm::vec3(0,1,0));
	box->add(s3);
	return box;
}

GameObject* ObjectFactory::createWorld(){
	return new GameObject(currentID++, "World", glm::vec3(0, 0, 0));
}

Light* ObjectFactory::createLight(){
	return new Light(currentID++, "Light", glm::vec3(20.0f, 100.0f, 150.0f));
}

Camera* ObjectFactory::createCamera(){
	return new Camera(currentID++, "Camera", glm::vec3(0, 0, 0));
}

GameObject* ObjectFactory::createSkyboxSide(std::string s, float x, float y,	float z){
	GameObject* side = new GameObject(currentID++, s, glm::vec3(x,y,z));
	Mesh * skyboxMesh = Mesh::load("assets/models/skyBoxPlane.obj");
	side->setMesh(skyboxMesh);
	std::string s2 = "assets/skyboxes/" + s + ".jpg";
	side->setColorMap(Texture::load(s2.c_str()));
	return side;
}
