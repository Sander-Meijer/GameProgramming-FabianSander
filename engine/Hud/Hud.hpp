#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include "../../Commonheader.h"
#include "HudString.h"

class Hud
{
	private:
		sf::RenderWindow* window;
		vector<HudString*>* hudStrings;
		static Hud* instance;
	public:
		Hud();
		virtual ~Hud();
		static Hud* getInstance();
		void draw( );
		void addHudString(HudString*);
		void setWindow(sf::RenderWindow*);
};

#endif // HUD_H
