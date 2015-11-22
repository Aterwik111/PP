#pragma once
#include "Module.h"
#include "DrawBuffer.h"
class MainMenu :
	public Module
{
	DrawBuffer db;
public:
	void onActivate();
	void onDeactivate();
	void onFrame(char a);
	MainMenu();
	~MainMenu();
};

