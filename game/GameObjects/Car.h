/*
 * Car.h
 *
 *  Created on: 13 feb. 2013
 *      Author: Fabian
 */

#ifndef CAR_H_
#define CAR_H_
#include "../../engine/object/GameObject.hpp"
#include "../../engine/Hud/HudString.h"
#include "../../Commonheader.h"

class Car : public GameObject {
private:
	float speed;
	HudString* speedString;

public:
	Car(int, std::string , glm::vec3  );
	float* getSpeedPointer();
	void rotateWheels();
	virtual ~Car();
	vector< GameObject * >* getChildren();
	string getSpeedString();
	void setSpeed(float);
};

#endif /* CAR_H_ */
