#pragma once
#include "Module.h"
#include "DrawBuffer.h"
class FPSCounter :
	public Module
{	
	DWORD tick1=0,tick2 = 0;
	DrawBuffer db;
	int counter=0;
public:
	void onActivate();
	void onDesactivate();
	void onFrame(char a);
	FPSCounter();
	~FPSCounter();
};

