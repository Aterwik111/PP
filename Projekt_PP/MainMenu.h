#pragma once
#include "Level.h"
#include "DrawBuffer.h"
class MainMenu :
	public Level
{
	DrawBuffer db;
public:
	void onEnter(int param);
	void onExit();
	void onFrame(key_buffer kb);
	MainMenu();
	~MainMenu();
};

