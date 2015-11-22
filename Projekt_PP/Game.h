#pragma once
#include "Module.h"
#include "Labirynth.h"
#include "DrawBuffer.h"
class Game :
	public Module
{
	DrawBuffer db2D;
	DrawBuffer db3D;
public:
	void onActivate();
	void onDeactivate();
	void onFrame(char a);
	Labirynth currLabirynth;
	Game();
	~Game();
};

