

#ifndef Player_H_
#define Player_H_
#include "../../engine/object/GameObject.hpp"
#include "../../engine/Hud/HudString.h"

class Player : public GameObject {
private:
	int keys;
	HudString* keyString;
public:
	Player(int, std::string , glm::vec3  );
	float* getSpeedPointer();
	void rotateWheels();
	virtual ~Player();
	void setKey(int);
	int getKeys();
};

#endif /* CAR_H_ */
