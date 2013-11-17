#ifndef LIGHT_H
#define LIGHT_H

#include <string>
#include "../object/GameObject.hpp"

class VisitorInterface;
class Light : public GameObject
{
	public:
		Light(int, std::string aName = NULL, glm::vec3 aPosition = glm::vec3( 2.0f, 10.0f, 5.0f ) );
		virtual ~Light();

		void accept(VisitorInterface*);
};

#endif // LIGHT_H
