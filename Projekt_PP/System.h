#pragma once
#include "Module.h"
#include "HelpModule.h"
#include "FPSCounter.h"
class System :
	public Module
{
	FPSCounter fpsc;
	int mode;
public:
	HelpModule helpMenu;
	void onFrame(char a);
	System();
	~System();
};

