/*
 * Observable.cpp
 *
 *  Created on: 2 apr. 2013
 *      Author: Fabian
 */

#include "Observable.h"

Observable::Observable() {
	observers = new vector<Observer*>();

}

Observable::~Observable() {
	// TODO Auto-generated destructor stub
}

void Observable::addObserver(Observer* o ) {
	observers->push_back(o);
}

void Observable::notifyAll(){
	for(vector<Observer*>::iterator iter = observers->begin(); iter != observers->end(); ++iter) {
		((Observer*)*iter)->update(this);
	}
}
