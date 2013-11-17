#include <cassert>

#include "World.hpp"
#include "camera/Camera.hpp"
#include "light/Light.hpp"

World::World(int id, std::string aName )
:	GameObject(id, aName )
{
	//ctor
}

World::~World()
{
	//dtor
}

bool World::checkCollisions()
{
	bool result = false;
	for ( std::vector< GameObject * >::iterator collider = children->begin(); collider != children->end(); ++collider ) {
		if ( ((GameObject * )*collider)->hasCollider() ) {
			for ( std::vector< GameObject * >::iterator collidee = collider+1; collidee != children->end(); ++collidee ) {
				if ( ((GameObject * )*collidee)->hasCollider() ) {
					result = result || ((GameObject * )*collider)->collides( (GameObject *)*collidee );
				}
			}
		}
	}
	return result; // any collision
}

