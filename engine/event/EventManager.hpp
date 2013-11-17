/*
 * EventManager.h
 *
 *  Created on: 3 apr. 2013
 *      Author: Yme
 */

#ifndef EVENTMANAGER_H_
#define EVENTMANAGER_H_

#include "../../Commonheader.h"
#include "../interfaces/Observable.h"

#include "Event.hpp"

class EventManager : public Observable{
	private:
		static EventManager* instance;

		vector<Event*> eventList;

		EventManager();
	public:
		virtual ~EventManager();
		static EventManager* getInstance();
		void pushEvent(Event* event);
		vector<Event*>* getEventList();
		vector<Event*>* getEventsOfType(Event::Command);
};

#endif /* EVENTMANAGER_H_ */
