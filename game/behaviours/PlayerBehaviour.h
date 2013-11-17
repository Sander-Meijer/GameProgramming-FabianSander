/*
 * PlayerBehaviour.h
 *
 *  Created on: 2 apr. 2013
 *      Author: Fabian
 */

#ifndef PLAYERBEHAVIOUR_H_
#define PLAYERBEHAVIOUR_H_

#include "../../engine/behaviours/Behaviour.hpp"
#include "../../Commonheader.h"
#include "../../engine/object/GameObject.hpp"
#include "../GameObjects/Player.h"

class PlayerBehaviour : public Behaviour{
private:
	Player* player;
	bool collided;
	float speed;
public:
	PlayerBehaviour(GameObject*);
	virtual ~PlayerBehaviour();
	void update(float step);
	void onCollision(GameObject*);
	void hardCodedCollisions();
};

#endif /* PLAYERBEHAVIOUR_H_ */
