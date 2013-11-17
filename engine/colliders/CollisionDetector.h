/*
 * CollisionDetector.h
 *
 *  Created on: 18 mrt. 2013
 *      Author: Sander
 */

#ifndef COLLISIONDETECTOR_H_
#define COLLISIONDETECTOR_H_

#include "../interfaces/VistitorInterface.hpp"
#include "../../Commonheader.h"
#include "../behaviours/Behaviour.hpp"

class CollisionDetector: VisitorInterface{
private:
	CollisionDetector();
public:
	virtual ~CollisionDetector();

	static CollisionDetector* getInstance();
	void checkCollisions(GameObject*);
	void visit(GameObject*);
	void visit(Mesh*);
	void visit(Camera*);
	void visit(Light*);
private:
	static CollisionDetector* instance;
};

#endif /* COLLISIONDETECTOR_H_ */
