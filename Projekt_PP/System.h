#pragma once
#include "Module.h"
#include "MainMenu.h"
#include "Game.h"
#include "HelpModule.h"
#include "FPSCounter.h"

class System :
	public Module
{
	bool lvlChanged = false;
	int param;
	FPSCounter fpsc;
	HelpModule helpMenu;
	Level* currentLvl = NULL;
public:
	void dialog(const char *tresc);
	bool textInputDialog(const char *komunikat, char *buffer);
	MainMenu menuLvl;
	Game gameLvl;
	void gotoLevel(Level* lvl,int param);
	void onFrame(key_buffer kb);
	System();
	~System();
};
extern System *systemModule;
