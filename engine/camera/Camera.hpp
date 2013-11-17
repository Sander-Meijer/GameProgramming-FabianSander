#ifndef CAMERA_H
#define CAMERA_H

#include "../object/GameObject.hpp"
#include "../../Commonheader.h"
class VisitorInterface;

class Camera : public GameObject
{
	private: //members
		glm::mat4 projection;

	public:
		Camera(int, std::string aName = NULL, glm::vec3 aPosition = glm::vec3( 0.0f, 3.0f, 5.0f ) );
		virtual ~Camera();

//		void draw( Renderer * renderer, glm::mat4 parentTransform = glm::mat4(1) );
		void accept( VisitorInterface * renderer);
		glm::mat4 getProjection();
};

#endif // CAMERA_H
