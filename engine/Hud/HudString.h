/*
 * HudString.h
 *
 *  Created on: 5 apr. 2013
 *      Author: Fabian
 */

#ifndef HUDSTRING_H_
#define HUDSTRING_H_

#include "../../Commonheader.h"
#include <SFML/Graphics.hpp>

class HudString {
	private:
		string hudString;
		int xLoc, yLoc, characterSize;
		sf::Color color;
		sf::Text::Style textType;
public:
	HudString(string , int , int, int = 20, sf::Color = sf::Color::White, sf::Text::Style = sf::Text::Bold);
	virtual ~HudString();
	void setString(string);
	string getString();
	int getxLoc();
	int getyLoc();
	int getCharacterSize();
	sf::Color getColor();
	sf::Text::Style getTextType();
};

#endif /* HUDSTRING_H_ */
