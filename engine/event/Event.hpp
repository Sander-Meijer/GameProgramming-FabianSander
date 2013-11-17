/*
 * Event.h
 *
 *  Created on: 3 apr. 2013
 *      Author: Yme
 */

#ifndef EVENT_H_
#define EVENT_H_

#include "../../CommonHeader.h"

class Event {
	private:
		string message;
	public:
		enum Command { SOUND  };
		Event(Command, string message);
		virtual ~Event();

		string getMessage();

		Command getCommand();
	private:
		Command command;
};


#endif /* EVENT_H_ */
