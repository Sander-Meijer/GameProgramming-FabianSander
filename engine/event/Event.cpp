/*
 * Event.cpp
 *
 *  Created on: 5 apr. 2013
 *      Author: Fabian
 */

#include "Event.hpp"
#include "EventManager.hpp"

Event::Event(Command command, string message) : message(message) {
	EventManager::getInstance()->pushEvent(this);
	this->command = command;
}

Event::~Event() {

}

std::string Event::getMessage() {
	return message;
}


Event::Command Event::getCommand() {
	return command;
}
