#ifndef WORLD_H
#define WORLD_H

#include "object/GameObject.hpp"
class Camera;
class Light;
class World : public GameObject
{
	private:

	public:
		World(int, std::string aName = NULL );
		virtual ~World();

		bool checkCollisions();


};

#endif // WORLD_H
