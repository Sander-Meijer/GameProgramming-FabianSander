#ifndef FPS_H
#define FPS_H

#include "../../Commonheader.h"
#include "../Hud/HudString.h"
class FPS {
private:
	FPS();
	HudString* fpsString;
public:
	void update();
	unsigned int getFPS();
	static FPS* getInstance();
private:
	static FPS* instance;
	float startTime;
	unsigned int count;
	unsigned int fps;
};

#endif // FPS_H
