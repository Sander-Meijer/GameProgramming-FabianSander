#include "Player.h"

using namespace std;
Player::Player(int id, std::string aName, glm::vec3 aPosition) :
		GameObject(id, aName, aPosition) {
	keys = 0;
	keyString = new HudString("keys: " + cI(keys), 10, 60);
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}


void Player::setKey(int keys) {
	this->keys = keys;
	keyString->setString("keys: " + cI(keys));
}

int Player::getKeys(){
	return keys;
}


