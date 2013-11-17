#ifndef SPHERECOLLISION_H
#define SPHERECOLLISION_H

#include "Collider.hpp"


class SphereCollider : public Collider
{
	private:
		float radius;
	public:
		SphereCollider( GameObject * aParent, float aRadius = 1.0f );
		virtual ~SphereCollider();

		virtual bool collides( Collider * otherCollider );
		virtual bool collides( SphereCollider * otherCollider );
		virtual bool collides( AABBCollider * otherCollider );

		string getName();
};

#endif // SPHERECOLLISION_H
