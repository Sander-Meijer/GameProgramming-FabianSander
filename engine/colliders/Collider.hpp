#ifndef COLLIDER_H
#define COLLIDER_H
#include "../../Commonheader.h"
class GameObject;
class SphereCollider;
class AABBCollider;
class Collider
{
	protected:
		GameObject * parent;
		float radius;
		bool deb;
	public:
		Collider( GameObject * aParent, float aRadius = 1.0f );
		virtual ~Collider();

		virtual bool collides( Collider * otherCollider );
		virtual string getName();

		GameObject* getParent();
//		void debug(string s);
};

#endif // COLLIDER_H
