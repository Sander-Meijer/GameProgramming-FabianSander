#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include "glm/glm.hpp"
#include "../../Commonheader.h"

class Transform;
class Collider;
class VisitorInterface;
class Mesh;
class Texture;
class Behaviour;

class GameObject {
	protected:
		int uniqueID;

		std::string name;
		glm::mat4 transform;
		Collider * collider;
		Behaviour * behaviour;

		Mesh * mesh;
		Texture * colorMap;

		GameObject* parent;
		vector< GameObject * >* children;

		bool solid;
		bool pickUpable;
		bool reqKey;
	public:
		GameObject(int id, std::string aName = NULL, glm::vec3 aPosition = glm::vec3( 0.0f, 0.0f, 0.0f ) );
		virtual ~GameObject();

		void translate( glm::vec3 translation );
		void rotate( float angle, glm::vec3 axis );

		const std::string getName();
		glm::vec3 getLocation();
		glm::mat4 getTransForm();
		void setTransform(glm::mat4);

		bool hasCollider();

		void setBehaviour( Behaviour * aBehaviour );
		void setCollider( Collider * aCollider );
		void setMesh( Mesh * aMesh );
		void setColorMap( Texture * aColorMap );
		void setTranslation(glm::vec3);
		void setParent(GameObject*);
		Mesh* getMesh();
		glm::mat4 getTransform();
		glm::mat4 getParentTransform();
		Texture* getColorMap();
		vector< GameObject * >* getChildren();
		vector< GameObject * >* getAllChildren();
		void removeChild(int id);

		Behaviour* getBehaviour();
		Collider* getCollider();
		glm::vec3 getAbsoluteLocation();

		virtual bool collides( GameObject * otherGameObject );
		virtual void onCollision(  GameObject * otherGameObject );

		virtual void accept (VisitorInterface*);

		void add( GameObject * child );

		bool getSolid();
		void setSolid(bool);
		bool canBePickedUp();
		void setCanBePickedUp(bool);
		bool requiresKey();
		void setReqKey(bool);

		int getUniqueID();
	protected:

};

#endif // GAMEOBJECT_H
