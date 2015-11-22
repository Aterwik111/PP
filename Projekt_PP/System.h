#pragma once
#include "Module.h"
#include "MainMenu.h"
#include "HelpModule.h"
#include "FPSCounter.h"
#include "Game.h"
class System :
	public Module
{
	MainMenu main_menu;
	FPSCounter fpsc;
	int currentLvl;
	int mode;
public:
	HelpModule helpMenu;
	void onFrame(char a);
	System();
	~System();
};

