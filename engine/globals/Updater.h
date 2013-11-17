/*
 * Updater.h
 *
 *  Created on: 14 mrt. 2013
 *      Author: Sander
 */

#ifndef UPDATER_H_
#define UPDATER_H_

#include "../interfaces/VistitorInterface.hpp"

class Updater: public VisitorInterface {
private:
	static Updater* instance;

public:
	static Updater* getInstance();
	virtual ~Updater();

	/* interface methods*/
	void visit(GameObject*);
	void visit(Mesh*);
	void visit(Camera*);
	void visit(Light*);

private:
	Updater(){};
};

#endif /* UPDATER_H_ */
