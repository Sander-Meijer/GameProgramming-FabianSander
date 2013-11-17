/*
 * Observable.h
 *
 *  Created on: 2 apr. 2013
 *      Author: Fabian
 */

#ifndef OBSERVABLE_H_
#define OBSERVABLE_H_

#include "../../Commonheader.h"
#include <vector>
#include "Observer.h"

class Observable  {
protected:
	vector<Observer*>* observers;
public:
	Observable();
	virtual ~Observable();
	void addObserver(Observer*);
	void notifyAll();
};

#endif /* OBSERVABLE_H_ */
