/*
 * HudString.cpp
 *
 *  Created on: 5 apr. 2013
 *      Author: Fabian
 */

#include "HudString.h"
#include "Hud.hpp"

HudString::HudString(string s, int x, int y, int cS, sf::Color c, sf::Text::Style t) {
	hudString = s;
	xLoc = x;
	yLoc = y;
	characterSize = cS;
	color = c;
	textType = t;
	Hud::getInstance()->addHudString(this);
}

HudString::~HudString() {
	// TODO Auto-generated destructor stub
}

void HudString::setString(string s) {
	hudString = s;
}

string HudString::getString() {
	return hudString;
}

int HudString::getxLoc() {
	return xLoc;
}

int HudString::getyLoc() {
	return yLoc;
}

sf::Color HudString::getColor() {
	return color;
}
sf::Text::Style HudString::getTextType() {
	return textType;
}

int HudString::getCharacterSize() {
	return characterSize;
}
