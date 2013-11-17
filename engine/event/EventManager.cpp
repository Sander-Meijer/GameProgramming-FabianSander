/*
 * EventManager.cpp
 *
 *  Created on: 3 apr. 2013
 *      Author: Fabian
 */

#include "EventManager.hpp"
#include "../globals/Time.hpp"

EventManager* EventManager::instance;

EventManager* EventManager::getInstance() {
	if (instance != NULL) {
		instance = new EventManager();
	}
	return instance;
}

EventManager::EventManager() {
	// TODO Auto-generated constructor stub

}

EventManager::~EventManager() {
	// TODO Auto-generated destructor stub
}

void EventManager::pushEvent(Event* event) {
	eventList.push_back(event);
	notifyAll();
}

std::vector<Event*>* EventManager::getEventList() {
	return &eventList;
}

vector<Event*>* EventManager::getEventsOfType(Event::Command command) {
	vector<Event*>* eventsOfType = new std::vector<Event*>();
	for(vector<Event*>::iterator iter = eventList.begin(); iter != eventList.end(); ++iter) {
		if(((Event*) *iter)->getCommand() == command) {
			eventsOfType->push_back(((Event*) *iter));
		}
	}

	return eventsOfType;
}
