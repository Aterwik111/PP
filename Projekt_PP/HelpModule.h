#pragma once
#include "Module.h"
#include "DrawBuffer.h"
class HelpModule :
	public Module
{
	DrawBuffer db;
public:
	bool bShown=false;
	void ShowHelp();
	void HideHelp();
	void ToggleHelp();
	void onFrame(key_buffer kb);
	HelpModule();
	~HelpModule();
};

