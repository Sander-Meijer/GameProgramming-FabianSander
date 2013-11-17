#include "Renderer.hpp"
#include <cassert>
#include <GL/glew.h>
#include "../../engine/globals/Time.hpp"
#include "../light/ShaderProgram.hpp"
#include "../object/Texture.hpp"

Renderer::Renderer(sf::RenderWindow * aWindow) : window(aWindow), program(NULL) {
	this->hud = Hud::getInstance();

}

Renderer::~Renderer() {
	delete program;
}

void Renderer::use(ShaderProgram * aProgram) {
	program = aProgram;
	program->use();
	findLocations();
}


void Renderer::setProjection(glm::mat4 aProjection) {
	projection = aProjection;
}

void Renderer::setView(glm::mat4 aView) {
	view = aView;
}

void Renderer::setModel(glm::mat4 aModel) {
	model = aModel;
}

void Renderer::setLight(glm::vec3 aLight) {
	light = aLight;
}

void Renderer::setColorMap(Texture * aColorMap) // for single texture at a time, otherwise use activeTexture
		{
	colorMap = aColorMap->getId();
}

void Renderer::setTime(float aTime) {
	time = aTime;
}

void Renderer::draw(GameObject * aWorld) {
	time = Time::getInstance()->now(); // provide the shader with time float in seconds, for later use !
	program->use(); // make sure default shader program is used
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE); // defaul GL_BACK
	glClearColor( 0.1f, 0.1f, 0.1f, 1.0f );
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear screen 0
	visit(aWorld);
	window->pushGLStates();
	hud->draw();
	window->popGLStates();
	window->display();


}

void Renderer::draw(unsigned int size, GLuint indicesBuffer, GLuint verticesBuffer, GLuint normalsBuffer, GLuint uvsBuffer) // size is count of indices
		{
	// set all uniforms
	glUniform1f(timeLoc, time);
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniform3fv(lightLoc, 1, glm::value_ptr(light));
	glBindTexture(GL_TEXTURE_2D, colorMap);
	glUniform1i(colorMapLoc, 0);

	// set attributes
	// set indices attribute
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesBuffer);
	// set vertexattribute
	glEnableVertexAttribArray(verticesLoc); // enable variable
	glBindBuffer(GL_ARRAY_BUFFER, verticesBuffer); // make vertices the current buffer
	glVertexAttribPointer(verticesLoc, 3, GL_FLOAT, GL_FALSE, 0, 0); // point to bound buffer
	// set normalAttribute
	glEnableVertexAttribArray(normalsLoc);
	glBindBuffer(GL_ARRAY_BUFFER, normalsBuffer); // make vertices the current buffer
	glVertexAttribPointer(normalsLoc, 3, GL_FLOAT, GL_TRUE, 0, 0); // GL_TRUE for nomalisation
	// set uv attribute
	glEnableVertexAttribArray(uvsLoc);
	glBindBuffer(GL_ARRAY_BUFFER, uvsBuffer); // make vertices the current buffer
	glVertexAttribPointer(uvsLoc, 2, GL_FLOAT, GL_FALSE, 0, 0);
	// draw indexed arrays
	glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, (GLvoid*) 0);
	// no current buffer, to avoid mishaps
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDisableVertexAttribArray(uvsLoc);
	glDisableVertexAttribArray(normalsLoc);
	glDisableVertexAttribArray(verticesLoc);
	glBindTexture(GL_TEXTURE_2D, 0);
}


// private members
void Renderer::findLocations() {
	assert( program != NULL);
	// only if there is a program set

	projectionLoc = program->getUniformLocation("projection");
	viewLoc = program->getUniformLocation("view");
	modelLoc = program->getUniformLocation("model");
	lightLoc = program->getUniformLocation("light");
	timeLoc = program->getUniformLocation("time");
	colorMapLoc = program->getUniformLocation("colorMap");

	verticesLoc = program->getAttribLocation("vertex");
	normalsLoc = program->getAttribLocation("normal");
	uvsLoc = program->getAttribLocation("uv");
}

void Renderer::visit(GameObject* gameObject) {
	std::vector<GameObject *>* children = gameObject->getChildren();
	Mesh* mesh = gameObject->getMesh();
	Texture* texture = gameObject->getColorMap();
	if (mesh) { // if there is something to draw
		setModel(gameObject->getParentTransform()); // combine parents transfor with own
		if (texture) { //is has a colormap
			setColorMap(texture);
		}
		mesh->accept(this);
	}
	// draw children
	for (std::vector<GameObject *>::iterator i = children->begin(); i != children->end(); ++i) {
		((GameObject *) *i)->accept(this);
	}
}

void Renderer::visit(Mesh* mesh) {
	draw(mesh->size(), mesh->getIndicesBuffer(), mesh->getVerticesBuffer(), mesh->getNormalsBuffer(), mesh->getUvsBuffer());
}

void Renderer::visit(Camera* camera) {
//	clear(glm::vec4(0.1f, 0.1f, 0.1f, 1.0f)); // clear screen with color
	setProjection(camera->getProjection()); // model = cam to worldspace so inverse for world->camspace
	setView(glm::inverse(camera->getTransform())); // model = cam to worldspace so inverse for world->camspace
}

void Renderer::visit(Light* light) {
	setLight(light->getLocation());
}
