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
	void onDeactivate();
	void onFrame(key_buffer kb);
	FPSCounter();
	~FPSCounter();
};

