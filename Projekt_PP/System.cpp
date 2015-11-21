#include "includes.h"
#include "System.h"


void System::onFrame(char a)
{
	switch(a)
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
	case 'e':
		//przejscie do edytora
		break;
	}
}

System::System()
{
}


System::~System()
{
}
