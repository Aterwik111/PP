#include "includes.h"
#include "System.h"


void System::gotoLevel(Level * lvl,int param)
{
	helpMenu.HideHelp();
	if (currentLvl != NULL) {
		returnPoint = currentLvl;
		currentLvl->onExit();
	}
	else {
		returnPoint = &menuLvl;
	}
	currentLvl = lvl;
	lvl->onEnter(param);
}

void System::onFrame(key_buffer kb)
{
	switch(kb.keys[0])
	{
	case 'h':
		helpMenu.ToggleHelp();		
		break;
	case 'f':
		if (fpsc.isActive()) {
			fpsc.setInactive();
		}
		else {
			fpsc.setActive();
		}
		break;
	}
	currentLvl->onFrame(kb);
}

System::System()
{
	gotoLevel(&menuLvl,0);
}


System::~System()
{
}
