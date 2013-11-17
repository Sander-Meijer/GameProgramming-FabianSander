#include "Light.hpp"

#include "../interfaces/VistitorInterface.hpp"

Light::Light(int id, std::string aName, glm::vec3 aPosition )
:	GameObject(id, aName, aPosition )
{
}

Light::~Light()
{
	//dtor
}

void Light::accept(VisitorInterface* renderer) {
	renderer->visit(this);
}
