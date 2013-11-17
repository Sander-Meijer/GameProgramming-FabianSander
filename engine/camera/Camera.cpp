#include "Camera.hpp"
#include "../glm/glm.hpp"
#include "../interfaces/VistitorInterface.hpp"

Camera::Camera(int id, std::string aName, glm::vec3 aPosition )
:	GameObject(id, aName, aPosition )
{
	glm::vec3 eye = aPosition;
	glm::vec3 at ( 0.0f, 1.0f, 0.0f );
	glm::vec3 up ( 0.0f, 1.0f, 0.0f );
	transform = glm::inverse( glm::lookAt( eye, at, up ) );
	projection = glm::perspective(  60.0f, 4.0f/3.0f, 0.1f, 1000.0f  );
}

Camera::~Camera()
{
	//dtor
}

void Camera::accept(VisitorInterface* renderer) {
	renderer->visit(this);
}

glm::mat4 Camera::getProjection() {
	return projection;
}

