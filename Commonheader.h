/*
 * Commonheader.h
 *
 *  Created on: 27 mrt. 2013
 *      Author: Fabian
 */

#ifndef COMMONHEADER_H_
#define COMMONHEADER_H_

#include "string"
#include <vector>
#include "iostream"
#include <sstream>
#include <cassert>

using namespace std;


inline void debug(string s ) { if (true) { cout << s << endl; } }
inline string cI(int number){ stringstream ss;ss << number; return ss.str(); }
inline string fI(float number){ stringstream ss;ss << number; return ss.str(); }

#endif /* COMMONHEADER_H_ */
