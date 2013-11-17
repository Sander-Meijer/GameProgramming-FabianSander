/*
 * VistitorInterface.hpp
 *
 *  Created on: 14 mrt. 2013
 *      Author: Sander & Fabian
 */

#ifndef VISTITORINTERFACE_HPP_
#define VISTITORINTERFACE_HPP_

#include "../object/GameObject.hpp"
#include "../object/Mesh.hpp"
#include "../camera/Camera.hpp"
#include "../light/Light.hpp"

class VisitorInterface {

public:
	virtual ~VisitorInterface() {};
	virtual void visit(GameObject* gameObject) = 0;
	virtual void visit(Mesh* mesh) = 0;
	virtual void visit(Camera* camera) = 0;
	virtual void visit(Light* light) = 0;
};

#endif /* VISTITORINTERFACE_HPP_ */
