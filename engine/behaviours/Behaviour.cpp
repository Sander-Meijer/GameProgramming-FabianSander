#include <cassert>
#include <iostream>
#include "Behaviour.hpp"
#include "../object/GameObject.hpp"

Behaviour::Behaviour( GameObject * aParent )
:	parent( aParent )
{
}

Behaviour::~Behaviour()
{
	//dtor
	parent->setBehaviour(NULL);
}

void Behaviour::update( float step )
{
//	std::cout << "Behavior handles update. Should not be ! " << std::endl;
}
void Behaviour::onCollision( GameObject * otherGameObject )
{
//	std::cout << "Behavior handles collision. Should not be ! " << std::endl;
}
