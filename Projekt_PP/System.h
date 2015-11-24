#pragma once
#include "Module.h"
#include "MainMenu.h"
#include "Game.h"
#include "HelpModule.h"
#include "FPSCounter.h"

class System :
	public Module
{
	FPSCounter fpsc;
	HelpModule helpMenu;
	Level* currentLvl = NULL;
	Level* returnPoint = NULL;
public:
	MainMenu menuLvl;
	Game gameLvl;
	void gotoLevel(Level* lvl,int param);
	void onFrame(key_buffer kb);
	System();
	~System();
};
extern System *systemModule;
