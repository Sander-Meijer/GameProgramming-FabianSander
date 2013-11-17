/*
 * Observer.h
 *
 *  Created on: 2 apr. 2013
 *      Author: Fabian
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

class Observable;
class Observer {
public:
	virtual ~Observer() {};
	virtual void update(Observable* calling) = 0;
};

#endif /* OBSERVER_H_ */
