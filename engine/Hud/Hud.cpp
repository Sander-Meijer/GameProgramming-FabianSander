#include <cassert>
#include <iostream>
#include <cstdio>
#include <GL/glew.h>
#include "../../engine/globals/FPS.hpp"
#include "Hud.hpp"
#include "../../engine/globals/Time.hpp"

Hud* Hud::instance;
Hud::Hud() {
	hudStrings = new vector<HudString*>();
	window = NULL;
}

Hud::~Hud() {
	//dtor
}

Hud* Hud::getInstance() {
	if (instance == NULL) {
		instance = new Hud();
	}
	return instance;
}



void Hud::addHudString(HudString* hudstring) {
	hudStrings->push_back(hudstring);
}

void Hud::setWindow(sf::RenderWindow* w) {
	window = w;
}


void Hud::draw() {
	assert( window != NULL);
	glDisable(GL_CULL_FACE); // needed for text, dont know why
	for (vector<HudString*>::iterator iter = hudStrings->begin(); iter != hudStrings->end(); ++iter) {
		HudString* hudstring = ((HudString *) *iter);
		sf::Text text(hudstring->getString());
		text.setCharacterSize(hudstring->getCharacterSize());
		text.setPosition(hudstring->getxLoc(), hudstring->getyLoc());
		text.setColor(hudstring->getColor());
		text.setStyle(hudstring->getTextType());
		window->draw(text);
	}

}
