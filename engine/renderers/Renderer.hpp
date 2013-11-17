#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <SFML/Window.hpp>
#include "../glm/glm.hpp"
#include "../interfaces/VistitorInterface.hpp"
#include "../Hud/Hud.hpp"

class ShaderProgram;
class Texture;

class Renderer: public VisitorInterface {
private:
	sf::RenderWindow * window;
	Hud* hud;
	// the shader wrapper
	ShaderProgram * program;
	// shader input locations
	GLuint projectionLoc, viewLoc, modelLoc, lightLoc, timeLoc; // uniform locations
	GLuint verticesLoc, normalsLoc, uvsLoc;		// attribute locations
	GLuint colorMapLoc;

	// buffered variables
	float time;
	glm::mat4 projection, view, model;
	glm::vec3 light;
	GLuint colorMap;

public:
	Renderer(sf::RenderWindow * aWindow);
	virtual ~Renderer();

	void use(ShaderProgram * program);


	void setProjection(glm::mat4 aProjection);
	void setView(glm::mat4 aView);
	void setModel(glm::mat4 aModel);

	void setTime(float aTime);
	void setLight(glm::vec3 aLight);
	void setColorMap(Texture * aColorMap);

	/* interface methods*/
	void visit(GameObject*);
	void visit(Mesh*);
	void visit(Camera*);
	void visit(Light*);

	void draw( GameObject * aWorld ); // starting point for drawing
	// attributes for drawElements so indexed drawing
	void draw(unsigned int size, GLuint indicesId, GLuint verticesId,
			GLuint normalsId, GLuint uvsId);


private:
	void findLocations();
};

#endif // RENDERER_H
